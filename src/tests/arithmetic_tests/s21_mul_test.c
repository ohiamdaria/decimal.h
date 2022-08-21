#include "../decimal_test.h"
#include <limits.h>

START_TEST(mul_t1) {
    float a = 0.0;
    for (; a < 456.789123; a += 0.12378) {
        float b = 0.45 * a;

        s21_decimal adec;
        s21_from_float_to_decimal(a, &adec);

        s21_decimal bdec;
        s21_from_float_to_decimal(b, &bdec);

        s21_decimal result;
        init_decimal(&result);
        s21_mul(adec, bdec, &result);

        float res = 0.0;
        s21_from_decimal_to_float(result, &res);

        s21_decimal resdec_expected;
        s21_from_float_to_decimal((float) a * b, &resdec_expected);
        // printf("a: %.30f\nb: %.30f\n", a, b);
        // printf("a + b: %.30f\nresult: %.30f\n", (float) a * b, res);
        ck_assert_double_eq_tol(a * b, res, 1e-6);
        // ck_assert_int_eq(s21_is_equal(result, resdec_expected), 1);
    }
}
END_TEST

// START_TEST(mul_t2) {
//     int a = 0;
//     for (; a < 234567; a += 456) {
//         int b = 3 * a;

//         s21_decimal adec;
//         s21_from_int_to_decimal(a, &adec);

//         s21_decimal bdec;
//         s21_from_int_to_decimal(b, &bdec);

//         s21_decimal result;
//         init_decimal(&result);
//         s21_mul(adec, bdec, &result);

//         int res = 0.0;
//         s21_from_decimal_to_int(result, &res);

//         s21_decimal resdec_expected;
//         s21_from_int_to_decimal((float)a * b, &resdec_expected);
   
//         ck_assert_int_eq((float)a * b, res);
//     }
// }
// END_TEST

// START_TEST(mul_t3) {
//     int a = -234567;
//     for (; a < 123; a += 456) {
//         int b = 3 * a;

//         s21_decimal adec;
//         s21_from_int_to_decimal(a, &adec);

//         s21_decimal bdec;
//         s21_from_int_to_decimal(b, &bdec);

//         s21_decimal result;
//         init_decimal(&result);
//         s21_mul(adec, bdec, &result);

//         int res = 0.0;
//         s21_from_decimal_to_int(result, &res);

//         s21_decimal resdec_expected;
//         s21_from_int_to_decimal((float)a * b, &resdec_expected);

//         ck_assert_int_eq((float)a * b, res);
//     }
// }
// END_TEST

START_TEST(mul_t4) {
    s21_decimal adec;
    s21_decimal bdec;

    adec.type = 3;
    bdec.type = rand() % 4;

    if (adec.type == 0) adec = random_decimal(3, 28);
    if (bdec.type == 0) bdec = random_decimal(3, 28);

    s21_decimal result;
    s21_mul(adec, bdec, &result);

    ck_assert_int_eq(result.type, 3);
}
END_TEST

START_TEST(mul_t5) {
    s21_decimal adec;
    s21_decimal bdec;
    float a = 2.5;
    float b = -2.5;
    s21_decimal result;
    s21_from_float_to_decimal(a, &adec);
    s21_from_float_to_decimal(b, &bdec);
    s21_mul(adec, bdec, &result);
    float res;
    s21_from_decimal_to_float(result, &res);
    ck_assert_float_eq_tol(a * b, res, 1e-6);
    
} END_TEST

START_TEST(mul_t6) {
    s21_decimal adec;
    s21_decimal bdec;
    float a = -2.5;
    float b = 2.5;
    s21_decimal result;
    s21_from_float_to_decimal(a, &adec);
    s21_from_float_to_decimal(b, &bdec);
    s21_mul(adec, bdec, &result);
    float res;
    s21_from_decimal_to_float(result, &res);
    ck_assert_float_eq_tol(a * b, res, 1e-6);
    
} END_TEST

Suite *s21_mul_test() {
    Suite *s = suite_create("[s21_mul] Unit Test");
    TCase *tc1_s21_mul = tcase_create("mul_t1");
    // TCase *tc2_s21_mul = tcase_create("mul_t2");
    // TCase *tc3_s21_mul = tcase_create("mul_t3");
    TCase *tc4_s21_mul = tcase_create("mul_t4");
    TCase *tc5_s21_mul = tcase_create("mul_t5");
    TCase *tc6_s21_mul = tcase_create("mul_t6");

    tcase_add_test(tc1_s21_mul, mul_t1);
    // tcase_add_test(tc2_s21_mul, mul_t2);
    // tcase_add_test(tc3_s21_mul, mul_t3);
    tcase_add_loop_test(tc4_s21_mul, mul_t4, 0, 10);
    tcase_add_test(tc5_s21_mul, mul_t5);
    tcase_add_test(tc6_s21_mul, mul_t6);

    suite_add_tcase(s, tc1_s21_mul);
    // suite_add_tcase(s, tc2_s21_mul);
    // suite_add_tcase(s, tc3_s21_mul);
    suite_add_tcase(s, tc4_s21_mul);
    suite_add_tcase(s, tc5_s21_mul);
    suite_add_tcase(s, tc6_s21_mul);
    return s;
}
