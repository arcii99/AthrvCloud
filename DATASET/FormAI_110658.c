//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator 
    srand(time(NULL));

    // Get the current time 
    time_t now = time(NULL);

    // Convert the current time to a string 
    char timeString[100];
    strftime(timeString, sizeof(timeString), "%c", localtime(&now));

    // Print out the current time 
    printf("Current time: %s\n\n", timeString);

    // Let the user choose a year to travel to 
    int year;
    printf("Enter a year to travel to: ");
    scanf("%d", &year);

    // Calculate the difference in years 
    int diff = year - localtime(&now)->tm_year - 1900;

    // Adjust the current time by the difference in years 
    struct tm* newTime = localtime(&now);
    newTime->tm_year += diff;

    // Convert the new time to a string 
    strftime(timeString, sizeof(timeString), "%c", newTime);

    // Print out the new time 
    printf("Time in %d: %s\n", year, timeString);

    return 0;
}