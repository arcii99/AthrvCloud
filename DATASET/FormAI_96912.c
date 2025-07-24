//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main()
{
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    int current_year = time_info->tm_year + 1900; // Current year
    int simulation_year = current_year; // Starting simulation year

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You will choose a year to travel to and experience life in that time period.\n");

    while (1)
    {
        printf("Which year would you like to travel to? (%d - 9999, type -1 to exit)\n> ", current_year);
        int chosen_year;
        scanf("%d", &chosen_year);

        if (chosen_year == -1) break;

        if (chosen_year < current_year)
        {
            printf("You can't travel back in time! Please choose a year after %d.\n", current_year);
            continue;
        }
        else if (chosen_year >= 10000)
        {
            printf("Sorry, the simulation can't travel that far into the future.\n");
            continue;
        }

        printf("\nTravelling to %d...\n\n", chosen_year);

        while (simulation_year <= chosen_year)
        {
            // Code to simulate one year's worth of events
            // ...

            simulation_year++;
        }

        printf("You have travelled through time and experienced life in %d!\n", chosen_year);
    }

    printf("\nThank you for using the Time Travel Simulator!\n");

    return 0;
}