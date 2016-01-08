#include "julian_day.h"

calendar_t get_calendar_type(intmax_t year, intmax_t month, double day) {
  if ((year < 1582) ||
      ((year == 1582) && (month < 10)) ||
      ((year == 1582) && (month == 10) && (day <= 4.0)))
    return JULIAN_CALENDAR;

  return GREGORIAN_CALENDAR;
}

double julian_day(intmax_t year, intmax_t month, double day) {
  calendar_t calendar = get_calendar_type(year, month, day);

  if (month <= 2) {
    year--;
    month += 12;
  }

  double
    a = floor(year / 100.0),
    b = (calendar == JULIAN_CALENDAR) ? 0.0 : 2.0 - a + floor(a / 4.0),
    jd = floor(365.25 * (year + 4716))
       + floor(30.6001 * (month + 1)) + day + b - 1524.5;

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

double modified_julian_day(intmax_t year, intmax_t month, double day) {
  return julian_day(year, month, day) - 2400000.5;
}
