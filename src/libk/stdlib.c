
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <kernel/heap.h>
#include <kernel/framebuffer_console.h> /* Color for panic() */
#include <kernel/color.h>               /* Color for panic() */

int digits_int(int64_t num) {
    if (num < 0)
        num = -num;

    int ret;

    /* Remove a digit each iteration until there are none left */
    for (ret = 1; (num /= 10) > 0; ret++)
        ;

    return ret;
}

int digits_hex(uint64_t num) {
    if (num == 0)
        return 1;

    int ret;

    /* 4 is the size in bits of 0xF */
    for (ret = 0; num != 0; ret++, num >>= 4)
        ;

    return ret;
}

int digits_double(double num, uint32_t decimals) {
    if (num < 0)
        num = -num;

    /* Digits of integer part + dot + decimal digits */
    return digits_int((int)num) + 1 + decimals;
}

void itoa(char* str, int64_t num) {
    int sign   = 0;
    int digits = digits_int(num);

    if (num < 0) {
        sign   = 1;
        num    = -num;
        str[0] = '-';
    }

    /* Since we know the last idx, write null terminator */
    str[digits + sign] = '\0';

    /*
     * Add 1 if num is negative (for "-")
     * Subtract 1 because we start on the string's idx (3 digits -> 2 last idx)
     *
     * Loop until i < sign (instead of until 0), because if sign is 1 (num is
     * negative), we want to stop before writing "-" (last pos is 1).
     */
    for (int i = digits + sign - 1; i >= sign; i--) {
        str[i] = num % 10 + '0';
        num /= 10;
    }
}

int atoi(const char* str) {
    int ret = 0;

    /* Go to the first digit of the string */
    while (*str != '-' && (*str < '0' || *str > '9'))
        str++;

    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    }

    /* We assume that if we encounter a '-', the number is immediately after */
    while (*str >= '0' && *str <= '9') {
        ret *= 10;
        ret += *str - '0';
        str++;
    }

    /* Make negative if needed and return */
    return ret * sign;
}

int ipow(int b, int e) {
    int ret = 1;

    /* Multiply by the base "e" times */
    while (e-- > 0)
        ret *= b;

    return ret;
}

/** @todo This is smart but not efficient. Optimize. */
void itoan(char* str, int64_t num, size_t max_digits) {
    if (max_digits <= 0) {
        str[0] = '\0';
        return;
    }

    /* sp is the current position we want to write in the string */
    size_t sp = 0;

    /* Write '-' for negative numbers and convert number to positive */
    if (num < 0) {
        str[sp++] = '-';
        num       = -num;
    }

    /*
     * cur_digit will count the current number we want to write, starting from
     * the right, where the last one is 0. So for 354, cur_digit will be 2, and
     * 354 / 100 is 3. If cur_digit is 1, 354 / 10 = 35, and we can extract the
     * last digit by doing (n%10)
     *
     * Also make sure the string position is not greater than the max we can
     * write.
     */
    int cur_digit;
    for (cur_digit = digits_int(num) - 1; cur_digit >= 0 && sp < max_digits;
         cur_digit--)
        str[sp++] = (num / ipow(10, cur_digit)) % 10 + '0';

    str[sp++] = '\0';
}

void panic(const char* func, unsigned int line, const char* fmt, ...) {

    va_list va;
    va_start(va, fmt);

    putchar('\n');
    fbc_setfore(COLOR_RED_B);

    if (func != NULL)
        printf("[%s:%d] ", func, line);

    printf("kernel panic: ");
    fbc_setfore(COLOR_RED);
    vprintf(fmt, va);

    va_end(va);

    asm volatile("hlt");

    for (;;)
        ;

    __builtin_unreachable();
}

void abort(void) {
    puts("\nkernel panic: abort");

    asm volatile("hlt");

    for (;;)
        ;

    __builtin_unreachable();
}

void* malloc(size_t sz) {
    /* Aligned to 8 bytes */
    return heap_alloc(sz, 8);
}

void* calloc(size_t item_n, size_t item_sz) {
    return heap_calloc(item_n, item_sz, 8);
}

void free(void* ptr) {
    heap_free(ptr);
}

/**
 * @var rand_next
 * @brief Used by the rand and srand functions
 */
static uint32_t rand_next = 1;

int rand(void) {
    rand_next = (rand_next * 1103515245) + 12345;
    return (unsigned int)(rand_next / 65536) % RAND_MAX;
}

void srand(unsigned int seed) {
    rand_next = seed;
}
