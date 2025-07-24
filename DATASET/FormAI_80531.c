//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
// C Temperature Monitor Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int currentTemperature = 0;
int highestTemperature = 0;
int lowestTemperature = 100;
int totalTemperature = 0;
int readings = 0;

void readTemperature() {
    // Simulate reading temperature from hardware
    srand(time(0));
    currentTemperature = rand() % 100;
    printf("Temperature reading: %d\n", currentTemperature);
}

void updateTemperatures() {
    // Check if current temperature is highest or lowest recorded so far
    if (currentTemperature > highestTemperature) {
        highestTemperature = currentTemperature;
    }
    if (currentTemperature < lowestTemperature) {
        lowestTemperature = currentTemperature;
    }
    // Add current temperature to total and increment readings counter
    totalTemperature += currentTemperature;
    readings++;
}

void printStatistics() {
    // Print current, highest, and lowest temperatures, as well as average temperature
    float averageTemperature = (float) totalTemperature / (float) readings;
    printf("Current Temperature: %d\n", currentTemperature);
    printf("Highest Temperature: %d\n", highestTemperature);
    printf("Lowest Temperature: %d\n", lowestTemperature);
    printf("Average Temperature: %.2f\n", averageTemperature);
}

int main() {
    for (int i = 0; i < 10; i++) {
        readTemperature();
        updateTemperatures();
        printStatistics();
        printf("\n");
    }
    return 0;
}