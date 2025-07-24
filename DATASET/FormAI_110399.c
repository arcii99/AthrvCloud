//FormAI DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define DAYS_TO_SIMULATE 7

// City structure to hold weather information
typedef struct {
    float temperature;
    int humidity;
    float windSpeed;
} City;

// Function to randomly generate weather data for a city
void generateWeatherDataForCity(City *city) {
    // Generate random temperature
    float temp = (float)rand()/(float)(RAND_MAX/100);
    city->temperature = temp;

    // Generate random humidity
    int humidity = rand() % 101;
    city->humidity = humidity;

    // Generate random wind speed
    float windSpeed = (float)rand()/(float)(RAND_MAX/50);
    city->windSpeed = windSpeed;
}

int main() {
    // Initialize cities
    City cities[NUM_CITIES];

    // Set seed for random number generation
    srand(time(NULL));

    // Generate initial weather data for each city
    for(int i = 0; i < NUM_CITIES; i++) {
        generateWeatherDataForCity(&cities[i]);
    }

    // Simulate weather for each city for a number of days
    for(int day = 1; day <= DAYS_TO_SIMULATE; day++) {
        printf("Day %d\n", day);

        // Simulate weather for each city
        for(int i = 0; i < NUM_CITIES; i++) {
            printf("City %d:\n", i+1);
            printf("\tTemperature: %0.2f\n", cities[i].temperature);
            printf("\tHumidity: %d%%\n", cities[i].humidity);
            printf("\tWind speed: %0.2f mph\n", cities[i].windSpeed);

            // Update weather data for next day
            generateWeatherDataForCity(&cities[i]);
        }

        printf("\n");
    }

    return 0;
}