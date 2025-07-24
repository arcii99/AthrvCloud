//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void time_travel(int travel_year) {
    time_t current_time;
    struct tm * time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    int current_year = time_info->tm_year + 1900;
    int year_difference = travel_year - current_year;

    if (year_difference > 0) {
        printf("Welcome to the future!\n");
    } else if (year_difference < 0) {
        printf("Welcome to the past!\n");
    } else {
        printf("You are still in the same year as before!\n");
        return;
    }

    printf("You have travelled %d years.\n", abs(year_difference));
    printf("The current year is %d.\n", current_year);
    printf("The new year is %d.\n", travel_year);
}

int main() {
    int year;

    printf("Welcome to the time travel simulator.\n");
    printf("Please enter a year to travel to: ");
    scanf("%d", &year);

    time_travel(year);

    return 0;
}