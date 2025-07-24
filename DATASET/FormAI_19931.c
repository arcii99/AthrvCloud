//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

int daysInMonth(int month, int year) {
    int leapYear = hasLeapYear(year);
    if (month == 2) {
        return leapYear ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int isValidDate(int day, int month, int year) {
    if (year < 1 || year >= 10000) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    int days = daysInMonth(month, year);
    if (day < 1 || day > days) {
        return 0;
    }
    return 1;
}

int countDays(int day, int month, int year) {
    int days = day;
    for (int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    return days;
}

char *monthToString(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}

char *dateToString(int day, int month, int year) {
    char *dateString = (char *) malloc(11);
    sprintf(dateString, "%02d/%02d/%04d", day, month, year);
    return dateString;
}

char *cNaturalToDate(char *input) {
    if (strlen(input) != 10) {
        return "Invalid date format!";
    }
    int day, month, year;
    sscanf(input, "%2d/%2d/%4d", &day, &month, &year);
    if (!isValidDate(day, month, year)) {
        return "Invalid date!";
    }
    int days = countDays(day, month, year);
    char *output = (char *) malloc(100);
    sprintf(output, "%s %d, %d", monthToString(month), days, year);
    return output;
}

int main() {
    char input[11];
    printf("Enter date in C natural language format (MM/DD/YYYY): ");
    fgets(input, 11, stdin);
    char *output = cNaturalToDate(input);
    printf("%s\n", output);
    free(output);
    return 0;
}