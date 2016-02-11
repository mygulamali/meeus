#pragma once

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <math.h>
#include <cmocka.h>

#ifdef DOXYGEN
/**
 * @brief Assert that the two given doubles are equal to within tolerance.
 *
 * The function prints an error message to standard error and terminates the
 * test by calling fail() if the doubles are not equal to within tolerance.
 *
 * @param[in]  a    The first double to compare.
 *
 * @param[in]  b    The double to compare against the first one.
 *
 * @param[in]  eps  The double tolerance value.
 */
void assert_double_equal(double a, double b, double eps);
#else
#define assert_double_equal(a, b, eps) \
    _assert_double_equal(a, b, eps, __FILE__, __LINE__)
#endif

#ifdef DOXYGEN
/**
 * @brief Assert that the two given doubles are not equal to within tolerance.
 *
 * The function prints an error message to standard error and terminates the
 * test by calling fail() if the doubles are equal to within tolerance.
 *
 * @param[in]  a    The first double to compare.
 *
 * @param[in]  b    The double to compare against the first one.
 *
 * @param[in]  eps  The double tolerance value.
 *
 * @see assert_double_equal()
 */
void assert_double_not_equal(double a, double b, double eps);
#else
#define assert_double_not_equal(a, b, eps) \
    _assert_double_not_equal(a, b, eps, __FILE__, __LINE__)
#endif

void _assert_double_equal(const double a, const double b, const double eps,
                          const char* const file, const int line);

void _assert_double_not_equal(const double a, const double b, const double eps,
                              const char* const file, const int line);
