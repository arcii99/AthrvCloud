//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t = time(NULL); // Current time
    struct tm* now = localtime(&t); // Convert time_t to struct tm

    // Print current date and time
    printf("Current date and time: %s\n", asctime(now));

    // Prompt user for the year they want to travel to
    printf("Enter the year you want to travel to: ");
    int year;
    scanf("%d", &year);

    // Calculate difference in years between current year and desired year
    int years_to_travel = year - now->tm_year - 1900;

    // Calculate new time_t for desired year
    struct tm desired_time = *now; // Start with current time
    desired_time.tm_year += years_to_travel; // Add years to desired year
    time_t desired_t = mktime(&desired_time); // Convert struct tm to time_t

    // Print new date and time
    printf("Time travel successful! You are now in the year %d.\n", year);
    printf("Current date and time: %s\n", asctime(localtime(&desired_t)));
    
    return 0;
}