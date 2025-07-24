//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void weather_simulation(int day, int temperature) {
    if (day == 1) {
        printf("Day 1 temperature: %d degrees Celsius\n", temperature);
    }
    else {
        int today_temperature = temperature + rand() % 6 - 3; // random temperature change within -3 to +3
        printf("Day %d temperature: %d degrees Celsius\n", day, today_temperature);
        weather_simulation(day-1, today_temperature);
    }
}

int main() {
    // set the seed for random number generator
    srand(time(NULL));

    printf("Starting weather simulation...\n");

    // start with a temperature between 20 to 30 degrees Celsius
    int starting_temperature = 20 + rand() % 11;

    // simulate weather for 7 days
    weather_simulation(7, starting_temperature);

    printf("Weather simulation completed.\n");
    return 0;
}