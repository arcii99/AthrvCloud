//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>

// Function to convert dates
void convertDate(int day, int month, int year) {
    // arrays containing the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // check if the year is a leap year
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        daysInMonth[1] = 29; // set February to 29 days
    }

    // check if the day and month are within valid ranges
    if (day < 1 || day > daysInMonth[month - 1] || month < 1 || month > 12) {
        printf("Invalid date\n");
        return;
    }

    // calculate the day of the year
    int dayOfYear = 0;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    dayOfYear += day;

    // output the result
    printf("The date %02d/%02d/%04d is day number %d of the year %04d.\n", day, month, year, dayOfYear, year);
}

int main() {
    // prompt the user for input
    printf("Please enter a date in the format (DD MM YYYY): ");
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);

    // call the conversion function
    convertDate(day, month, year);

    return 0;
}