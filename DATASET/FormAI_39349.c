//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float simulate_weather(float temperature, int days_left) {
    if (days_left <= 0) {
        return temperature;
    }

    float temperature_change = ((float) rand() / RAND_MAX) - 0.5;
    temperature += temperature_change;

    printf("Day %d temperature: %.1f\n", (5 - days_left), temperature);

    return simulate_weather(temperature, days_left - 1);
}

int main() {
    srand(time(NULL));
    int days = 5;
    float starting_temperature = 20.0;

    printf("Starting temperature: %.1f\n", starting_temperature);
    printf("Forecast for next %d days:\n", days);

    float final_temperature = simulate_weather(starting_temperature, days);

    printf("Final temperature after %d days: %.1f\n", days, final_temperature);

    return 0;
}