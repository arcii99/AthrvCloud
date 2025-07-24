//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
// C Natural Language Date Converter
// Shape-shifting Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

char* month_name[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Helper function to check if a year is a leap year
bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Helper function to get the month index from a given month name
int get_month_index(char* month_name) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(month_name, month_name[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function to convert natural language dates to standard DD/MM/YYYY format
char* convert_date(char* input_date) {
    static char output_date[11];
    int day, month, year;

    // Initialize to invalid values to check later if they have been set or not
    day = -1;
    month = -1;
    year = -1;

    // Convert the input date string to lowercase for easy matching
    for (int i = 0; i < strlen(input_date); i++) {
        input_date[i] = tolower(input_date[i]);
    }

    // Check if the input date string contains the current year or not
    if (strstr(input_date, "this year") != NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year = tm.tm_year + 1900;
    } else if (strstr(input_date, "next year") != NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year = tm.tm_year + 1901;
    } else {
        // If the year is not mentioned, assume it is the current year
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year = tm.tm_year + 1900;
    }

    // Check if the input date string contains a month name or not
    for (int i = 0; i < 12; i++) {
        if (strstr(input_date, month_name[i]) != NULL) {
            month = i + 1;
            break;
        }
    }

    // Check if the input date string contains a day number or not
    char* day_str = strtok(input_date, " ");
    while (day_str != NULL) {
        if (isdigit(day_str[0])) {
            day = atoi(day_str);
            break;
        }
        day_str = strtok(NULL, " ");
    }

    // Check for some special cases (e.g. "tomorrow", "next week", etc.)
    if (strstr(input_date, "tomorrow") != NULL) {
        time_t t = time(NULL) + 86400;
        struct tm tm = *localtime(&t);
        day = tm.tm_mday;
        month = tm.tm_mon + 1;
        year = tm.tm_year + 1900;
    } else if (strstr(input_date, "next week") != NULL) {
        time_t t = time(NULL) + 604800;
        struct tm tm = *localtime(&t);
        day = tm.tm_mday;
        month = tm.tm_mon + 1;
        year = tm.tm_year + 1900;
    }

    // Check if all three values have been set or not
    if (day == -1 || month == -1 || year == -1) {
        return "Invalid input date";
    }

    // Check for leap years and the number of days in the given month
    if (month == 2) {
        if (is_leap_year(year)) {
            if (day > 29) {
                return "Invalid input date";
            }
        } else {
            if (day > 28) {
                return "Invalid input date";
            }
        }
    } else {
        if (day > month_days[month - 1]) {
            return "Invalid input date";
        }
    }

    // Construct the output date string
    sprintf(output_date, "%02d/%02d/%04d", day, month, year);

    return output_date;
}

int main() {
    char input_dates[][50] = {"25th November", "1st August this year", "15th June next year",
                              "31st February next year", "2nd April 2023", "tomorrow",
                              "next week", "some gibberish text"};
    for (int i = 0; i < sizeof(input_dates) / sizeof(input_dates[0]); i++) {
        char* output_date = convert_date(input_dates[i]);
        printf("%s -> %s\n", input_dates[i], output_date);
    }
    return 0;
}