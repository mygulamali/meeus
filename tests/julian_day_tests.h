#pragma once

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "julian_day.h"

void get_calendar_type_test(void **state);
void julian_day_test(void **state);
void julian_day_zero_test(void **state);
void get_year_type_test(void **state);
void modified_julian_day_test(void **state);
