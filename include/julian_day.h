#pragma once

#include <stdint.h>
#include <math.h>

typedef enum calendar_types {JULIAN_CALENDAR, GREGORIAN_CALENDAR} calendar_t;
typedef enum year_types {COMMON_YEAR, BISSEXTILE_YEAR} year_t;

calendar_t get_calendar_type(intmax_t year, intmax_t month, double day);
double julian_day(intmax_t year, intmax_t month, double day);
year_t get_julian_year_type(intmax_t year);
year_t get_gregorian_year_type(intmax_t year);
year_t get_year_type(intmax_t year);
double modified_julian_day(intmax_t year, intmax_t month, double day);
