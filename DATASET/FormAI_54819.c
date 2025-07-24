//FormAI DATASET v1.0 Category: Weather simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TEMP 45
#define MIN_TEMP -10

int main() {
    srand((unsigned int)time(NULL));
    int minTemp = MIN_TEMP, maxTemp = MAX_TEMP;
    int tempArray[24];
    for (int i = 0; i < 24; i++) {
        tempArray[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Hour %d: %d°C\n", i + 1, tempArray[i]);
    }
    int sumTemp = 0;
    float avgTemp;
    for (int i = 0; i < 24; i++) {
        sumTemp += tempArray[i];
    }
    avgTemp = (float)sumTemp / 24;
    printf("\nAverage Temperature of Today: %.2f°C\n", avgTemp);
    for (int i = 0; i < 24; i++) {
        if (tempArray[i] < minTemp) {
            minTemp = tempArray[i];
        }
        if (tempArray[i] > maxTemp) {
            maxTemp = tempArray[i];
        }
    }
    printf("\nMaximum Temperature of Today: %d°C\n", maxTemp);
    printf("Minimum Temperature of Today: %d°C\n", minTemp);
    printf("The weather seems to be ");
    if (avgTemp >= 30) {
        printf("very hot today, stay hydrated!");
    }
    else if (avgTemp >= 20) {
        printf("moderately warm, enjoy the day!");
    }
    else if (avgTemp >= 10) {
        printf("cool and comfortable, get cozy!");
    }
    else {
        printf("very cold today, wrap up warm!");
    }
    return 0;
}