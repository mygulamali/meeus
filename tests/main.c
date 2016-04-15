#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "julian_day_tests.h"

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(get_calendar_type_test),
        cmocka_unit_test(julian_day_test),
        cmocka_unit_test(julian_day_zero_test),
        cmocka_unit_test(get_year_type_test),
        cmocka_unit_test(modified_julian_day_test),
        cmocka_unit_test(calendar_date_test),
        cmocka_unit_test(calendar_diff_test)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
