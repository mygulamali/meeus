#pragma once

#include <math.h>
#include <stdint.h>

typedef enum calendar_types {
    JULIAN_CALENDAR,
    GREGORIAN_CALENDAR
} calendar_t;

typedef enum year_types {
    COMMON_YEAR,
    BISSEXTILE_YEAR
} year_t;

typedef enum day_types {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} day_t;

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
date_t calendar_date(double julian_day);
double calendar_diff(date_t date_1, date_t date_2);
date_t date_before(date_t date, double days);
date_t date_after(date_t date, double days);
day_t day_of_week(date_t date);
