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

double julian_day_zero(intmax_t year) {
    date_t date = {
        .year = year - 1,
        .mon = 12,
        .mday = 31.0
    };
    calendar_t calendar = get_calendar_type(date);

    if (calendar == JULIAN_CALENDAR)
        return julian_day(date);

    year--;
    if ((1901 <= year) && (year <= 2099))
        return (floor(365.25 * year) + 1721409.5);

    double a = floor(year / 100.0);
    return floor(365.25 * year) - a + floor(a / 4.0) + 1721424.5;
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

date_t calendar_date(double julian_day) {
    julian_day += 0.5;
    double z = floor(julian_day);
    double f = julian_day - z;

    double a;
    if (z < 2299161)
        a = z;
    else {
        double alpha = floor((z - 1867216.25) / 36524.25);
        a = z + 1.0 + alpha - floor(0.25*alpha);
    }

    double b = a + 1524.0;
    double c = floor((b - 122.1) / 365.25);
    double d = floor(365.25 * c);
    double e = floor((b - d) / 30.6001);

    date_t date;
    date.mday = b - d - floor(30.6001 * e) + f;

    if (e < 14.0)
        date.mon = (intmax_t) e - 1;
    else if ((e == 14) || (e == 15))
        date.mon = (intmax_t) e - 13;
    else
        date.mon = NAN;

    if (date.mon > 2)
        date.year = (intmax_t) c - 4716;
    else if ((date.mon == 1) || (date.mon == 2))
        date.year = (intmax_t) c - 4715;
    else
        date.year = NAN;

    return date;
}

double calendar_diff(date_t date_1, date_t date_2) {
  return julian_day(date_1) - julian_day(date_2);
}

date_t date_before(date_t date, double days) {
  return calendar_date(julian_day(date) - days);
}

date_t date_after(date_t date, double days) {
  return calendar_date(julian_day(date) + days);
}
