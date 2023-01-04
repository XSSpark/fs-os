
#ifndef _FONTS_MAIN_FONT_H
#define _FONTS_MAIN_FONT_H

#include <kernel/font.h>

/*
 * Each item of the char idx is a 8px column of that char, represented by each bit of
 * the byte. Example:
 *      *.font['a'] = {
 *          #######.,
 *          ...#...#,
 *          ...#...#,
 *          ...#...#,
 *          ...#...#,
 *          #######.,
 *      }
 * Where each item of idx 'a' is a byte, and each # is a bit set to 1 of that byte,
 * and each . is a bit set to 0.
 * Because it is a 3d array in 1d format, to access a px of a char we use:
 *      Font->font['X' * Font->w + x] & (1 << y)
 *
 * For more information see:
 * https://jared.geek.nz/2014/jan/custom-fonts-for-microcontrollers
 * (https://web.archive.org/web/20221206153507/https://jared.geek.nz/2014/jan/custom-fonts-for-microcontrollers)
 */
Font main_font = {
    .w = 7,
    .h = 8,
    /* Invalid ptrs are spaces (marked as NULL) */
    .font = "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /*   */
            "\x00\x00\x5f\x00\x00\x00\x00"  /* ! */
            "\x03\x00\x03\x00\x00\x00\x00"  /* " */
            "\x14\x7f\x14\x7f\x14\x00\x00"  /* # */
            "\x6f\x49\xc9\x7b\x00\x00\x00"  /* $ */
            "\x63\x13\x08\x64\x63\x00\x00"  /* % */
            "\x7f\xc9\x49\x63\x00\x00\x00"  /* & */
            "\x03\x00\x00\x00\x00\x00\x00"  /* ' */
            "\x3e\x41\x00\x00\x00\x00\x00"  /* ( */
            "\x41\x3e\x00\x00\x00\x00\x00"  /* ) */
            "\x0a\x04\x1f\x04\x0a\x00\x00"  /* * */
            "\x08\x08\x3e\x08\x08\x00\x00"  /* + */
            "\xc0\x00\x00\x00\x00\x00\x00"  /* , */
            "\x08\x08\x08\x08\x00\x00\x00"  /* - */
            "\x40\x00\x00\x00\x00\x00\x00"  /* . */
            "\x60\x10\x08\x04\x03\x00\x00"  /* / */
            "\x7f\x41\x41\x7f\x00\x00\x00"  /* 0 */
            "\x01\x7f\x00\x00\x00\x00\x00"  /* 1 */
            "\x7b\x49\x49\x6f\x00\x00\x00"  /* 2 */
            "\x63\x49\x49\x7f\x00\x00\x00"  /* 3 */
            "\x0f\x08\x08\x7f\x00\x00\x00"  /* 4 */
            "\x6f\x49\x49\x7b\x00\x00\x00"  /* 5 */
            "\x7f\x49\x49\x7b\x00\x00\x00"  /* 6 */
            "\x03\x01\x01\x7f\x00\x00\x00"  /* 7 */
            "\x7f\x49\x49\x7f\x00\x00\x00"  /* 8 */
            "\x0f\x09\x09\x7f\x00\x00\x00"  /* 9 */
            "\x41\x00\x00\x00\x00\x00\x00"  /* : */
            "\xc1\x00\x00\x00\x00\x00\x00"  /* ; */
            "\x08\x14\x22\x00\x00\x00\x00"  /* < */
            "\x14\x14\x14\x14\x00\x00\x00"  /* = */
            "\x22\x14\x08\x00\x00\x00\x00"  /* > */
            "\x03\x59\x09\x0f\x00\x00\x00"  /* ? */
            "\x7f\x41\x5d\x55\x5f\x00\x00"  /* @ */
            "\x7f\x09\x09\x7f\x00\x00\x00"  /* A */
            "\x7f\x49\x49\x77\x00\x00\x00"  /* B */
            "\x7f\x41\x41\x63\x00\x00\x00"  /* C */
            "\x7f\x41\x41\x3e\x00\x00\x00"  /* D */
            "\x7f\x49\x49\x63\x00\x00\x00"  /* E */
            "\x7f\x09\x09\x03\x00\x00\x00"  /* F */
            "\x7f\x41\x49\x7b\x00\x00\x00"  /* G */
            "\x7f\x08\x08\x7f\x00\x00\x00"  /* H */
            "\x41\x7f\x41\x00\x00\x00\x00"  /* I */
            "\x60\x40\x40\x7f\x00\x00\x00"  /* J */
            "\x7f\x08\x08\x77\x00\x00\x00"  /* K */
            "\x7f\x40\x40\x60\x00\x00\x00"  /* L */
            "\x7f\x01\x01\x7f\x01\x01\x7f"  /* M */
            "\x7f\x01\x01\x7f\x00\x00\x00"  /* N */
            "\x00\x7f\x41\x41\x7f\x00\x00"  /* O */
            "\x7f\x09\x09\x0f\x00\x00\x00"  /* P */
            "\x7f\x41\xc1\x7f\x00\x00\x00"  /* Q */
            "\x7f\x09\x09\x77\x00\x00\x00"  /* R */
            "\x6f\x49\x49\x7b\x00\x00\x00"  /* S */
            "\x01\x01\x7f\x01\x01\x00\x00"  /* T */
            "\x7f\x40\x40\x7f\x00\x00\x00"  /* U */
            "\x7f\x20\x10\x0f\x00\x00\x00"  /* V */
            "\x7f\x40\x40\x7f\x40\x40\x7f"  /* W */
            "\x77\x08\x08\x77\x00\x00\x00"  /* X */
            "\x6f\x48\x48\x7f\x00\x00\x00"  /* Y */
            "\x71\x49\x49\x47\x00\x00\x00"  /* Z */
            "\x7f\x41\x00\x00\x00\x00\x00"  /* [ */
            "\x03\x04\x08\x10\x60\x00\x00"  /* \ */
            "\x41\x7f\x00\x00\x00\x00\x00"  /* ] */
            "\x04\x02\x01\x02\x04\x00\x00"  /* ^ */
            "\x80\x80\x80\x80\x00\x00\x00"  /* _ */
            "\x03\x00\x00\x00\x00\x00\x00"  /* ` */
            "\x74\x54\x54\x7c\x00\x00\x00"  /* a */
            "\x7f\x44\x44\x7c\x00\x00\x00"  /* b */
            "\x7c\x44\x44\x6c\x00\x00\x00"  /* c */
            "\x7c\x44\x44\x7f\x00\x00\x00"  /* d */
            "\x7c\x54\x54\x5c\x00\x00\x00"  /* e */
            "\x7f\x05\x05\x01\x00\x00\x00"  /* f */
            "\xbc\xa4\xa4\xfc\x00\x00\x00"  /* g */
            "\x7f\x04\x04\x7c\x00\x00\x00"  /* h */
            "\x7d\x00\x00\x00\x00\x00\x00"  /* i */
            "\x80\xfd\x00\x00\x00\x00\x00"  /* j */
            "\x7f\x04\x04\x7a\x00\x00\x00"  /* k */
            "\x00\x01\x7f\x40\x00\x00\x00"  /* l */
            "\x7c\x04\x04\x7c\x04\x04\x7c"  /* m */
            "\x7c\x04\x04\x7c\x00\x00\x00"  /* n */
            "\x00\x7c\x44\x44\x7c\x00\x00"  /* o */
            "\xfc\x44\x44\x7c\x00\x00\x00"  /* p */
            "\x7c\x44\x44\xfc\x00\x00\x00"  /* q */
            "\x7c\x04\x04\x0c\x00\x00\x00"  /* r */
            "\x5c\x54\x54\x74\x00\x00\x00"  /* s */
            "\x7f\x44\x44\x60\x00\x00\x00"  /* t */
            "\x7c\x40\x40\x7c\x00\x00\x00"  /* u */
            "\x7c\x20\x10\x0c\x00\x00\x00"  /* v */
            "\x7c\x40\x40\x7c\x40\x40\x7c"  /* w */
            "\x6c\x10\x10\x6c\x00\x00\x00"  /* x */
            "\xbc\xa0\xa0\xfc\x00\x00\x00"  /* y */
            "\x64\x54\x54\x4c\x00\x00\x00"  /* z */
            "\x08\x3e\x41\x00\x00\x00\x00"  /* { */
            "\xff\x00\x00\x00\x00\x00\x00"  /* | */
            "\x41\x3e\x08\x00\x00\x00\x00"  /* } */
            "\x1c\x04\x1c\x10\x1c\x00\x00"  /* ~ */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00"  /* NULL */
            "\x00\x00\x00\x00\x00\x00\x00", /* NULL */
};

#endif /* _FONTS_MAIN_FONT_H */

