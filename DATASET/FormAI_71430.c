//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>

int main() {
    int current_year, target_year, increment, year_difference, i;
    current_year = 2021; // set current year to 2021
    increment = 5; // set time increment to 5 years
    printf("Enter target year: ");
    scanf("%d", &target_year);
    year_difference = target_year - current_year; // calculate year difference between current year and target year
    printf("Jumping through time from %d to %d in %d year increments:\n", current_year, target_year, increment);
    if (year_difference > 0) {
        for (i = 0; i <= year_difference; i += increment) {
            printf("%d\n", current_year + i);
        }
    } else if (year_difference < 0) {
        for (i = 0; i >= year_difference; i -= increment) {
            printf("%d\n", current_year + i);
        }
    } else {
        printf("%d\n", current_year);
    }
    return 0;
}