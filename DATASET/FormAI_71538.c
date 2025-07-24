//FormAI DATASET v1.0 Category: Weather simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h> // For random number generation
#include <time.h>   // For seeding random number generator

// Function to generate random temperature
float generateTemperature() {
    float temperature = (rand() % 41) - 10; // Temperature range: -10°C to 30°C
    return temperature;
}

// Function to generate random wind speed
float generateWindSpeed() {
    float windSpeed = rand() % 61; // Wind speed range: 0 kmph to 60 kmph
    return windSpeed;
}

// Function to generate random humidity
float generateHumidity() {
    float humidity = (rand() % 101) / 100.0; // Humidity range: 0% to 100%
    return humidity;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print simulation start message
    printf("Starting peaceful weather simulation...\n");

    // Loop to simulate 24 hours of weather
    for(int hour = 0; hour < 24; hour++) {
        // Generate weather data for the hour
        float temperature = generateTemperature();
        float windSpeed = generateWindSpeed();
        float humidity = generateHumidity();

        // Print weather data for the hour
        printf("Hour %d: Temperature = %.2f°C, Wind Speed = %.2f kmph, Humidity = %.2f%%\n", hour, temperature, windSpeed, humidity);

        // Sleep for 1 second to simulate passage of time
        sleep(1);
    }

    // Print simulation end message
    printf("Peaceful weather simulation complete!\n");

    return 0;
}