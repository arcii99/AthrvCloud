//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 30

int simulate_weather(int base_temp, int base_humidity, int base_pressure, int day) {
    int temp = base_temp + rand() % 11 - 5;
    int humidity = base_humidity + rand() % 21 - 10;
    int pressure = base_pressure + rand() % 31 - 15;

    printf("Day %d: temperature %d C, humidity %d%%, pressure %d hPa\n", day, temp, humidity, pressure);

    if (temp < 0) {
        printf("Warning: possibility of snow!\n");
    } else if (temp > 30 && humidity > 80) {
        printf("Warning: possibility of thunderstorms!\n");
    } else if (humidity < 20) {
        printf("Warning: possibility of forest fire!\n");
    }

    return temp + humidity + pressure;
}

int main() {
    srand(time(NULL));

    int base_temp = 20;
    int base_humidity = 60;
    int base_pressure = 1000;
    int total_score = 0;

    for (int i = 1; i <= NUM_DAYS; i++) {
        total_score += simulate_weather(base_temp, base_humidity, base_pressure, i);
    }

    printf("Total score for the month: %d\n", total_score);

    if (total_score < 45000) {
        printf("Weather conditions were not optimal this month.\n");
    } else {
        printf("Weather conditions were optimal this month!\n");
    }

    return 0;
}