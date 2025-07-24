//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
    
    int day, month, year;
    printf("Enter date in format (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);
    
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days in each month array
    
    // leap year check
    if((year%4==0 && year%100!=0) || year%400==0)
        days_in_month[1] = 29;
    
    // calculating number of days
    int total_days = 0;
    for(int i = 0; i < month - 1; i++) {
        total_days += days_in_month[i];
    }
    total_days += day;
    
    // output
    printf("The day number for the given date is: %d", total_days);
    
    return 0;
}