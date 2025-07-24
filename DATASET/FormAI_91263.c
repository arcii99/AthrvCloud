//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Current time
    time_t curr_time;
    curr_time = time(NULL);
 
    // Get the current year
    struct tm *tm_ptr = localtime(&curr_time);
    int current_year = tm_ptr->tm_year + 1900;
 
    // Choose a year to time travel to
    int year_travel;
    printf("Enter a year you want to travel to: ");
    scanf("%d", &year_travel);
 
    // Check if chosen year is in the past or future
    if(year_travel > current_year){
        printf("Sorry, time travel to the future is not possible.\n");
    }
    else if(year_travel < 1900){
        printf("Sorry, time travel to the %d is not possible.\n", year_travel);
    }
    else{
        // Calculate the time difference
        int years_diff = current_year - year_travel;
 
        // Get the new date and time
        curr_time = curr_time - (years_diff * 365 * 24 * 60 * 60);
        tm_ptr = localtime(&curr_time);
        printf("Time travel successful. Dated %s", asctime(tm_ptr));
    }
 
    return 0;
}