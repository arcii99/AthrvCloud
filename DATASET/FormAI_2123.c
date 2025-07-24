//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Set up variables
    int temperature = 20 + (rand() % 15); // between 20-34 Celsius
    int humidity = rand() % 100; // between 0-99%
    int windSpeed = rand() % 20; // between 0-19 km/h
    int precipitation = rand() % 100; // between 0-99%
    
    // Output the current weather conditions
    printf("Welcome to the cheerful weather simulation!\n\n");
    printf("Here are the current weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Wind Speed: %d km/h\n", windSpeed);
    printf("Precipitation: %d percent\n\n", precipitation);
    
    // Simulate the passage of time
    printf("Now let's simulate the passage of time...\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Hour %d:\n", i+1);
        
        // Adjust temperature and humidity
        int temperatureChange = (rand() % 6) - 2; // between -2 and 3 Celsius
        int humidityChange = (rand() % 11) - 5; // between -5 and 5 percent
        temperature += temperatureChange;
        humidity += humidityChange;
        
        // Adjust wind speed
        int windSpeedChange = (rand() % 5) - 2; // between -2 and 2 km/h
        windSpeed += windSpeedChange;
        
        // Adjust precipitation
        int precipitationChange = (rand() % 11) - 5; // between -5 and 5 percent
        precipitation += precipitationChange;
        
        // Ensure that all variables remain within their valid ranges
        if (temperature < 20) {
            temperature = 20;
        } else if (temperature > 34) {
            temperature = 34;
        }
        if (humidity < 0) {
            humidity = 0;
        } else if (humidity > 100) {
            humidity = 100;
        }
        if (windSpeed < 0) {
            windSpeed = 0;
        } else if (windSpeed > 19) {
            windSpeed = 19;
        }
        if (precipitation < 0) {
            precipitation = 0;
        } else if (precipitation > 100) {
            precipitation = 100;
        }
        
        // Output the new weather conditions
        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d percent\n", humidity);
        printf("Wind Speed: %d km/h\n", windSpeed);
        printf("Precipitation: %d percent\n\n", precipitation);
    }
    
    // Say goodbye
    printf("Thanks for using the cheerful weather simulation! Stay safe and stay hydrated :)\n");
    
    return 0;
}