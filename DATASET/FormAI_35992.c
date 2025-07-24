//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize variables
    int temperature = 75; // Starting temperature in degrees Fahrenheit
    int humidity = 50; // Starting humidity as a percentage
    char skyConditions[10] = "Clear"; // Starting sky conditions

    // Loop for 24 simulated hours
    for (int i = 0; i < 24; i++) {
        // Generate a random temperature change of up to 5 degrees Fahrenheit
        int tempChange = rand() % 6 - 2;
        temperature += tempChange;

        // Generate a random humidity change of up to 10%
        int humidityChange = rand() % 11 - 5;
        humidity += humidityChange;

        // Determine new sky conditions based on temperature and humidity
        if (temperature >= 90 && humidity >= 70) {
            strcpy(skyConditions, "Hot and humid");
        } else if (temperature >= 80 && humidity >= 50) {
            strcpy(skyConditions, "Partly cloudy");
        } else if (temperature >= 70 && humidity >= 30) {
            strcpy(skyConditions, "Mostly sunny");
        } else if (temperature >= 60 && humidity >= 20) {
            strcpy(skyConditions, "Partly sunny");
        } else {
            strcpy(skyConditions, "Clear");
        }

        // Print the weather conditions for the hour
        printf("Hour %d: Temperature %d°F, Humidity %d%%, Sky Conditions %s\n", i+1, temperature, humidity, skyConditions);
    }

    return 0;
}