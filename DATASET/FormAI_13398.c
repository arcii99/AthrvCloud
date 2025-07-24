//FormAI DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Define variables
    int temperature = rand() % 30; // generate random temperature between 0 and 30
    int humidity = rand() % 100; // generate random humidity between 0 and 100
    int windDirection = rand() % 360; // generate random wind direction between 0 and 360 degrees
    int windSpeed = rand() % 100; // generate random wind speed between 0 and 100 mph
    
    // Print weather report
    printf("Today's weather report:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind: %d mph %d degrees\n", windSpeed, windDirection);
    
    // Determine weather condition
    if (temperature >= 25 && humidity >= 70 && windSpeed < 10) {
        printf("Heat wave warning in effect.\n");
    } else if (temperature <= 5 && windSpeed >= 30) {
        printf("Blizzard warning in effect.\n");
    } else if (windSpeed >= 50) {
        printf("Hurricane warning in effect.\n");
    } else if (temperature >= 30 && humidity >= 80) {
        printf("Thunderstorm warning in effect.\n");
    } else {
        printf("No severe weather conditions currently.\n");
    }
    
    return 0;
}