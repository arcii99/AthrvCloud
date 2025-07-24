//FormAI DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, windSpeed, humidity;
    srand(time(NULL));
    
    // Generate random values for temperature, wind speed and humidity
    temperature = rand() % 61 - 20; // Temperature range: -20°C to 40°C
    windSpeed = rand() % 51; // Wind speed range: 0 to 50 km/h
    humidity = rand() % 101; // Humidity range: 0 to 100%
    
    printf("Welcome to the Weather Simulation App\n\n");
    printf("Today's temperature is %d°C\n", temperature);
    printf("Today's wind speed is %d km/h\n", windSpeed);
    printf("Today's humidity is %d%%\n\n", humidity);
    
    // Determine the weather condition based on the values
    if (temperature < 0) {
        printf("It's freezing cold outside!");
        if (windSpeed > 20) {
            printf(" Better put on some warm clothes and stay indoors.\n");
        } else {
            printf("\n");
        }
    } else if (temperature < 10) {
        printf("It's cold outside, better put on a coat!\n");
    } else if (temperature < 20) {
        printf("The weather is mild today, enjoy the day!\n");
    } else if (temperature < 30) {
        printf("It's getting hot outside, better stay hydrated!\n");
    } else {
        printf("It's scorching hot outside, stay indoors or go to the pool!\n");
    }
    
    // Determine the wind condition based on the values
    if (windSpeed > 30) {
        printf("It's very windy outside, take precautions while driving!\n");
    } else if (windSpeed > 20) {
        printf("It's windy outside, take precautions while driving!\n");
    } else if (windSpeed > 10) {
        printf("There's a gentle breeze, it's a good day to fly a kite!\n");
    } else {
        printf("There's no wind today, enjoy the stillness!\n");
    }
    
    // Determine the humidity condition based on the values
    if (humidity > 80) {
        printf("It's very humid today, better stay in the shade!\n");
    } else if (humidity > 60) {
        printf("It's humid today, better stay hydrated!\n");
    } else if (humidity > 40) {
        printf("The humidity is just right, enjoy the day!\n");
    } else {
        printf("The air is dry today, it's a good day for walking!\n");
    }
    
    return 0;
}