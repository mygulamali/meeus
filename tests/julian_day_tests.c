#include "julian_day_tests.h"

void get_calendar_type_test(void **state) {
    intmax_t dates[5][4] = {
        {1581, 10,  4, JULIAN_CALENDAR},
        {1582,  9,  4, JULIAN_CALENDAR},
        {1582, 10,  3, JULIAN_CALENDAR},
        {1582, 10,  4, JULIAN_CALENDAR},
        {1582, 10, 15, GREGORIAN_CALENDAR}
    };

    for (intmax_t i = 0; i < 5; i++) {
        date_t date = {
            .year = dates[i][0],
            .mon = dates[i][1],
            .mday = dates[i][2]
        };

        calendar_t calendar = get_calendar_type(date);
        assert_int_equal(calendar, dates[i][3]);
    }

    (void) state;
}

void julian_day_test(void **state) {
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

    for (intmax_t i = 0; i < 15; i++) {
        date_t date = {
            .year = dates[i][0],
            .mon = dates[i][1],
            .mday = dates[i][2]
        };

        double jd = julian_day(date);
        assert_double_equal(jd, dates[i][3], JULIAN_DAY_TOLERANCE);
    }

    (void) state;
}

void julian_day_zero_test(void **state) {
    double years[4][2] = {
        // Selected data adapted from table in Chapter 7
        { 2000, 2451543.5},
        { 1900, 2415019.5},
        { 1600, 2305446.5},
        {-4712,      -1.5}
    };

    for (intmax_t i = 0; i < 4; i++) {
        double jd0 = julian_day_zero(years[i][0]);
        assert_double_equal(jd0, years[i][1], JULIAN_DAY_TOLERANCE);
    }

    (void) state;
}

void get_year_type_test(void **state) {
    // Data from examples on page 62
    intmax_t years[11][2] = {
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

    for (intmax_t i = 0; i < 11; i++) {
        year_t year = get_year_type(years[i][0]);
        assert_int_equal(year, years[i][1]);
    }

    (void) state;
}

void modified_julian_day_test(void **state) {
    // Example on page 63
    date_t date = {
        .year = 1858,
        .mon = 11,
        .mday = 17
    };

    double mjd = modified_julian_day(date);
    assert_double_equal(mjd, 0.0, JULIAN_DAY_TOLERANCE);

    (void) state;
}

void calendar_date_test(void **state) {
    double dates[16][4] = {
        // Example 7.c
        {2436116.31, 1957, 10,  4.81},
        // Subsequent exercises
        {1842713.0,   333,  1, 27.5},
        {1507900.13, -584,  5, 28.63},
        // Data from table in Chapter 7
        {2451545.0,  2000,  1,  1.5},
        {2446822.5,  1987,  1, 27.0},
        {2446966.0,  1987,  6, 19.5},
        {2447187.5,  1988,  1, 27.0},
        {2447332.0,  1988,  6, 19.5},
        {2415020.5,  1900,  1,  1.0},
        {2305447.5,  1600,  1,  1.0},
        {2305812.5,  1600, 12, 31.0},
        {2026871.8,   837,  4, 10.3},
        {1356001.0, -1000,  7, 12.5},
        {1355866.5, -1000,  2, 29.0},
        {1355671.4, -1001,  8, 17.9},
        {      0.0, -4712,  1,  1.5}
    };

    for (intmax_t i = 0; i < 16; i++) {
        date_t date = calendar_date(dates[i][0]);

        assert_int_equal(date.year, dates[i][1]);
        assert_int_equal(date.mon, dates[i][2]);
        assert_double_equal(date.mday, dates[i][3], JULIAN_DAY_TOLERANCE);
    }

    (void) state;
}

void calendar_diff_test(void **state) {
  // Example 7.d
  date_t date_1 = {.year = 1986, .mon = 2, .mday =  9};
  date_t date_2 = {.year = 1910, .mon = 4, .mday = 20};

  double days = calendar_diff(date_1, date_2);

  assert_double_equal(days, 27689.0, JULIAN_DAY_TOLERANCE);

  (void) state;
}

void date_before_test(void **state) {
  // Exercise at the end of page 64
  date_t input_date = {.year = 2018, .mon = 11, .mday = 26};

  date_t date = date_before(input_date, 10000);

  assert_int_equal(date.year, 1991);
  assert_int_equal(date.mon, 7);
  assert_double_equal(date.mday, 11.0, JULIAN_DAY_TOLERANCE);

  (void) state;
}

void date_after_test(void **state) {
  // Exercise at the end of page 64
  date_t input_date = {.year = 1991, .mon = 7, .mday = 11};

  date_t date = date_after(input_date, 10000);

  assert_int_equal(date.year, 2018);
  assert_int_equal(date.mon, 11);
  assert_double_equal(date.mday, 26.0, JULIAN_DAY_TOLERANCE);

  (void) state;
}

void day_of_week_test(void **state) {
  // Example 7.e
  date_t date = {.year = 1954, .mon = 6, .mday = 30};

  day_t day = day_of_week(date);

  assert_int_equal(day, WEDNESDAY);

  (void) state;
}

void day_of_year_test(void **state) {
  intmax_t dates[2][4] = {
    // Example 7.f
    {1978, 11, 14, 318},
    // Example 7.g
    {1988,  4, 22, 113}
  };

  for (intmax_t i = 0; i < 2; i++) {
    date_t date = {
      .year = dates[i][0],
      .mon  = dates[i][1],
      .mday = dates[i][2]
    };

    intmax_t doy = day_of_year(date);
    assert_int_equal(doy, dates[i][3]);
  }

  (void) state;
}

void date_from_doy_test(void **state) {
  intmax_t dates[2][4] = {
    // Example 7.f
    {1978, 11, 14, 318},
    // Example 7.g
    {1988,  4, 22, 113}
  };

  for (intmax_t i = 0; i < 2; i++) {
    date_t date = date_from_doy(dates[i][0], dates[i][3]);

    assert_int_equal(date.year, dates[i][0]);
    assert_int_equal(date.mon, dates[i][1]);
    assert_double_equal(date.mday, dates[i][2], JULIAN_DAY_TOLERANCE);
  }

  (void) state;
}
