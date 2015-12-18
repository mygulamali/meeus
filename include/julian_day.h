#ifndef _JULIAN_DAY_H
#define _JULIAN_DAY_H

#include <math.h>

typedef enum calendar_types {JULIAN_CALENDAR, GREGORIAN_CALENDAR} calendar_type;

calendar_type get_calendar_type(int year, int month, double day);
double julian_day(int year, int month, double day);

#endif
