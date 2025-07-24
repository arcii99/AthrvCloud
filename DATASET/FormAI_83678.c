//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set seed for random number generation
    srand(time(NULL)); 
    // Get current time
    time_t now = time(NULL);
    // Convert time to tm structure
    struct tm* date = localtime(&now);
    
    // Print current date and time
    printf("Current date and time: %s", asctime(date));
    
    // Ask user for time travel destination
    printf("\nPlease enter the year you want to travel to: ");
    int year;
    scanf("%d", &year);
    
    // Calculate difference between current year and destination year
    int year_diff = year - (date->tm_year + 1900);
    // Calculate the time travel distance (in seconds)
    time_t time_diff = year_diff * 365 * 24 * 60 * 60;
    // Calculate the new time (in seconds)
    time_t new_time = now + time_diff;
    
    // Convert the new time to tm structure
    struct tm* new_date = localtime(&new_time);
    
    // Print the time travel destination
    printf("\nYou have traveled in time to: %s", asctime(new_date));
    
    // Generate a random event in the new time period
    char* events[] = {"You witness the signing of the Declaration of Independence.", "You meet William Shakespeare.", "You attend Woodstock.", "You witness the fall of the Berlin Wall."};
    int event_index = rand() % 4;
    printf("\n%s", events[event_index]);
    
    // End program
    return 0;
}