#ifndef SRC_ARITHMETIC_S21_ARITHMETIC_H_
#define SRC_ARITHMETIC_S21_ARITHMETIC_H_

#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int simple_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int simple_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int simple_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

s21_decimal int_div(s21_decimal value_1, s21_decimal value_2);
int is_normal_values(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  // SRC_ARITHMETIC_S21_ARITHMETIC_H_
