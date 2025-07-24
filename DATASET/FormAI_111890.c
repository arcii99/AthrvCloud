//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#define DAYS 7
#define HOURS 24

int main(void) {
    int temperature[DAYS][HOURS];
    int maxTemp = 0, minTemp = 100, totalTemp = 0, averageTemp;
    int maxDay, minDay, day, hour;

    // Simulating temperature for the week
    printf("Simulating temperature for the week...\n");
    for (day = 0; day < DAYS; day++) {
        for (hour = 0; hour < HOURS; hour++) {
            temperature[day][hour] = rand() % 35;
            printf("Day %d, Hour %d: %d°C\n", day + 1, hour + 1, temperature[day][hour]);
        }
    }

    // Finding maximum and minimum temperature and their respective days
    for (day = 0; day < DAYS; day++) {
        for (hour = 0; hour < HOURS; hour++) {
            if (temperature[day][hour] > maxTemp) {
                maxTemp = temperature[day][hour];
                maxDay = day + 1;
            }
            if (temperature[day][hour] < minTemp) {
                minTemp = temperature[day][hour];
                minDay = day + 1;
            }
            totalTemp += temperature[day][hour];
        }
    }

    // Calculating average temperature for the week
    averageTemp = totalTemp / (DAYS * HOURS);

    // Printing weather report
    printf("\nWeather report for the week:\n");
    printf("Maximum temperature: %d°C on Day %d\n", maxTemp, maxDay);
    printf("Minimum temperature: %d°C on Day %d\n", minTemp, minDay);
    printf("Average temperature: %d°C\n", averageTemp);

    return 0;
}