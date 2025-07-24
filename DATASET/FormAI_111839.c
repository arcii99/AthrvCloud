//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>

// function to convert number of days to equivalent date
void dayToDate(int days) {
    int year, month, day;
    
    year = days / 365;
    days = days % 365;
    
    month = days / 30;
    days = days % 30;
    
    day = days;
    
    printf("The equivalent date is: %d-%d-%d", day, month, year);
}

int main() {
    int days;
    
    // get input from user
    printf("Enter number of days: ");
    scanf("%d", &days);
    
    // call function to convert and display date
    dayToDate(days);
    
    return 0;
}