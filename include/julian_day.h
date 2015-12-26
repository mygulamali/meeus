#ifndef _JULIAN_DAY_H
#define _JULIAN_DAY_H

#include <math.h>

typedef enum calendar_types {JULIAN_CALENDAR, GREGORIAN_CALENDAR} calendar_type;
typedef enum year_types {COMMON_YEAR, BISSEXTILE_YEAR} year_type;

calendar_type get_calendar_type(int year, int month, double day);
double julian_day(int year, int month, double day);
year_type get_julian_year_type(int year);
year_type get_gregorian_year_type(int year);
year_type get_year_type(int year);

#endif
