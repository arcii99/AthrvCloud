//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random number generator
    srand(time(NULL));
    
    // Constants
    const int TEMP_MAX = 40;        // Highest possible temperature
    const int TEMP_MIN = -20;       // Lowest possible temperature
    const int WIND_MAX = 20;        // Highest possible wind speed
    const int WIND_MIN = 0;         // Lowest possible wind speed
    const int HUMIDITY_MAX = 100;   // Highest possible humidity
    const int HUMIDITY_MIN = 0;     // Lowest possible humidity
    
    // Variables
    int temperature, wind_speed, humidity;
    double feels_like;
    
    // Generate random weather data
    temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    wind_speed = rand() % (WIND_MAX - WIND_MIN + 1) + WIND_MIN;
    humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN + 1) + HUMIDITY_MIN;
    
    // Calculate feels like temperature using the formula: 
    feels_like = temperature - (0.131 * wind_speed) * (0.02 * humidity - 1.8);
    
    // Print weather data and feels like temperature
    printf("Temperature: %d\n", temperature);
    printf("Wind Speed: %d\n", wind_speed);
    printf("Humidity: %d\n", humidity);
    printf("Feels Like: %.2f\n", feels_like);
    
    return 0;
}