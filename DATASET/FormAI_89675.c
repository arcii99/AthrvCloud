//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set seed for random number generation
    srand(time(NULL));

    // Get current time
    time_t current_time;
    time(&current_time);

    // Convert current time to struct tm
    struct tm *time_info;
    time_info = localtime(&current_time);

    // Get input from user
    int years_to_travel;
    printf("Enter the number of years you want to travel: ");
    scanf("%d", &years_to_travel);

    // Calculate future date
    time_info->tm_year += years_to_travel;
    mktime(time_info);

    // Print future date and time
    char time_string[30];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    printf("In %d years, the date and time will be: %s\n", years_to_travel, time_string);

    // Generate a random number of past years to travel
    int past_years_to_travel = rand() % 100 + 1;

    // Calculate past date
    time_info->tm_year -= past_years_to_travel;
    mktime(time_info);

    // Print past date and time
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    printf("You have travelled %d years into the past, the date and time is now: %s\n", past_years_to_travel, time_string);

    // Exit program
    return 0;
}