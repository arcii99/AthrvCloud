//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random temperature
int generateTemp(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate weather conditions for a day
void simulateDay(int dayNum)
{
    printf("Day %d\n", dayNum);
    int highTemp = generateTemp(80, 100);
    int lowTemp = generateTemp(50, 70);
    int avgTemp = (highTemp + lowTemp) / 2;

    printf("High Temperature: %d\n", highTemp);
    printf("Low Temperature: %d\n", lowTemp);
    printf("Average Temperature: %d\n", avgTemp);

    if (avgTemp > 85) {
        printf("Warning: It's a hot day! Stay hydrated.\n");
    } else if (avgTemp < 60) {
        printf("Warning: It's a cold day! Wear warm clothes.\n");
    }

    int chanceOfRain = generateTemp(0, 100);
    if (chanceOfRain < 20) {
        printf("Chance of rain: Low\n");
    } else if (chanceOfRain < 60) {
        printf("Chance of rain: Moderate\n");
    } else {
        printf("Chance of rain: High\n");
    }

    printf("*********************************\n");
}

// Main function to simulate weather for a week
int main()
{
    srand(time(NULL)); // Initialize random seed

    printf("********** Weather Report **********\n");

    for (int i = 1; i <= 7; i++) {
        simulateDay(i);
    }

    return 0;
}