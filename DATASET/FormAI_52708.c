//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate time travel
void time_travel(int year, int month, int day) {
    time_t current_time;
    time(&current_time);
    struct tm *local_time = localtime(&current_time);
    
    // Set values for time travel
    local_time->tm_year = year - 1900;
    local_time->tm_mon = month - 1;
    local_time->tm_mday = day;
    
    // Display original and time-traveled dates
    printf("Original Date: %s", asctime(localtime(&current_time)));
    printf("Time-Traveled Date: %s", asctime(local_time));
}

int main() {
    printf("==========================================\n");
    printf("Welcome to the Time Travel Simulator Program\n");
    printf("==========================================\n\n");
    
    int year, month, day;
    // Get user input for date to time travel to
    printf("Please enter a year (1900-2100): ");
    scanf("%d", &year);
    printf("Please enter a month (1-12): ");
    scanf("%d", &month);
    printf("Please enter a day (1-31): ");
    scanf("%d", &day);
    
    // Validate user input
    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }
    
    // Call time travel function
    time_travel(year, month, day);
    
    printf("\nThank you for using the Time Travel Simulator Program.\n");
    
    return 0;
}