//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int current_year = 2021, destination_year, years_travel, should_continue = 1;
    char response;

    while (should_continue) {
        printf("Welcome to time travel simulator!\n");
        printf("Enter the year you would like to travel to: ");
        scanf("%d", &destination_year);

        if (destination_year < 0) {
            printf("Invalid year selected. Please select a positive integer.\n");
            continue;
        } else if (destination_year < current_year) {
            printf("Warning: You have selected a year prior to the current year!\n");
        }

        years_travel = abs(current_year - destination_year);
        printf("You are travelling to the year %d.\n", destination_year);
        printf("You will be travelling %d %s into the %s.\n", years_travel,
               (years_travel > 1 ? "years" : "year"),
               (destination_year > current_year ? "future" : "past"));

        printf("Do you wish to continue? (y/n): ");
        scanf(" %c", &response);

        if (response == 'n' || response == 'N') {
            should_continue = 0;
        }
    }

    printf("Thank you for using the time travel simulator!\n");
    return 0;
}