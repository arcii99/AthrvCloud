//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP -50

int main() {
    int current_temp = 0;
    srand(time(NULL)); // Seed the random number generator with system time
    printf("Welcome to Ken's Weather Simulator\n");
    printf("Initializing...\n");

    // Randomly generate current temperature between -50 and 100
    current_temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;

    printf("Current temperature: %d\n", current_temp);

    // Simulate weather changes for 7 days
    for (int i = 1; i <= 7; i++) {
        printf("\nDay %d: \n", i);

        // Randomly generate temperature change between -10 and 10, favoring no change
        int temp_change = rand() % 21 - 10;
        if (temp_change >= -2 && temp_change <= 2) {
            printf("No change in temperature\n");
        } else if (temp_change < -2) {
            printf("Temperature dropped by %d degrees.\n", abs(temp_change));
        } else {
            printf("Temperature rose by %d degrees.\n", temp_change);
        }

        // Update current temperature with temperature change
        current_temp += temp_change;

        // Ensure new temperature is within valid temperature range
        if (current_temp > MAX_TEMP) {
            current_temp = MAX_TEMP;
        } else if (current_temp < MIN_TEMP) {
            current_temp = MIN_TEMP;
        }

        printf("New temperature: %d\n", current_temp);
    }

    printf("\nWeather simulation complete. Thank you for using Ken's Weather Simulator.\n");

    return 0;
}