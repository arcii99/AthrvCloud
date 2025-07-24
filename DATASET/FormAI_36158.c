//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 31
#define MIN_TEMP -20
#define MAX_TEMP 40
#define NUM_LOCATIONS 5

int getRandTemp(int minTemp, int maxTemp);
void initializeTemperatures(int temperatures[NUM_LOCATIONS][MAX_DAYS]);
void printTemperatures(int temperatures[NUM_LOCATIONS][MAX_DAYS]);

int main() {
    srand(time(NULL)); // seed for random generator
    int temperatures[NUM_LOCATIONS][MAX_DAYS]; // array to hold temperatures for each location

    initializeTemperatures(temperatures);
    printTemperatures(temperatures);

    return 0;
}

int getRandTemp(int minTemp, int maxTemp) {
    int randTemp = rand() % (maxTemp - minTemp + 1) + minTemp;
    return randTemp;
}

void initializeTemperatures(int temperatures[NUM_LOCATIONS][MAX_DAYS]) {
    for(int i = 0; i < NUM_LOCATIONS; i++) {
        for(int j = 0; j < MAX_DAYS; j++) {
            temperatures[i][j] = getRandTemp(MIN_TEMP, MAX_TEMP);
        }
    }
}

void printTemperatures(int temperatures[NUM_LOCATIONS][MAX_DAYS]) {
    printf("Temperatures for the month:\n\n");
    for(int i = 0; i < NUM_LOCATIONS; i++) {
        printf("Location #%d:\n", i+1);
        for(int j = 0; j < MAX_DAYS; j++) {
            printf("Day %2d: %2d°C\n", j+1, temperatures[i][j]);
        }
        printf("\n");
    }
}