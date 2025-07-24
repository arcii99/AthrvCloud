//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate weather
void simulateWeather(int initialTemp, int initialHumidity, int initialWindSpeed) {
    int temperature = initialTemp;
    int humidity = initialHumidity;
    int windSpeed = initialWindSpeed;

    // Print initial weather conditions
    printf("Initial weather conditions:\n");
    printf("Temperature: %d\n", temperature);
    printf("Humidity: %d\n", humidity);
    printf("Wind Speed: %d\n\n", windSpeed);

    // Simulate weather for a week
    for(int i=1; i<=7; i++) {
        // Generate random changes in temperature, humidity and wind speed
        int tempChange = rand() % 11 - 5;
        int humidChange = rand() % 31 - 15;
        int windChange = rand() % 11 - 5;

        // Update weather conditions
        temperature += tempChange;
        humidity += humidChange;
        windSpeed += windChange;

        // Make sure values stay within reasonable limits
        if(temperature < -40) temperature = -40;
        if(temperature > 50) temperature = 50;
        if(humidity < 10) humidity = 10;
        if(humidity > 90) humidity = 90;
        if(windSpeed < 0) windSpeed = 0;
        if(windSpeed > 60) windSpeed = 60;

        // Print weather conditions for the day
        printf("Day %d:\n", i);
        printf("Temperature: %d\n", temperature);
        printf("Humidity: %d\n", humidity);
        printf("Wind Speed: %d\n\n", windSpeed);

        // Simulate some delay before next day's weather is simulated
        int delay = rand() % 6;
        sleep(delay);
    }
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Call simulateWeather function with initial weather conditions
    simulateWeather(20, 50, 15);

    return 0;
}