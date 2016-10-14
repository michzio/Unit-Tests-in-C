//
// Created by Michal Ziobro on 28/07/2016.
//

#ifndef UNIT_TESTS_ASSERTION_H
#define UNIT_TESTS_ASSERTION_H

#include "../../comparers/comparer.h"

void assert_not_null(const void *arg, const char *test_name);
void assert_null(const void *arg, const char *test_name);
void assert_equal(const void *l_arg, const void *r_arg, compare_func_t cmp_func, const char *test_name);
void assert_equal_int(const int l_arg, const int r_arg, const char *test_name);
void assert_equal_float(const float l_arg, const float r_arg, const char *test_name);
void assert_not_equal(const void *l_arg, const void *r_arg, compare_func_t cmp_func, const char *test_name);
void assert_not_equal_int(const int l_arg, const int r_arg, const char *test_name);
void assert_not_equal_float(const float l_arg, const float r_arg, const char *test_name);
void assert_greater_than(const int l_arg, const int r_arg, const char *test_name);
void assert_less_than(const int l_arg, const int r_arg, const char *test_name);
void assert_in_range(const int arg, const int min, const int max, const char *test_name);

#endif //UNIT_TESTS_ASSERTION_H
