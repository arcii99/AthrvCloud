//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int days_since_event; // number of days counted since the event
    
    printf("Enter the number of days since the event: ");
    scanf("%d", &days_since_event);
    
    int years = days_since_event / 365; // calculate approximate number of years
    int remaining_days = days_since_event % 365; // calculate remaining days
    
    int weeks = remaining_days / 7; // calculate approximate number of weeks
    remaining_days = remaining_days % 7; // calculate remaining days
     
    printf("It has been approximately %d years, %d weeks, and %d days since the event.", years, weeks, remaining_days);
    
    return 0;
}