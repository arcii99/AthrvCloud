//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    time(&current_time);
    struct tm* time_info = localtime(&current_time);

    int current_year = time_info->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current year: %d\n", current_year);

    printf("Please enter a year to travel to: ");
    int target_year;
    scanf("%d", &target_year);

    if (target_year < current_year) {
        printf("Sorry, we can only travel to the future!\n");
        return 0;
    }

    int travel_years = target_year - current_year;
    printf("You will travel %d years into the future!\n", travel_years);

    printf("Starting the time machine...\n");

    for (int i = 0; i < travel_years; i++) {
        printf("Year %d...\n", current_year + i + 1);
        printf("...");
        srand(time(NULL));
        int rand_num = rand() % 100 + 1;
        for (int j = 0; j < rand_num; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("Arrived at year %d!\n", target_year);
    printf("Hope you had a surreal time traveling experience! Bye bye!");
    return 0;
}