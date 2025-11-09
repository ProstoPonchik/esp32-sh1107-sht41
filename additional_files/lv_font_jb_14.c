/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --stride 1 --align 1 --font JetBrainsMono-Medium.ttf --symbols °℃µΩ --range 32-127,1024-1279 --format lvgl -o lv_font_jb_14.c
 * Path for inserting: managed_components/lvgl__lvgl/src/font/lv_font_jb_14.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#include "../../lvgl.h"


#ifndef LV_FONT_JB_14
#define LV_FONT_JB_14 1
#endif

#if LV_FONT_JB_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x55, 0x54, 0xf0,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x22, 0x4b, 0xfa, 0x24, 0x48, 0xbf, 0xa4, 0xc9,
    0x10,

    /* U+0024 "$" */
    0x10, 0x43, 0x9f, 0x96, 0x4d, 0x1e, 0x1c, 0x59,
    0x75, 0x78, 0x41, 0x0,

    /* U+0025 "%" */
    0xf1, 0x92, 0x94, 0xf4, 0x8, 0x16, 0x29, 0x29,
    0x49, 0x86,

    /* U+0026 "&" */
    0x38, 0x44, 0x40, 0x60, 0x70, 0x9b, 0x8e, 0x84,
    0x8a, 0x73,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x19, 0x91, 0x88, 0x42, 0x10, 0x84, 0x30, 0xc3,
    0x84,

    /* U+0029 ")" */
    0x8e, 0x21, 0x11, 0x11, 0x11, 0x32, 0xc8,

    /* U+002A "*" */
    0x10, 0x23, 0x5b, 0xe3, 0x85, 0x13, 0x0,

    /* U+002B "+" */
    0x10, 0x23, 0xf8, 0x81, 0x2, 0x0,

    /* U+002C "," */
    0x7e,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x4, 0x10, 0xc2, 0x18, 0x61, 0xc, 0x20, 0x86,
    0x10, 0x43, 0x0,

    /* U+0030 "0" */
    0x7b, 0x38, 0x61, 0x96, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0031 "1" */
    0x33, 0xc9, 0x4, 0x10, 0x41, 0x4, 0x13, 0xf0,

    /* U+0032 "2" */
    0x7b, 0x38, 0x41, 0xc, 0x63, 0x18, 0xc3, 0xf0,

    /* U+0033 "3" */
    0xfc, 0x31, 0x8c, 0x38, 0x10, 0x61, 0xcd, 0xe0,

    /* U+0034 "4" */
    0x8, 0x43, 0x8, 0x47, 0x18, 0x7f, 0x4, 0x10,

    /* U+0035 "5" */
    0xfe, 0x8, 0x3e, 0xc, 0x10, 0x61, 0xcd, 0xe0,

    /* U+0036 "6" */
    0x10, 0x82, 0x1e, 0x4e, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0037 "7" */
    0xff, 0xa, 0x30, 0x41, 0x83, 0x4, 0x18, 0x20,
    0xc0,

    /* U+0038 "8" */
    0x7a, 0x38, 0x63, 0x7b, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x38, 0x61, 0xcd, 0xe1, 0x84, 0x30, 0x80,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0xf0, 0x3, 0xe8,

    /* U+003C "<" */
    0x0, 0x33, 0xb8, 0xc1, 0xc1, 0xc1,

    /* U+003D "=" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003E ">" */
    0x3, 0x7, 0x7, 0x4, 0x66, 0x20,

    /* U+003F "?" */
    0xf0, 0x42, 0x13, 0x10, 0x0, 0x63, 0x0,

    /* U+0040 "@" */
    0x3c, 0x8a, 0xc, 0x79, 0x32, 0x64, 0xc9, 0x93,
    0x1a, 0x2, 0x3, 0x80,

    /* U+0041 "A" */
    0x30, 0x70, 0xa3, 0x44, 0x89, 0x9f, 0x62, 0x85,
    0xc,

    /* U+0042 "B" */
    0xfa, 0x18, 0x61, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0043 "C" */
    0x7a, 0x38, 0x60, 0x82, 0x8, 0x21, 0xc5, 0xe0,

    /* U+0044 "D" */
    0xfa, 0x38, 0x61, 0x86, 0x18, 0x61, 0x8f, 0xe0,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x82, 0x0,

    /* U+0047 "G" */
    0x7a, 0x18, 0x20, 0x9e, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+0049 "I" */
    0xfc, 0x82, 0x8, 0x20, 0x82, 0x8, 0x23, 0xf0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x61, 0xcd, 0xe0,

    /* U+004B "K" */
    0x8e, 0x29, 0xa4, 0xf2, 0x49, 0xa2, 0x8e, 0x30,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0xcf, 0x3d, 0x6d, 0xb6, 0xd8, 0x61, 0x86, 0x10,

    /* U+004E "N" */
    0xc7, 0x1e, 0x69, 0xa6, 0x59, 0x67, 0x8e, 0x30,

    /* U+004F "O" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x8d, 0xe0,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x7b, 0x38, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,
    0x83, 0x4,

    /* U+0052 "R" */
    0xfa, 0x38, 0x61, 0x8f, 0xe9, 0xa2, 0x8e, 0x10,

    /* U+0053 "S" */
    0x7a, 0x38, 0x60, 0x70, 0x70, 0x61, 0xcd, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+0056 "V" */
    0x87, 0xb, 0x12, 0x64, 0xc9, 0x1a, 0x1c, 0x38,
    0x60,

    /* U+0057 "W" */
    0x99, 0x99, 0x9b, 0xdb, 0xda, 0x6a, 0x66, 0x66,
    0x66, 0x66,

    /* U+0058 "X" */
    0xc4, 0x99, 0xa1, 0xc3, 0x6, 0xe, 0x24, 0xcd,
    0xc,

    /* U+0059 "Y" */
    0xc6, 0x89, 0x11, 0x42, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0xfc, 0x30, 0x86, 0x10, 0x86, 0x10, 0xc3, 0xf0,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x4e,

    /* U+005C "\\" */
    0x83, 0x4, 0x18, 0x60, 0x83, 0x4, 0x10, 0x60,
    0x82, 0xc, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x9e,

    /* U+005E "^" */
    0x10, 0xc2, 0x92, 0x4f, 0x10,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x4c,

    /* U+0061 "a" */
    0x7b, 0x10, 0x5f, 0x86, 0x18, 0xdd,

    /* U+0062 "b" */
    0x82, 0xb, 0xb1, 0x86, 0x18, 0x61, 0xc6, 0xe0,

    /* U+0063 "c" */
    0x7b, 0x18, 0x60, 0x82, 0x1c, 0x5e,

    /* U+0064 "d" */
    0x4, 0x17, 0x63, 0x86, 0x18, 0x61, 0x8d, 0xd0,

    /* U+0065 "e" */
    0x7a, 0x18, 0x7f, 0x82, 0xc, 0xde,

    /* U+0066 "f" */
    0x1e, 0x40, 0x87, 0xf2, 0x4, 0x8, 0x10, 0x20,
    0x40,

    /* U+0067 "g" */
    0x77, 0x38, 0x61, 0x86, 0x1c, 0xdd, 0x4, 0x17,
    0x80,

    /* U+0068 "h" */
    0x82, 0xb, 0xb3, 0x86, 0x18, 0x61, 0x86, 0x10,

    /* U+0069 "i" */
    0x0, 0x60, 0x7, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x23, 0xf8,

    /* U+006A "j" */
    0x0, 0xc1, 0xf0, 0x84, 0x21, 0x8, 0x42, 0x11,
    0xf8,

    /* U+006B "k" */
    0x82, 0x8, 0xe6, 0x93, 0xc9, 0x26, 0x8a, 0x30,

    /* U+006C "l" */
    0xf0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0xf,

    /* U+006D "m" */
    0xfd, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xc9,

    /* U+006E "n" */
    0xbb, 0x38, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x7b, 0x38, 0x61, 0x86, 0x1c, 0xde,

    /* U+0070 "p" */
    0xbb, 0x18, 0x61, 0x86, 0x1c, 0x6e, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x76, 0x38, 0x61, 0x86, 0x18, 0xdd, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xbb, 0x18, 0x60, 0x82, 0x8, 0x20,

    /* U+0073 "s" */
    0x7a, 0x18, 0x3e, 0x3c, 0x18, 0x5e,

    /* U+0074 "t" */
    0x20, 0x43, 0xf9, 0x2, 0x4, 0x8, 0x10, 0x20,
    0x3c,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0xde,

    /* U+0076 "v" */
    0x87, 0x89, 0x32, 0x66, 0x8d, 0xe, 0x18,

    /* U+0077 "w" */
    0xd9, 0x59, 0x59, 0x5a, 0x56, 0x56, 0x66, 0x26,

    /* U+0078 "x" */
    0xc4, 0x99, 0xe1, 0x83, 0xd, 0x13, 0x62,

    /* U+0079 "y" */
    0x87, 0x89, 0x32, 0x66, 0x87, 0xc, 0x18, 0x30,
    0x40, 0x80,

    /* U+007A "z" */
    0xfc, 0x31, 0x84, 0x21, 0x8c, 0x3f,

    /* U+007B "{" */
    0xc, 0x41, 0x4, 0x10, 0x4e, 0x4, 0x10, 0x41,
    0x4, 0xc,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xe0, 0x82, 0x8, 0x20, 0x81, 0xc8, 0x20, 0x82,
    0x8, 0xc0,

    /* U+007E "~" */
    0x66, 0xd9, 0x80,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B5 "µ" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0xff, 0x82, 0x8,
    0x0,

    /* U+03A9 "Ω" */
    0x38, 0x89, 0x12, 0x24, 0x48, 0x91, 0x22, 0x2d,
    0xdc,

    /* U+0401 "Ё" */
    0xcf, 0x30, 0x0, 0xfe, 0x8, 0x20, 0xfe, 0x8,
    0x20, 0x83, 0xf0,

    /* U+0402 "Ђ" */
    0xf8, 0x40, 0x81, 0x63, 0x24, 0x48, 0x91, 0x22,
    0x44, 0x8, 0x10, 0xc0,

    /* U+0403 "Ѓ" */
    0x10, 0xc6, 0x0, 0xfe, 0x8, 0x20, 0x82, 0x8,
    0x20, 0x82, 0x0,

    /* U+0404 "Є" */
    0x7a, 0x18, 0x60, 0xfa, 0x8, 0x21, 0xcd, 0xe0,

    /* U+0405 "Ѕ" */
    0x7a, 0x38, 0x60, 0x70, 0x70, 0x61, 0xcd, 0xe0,

    /* U+0406 "І" */
    0xfc, 0x82, 0x8, 0x20, 0x82, 0x8, 0x23, 0xf0,

    /* U+0407 "Ї" */
    0xdb, 0x60, 0x0, 0xfc, 0x82, 0x8, 0x20, 0x82,
    0x8, 0x23, 0xf0,

    /* U+0408 "Ј" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x61, 0xcd, 0xe0,

    /* U+0409 "Љ" */
    0x78, 0x48, 0x48, 0x48, 0x4e, 0x49, 0x49, 0x49,
    0x49, 0x8e,

    /* U+040A "Њ" */
    0x91, 0x22, 0x44, 0x8f, 0xd2, 0x64, 0xc9, 0x93,
    0x38,

    /* U+040B "Ћ" */
    0xf8, 0x40, 0x81, 0x63, 0x24, 0x48, 0x91, 0x22,
    0x44,

    /* U+040C "Ќ" */
    0x18, 0xc2, 0x0, 0x8e, 0x29, 0xa4, 0xf2, 0x49,
    0xa2, 0x8e, 0x30,

    /* U+040E "Ў" */
    0x4c, 0x90, 0xe0, 0x8, 0x78, 0x93, 0x34, 0x28,
    0x50, 0xc0, 0x83, 0x4, 0x0,

    /* U+040F "Џ" */
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8f, 0xc8, 0x40,

    /* U+0410 "А" */
    0x30, 0x70, 0xa3, 0x44, 0x89, 0x9f, 0x62, 0x85,
    0xc,

    /* U+0411 "Б" */
    0xfe, 0x8, 0x20, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0412 "В" */
    0xfa, 0x18, 0x61, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0413 "Г" */
    0xfe, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0x0,

    /* U+0414 "Д" */
    0x3e, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x62, 0xff, 0x81, 0x81,

    /* U+0415 "Е" */
    0xfe, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x83, 0xf0,

    /* U+0416 "Ж" */
    0x49, 0x24, 0x9a, 0xc5, 0x43, 0xe1, 0x50, 0xa8,
    0xd6, 0x49, 0x24, 0x80,

    /* U+0417 "З" */
    0x79, 0x8a, 0x10, 0x23, 0x80, 0x80, 0xc1, 0xc6,
    0xf8,

    /* U+0418 "И" */
    0x8e, 0x39, 0xe5, 0x96, 0x9a, 0x79, 0xc7, 0x10,

    /* U+0419 "Й" */
    0x49, 0x27, 0x80, 0x8e, 0x39, 0xe5, 0x96, 0x9a,
    0x79, 0xc7, 0x10,

    /* U+041A "К" */
    0x8e, 0x29, 0xa4, 0xf2, 0x49, 0xa2, 0x8e, 0x30,

    /* U+041B "Л" */
    0x7d, 0x14, 0x51, 0x45, 0x14, 0x51, 0x46, 0x10,

    /* U+041C "М" */
    0xcf, 0x3d, 0x6d, 0xb6, 0xd8, 0x61, 0x86, 0x10,

    /* U+041D "Н" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+041E "О" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x8d, 0xe0,

    /* U+041F "П" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x10,

    /* U+0420 "Р" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0421 "С" */
    0x7a, 0x38, 0x60, 0x82, 0x8, 0x21, 0xc5, 0xe0,

    /* U+0422 "Т" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0423 "У" */
    0x87, 0x89, 0x32, 0x46, 0x87, 0xc, 0x8, 0x30,
    0x40,

    /* U+0424 "Ф" */
    0x10, 0xfb, 0x5c, 0x99, 0x32, 0x64, 0xc9, 0xd6,
    0xf8, 0x40,

    /* U+0425 "Х" */
    0xc4, 0x99, 0xa1, 0xc3, 0x6, 0xe, 0x24, 0xcd,
    0xc,

    /* U+0426 "Ц" */
    0x89, 0x12, 0x24, 0x48, 0x91, 0x22, 0x44, 0x89,
    0xfc, 0x8, 0x10,

    /* U+0427 "Ч" */
    0x86, 0x18, 0x61, 0x85, 0xf0, 0x41, 0x4, 0x10,

    /* U+0428 "Ш" */
    0x93, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xc9, 0x93,
    0xfc,

    /* U+0429 "Щ" */
    0x93, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xc9, 0x93,
    0xfc, 0x8, 0x10,

    /* U+042A "Ъ" */
    0xe0, 0x20, 0x20, 0x20, 0x3e, 0x23, 0x21, 0x21,
    0x23, 0x3e,

    /* U+042B "Ы" */
    0x83, 0x6, 0xc, 0x1e, 0x32, 0x64, 0xc9, 0x93,
    0xc4,

    /* U+042C "Ь" */
    0x82, 0x8, 0x20, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+042D "Э" */
    0x7a, 0x18, 0x41, 0x7c, 0x10, 0x61, 0xcd, 0xe0,

    /* U+042E "Ю" */
    0x8d, 0x26, 0x4c, 0x9f, 0x32, 0x64, 0xc9, 0x93,
    0x18,

    /* U+042F "Я" */
    0x7f, 0x18, 0x61, 0xc5, 0xf6, 0x51, 0xc6, 0x10,

    /* U+0430 "а" */
    0x7b, 0x10, 0x5f, 0x86, 0x18, 0xdd,

    /* U+0431 "б" */
    0x7f, 0x88, 0x2e, 0xce, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0432 "в" */
    0xfa, 0x18, 0x7e, 0x86, 0x18, 0x7e,

    /* U+0433 "г" */
    0xfc, 0x21, 0x8, 0x42, 0x10,

    /* U+0434 "д" */
    0x3c, 0x24, 0x24, 0x24, 0x24, 0x24, 0x64, 0xff,
    0x81, 0x81,

    /* U+0435 "е" */
    0x7a, 0x18, 0x7f, 0x82, 0xc, 0xde,

    /* U+0436 "ж" */
    0x93, 0xad, 0x53, 0xe5, 0x5a, 0xe4, 0xc9,

    /* U+0437 "з" */
    0x7b, 0x10, 0x4e, 0x4, 0x1c, 0x5e,

    /* U+0438 "и" */
    0x8e, 0x39, 0xe5, 0xa7, 0x9c, 0x71,

    /* U+0439 "й" */
    0x49, 0xe0, 0x23, 0x8e, 0x79, 0x69, 0xe7, 0x1c,
    0x40,

    /* U+043A "к" */
    0x8e, 0x69, 0x3c, 0x92, 0x68, 0xa3,

    /* U+043B "л" */
    0x7d, 0x14, 0x51, 0x45, 0x14, 0x61,

    /* U+043C "м" */
    0xcf, 0x3d, 0x6d, 0xb6, 0x18, 0x61,

    /* U+043D "н" */
    0x86, 0x18, 0x7f, 0x86, 0x18, 0x61,

    /* U+043E "о" */
    0x7b, 0x38, 0x61, 0x86, 0x1c, 0xde,

    /* U+043F "п" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61,

    /* U+0440 "р" */
    0xbb, 0x18, 0x61, 0x86, 0x1c, 0x6e, 0x82, 0x8,
    0x0,

    /* U+0441 "с" */
    0x7b, 0x18, 0x60, 0x82, 0x1c, 0x5e,

    /* U+0442 "т" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8,

    /* U+0443 "у" */
    0x87, 0x89, 0x32, 0x66, 0x87, 0xc, 0x18, 0x30,
    0x40, 0x80,

    /* U+0444 "ф" */
    0x10, 0x21, 0xf6, 0xb9, 0x32, 0x64, 0xc9, 0xd6,
    0xf8, 0x40, 0x81, 0x0,

    /* U+0445 "х" */
    0xc4, 0x99, 0xe1, 0x83, 0xd, 0x13, 0x62,

    /* U+0446 "ц" */
    0x85, 0xa, 0x14, 0x28, 0x50, 0xa1, 0x7f, 0x2,
    0x4,

    /* U+0447 "ч" */
    0x86, 0x18, 0x61, 0x7c, 0x10, 0x41,

    /* U+0448 "ш" */
    0x93, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xff,

    /* U+0449 "щ" */
    0x95, 0x2a, 0x54, 0xa9, 0x52, 0xa5, 0x7f, 0x2,
    0x4,

    /* U+044A "ъ" */
    0xe0, 0x20, 0x20, 0x3e, 0x21, 0x21, 0x21, 0x3e,

    /* U+044B "ы" */
    0x83, 0x6, 0xf, 0x98, 0xb1, 0x62, 0xf9,

    /* U+044C "ь" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x7e,

    /* U+044D "э" */
    0x7a, 0x30, 0x4f, 0x6, 0x1c, 0xde,

    /* U+044E "ю" */
    0x8d, 0x26, 0x4f, 0x99, 0x32, 0x64, 0xc6,

    /* U+044F "я" */
    0x7e, 0x18, 0x61, 0x7d, 0x94, 0x61,

    /* U+0451 "ё" */
    0xcf, 0x30, 0x1e, 0x86, 0x1f, 0xe0, 0x83, 0x17,
    0x80,

    /* U+0452 "ђ" */
    0x41, 0xf1, 0x2, 0xe6, 0x68, 0x50, 0xa1, 0x42,
    0x84, 0x8, 0x31, 0xc0,

    /* U+0453 "ѓ" */
    0x11, 0x1, 0xf8, 0x42, 0x10, 0x84, 0x20,

    /* U+0454 "є" */
    0x7a, 0x18, 0x3c, 0x82, 0x1c, 0xde,

    /* U+0455 "ѕ" */
    0x7a, 0x18, 0x3e, 0x3c, 0x18, 0x5e,

    /* U+0456 "і" */
    0x30, 0x60, 0x7, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x23, 0xf8,

    /* U+0457 "ї" */
    0x6c, 0xd8, 0x7, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x23, 0xf8,

    /* U+0458 "ј" */
    0x18, 0xc1, 0xf0, 0x84, 0x21, 0x8, 0x42, 0x11,
    0xf8,

    /* U+0459 "љ" */
    0x78, 0x48, 0x48, 0x4e, 0x49, 0x49, 0x49, 0x8e,

    /* U+045A "њ" */
    0x91, 0x22, 0x47, 0xe9, 0x32, 0x64, 0xce,

    /* U+045B "ћ" */
    0x41, 0xf1, 0x2, 0xe6, 0x68, 0x50, 0xa1, 0x42,
    0x84,

    /* U+045C "ќ" */
    0x10, 0x80, 0x23, 0x9a, 0x4f, 0x24, 0x9a, 0x28,
    0xc0,

    /* U+045E "ў" */
    0x48, 0x70, 0x4, 0x3c, 0x49, 0x93, 0x34, 0x38,
    0x70, 0x41, 0x82, 0x4, 0x0,

    /* U+045F "џ" */
    0x8c, 0x63, 0x18, 0xc6, 0x3f, 0x21, 0x0,

    /* U+0490 "Ґ" */
    0x4, 0x1f, 0xe0, 0x82, 0x8, 0x20, 0x82, 0x8,
    0x20,

    /* U+0491 "ґ" */
    0x8, 0x7f, 0x8, 0x42, 0x10, 0x84, 0x0,

    /* U+0492 "Ғ" */
    0x3e, 0x40, 0x81, 0xf, 0x84, 0x8, 0x10, 0x20,
    0x40,

    /* U+0493 "ғ" */
    0x3e, 0x40, 0x81, 0xf, 0x84, 0x8, 0x10,

    /* U+049A "Қ" */
    0x85, 0x1a, 0x64, 0xcf, 0x12, 0x26, 0x44, 0x8d,
    0xc, 0x8, 0x10,

    /* U+049B "қ" */
    0x85, 0x1a, 0x67, 0x89, 0x91, 0x23, 0x43, 0x2,
    0x4,

    /* U+04A2 "Ң" */
    0x85, 0xa, 0x14, 0x2f, 0xd0, 0xa1, 0x42, 0x85,
    0xc, 0x8, 0x10,

    /* U+04A3 "ң" */
    0x86, 0x18, 0x7f, 0x86, 0x18, 0x61, 0x4, 0x10,

    /* U+04AE "Ү" */
    0xc6, 0x89, 0x11, 0x42, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+04AF "ү" */
    0xc6, 0x89, 0x13, 0x62, 0x85, 0xa, 0x8, 0x10,
    0x20, 0x40,

    /* U+04B0 "Ұ" */
    0x82, 0x89, 0x11, 0x42, 0x82, 0x1f, 0x8, 0x10,
    0x20,

    /* U+04B1 "ұ" */
    0xc6, 0x89, 0x13, 0x62, 0x85, 0xa, 0x8, 0x7c,
    0x20, 0x40,

    /* U+04B6 "Ҷ" */
    0x85, 0xa, 0x14, 0x28, 0x4f, 0x81, 0x2, 0x4,
    0xc, 0x8, 0x10,

    /* U+04B7 "ҷ" */
    0x85, 0xa, 0x14, 0x27, 0xc0, 0x81, 0x3, 0x2,
    0x4,

    /* U+04BA "Һ" */
    0x82, 0x8, 0x20, 0xfa, 0x18, 0x61, 0x86, 0x10,

    /* U+04BB "һ" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x61,

    /* U+04D8 "Ә" */
    0x7a, 0x18, 0x41, 0xfe, 0x18, 0x61, 0xcd, 0xe0,

    /* U+04D9 "ә" */
    0x7a, 0x30, 0x41, 0xfe, 0x18, 0x5e,

    /* U+04DC "Ӝ" */
    0x36, 0x1b, 0x0, 0x0, 0x4, 0x92, 0x49, 0xac,
    0x54, 0x3e, 0x15, 0xa, 0x8d, 0x64, 0x92, 0x48,

    /* U+04DD "ӝ" */
    0x36, 0x1b, 0x0, 0x9, 0x26, 0xb1, 0x50, 0xf8,
    0x54, 0x6b, 0x24, 0x92, 0x40,

    /* U+04DE "Ӟ" */
    0x6c, 0xd8, 0x0, 0x7, 0x98, 0xa1, 0x2, 0x38,
    0x8, 0xc, 0x1c, 0x6f, 0x80,

    /* U+04DF "ӟ" */
    0x6d, 0xb0, 0x1e, 0xc4, 0x13, 0x81, 0x7, 0x17,
    0x80,

    /* U+04E4 "Ӥ" */
    0xcf, 0x30, 0x0, 0x8e, 0x39, 0xe5, 0x96, 0x9a,
    0x79, 0xc7, 0x10,

    /* U+04E5 "ӥ" */
    0xcf, 0x30, 0x23, 0x8e, 0x79, 0x69, 0xe7, 0x1c,
    0x40,

    /* U+04E6 "Ӧ" */
    0xcf, 0x30, 0x0, 0x7a, 0x18, 0x61, 0x86, 0x18,
    0x61, 0x8d, 0xe0,

    /* U+04E7 "ӧ" */
    0xcf, 0x30, 0x1e, 0xce, 0x18, 0x61, 0x87, 0x37,
    0x80,

    /* U+04E8 "Ө" */
    0x7a, 0x18, 0x61, 0xfe, 0x18, 0x61, 0xcd, 0xe0,

    /* U+04E9 "ө" */
    0x7a, 0x18, 0x7f, 0x86, 0x1c, 0xde,

    /* U+04F4 "Ӵ" */
    0x6d, 0xb0, 0x0, 0x86, 0x18, 0x61, 0x85, 0xf0,
    0x41, 0x4, 0x10,

    /* U+04F5 "ӵ" */
    0x6d, 0xb0, 0x21, 0x86, 0x18, 0x5f, 0x4, 0x10,
    0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 134, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 134, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 134, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 6, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 134, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 27, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 134, .box_w = 1, .box_h = 4, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 48, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 57, .adv_w = 134, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 64, .adv_w = 134, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 71, .adv_w = 134, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 77, .adv_w = 134, .box_w = 2, .box_h = 4, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 78, .adv_w = 134, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 79, .adv_w = 134, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 91, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 134, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 134, .box_w = 2, .box_h = 11, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 177, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 183, .adv_w = 134, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 187, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 193, .adv_w = 134, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 212, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 351, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 134, .box_w = 3, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 434, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 445, .adv_w = 134, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 450, .adv_w = 134, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 455, .adv_w = 134, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 456, .adv_w = 134, .box_w = 3, .box_h = 2, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 457, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 509, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 536, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 573, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 582, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 591, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 597, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 650, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 656, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 666, .adv_w = 134, .box_w = 1, .box_h = 14, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 668, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 678, .adv_w = 134, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 681, .adv_w = 134, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 683, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 692, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 701, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 712, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 724, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 759, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 778, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 788, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 817, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 830, .adv_w = 134, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 838, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 847, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 855, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 883, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 891, .adv_w = 134, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 912, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 931, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 939, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 955, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 963, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 971, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 979, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 987, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 995, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1004, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1013, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1023, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1032, .adv_w = 134, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1043, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1060, .adv_w = 134, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1071, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1081, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1090, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1098, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1115, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1123, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1129, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1137, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1143, .adv_w = 134, .box_w = 5, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1148, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1158, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1164, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1171, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1177, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1183, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1192, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1198, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1210, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1216, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1222, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1228, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1237, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1243, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1250, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1260, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1272, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1279, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1288, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1294, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1301, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1310, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1318, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1325, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1331, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1337, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1344, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1350, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1359, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1371, .adv_w = 134, .box_w = 5, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1378, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1384, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1390, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1400, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1410, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1419, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1427, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1434, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1443, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1452, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1465, .adv_w = 134, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1472, .adv_w = 134, .box_w = 6, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1481, .adv_w = 134, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1488, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1497, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1504, .adv_w = 134, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1515, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1524, .adv_w = 134, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1535, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1543, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1552, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1562, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1571, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1581, .adv_w = 134, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1592, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1601, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1609, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1615, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1623, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1629, .adv_w = 134, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1645, .adv_w = 134, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1658, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1671, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1680, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1691, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1700, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1711, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1720, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1728, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1734, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1745, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x5, 0x2f9
};

static const uint16_t unicode_list_5[] = {
    0x0, 0x1, 0x32, 0x33, 0x34, 0x35, 0x3c, 0x3d,
    0x44, 0x45, 0x50, 0x51, 0x52, 0x53, 0x58, 0x59,
    0x5c, 0x5d, 0x7a, 0x7b, 0x7e, 0x7f, 0x80, 0x81,
    0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x96, 0x97
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 762, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 1025, .range_length = 12, .glyph_id_start = 99,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 1038, .range_length = 66, .glyph_id_start = 111,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 1105, .range_length = 12, .glyph_id_start = 177,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 1118, .range_length = 152, .glyph_id_start = 189,
        .unicode_list = unicode_list_5, .glyph_id_ofs_list = NULL, .list_length = 32, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 6,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

extern const lv_font_t lv_font_jb_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t lv_font_jb_14 = {
#else
lv_font_t lv_font_jb_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_jb_14,
#endif
    .user_data = NULL,
};



#endif /*#if LV_FONT_JB_14*/
