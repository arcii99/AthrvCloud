//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program converts dates between the Gregorian and Julian calendars
 * It takes input in natural language format such as "September 7th, 2021" or "August 20th, 1455 BC"
 * It then converts the input date to Julian Days and outputs the date in the desired output format
 */

struct Date {
    int year;
    int month;
    int day;
    int julianDay;
};

/* Returns the number of days in a given month, accounting for leap years */
int daysInMonth(int year, int month) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

/* Returns the Julian Day for a given date */
int getJulianDay(struct Date date) {
    int a, b, c, d, e, f, g, h, i, j, k;
    if (date.month <= 2) {
        date.year--;
        date.month += 12;
    }
    a = date.year / 100;
    b = 2 - a + (a / 4);
    c = 365.25 * date.year;
    d = 30.6001 * (date.month + 1);
    e = date.day;
    f = b + c + d + e + 1720994.5;
    if (date.year < 0) {
        f -= 1;
    }
    return f;
}

/* Returns the Gregorian Date for a given Julian Day */
struct Date getGregorianDate(int julianDay) {
    int a, b, c, d, e, month, year, day;
    int f = julianDay + 68569;
    int g = (f * 4) / 146097;
    int h = f - (146097 * g + 3) / 4;
    int i = 4000 * (h + 1) / 1461001;
    int k = h - (1461 * i / 4) + 31;
    int j = 80 * k / 2447;
    day = k - (2447 * j / 80);
    k = j / 11;
    month = j + 2 - (12 * k);
    year = 100 * (g - 49) + i + k;
    struct Date date = {year, month, day, julianDay};
    return date;
}

/* Returns the Julian Date for a given date in natural language format */
struct Date getDate(char* input) {
    int year, month, day;
    char *monthStr;
    sscanf(input, "%s %d, %d", monthStr, &day, &year);
    if (strstr(input, "BC")) {
        year = -year + 1; // Switch to astronomical dating convention
    }
    if (strcmp(monthStr, "January") == 0) {
        month = 1;
    } else if (strcmp(monthStr, "February") == 0) {
        month = 2;
    } else if (strcmp(monthStr, "March") == 0) {
        month = 3;
    } else if (strcmp(monthStr, "April") == 0) {
        month = 4;
    } else if (strcmp(monthStr, "May") == 0) {
        month = 5;
    } else if (strcmp(monthStr, "June") == 0) {
        month = 6;
    } else if (strcmp(monthStr, "July") == 0) {
        month = 7;
    } else if (strcmp(monthStr, "August") == 0) {
        month = 8;
    } else if (strcmp(monthStr, "September") == 0) {
        month = 9;
    } else if (strcmp(monthStr, "October") == 0) {
        month = 10;
    } else if (strcmp(monthStr, "November") == 0) {
        month = 11;
    } else {
        month = 12;
    }
    struct Date date = {year, month, day, 0};
    date.julianDay = getJulianDay(date);
    return date;
}

int main() {
    char input[100];
    printf("Enter a date in the format: Month Day, Year (or BC):\n");
    fgets(input, sizeof(input), stdin);
    struct Date date = getDate(input);
    printf("The Julian Day for this date is: %d\n", date.julianDay);
    printf("Enter desired output format: (1) Month Day, Year or (2) Julian Day\n");
    int outputType;
    scanf("%d", &outputType);
    if (outputType == 1) {
        struct Date gregorianDate = getGregorianDate(date.julianDay);
        printf("The Gregorian date is: %s %d, %d\n", 
            gregorianDate.month == 1 ? "January" : gregorianDate.month == 2 ? "February" :
            gregorianDate.month == 3 ? "March" : gregorianDate.month == 4 ? "April" :
            gregorianDate.month == 5 ? "May" : gregorianDate.month == 6 ? "June" :
            gregorianDate.month == 7 ? "July" : gregorianDate.month == 8 ? "August" :
            gregorianDate.month == 9 ? "September" : gregorianDate.month == 10 ? "October" :
            gregorianDate.month == 11 ? "November" : "December",
            gregorianDate.day, gregorianDate.year);
    } else {
        printf("The Julian Day for this date is: %d\n", date.julianDay);
    }
    return 0;
}