//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Time Travel Simulator program!\n");

    // Get user input for desired year to travel to
    int year;
    printf("Enter the year you want to travel to (in the range 1900 to 2100): ");
    scanf("%d", &year);

    // Check if the input year is valid
    if(year < 1900 || year > 2100) {
        printf("Invalid year entered. Please enter a year in the range 1900 to 2100.\n");
        return 0;
    }

    // Get the current date and time
    time_t current_time;
    time(&current_time);

    // Convert the current time to a local time
    struct tm *local_time = localtime(&current_time);

    // Set the user desired year, and keep the rest of date/time parameters from current local time
    local_time->tm_year = year - 1900;

    // Convert the modified local time to seconds since epoch
    time_t new_time = mktime(local_time);

    // Convert the new seconds since epoch to a new local time
    struct tm *new_local_time = localtime(&new_time);

    // Print the time travel details
    printf("\n\nTime travel successful! You have arrived at %d/%d/%d %d:%d:%d\n", 
        new_local_time->tm_mday, new_local_time->tm_mon + 1, new_local_time->tm_year + 1900,
        new_local_time->tm_hour, new_local_time->tm_min, new_local_time->tm_sec);

    return 0;
}