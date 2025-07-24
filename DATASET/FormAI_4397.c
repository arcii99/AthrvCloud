//FormAI DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 25 + 10; // Temperature between 10 and 35 degrees Celsius
    int humidity = rand() % 50 + 50; // Humidity between 50% and 100%
    int windSpeed = rand() % 20; // Wind speed between 0 and 20 km/h
    int windDirection = rand() % 360; // Wind direction between 0 and 360 degrees
    
    printf("Welcome to our weather simulation!\n\n");
    printf("Current temperature: %d degrees Celsius\n", temperature);
    printf("Current humidity: %d%%\n", humidity);
    printf("Current wind speed: %d km/h\n", windSpeed);
    printf("Current wind direction: %d degrees\n\n", windDirection);
    
    // Let's generate a weather forecast for the next 7 days
    printf("Weather forecast for the next 7 days:\n\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d:\n", i+1);
        temperature += rand() % 6 - 2; // Temperature change between -2 and 3 degrees Celsius
        if (temperature < 10) temperature = 10;
        if (temperature > 35) temperature = 35;
        printf("Temperature: %d degrees Celsius\n", temperature);
        
        humidity += rand() % 11 - 5; // Humidity change between -5% and 5%
        if (humidity < 50) humidity = 50;
        if (humidity > 100) humidity = 100;
        printf("Humidity: %d%%\n", humidity);
        
        windSpeed += rand() % 6 - 3; // Wind speed change between -3 and 3 km/h
        if (windSpeed < 0) windSpeed = 0;
        if (windSpeed > 20) windSpeed = 20;
        printf("Wind speed: %d km/h\n", windSpeed);
        
        windDirection += rand() % 31 - 15; // Wind direction change between -15 and 15 degrees
        if (windDirection < 0) windDirection += 360;
        if (windDirection > 359) windDirection -= 360;
        printf("Wind direction: %d degrees\n\n", windDirection);
    }
    
    printf("Thank you for using our weather simulation!\n");
    
    return 0;
}