//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DAYS 7
#define MAX_HOURS 24

int main() {

    // Initializing variables
    int temperature[MAX_DAYS][MAX_HOURS];
    int total_temp = 0;
    int avg_temp = 0;
    int highest_temp = -100;
    int lowest_temp = 100;

    // Generating random temperatures
    srand(time(0));
    for (int i = 0; i < MAX_DAYS; i++) {
        for (int j = 0; j < MAX_HOURS; j++) {
            temperature[i][j] = rand() % 41 - 20; // a temperature range from -20 to 20 degrees Celsius
        }
    }

    // Finding the highest and lowest temperatures
    for (int i = 0; i < MAX_DAYS; i++) {
        for (int j = 0; j < MAX_HOURS; j++) {
            if (temperature[i][j] > highest_temp) {
                highest_temp = temperature[i][j];
            }
            if (temperature[i][j] < lowest_temp) {
                lowest_temp = temperature[i][j];
            }
        }
    }

    // Calculating the total and average temperatures
    for (int i = 0; i < MAX_DAYS; i++) {
        for (int j = 0; j < MAX_HOURS; j++) {
            total_temp += temperature[i][j];
            avg_temp = total_temp / (MAX_DAYS * MAX_HOURS);
        }
    }

    // Displaying the temperatures
    printf("Weather Simulation for the next %d days:\n", MAX_DAYS);
    printf("------------------------------------\n");
    printf("Day/Hour\t|");
    for (int i = 0; i < MAX_HOURS; i++) {
        printf("%d\t", i+1);
    }
    printf("\n");
    printf("------------------------------------\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%d\t\t|", i+1);
        for (int j = 0; j < MAX_HOURS; j++) {
            printf("%d\t", temperature[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
    printf("Highest temperature: %d degrees Celsius\n", highest_temp);
    printf("Lowest temperature: %d degrees Celsius\n", lowest_temp);
    printf("Average temperature: %d degrees Celsius\n", avg_temp);

    return 0;
}