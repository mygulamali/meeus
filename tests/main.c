#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "julian_day.h"

static void get_calendar_type_test(void **state) {
  int dates[5][4] = {
    {1581, 10,  4, JULIAN_CALENDAR},
    {1582,  9,  4, JULIAN_CALENDAR},
    {1582, 10,  3, JULIAN_CALENDAR},
    {1582, 10,  4, JULIAN_CALENDAR},
    {1582, 10, 15, GREGORIAN_CALENDAR}
  };

  calendar_type calendar;
  for (int i = 0; i < 5; i++) {
    calendar = get_calendar_type(dates[i][0], dates[i][1], dates[i][2]);
    assert_int_equal(calendar, dates[i][3]);
  }

  (void) state;
}

static void julian_day_test(void **state) {
  double dates[15][4] = {
    // Example 7.a
    { 1957, 10,  4.81, 2436116.31},
    // Example 7.b
    {  333,  1, 27.5,  1842713.0},
    // Data from table in Chapter 7
    { 2000,  1,  1.5,  2451545.0},
    { 1987,  1, 27.0,  2446822.5},
    { 1987,  6, 19.5,  2446966.0},
    { 1988,  1, 27.0,  2447187.5},
    { 1988,  6, 19.5,  2447332.0},
    { 1900,  1,  1.0,  2415020.5},
    { 1600,  1,  1.0,  2305447.5},
    { 1600, 12, 31.0,  2305812.5},
    {  837,  4, 10.3,  2026871.8},
    {-1000,  7, 12.5,  1356001.0},
    {-1000,  2, 29.0,  1355866.5},
    {-1001,  8, 17.9,  1355671.4},
    {-4712,  1,  1.5,        0.0}
  };

  double jd;
  for (int i = 0; i < 15; i++) {
    jd = julian_day(dates[i][0], dates[i][1], dates[i][2]);
    assert_in_range(jd, dates[i][3], dates[i][3]);
  }

  (void) state;
}

static void get_year_type_test(void **state) {
  // Data from examples on page 62
  int years[11][2] = {
    { 750, COMMON_YEAR},
    { 900, BISSEXTILE_YEAR},
    {1236, BISSEXTILE_YEAR},
    {1429, COMMON_YEAR},
    {1600, BISSEXTILE_YEAR},
    {1700, COMMON_YEAR},
    {1800, COMMON_YEAR},
    {1900, COMMON_YEAR},
    {2000, BISSEXTILE_YEAR},
    {2100, COMMON_YEAR},
    {2400, BISSEXTILE_YEAR}
  };

  year_type year;
  for (int i = 0; i < 11; i++) {
    year = get_year_type(years[i][0]);
    assert_int_equal(year, years[i][1]);
  }

  (void) state;
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(get_calendar_type_test),
    cmocka_unit_test(julian_day_test),
    cmocka_unit_test(get_year_type_test)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
