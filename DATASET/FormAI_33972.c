//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

// Define constants for the current and future times
#define CURRENT_YEAR 2021
#define FUTURE_YEAR 2050

// Function to display the current and future times
void displayTime(struct tm *currentTime, struct tm *futureTime) {
    printf("Current Time: %d-%02d-%02d %02d:%02d:%02d\n", 
            (currentTime->tm_year + 1900), 
            (currentTime->tm_mon + 1), 
            currentTime->tm_mday, 
            currentTime->tm_hour, 
            currentTime->tm_min, 
            currentTime->tm_sec);
    printf("Future Time: %d-%02d-%02d %02d:%02d:%02d\n", 
            (futureTime->tm_year + 1900), 
            (futureTime->tm_mon + 1), 
            futureTime->tm_mday, 
            futureTime->tm_hour, 
            futureTime->tm_min, 
            futureTime->tm_sec);
}

int main() {
    // Get the current time
    time_t rawTime = time(NULL);
    struct tm *currentTime = localtime(&rawTime);

    // Compute the time difference between the current time and the future time
    int diff = FUTURE_YEAR - CURRENT_YEAR;

    // Set the future time by adding the difference to the current time
    struct tm *futureTime = localtime(&rawTime);
    futureTime->tm_year += diff;

    // Display the current and future times
    displayTime(currentTime, futureTime);

    return 0;
}