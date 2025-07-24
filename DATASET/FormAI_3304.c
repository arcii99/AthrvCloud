//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <time.h>

int main() {
    // Set up the time variables
    time_t current_time;
    struct tm * time_info;
    
    // Get the current time
    time(&current_time);
    time_info = localtime(&current_time);

    // Ask the user for a year to travel to
    int year;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("What year would you like to travel to? (Enter a year greater than 1900)\n");
    scanf("%d", &year);

    // Calculate the difference in years
    int year_diff = year - (1900 + time_info->tm_year);

    // Calculate the future or past time
    time_t travel_time = current_time + (year_diff * 31536000);

    // Set the new time
    time_info = localtime(&travel_time);

    printf("\nPreparing to travel to %d...\n\n", year);
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Jumping to %d!\n", year);   
    
    // Output the new date and time
    printf("\n\n");
    printf("------------------------------\n");
    printf("Year: %d\n", 1900 + time_info->tm_year);
    printf("Month: %d\n", time_info->tm_mon + 1);
    printf("Day: %d\n", time_info->tm_mday);
    printf("Time: %d:%02d:%02d\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
    printf("------------------------------\n");

    return 0;
}