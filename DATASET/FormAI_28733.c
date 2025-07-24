//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_FORECASTS 5

typedef struct {
    int high; // High temperature in Celsius
    int low; // Low temperature in Celsius
    float precipitation; // Probability of rainfall (0 to 1)
} Forecast;

typedef struct {
    char name[50];
    float latitude;
    float longitude;
    Forecast forecasts[MAX_FORECASTS];
} City;

City cities[MAX_CITIES];

void initializeCities() {
    srand(time(NULL));
    for (int i = 0; i < MAX_CITIES; i++) {
        // Set city name
        sprintf(cities[i].name, "City %d", i+1);
        // Set latitude and longitude within range of -90 to 90 degrees
        cities[i].latitude = (float) (rand() % 181) - 90;
        cities[i].longitude = (float) (rand() % 361) - 180;
        // Generate random forecasts for current and next 4 days
        for (int j = 0; j < MAX_FORECASTS; j++) {
            cities[i].forecasts[j].high = rand() % 21 + 10; // High temperature between 10 to 30 Celsius
            cities[i].forecasts[j].low = rand() % 11; // Low temperature between 0 to 10 Celsius
            cities[i].forecasts[j].precipitation = (float) rand() / RAND_MAX; // Random value between 0 and 1
        }
    }
}

void printCityForecasts(int cityIndex) {
    printf("%s:\n", cities[cityIndex].name);
    for (int i = 0; i < MAX_FORECASTS; i++) {
        printf("Day %d - High: %d C, Low: %d C, Precipitation: %.2f\n", i+1, cities[cityIndex].forecasts[i].high, cities[cityIndex].forecasts[i].low, cities[cityIndex].forecasts[i].precipitation);
    }
    printf("\n");
}

int main() {
    initializeCities();

    printf("Weather forecasts for %d cities:\n\n", MAX_CITIES);
    for (int i = 0; i < MAX_CITIES; i++) {
        printCityForecasts(i);
    }

    return 0;
}