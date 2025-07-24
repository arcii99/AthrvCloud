//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayOfYear(int day, int month, int year) {
    int leap = isLeapYear(year);

    int totalDays = 0;
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 2:
                totalDays += leap ? 29 : 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                totalDays += 30;
                break;
            default:
                totalDays += 31;
                break;
        }
    }

    totalDays += day;
    return totalDays;
}

void printDate(int day, int month, int year) {
    printf("%d%s ", day, (day % 10 == 1 && day != 11) ? "st" : (day % 10 == 2 && day != 12) ? "nd" : (day % 10 == 3 && day != 13) ? "rd" : "th");

    switch (month) {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }

    printf(" %d\n", year);
}

int main() {
    int day, month, year;
    printf("Enter a date in format DD MM YYYY: ");
    scanf("%d %d %d", &day, &month, &year);

    if (day <= 0 || month <= 0 || month > 12) {
        printf("Invalid date\n");
        return 1;
    }

    if (day > 31 || (month == 2 && day > (isLeapYear(year) ? 29 : 28)) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        printf("Invalid date\n");
        return 1;
    }

    printf("Day %d of the year %d is:\n", dayOfYear(day, month, year), year);
    printDate(day, month, year);

    return 0;
}