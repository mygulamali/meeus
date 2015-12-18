#include "julian_day.h"

calendar_type get_calendar_type(int year, int month, double day) {
  if ((year < 1582) ||
      ((year == 1582) && (month < 10)) ||
      ((year == 1582) && (month == 10) && (day <= 4.0)))
    return JULIAN_CALENDAR;

  return GREGORIAN_CALENDAR;
}

double julian_day(int year, int month, double day) {
  calendar_type calendar = get_calendar_type(year, month, day);

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
