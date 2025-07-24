//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float temperature[1000];
int top = 0;

void getTemperature() {
    float temp = (float)rand()/(float)(RAND_MAX/100.0);
    if (top < 1000) {
        temperature[top++] = temp;
    }
}

float getAverageTemperature() {
    if (top == 0) {
        return -1.0;
    }

    float sum = 0.0;
    for (int i = 0; i < top; i++) {
        sum += temperature[i];
    }

    return sum / top;
}

void printTemperatureStats() {
    float avgTemp = getAverageTemperature();
    if (avgTemp >= 0) {
        printf("Average temperature: %.2f\n", avgTemp);
    }

    printf("Temperature readings: ");
    for (int i = 0; i < top; i++) {
        printf("%.1f ", temperature[i]);
    }

    printf("\n\n");
}

int main() {
    srand(time(0));

    printf("Welcome to the temperature monitor!\n");
    while (1) {
        getTemperature();
        printTemperatureStats();
        sleep(1);
    }

    return 0;
}