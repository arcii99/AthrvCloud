//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int num_days_in_month(int month, int year) {
    int days_in_month[] = {31, 28 + is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month - 1];
}

void date_converter(char input_date[]) {
    int day, month, year, num_days, i;
    char month_str[10];
    
    sscanf(input_date, "%d %s %d", &day, month_str, &year);
    
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    for (i = 0; i < 12; i++) {
        if (strcmp(month_str, months[i]) == 0) {
            month = i + 1;
            break;
        }
    }
    
    num_days = num_days_in_month(month, year);
    
    printf("%d-%d-%d\n", month, day, year);
    printf("Number of days in month: %d\n", num_days);
}

int main() {
    char input_date[] = "23 September 2021";
    date_converter(input_date);
    return 0;
}