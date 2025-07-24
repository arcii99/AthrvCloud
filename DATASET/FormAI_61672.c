//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <string.h>

int main(void) {
    char input_date[11]; //input date in the format "dd/mm/yyyy"
    int day, month, year; //variables to store the day, month, and year of the input date
    int leap_year = 0; //variable to check if the year is a leap year

    //prompt the user to enter the date
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", input_date);

    //parse the input date to obtain the day, month, and year
    sscanf(input_date, "%d/%d/%d", &day, &month, &year);

    //check if the year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        leap_year = 1;
    }

    //set the number of days in each month based on whether it's a leap year or not
    int num_days_in_month[] = {31, 28 + leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //calculate the number of days from the start of the year to the input date
    int days_elapsed = day;
    for (int i = 0; i < month - 1; i++) {
        days_elapsed += num_days_in_month[i];
    }

    //calculate the number of days from the start of the year to the last day of the previous year
    int days_previous_year = 365 + leap_year - days_elapsed;

    //calculate the number of days from the start of the year to the input date in the next year
    int days_next_year = 0;
    for (int i = month; i <= 12; i++) {
        days_next_year += num_days_in_month[i - 1];
    }
    days_next_year += 31; //add the days in January

    //print the result
    printf("%d/%d/%d is day %d of the year %d.\n", day, month, year, days_elapsed, year);
    printf("The equivalent date in the previous year is %d/%d/%d.\n", days_previous_year, 12, year - 1);
    printf("The equivalent date in the next year is %d/%d/%d.\n", days_next_year - (365 + leap_year), 1, year + 1);

    return 0;
}