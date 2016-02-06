#pragma once

#include <math.h>
#include <stdint.h>

typedef enum calendar_types {JULIAN_CALENDAR, GREGORIAN_CALENDAR} calendar_t;
typedef enum year_types {COMMON_YEAR, BISSEXTILE_YEAR} year_t;
typedef struct date_type {
  intmax_t year,
           mon;
  double   mday;
} date_t;

calendar_t get_calendar_type(date_t date);
double julian_day(date_t date);
double julian_day_zero(intmax_t year);
year_t get_julian_year_type(intmax_t year);
year_t get_gregorian_year_type(intmax_t year);
year_t get_year_type(intmax_t year);
double modified_julian_day(date_t date);
