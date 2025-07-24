//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int current_year, travel_year, age, new_age;
    
    // Getting current year
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_year = tm.tm_year + 1900; // tm_year starts from 1900
    
    // Getting year to travel
    printf("Enter the year you want to travel to: ");
    scanf("%d", &travel_year);
    
    // Calculate age and new age
    printf("Enter your age in %d: ", current_year);
    scanf("%d", &age);
    new_age = age + (travel_year - current_year);
    
    // Output on console
    printf("Year of travel: %d\n", travel_year);
    printf("Current age: %d\nNew age in %d: %d", age, travel_year, new_age);
    
    return 0;
}