#pragma once

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "test_helpers.h"
#define JULIAN_DAY_TOLERANCE 1.157e-06 // 1/864000 = 0.1 sec per day

#include "julian_day.h"

void get_calendar_type_test(void **state);
void julian_day_test(void **state);
void julian_day_zero_test(void **state);
void get_year_type_test(void **state);
void modified_julian_day_test(void **state);
void calendar_date_test(void **state);
void calendar_diff_test(void **state);
