#include "julian_day.h"

calendar_t get_calendar_type(date_t date) {
  if ((date.year < 1582) ||
      ((date.year == 1582) && (date.mon < 10)) ||
      ((date.year == 1582) && (date.mon == 10) && (date.mday <= 4)))
    return JULIAN_CALENDAR;

  return GREGORIAN_CALENDAR;
}

double julian_day(date_t date) {
  calendar_t calendar = get_calendar_type(date);

  if (date.mon <= 2) {
    date.year--;
    date.mon += 12;
  }

  double
    a = floor(date.year / 100.0),
    b = (calendar == JULIAN_CALENDAR) ? 0.0 : 2.0 - a + floor(a / 4.0),
    jd = floor(365.25 * (date.year + 4716))
       + floor(30.6001 * (date.mon + 1)) + date.mday + b - 1524.5;

  return jd;
}

year_t get_julian_year_type(intmax_t year) {
  if (year % 4 == 0)
    return BISSEXTILE_YEAR;
  return COMMON_YEAR;
}

year_t get_gregorian_year_type(intmax_t year) {
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    return BISSEXTILE_YEAR;
  return COMMON_YEAR;
}

year_t get_year_type(intmax_t year) {
  if (year < 1582)
    return get_julian_year_type(year);
  return get_gregorian_year_type(year);
}

double modified_julian_day(date_t date) {
  return julian_day(date) - 2400000.5;
}
