//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *currentLocalTime;
    time_t timeTravel;
    struct tm *timeTravelLocalTime;

    // get current time
    time(&currentTime);
    currentLocalTime = localtime(&currentTime);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current date and time is: %s", asctime(currentLocalTime));

    // ask for time travel input
    printf("Enter the number of years to travel: ");
    int years;
    scanf("%d", &years);

    // calculate time travel
    timeTravel = currentTime - (years * 365 * 24 * 60 * 60);
    timeTravelLocalTime = localtime(&timeTravel);

    // print time travel result
    printf("Time travel complete! You have arrived at: %s", asctime(timeTravelLocalTime));
    printf("Press any key to exit.\n");

    return 0;
}