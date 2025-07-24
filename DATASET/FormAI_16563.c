//FormAI DATASET v1.0 Category: Weather simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int weatherType, temperature, humidity, windSpeed;
    srand(time(0)); // Generate seed for random values

    printf("Welcome to the Weather Simulation Program!\n");

    // Generate random values for weather variables
    temperature = rand() % 50; // Temperature range from 0 to 50 celcius
    humidity = rand() % 100; // Humidity range from 0% to 100%
    windSpeed = rand() % 100; // Wind speed range from 0 km/h to 100 km/h

    // Determine weather type based on temperature, humidity, and wind speed
    if (temperature >= 30 && humidity >= 60 && windSpeed >= 50) {
        weatherType = 1; // Hurricane
    } else if (temperature >= 25 && humidity >= 70 && windSpeed >= 30) {
        weatherType = 2; // Thunderstorm
    } else if (temperature >= 20 && humidity >= 80 && windSpeed >= 20) {
        weatherType = 3; // Rainy
    } else if (temperature >= 18 && humidity < 80 && windSpeed < 10) {
        weatherType = 4; // Sunny
    } else {
        weatherType = 5; // Cloudy
    }

    // Display weather information based on weather type
    switch (weatherType) {
        case 1:
            printf("Hurricane warning! Temperature: %d C, Humidity: %d%%, Wind Speed: %d km/h\n", temperature, humidity, windSpeed);
            break;
        case 2:
            printf("Thunderstorm warning! Temperature: %d C, Humidity: %d%%, Wind Speed: %d km/h\n", temperature, humidity, windSpeed);
            break;
        case 3:
            printf("Rainy day! Temperature: %d C, Humidity: %d%%, Wind Speed: %d km/h\n", temperature, humidity, windSpeed);
            break;
        case 4:
            printf("Sunny day! Temperature: %d C, Humidity: %d%%, Wind Speed: %d km/h\n", temperature, humidity, windSpeed);
            break;
        case 5:
            printf("Cloudy day Temperature: %d C, Humidity: %d%%, Wind Speed: %d km/h\n", temperature, humidity, windSpeed);
            break;
        default:
            printf("Unknown weather type\n");
            break;
    }

    return 0;
}