//FormAI DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for storing weather data
typedef struct {
    int temperature;
    int wind;
    int humidity;
} weather_data;

// Function to generate random weather data
void generate_weather_data(weather_data* data) {
    // Generate random temperature between -10 and 40 Celsius
    data->temperature = rand() % 51 - 10;
    // Generate random wind speed between 0 and 20 mph
    data->wind = rand() % 21;
    // Generate random humidity level between 0 and 100%
    data->humidity = rand() % 101;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Initialize weather data struct
    weather_data data;
    // Generate random weather data
    generate_weather_data(&data);
    // Print out weather data
    printf("Temperature: %dC\n", data.temperature);
    printf("Wind Speed: %dmph\n", data.wind);
    printf("Humidity: %d%%\n", data.humidity);
    return 0;
}