//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random temperature within a given range
double generateTemperature(double minTemp, double maxTemp) {
    double tempRange = maxTemp - minTemp;
    double randomTemp = ((double)rand()/RAND_MAX) * tempRange + minTemp;
    return randomTemp;
}

int main() {
    srand(time(NULL));  // Seed the random number generator using the current time
    double minTemp = 10.0;
    double maxTemp = 30.0;
    double avgTemp = (minTemp + maxTemp) / 2.0;

    printf("Welcome to the Weather Simulator!\n");
    printf("Today's temperature range is %.1f to %.1f degrees Celsius.\n", minTemp, maxTemp);
    printf("The average temperature is %.1f degrees Celsius.\n", avgTemp);
    printf("Press enter to see today's temperature readings:\n");
    getchar();  // Wait for user to press enter

    // Loop to generate and display temperature readings for different times of day
    for (int time = 0; time <= 23; time++) {
        double temp = generateTemperature(minTemp, maxTemp);
        printf("At %02d:00 hours, the temperature is %.1f degrees Celsius.\n", time, temp);
        if (temp < avgTemp) {
            printf("It's colder than average today!\n");
        } else if (temp > avgTemp) {
            printf("It's hotter than average today!\n");
        } else {
            printf("It's exactly the average temperature today!\n");
        }
    }

    return 0;
}