//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up the time travel simulator
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please select the year you wish to travel to: ");
    int year;
    scanf("%d", &year);
    printf("Preparing to travel to year %d...\n\n", year);
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    printf("You are currently in the year %d\n\n", now->tm_year + 1900);

    // Performing the time travel
    if (now->tm_year + 1900 < year) {
        printf("Accelerating time travel to the future...\n\n");
        while (now->tm_year + 1900 != year) {
            t += 60 * 60 * 24 * 365;
            now = localtime(&t);
        }
    } else if (now->tm_year + 1900 > year) {
        printf("Starting time travel to the past...\n\n");
        while (now->tm_year + 1900 != year) {
            t -= 60 * 60 * 24 * 365;
            now = localtime(&t);
        }
    } else {
        printf("Already at your target year!\n\n");
    }

    // Displaying the result of time travel
    printf("You have arrived in the year %d\n\n", now->tm_year + 1900);
    printf("Thank you for using the Time Travel Simulator! Have a great trip!\n");

    return 0;
}