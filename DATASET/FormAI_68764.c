//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL); // get the current time
    struct tm* ptm = localtime(&now); // convert time_t to tm struct
    int year = ptm->tm_year + 1900; // current year

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Would you like to travel to the past or the future? (Enter 'past' or 'future')\n");

    char input[10];
    scanf("%s", input);
    int is_past = 0;
    if (strcmp(input, "past") == 0) {
        is_past = 1;
        printf("You have chosen to travel to the past.\n");
    }
    else if (strcmp(input, "future") == 0) {
        printf("You have chosen to travel to the future.\n");
    }
    else {
        printf("Invalid input.\n");
        return 0;
    }

    int target_year;
    printf("What year would you like to travel to? (Enter a year between 1900 and %d):\n", year);
    scanf("%d", &target_year);
    if (target_year < 1900 || target_year > year) {
        printf("Invalid input. You must enter a year between 1900 and %d\n", year);
        return 0;
    }
    int years_diff = is_past ? (year - target_year) : (target_year - year);
    printf("You have chosen to travel %d years into the %s.\n", years_diff, is_past ? "past" : "future");

    int i = is_past ? year : (year + 1);
    while ((is_past && i >= target_year) || (!is_past && i <= target_year)) {
        printf("It is now the year %d.\n", i);
        i += (is_past ? -1 : 1);
        if (i % 4 == 0) {
            printf("Happy leap year!\n");
        }
    }

    printf("You have arrived at your destination year of %d. Enjoy your %s adventures!\n", target_year, is_past ? "past" : "future");
    return 0;
}