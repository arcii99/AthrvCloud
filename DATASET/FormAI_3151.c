//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>

int main() {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    int day, month, year, i, days = 0;
    printf("Enter date in natural language format (e.g., July 4, 2021): ");
    scanf("%s %d, %d", months, &day, &year);
    month = 0;
    for (i = 0; i < 12; i++) {
        if (strcmp(months[i], months) == 0) {
            month = i + 1;
            break;
        }
    }
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            daysInMonth[1] = 29;
        }
    }
    for (i = 0; i < month - 1; i++) {
        days += daysInMonth[i];
    }
    days += day;
    printf("The date %s %d, %d is the %d day of the year.\n", months[month-1], day, year, days);
    return 0;
}