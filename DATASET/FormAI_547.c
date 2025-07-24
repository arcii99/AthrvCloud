//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int current_year, target_year, i;
    struct tm t = {0};

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter the current year (ex: 2021): ");
    scanf("%d", &current_year);

    // Set the time to the current year
    t.tm_year = current_year - 1900;
    t.tm_mon = 1;
    t.tm_mday = 1;
    mktime(&t);

    printf("Enter the year you want to travel to (ex: 2050): ");
    scanf("%d", &target_year);

    // Calculate difference in years
    int diff_year = abs(target_year - current_year);

    // Determine if we are traveling back in time or forward
    int time_direction = target_year > current_year ? 1 : -1;

    printf("\n");

    // Start the time travel simulation
    printf("Initializing time travel simulation...\n\n");

    for(i = 1; i <= diff_year; i++) {
        printf("Year %d: %d...\n", i, current_year);
        current_year += time_direction;
        sleep(1);
    }

    printf("\n");
    printf("Welcome to %d!\n", target_year);
    printf("Time travel simulation complete.\n");

    return 0;
}