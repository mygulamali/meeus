#include "test_helpers.h"

/* GCC have printf type attribute check.  */
#ifdef __GNUC__
#define CMOCKA_PRINTF_ATTRIBUTE(a,b) __attribute__ \
    ((__format__ (__printf__, a, b)))
#else
#define CMOCKA_PRINTF_ATTRIBUTE(a,b)
#endif /* __GNUC__ */

void cm_print_error(const char * const format, ...)
    CMOCKA_PRINTF_ATTRIBUTE(1, 2);

/* Returns 1 if the specified values are equal within tolerance. If the values
 * are not equal, an error is displayed and 0 is returned. */
static int double_values_equal_display_error(const double left,
                                             const double right,
                                             const double tolerance) {
    const int equal = fabs(left - right) < tolerance;
    if (!equal) {
        cm_print_error("%f != %f ± %f\n", left, right, tolerance);
    }
    return equal;
}

/*
 * Returns 1 if the specified values are not equal within tolerance. If the
 * values are equal an error is displayed and 0 is returned. */
static int double_values_not_equal_display_error(const double left,
                                                 const double right,
                                                 const double tolerance) {
    const int not_equal = fabs(left - right) >= tolerance;
    if (!not_equal) {
        cm_print_error("%f == %f ± %f\n", left, right, tolerance);
    }
    return not_equal;
}

void _assert_double_equal(const double a, const double b, const double eps,
                          const char* const file, const int line) {
    if (!double_values_equal_display_error(a, b, eps)) {
        _fail(file, line);
    }
}

void _assert_double_not_equal(const double a, const double b, const double eps,
                              const char* const file, const int line) {
    if (!double_values_not_equal_display_error(a, b, eps)) {
        _fail(file, line);
    }
}
