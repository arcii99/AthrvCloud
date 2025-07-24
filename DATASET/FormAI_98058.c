//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a year is a leap year
bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

// Function to get the number of days in a month
int get_days_in_month(int month, int year) {
    switch (month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

// Function to convert a date in natural language to a date in YYYY-MM-DD format
void convert_date(char* input_date, char* output_date) {
    int month, day, year;
    sscanf(input_date, "%d %*s %d %*s %d", &month, &day, &year);

    // Validate the input date
    if (month < 1 || month > 12 || day < 1 || day > get_days_in_month(month, year)) {
        printf("Invalid date: %s\n", input_date);
        return;
    }

    // Convert the date to YYYY-MM-DD format
    sprintf(output_date, "%04d-%02d-%02d", year, month, day);
}

int main() {
    char input_date[20], output_date[11];

    // Get a date in natural language from the user
    printf("Enter a date in natural language (e.g. January 1, 2022): ");
    fgets(input_date, 20, stdin);

    // Remove the newline character from the input date
    input_date[strcspn(input_date, "\n")] = '\0';

    // Convert the date to YYYY-MM-DD format
    convert_date(input_date, output_date);

    printf("%s in YYYY-MM-DD format is: %s\n", input_date, output_date);

    return 0;
}