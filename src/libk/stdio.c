
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef USE_VGA
#include <kernel/vga.h>
#else /* Framebuffer console */
#include <kernel/framebuffer_console.h>
#endif

/* print: calls "putchar" for each char of "str". Returns bytes written. */
static inline int print(const char* str) {
    while (*str != '\0')
        putchar(*str++);

    return 0;
}

/* printi: similar to stdlib's itoan, but instead of writting to buffer, prints. Used
 * by printf's "%i". */
static void printi(int num) {
    /* Write '-' for negative numbers and convert number to positive */
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    /* For more information about this loop, see stdlib's itoan. */
    for (int cur_digit = count_digits(num) - 1; cur_digit >= 0; cur_digit--)
        putchar((num / ipow(10, cur_digit)) % 10 + '0');
}

/* printx: print "num" in hexadecimal format (lowercase) */
static void printx(unsigned long num) {
    if (num == 0)
        print("0");

    /* max digits of an unsigned long */
    char hex_str[12] = { 0 };

    int tmp = 0;
    size_t i;
    for (i = 0; num > 0 && i < sizeof(hex_str) - 1; i++) {
        tmp = num % 16;
        num /= 16;

        /* Convert to char */
        tmp += (tmp < 10) ? '0' : 'a' - 10;

        hex_str[i] = tmp;
    }

    hex_str[i] = '\0';

    /* Reverse string and print */
    strrev(hex_str);
    print(hex_str);
}

/* printX: print "num" in hexadecimal format (uppercase) */
static void printX(unsigned long num) {
    if (num == 0)
        print("0");

    /* max digits of an unsigned long */
    char hex_str[12] = { 0 };

    int tmp = 0;
    size_t i;
    for (i = 0; num > 0 && i < sizeof(hex_str) - 1; i++) {
        tmp = num % 16;
        num /= 16;

        /* Convert to char */
        tmp += (tmp < 10) ? '0' : 'A' - 10;

        hex_str[i] = tmp;
    }

    hex_str[i] = '\0';

    /* Reverse string and print */
    strrev(hex_str);
    print(hex_str);
}

/* puts: prints "str" and a newline char */
int puts(const char* str) {
    return printf("%s\n", str);
}

/* printf: prints with format "fmt" */
int printf(const char* fmt, ...) {
    va_list va;
    va_start(va, fmt);

    int ret = vprintf(fmt, va);

    va_end(va);
    return ret;
}

/* vprintf: prints with format "fmt" using the variable argument list "va" */
int vprintf(const char* fmt, va_list va) {
    int written = 0;

    while (*fmt != '\0') {
        /* If we get a '%', expect format, if not, just print normal char */
        if (*fmt == '%') {
            fmt++;
            if (written < INT_MAX)
                written++;
            else
                return -1; /* TODO: Set errno to EOVERFLOW */

            /* TODO: Support for more than 1 format char */
            switch (*fmt) {
                case 'c':
                    putchar((char)va_arg(va, int));
                    break;
                case 's':
                    const char* va_str = va_arg(va, const char*);
                    print(va_str);

                    /* If printing a string from va_list, add len to "written" */
                    int va_strlen = strlen(va_str);
                    if (written + va_strlen < INT_MAX)
                        written += va_strlen;
                    else
                        return -1; /* TODO: Set errno to EOVERFLOW */

                    break;
                case 'd':
                    printi(va_arg(va, int));
                    break;
                case 'x':
                    printx(va_arg(va, unsigned long));
                    break;
                case 'X':
                    printX(va_arg(va, unsigned long));
                    break;
                default:
                    /* If unknown fmt, print the % and the unknown char */
                    putchar('%');
                    putchar(*fmt);
                    break;
            }
        } else {
            /* TODO: Any kind of return value check? */
            putchar(*fmt);
        }

        fmt++;
        if (written < INT_MAX)
            written++;
        else
            return -1; /* TODO: Set errno to EOVERFLOW */
    }

    return written;
}

/* putchar: prints the single character "c" */
int putchar(int c) {
    const char tmp = (char)c;

#ifdef USE_VGA
    term_putchar(tmp);
#else /* Framebuffer console */
    fbc_putchar(tmp);
#endif

    return tmp;
}

