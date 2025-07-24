//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define DAYS 7

int main() {

    srand(time(0)); //seed the random number generator

    char *city_names[NUM_CITIES] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
    int temperatures[NUM_CITIES][DAYS];
    int lowest, highest, range;

    for (int i = 0; i < NUM_CITIES; i++) {
        printf("Generating temperature data for %s\n", city_names[i]);

        for (int j = 0; j < DAYS; j++) {
            temperatures[i][j] = rand() % 75 - 20; //random temperature between -20 and 54 degrees Celsius
        }

        //find the lowest and highest temperatures
        lowest = temperatures[i][0];
        highest = temperatures[i][0];

        for (int j = 1; j < DAYS; j++) {
            if (temperatures[i][j] < lowest) {
                lowest = temperatures[i][j];
            }
            if (temperatures[i][j] > highest) {
                highest = temperatures[i][j];
            }
        }

        range = highest - lowest;

        printf("Data for %s:\n", city_names[i]);
        printf("Lowest temperature: %dC\n", lowest);
        printf("Highest temperature: %dC\n", highest);
        printf("Temperature range: %dC\n\n", range);
    }

    return 0;
}