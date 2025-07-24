//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int timeTraveled, years, days, hours, minutes, seconds;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter the number of years you want to travel in time: ");
    scanf("%d", &timeTraveled);

    // Calculating time
    seconds = timeTraveled * 365 * 24 * 60 * 60;
    minutes = seconds / 60;
    hours = minutes / 60;
    days = hours / 24;
    years = days / 365;

    if (timeTraveled < 0) // Checking for negative time
    {
        printf("Time travel in opposite direction is not possible\n");
    }
    else if (timeTraveled == 0) // Checking for no time travel
    {
        printf("You did not travel in time\n");
    }
    else
    {
        printf("You have traveled %d years into the future\n", timeTraveled);
        printf("That's equivalent to %d days, %d hours, %d minutes and %d seconds\n", days, hours % 24, minutes % 60, seconds % 60);
    }

    return 0;
}