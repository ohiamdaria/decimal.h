#include "s21_helpers.h"
// #include "../converters/s21_converters.h"

int shiftleft(s21_decimal *a) {
    int over = SUCCESS;
    int last_low_bit = isBit(a->bits[LOW], INT_BITS - 1);
    int last_mid_bit = isBit(a->bits[MID], INT_BITS - 1);
    int last_high_bit = isBit(a->bits[HIGH], INT_BITS - 1);
    a->bits[LOW] <<= 1;
    a->bits[MID] <<= 1;
    if (last_low_bit)
        a->bits[MID] = setBit(a->bits[MID], 0);
    a->bits[HIGH] <<= 1;
    if (last_mid_bit)
        a->bits[HIGH] = setBit(a->bits[HIGH], 0);
    if (last_high_bit) over = FAIL;
    return over;
}

int shiftright(s21_decimal *a) {
    int below = SUCCESS;
    int first_low_bit = isBit(a->bits[LOW], 0);
    int first_mid_bit = isBit(a->bits[MID], 0);
    int first_high_bit = isBit(a->bits[HIGH], 0);
    a->bits[HIGH] >>= 1;
    a->bits[MID] >>= 1;
    if (first_high_bit)
        a->bits[MID] = setBit(a->bits[MID], INT_BITS - 1);
    a->bits[LOW] >>= 1;
    if (first_mid_bit)
        a->bits[LOW] = setBit(a->bits[LOW], INT_BITS - 1);
    if (first_low_bit) below = FAIL;
    return below;
}

// int main () {
//     int a = 395868579, b = 0;
//     s21_decimal dst;
//     s21_from_int_to_decimal(a, &dst);
//     print_decimal(dst);
//     for(int i = 0; i < 64; i++) {
//         shiftleft(&dst);
//         print_decimal(dst);
//     }
//     for(int i = 0; i < 66; i++) {
//         shiftright(&dst);
//         print_decimal(dst);
//     }
//     s21_from_decimal_to_int(dst, &b);
//     printf("%d\n", b);
//     return 0;
// }