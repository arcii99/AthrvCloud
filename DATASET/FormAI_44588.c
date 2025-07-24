//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_YEARS 10 // Maximum number of years to simulate
#define DAYS_IN_YEAR 365 // Number of days in a typical year
#define MAX_TEMP_CHANGE 10 // Maximum temperature change in a day

// Month names for display purposes
const char *month_names[] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

// Function to generate a random temperature change for a day
int get_random_temp_change() {
    return rand() % (MAX_TEMP_CHANGE * 2 + 1) - MAX_TEMP_CHANGE;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Initialize temperature array with random starting temperatures for each month
    int temperatures[12] = {rand() % 30, rand() % 30, rand() % 30, rand() % 30, rand() % 30, rand() % 30,
                            rand() % 30, rand() % 30, rand() % 30, rand() % 30, rand() % 30, rand() % 30};

    int current_year = 0;

    // Loop through each year of the simulation
    while (current_year < MAX_YEARS) {
        printf("Year %d:\n", current_year + 1);
        int total_rainfall = 0; // Keep track of total rainfall for the year

        // Loop through each month of the year
        for (int i = 0; i < 12; i++) {
            int temp_change = get_random_temp_change(); // Generate random temperature change for the day
            temperatures[i] += temp_change; // Update temperature for the month

            if (temperatures[i] < 0) {
                temperatures[i] = 0; // Ensure that temperature doesn't go below freezing point
            }

            // Generate random rainfall for the month
            int rainfall = rand() % 100;
            total_rainfall += rainfall;
            printf("%s - Temperature: %d C, Rainfall: %d mm\n", month_names[i], temperatures[i], rainfall);
        }

        printf("Total rainfall for the year: %d mm\n", total_rainfall);

        current_year++;
    }

    return 0;
}