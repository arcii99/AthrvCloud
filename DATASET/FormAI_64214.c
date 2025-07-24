//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>

const char *months[12] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};

int is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int get_days_in_month(int month, int year) {
    int days;
    if (month == 2) {
        days = is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }
    return days;
}

void natural_language_date_converter(int day, int month, int year, char *output) {
    sprintf(output, "%d%s %s %d", day, (day > 3 && day < 21) || (day % 10 == 0 && day != 10) ? "th" : (day % 10 == 1) ? "st" : (day % 10 == 2) ? "nd" : "rd", months[month - 1], year);
}

int main() {
    int day, month, year;
    char output[50];
    printf("Enter a date in the format DD MM YYYY:\n");
    scanf("%d %d %d", &day, &month, &year);
    if (day > 0 && month > 0 && month <= 12 && year >= 0) {
        if (day <= get_days_in_month(month, year)) {
            natural_language_date_converter(day, month, year, output);
            printf("Natural Language Date: %s", output);
        } else {
            printf("Invalid day for the given month and year.");
        }
    } else {
        printf("Invalid input.");
    }
    return 0;
}