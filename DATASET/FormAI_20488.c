//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>

// Function to determine whether the given year is a leap year or not
int isLeapYear(int year) {
    // A year is a leap year if:
    // 1. It is divisible by 4 but not divisible by 100, OR
    // 2. It is divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the total number of days from 1st January of a given year to a given date
int getTotalDays(int day, int month, int year) {
    int totalDays = 0;
    int daysInMonths[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonths[i];
    }
    totalDays += day;
    return totalDays;
}

// Function to convert a date from DD/MM/YYYY format to Julian Date
double convertToJulianDate(int day, int month, int year) {
    int totalDays = getTotalDays(day, month, year);
    int daysInYear = isLeapYear(year) ? 366 : 365;
    double julianDate = year + (totalDays - 1) / (double)daysInYear + 1721013.5;
    return julianDate;
}

// Function to convert a date from Julian Date to DD/MM/YYYY format
void convertFromJulianDate(double julianDate, int *day, int *month, int *year) {
    double jd = julianDate + 0.5;
    int z = (int) jd;
    double f = jd - z;
    int a = z;
    if (z >= 2299161) {
        int alpha = (int) ((z - 1867216.25) / 36524.25);
        a = z + 1 + alpha - alpha / 4;
    }
    int b = a + 1524;
    int c = (int) ((b - 122.1) / 365.25);
    int d = (int) (365.25 * c);
    int e = (int) ((b - d) / 30.6001);
    *day = b - d - (int) (30.6001 * e) + f;
    *month = e < 14 ? e - 1 : e - 13;
    *year = *month > 2 ? c - 4716 : c - 4715;
}

// Sample main function to test the above functions
int main() {
    int day = 27, month = 9, year = 2022;
    printf("Date in DD/MM/YYYY format: %d/%d/%d\n", day, month, year);

    double jd = convertToJulianDate(day, month, year);
    printf("Equivalent Julian Date: %lf\n", jd);

    int newDay, newMonth, newYear;
    convertFromJulianDate(jd, &newDay, &newMonth, &newYear);
    printf("Converted Back to DD/MM/YYYY format: %d/%d/%d\n", newDay, newMonth, newYear);

    return 0;
}