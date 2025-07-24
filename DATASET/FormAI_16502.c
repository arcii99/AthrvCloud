//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, wind_speed, chance_of_rain, chance_of_snow;

    // Use the time function to seed the random number generator
    srand(time(NULL));

    // Generate random weather conditions
    temperature = rand() % 60 - 40; // Range: -40C to 20C
    humidity = rand() % 101; // Range: 0% to 100%
    wind_speed = rand() % 91; // Range: 0 km/h to 90 km/h
    chance_of_rain = rand() % 101; // Range: 0% to 100%
    chance_of_snow = rand() % 101; // Range: 0% to 100%

    printf("Today's weather conditions:\n\n");

    // Print temperature
    printf("Temperature: %d degrees Celsius\n", temperature);

    // Print humidity
    printf("Humidity: %d%%\n", humidity);

    // Print wind speed
    printf("Wind speed: %d km/h\n", wind_speed);

    // Print chance of rain
    printf("Chance of rain: %d%%\n", chance_of_rain);

    // Print chance of snow
    printf("Chance of snow: %d%%\n", chance_of_snow);

    // Determine weather forecast
    if (temperature >= 30 && humidity > 50 && wind_speed < 20 && chance_of_rain < 10) {
        printf("\nThe weather will be sunny and hot today.\n");
    }
    else if (temperature >= 20 && temperature < 30 && humidity > 50 && chance_of_rain < 25 && chance_of_snow < 5) {
        printf("\nThe weather will be partly cloudy with a chance of rain.\n");
    }
    else if (temperature >= 10 && temperature < 20 && humidity > 70 && wind_speed < 50 && chance_of_rain < 50 && chance_of_snow < 10) {
        printf("\nThe weather will be cloudy with a chance of rain.\n");
    }
    else if (temperature >= 0 && temperature < 10 && humidity > 80 && wind_speed > 30 && chance_of_rain < 75 && chance_of_snow < 50) {
        printf("\nThe weather will be cold and windy with a chance of snow.\n");
    }
    else if (temperature < 0 && humidity > 90 && wind_speed > 60 && chance_of_snow > 75) {
        printf("\nThe weather will be very cold and blizzard conditions are expected.\n");
    }
    else {
        printf("\nThe weather conditions are unpredictable.\n");
    }

    return 0;
}