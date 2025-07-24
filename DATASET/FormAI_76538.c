//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Initializing variables
    int day, month, year;
    int time_travel_year;

    // Getting user input and validating
    printf("Enter the present day (1-31): ");
    scanf("%d", &day);
    if (day < 1 || day > 31) {
        printf("Invalid input. Please enter a day between 1 and 31.\n");
        exit(0);
    }
    printf("Enter the present month (1-12): ");
    scanf("%d", &month);
    if (month < 1 || month > 12) {
        printf("Invalid input. Please enter a month between 1 and 12.\n");
        exit(0);
    }
    printf("Enter the present year: ");
    scanf("%d", &year);
    if (year < 0) {
        printf("Invalid input. Please enter a positive year.\n");
        exit(0);
    }
    printf("Enter the year you want to travel to: ");
    scanf("%d", &time_travel_year);
    if (time_travel_year < 0) {
        printf("Invalid input. Please enter a positive year.\n");
        exit(0);
    }

    // Printing travel details for user
    printf("\nTravel details:\n");
    printf("Present day: %d\nPresent month: %d\nPresent year: %d\nTime travel year: %d\n\n", day, month, year, time_travel_year);

    // Calculating travel duration and elapsed time
    int travel_duration = time_travel_year - year;
    int elapsed_days = travel_duration * 365 + (month - 1) * 31 + day;

    // Printing travel duration and elapsed time
    printf("Total travel duration: %d years\n", travel_duration);
    printf("Total travel elapsed time: %d days\n", elapsed_days);

    return 0;
}