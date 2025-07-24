//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    // Declare variables
    int temperature = 70;
    int humidity = 50;
    int windspeed = 10;
    char weatherType;

    // Seed the random number generator
    srand(time(NULL));

    // Start the simulation loop
    while (1) {
        // Simulate changes in temperature
        int temperatureChange = rand() % 7 - 3;
        temperature += temperatureChange;

        // Simulate changes in humidity
        int humidityChange = rand() % 17 - 8;
        humidity += humidityChange;

        // Simulate changes in windspeed
        int windspeedChange = rand() % 5 - 2;
        windspeed += windspeedChange;

        // Determine the current weather type based on temperature, humidity, and windspeed
        if (temperature >= 85 && humidity >= 70 && windspeed < 10) {
            weatherType = 'H'; // Hot and humid with light winds
        }
        else if (temperature >= 70 && humidity >= 50 && windspeed < 15) {
            weatherType = 'C'; // Comfortable with light winds
        }
        else if (temperature >= 60 && humidity >= 50 && windspeed >= 15) {
            weatherType = 'W'; // Windy and cool
        }
        else if (temperature < 60 && humidity >= 50 && windspeed < 10) {
            weatherType = 'F'; // Foggy and cool
        }
        else if (temperature < 32) {
            weatherType = 'S'; // Snowy and cold
        }
        // Default to clear with moderate winds
        else {
            weatherType = 'K';
        }

        // Print the current weather values
        printf("Temperature: %d\tHumidity: %d\tWindspeed: %d\tWeather: %c\n", temperature, humidity, windspeed, weatherType);

        // Wait for 2 seconds before updating again
        sleep(2);
    }

    // Exit the program
    return 0;
}