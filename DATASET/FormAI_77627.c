//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    char date[11];
    int day, month, year;

    printf("Enter any date in format DD/MM/YYYY: ");
    scanf("%s", date);

    day = atoi(&date[0]);
    month = atoi(&date[3]);
    year = atoi(&date[6]);

    printf("You entered the date %d-%d-%d\n", day, month, year);

    // check if year is a leap year
    int isLeap = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                isLeap = 1;
        } else {
            isLeap = 1;
        }
    }

    // calculate the number of days in each month
    int daysInMonth[12] = {
        31, 28 + isLeap, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    // calculate the number of days from the beginning of the year to the given date
    int totalDays = 0;
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += day;

    printf("%d days have elapsed since the beginning of the year.\n", totalDays);

    return 0;
}