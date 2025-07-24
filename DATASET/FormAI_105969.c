//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up variables for weather simulation
    int temperature, wind_speed, humidity, pressure;
    srand(time(NULL)); // Set seed for random number generation

    // Main loop for weather simulation
    for(int i=0; i<10; i++) {
        // Generate random weather conditions
        temperature = rand() % 41 - 20; // Temperature between -20°C to 20°C
        wind_speed = rand() % 201; // Wind speed between 0 to 200 km/h
        humidity = rand() % 101; // Humidity between 0% to 100%
        pressure = rand() % 400 + 900; // Pressure between 900 to 1300 hPa

        // Output weather conditions
        printf("Day %d\n", i+1);
        printf("Temperature: %d°C\n", temperature);
        printf("Wind speed: %d km/h\n", wind_speed);
        printf("Humidity: %d%%\n", humidity);
        printf("Pressure: %d hPa\n", pressure);

        // Adjust temperature based on humidity and pressure
        if (pressure < 1000) {
            temperature -= 10; // Decrease temperature by 10°C for low pressure
        }
        if (humidity > 75) {
            temperature += 5; // Increase temperature by 5°C for high humidity
        }

        // Adjust pressure based on wind speed
        if (wind_speed > 150) {
            pressure -= 50; // Decrease pressure by 50 hPa for high winds
        } else if (wind_speed > 100) {
            pressure -= 20; // Decrease pressure by 20 hPa for moderate winds
        }

        // Output adjusted conditions
        printf("Adjusted temperature: %d°C\n", temperature);
        printf("Adjusted pressure: %d hPa\n", pressure);
        printf("\n");
    }
    return 0;
}