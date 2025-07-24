//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char year_input[5];
    int year;

    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);

    printf("Welcome to the Time Travel Simulator!\n\n");

    // Get the year to time travel to
    printf("Please enter the year you want to time travel to: ");
    fgets(year_input, 5, stdin);
    sscanf(year_input, "%d", &year);

    // Calculate the difference in years
    int diff = year - (time_info->tm_year + 1900);

    if (diff == 0) {
        printf("\nYou have not time traveled at all. You are still in the present year of %d.\n", year);
    } else if (diff > 0) {
        printf("\nYou have time traveled %d year(s) into the future. It is now the year %d.\n", diff, year);
    } else if (diff < 0) {
        printf("\nYou have time traveled %d year(s) into the past. It is now the year %d.\n", -diff, year);
    }

    return 0;
}