//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>

int main() {
    int month, day, year, days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* month_names[] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

    printf("Enter a date (in the format mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    int days_so_far = day;

    // determine if it's a leap year, if so, Feb has 29 days
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_in_months[1] = 29;
    }

    // add up to the number of days passed so far
    for (int i = 0; i < month - 1; i++) {
        days_so_far += days_in_months[i];
    }

    printf("That date is %d day(s) into the year.\n", days_so_far);
    printf("It is the %d%s day of %s, %d.\n",
           days_so_far,
           (days_so_far % 10 == 1 && days_so_far % 100 != 11) ? "st" :
           (days_so_far % 10 == 2 && days_so_far % 100 != 12) ? "nd" :
           (days_so_far % 10 == 3 && days_so_far % 100 != 13) ? "rd" :
           "th",
           month_names[month - 1],
           year);

    return 0;
}