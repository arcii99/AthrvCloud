//FormAI DATASET v1.0 Category: Scientific ; Style: curious
#include <stdio.h>

int main() {
    int days_in_year = 365; // number of days in a year
    float hours_in_day = 24.0; // number of hours in a day, represented as a float
    int minutes_in_hour = 60; // number of minutes in an hour
    int seconds_in_minute = 60; // number of seconds in a minute

    float hours_in_year = days_in_year * hours_in_day; // calculate number of hours in a year
    float minutes_in_year = hours_in_year * minutes_in_hour; // calculate number of minutes in a year
    float seconds_in_year = minutes_in_year * seconds_in_minute; // calculate number of seconds in a year

    printf("Did you know that there are %f hours or %f minutes or %f seconds in a year?\n", hours_in_year, minutes_in_year, seconds_in_year);

    printf("Curious about how many seconds there are in a month? Let's find out!\n");

    int days_in_month = 30; // let's say each month has 30 days
    float hours_in_month = days_in_month * hours_in_day; // calculate the number of hours in a month
    float minutes_in_month = hours_in_month * minutes_in_hour; // calculate the number of minutes in a month
    float seconds_in_month = minutes_in_month * seconds_in_minute; // calculate the number of seconds in a month

    printf("In a month, there are %f seconds!\n", seconds_in_month);

    printf("Let's take it even further. How many seconds are in a leap year?\n");

    int days_in_leap_year = 366; // number of days in a leap year
    float hours_in_leap_year = days_in_leap_year * hours_in_day; // number of hours in a leap year
    float minutes_in_leap_year = hours_in_leap_year * minutes_in_hour; // number of minutes in a leap year
    float seconds_in_leap_year = minutes_in_leap_year * seconds_in_minute; // number of seconds in a leap year

    printf("In a leap year, there are %f seconds!\n", seconds_in_leap_year);

    return 0;
}