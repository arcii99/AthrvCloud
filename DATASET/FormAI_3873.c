//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set the seed for the random generator

    int temperature = 20;
    int humidity = 60;
    int airPollution = 50;

    printf("Welcome to the Cyberpunk Weather Simulator!\n\n");

    for (int i = 0; i < 10; i++) {
        printf("DAY %d\n", i+1);

        int tempChange = rand() % 11 - 5; // Random temperature change between -5 and 5 degrees
        temperature += tempChange;

        int humChange = rand() % 11 - 5; // Random humidity change between -5 and 5%
        humidity += humChange;

        int apChange = rand() % 11 - 5; // Random air pollution change between -5 and 5%
        airPollution += apChange;

        // Limit the values to between 0 and 100
        temperature = temperature < 0 ? 0 : temperature > 100 ? 100 : temperature;
        humidity = humidity < 0 ? 0 : humidity > 100 ? 100 : humidity;
        airPollution = airPollution < 0 ? 0 : airPollution > 100 ? 100 : airPollution;

        printf("Temperature: %dC\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Air Pollution: %d%%\n", airPollution);

        // Determine the weather conditions based on the values
        if (temperature <= 5) {
            printf("Conditions: Freezing\n");
        } else if (temperature < 15 && humidity > 75) {
            printf("Conditions: Foggy\n");
        } else if (temperature < 20 && humidity > 85) {
            printf("Conditions: Rainy\n");
        } else if (temperature > 35 && humidity < 30 && airPollution < 40) {
            printf("Conditions: Scorching\n");
        } else if (airPollution > 70 && humidity < 50) {
            printf("Conditions: Smoggy\n");
        } else {
            printf("Conditions: Normal\n");
        }

        printf("\n");
    }

    printf("Thank you for using the Cyberpunk Weather Simulator!");

    return 0;
}