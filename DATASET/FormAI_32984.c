//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    time_t currentTime;
    struct tm *timeDetails;
    char timeString[25];
    int years;

    // Get the current time
    time(&currentTime);

    // Get time details
    timeDetails = localtime(&currentTime);

    // Print the current time
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeDetails);
    printf("Current time is: %s\n", timeString);

    // Prompt user to enter years they want to travel
    printf("Enter the number of years you want to travel (positive for future, negative for past): ");
    scanf("%d", &years);

    // Calculate the time difference
    timeDetails->tm_year += years;
    currentTime = mktime(timeDetails);

    // Get the new time details
    timeDetails = localtime(&currentTime);

    // Print the new time
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeDetails);
    printf("After travelling %d years, the time is: %s\n", years, timeString);

    return 0;
}