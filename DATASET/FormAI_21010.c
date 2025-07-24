//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator with current time
    srand(time(0));
    
    int temperature, humidity, windSpeed, rainfall;
    
    // generate random values for weather parameters between their respective ranges
    temperature = rand() % 30 - 10; // -10 to 20 degree Celsius
    humidity = rand() % 100; // 0 to 100 percent
    windSpeed = rand() % 50; // 0 to 50 km/h
    rainfall = rand() % 50; // 0 to 50 mm
    
    printf("Today's weather simulation:\n");
    printf("Temperature: %d degree Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", windSpeed);
    printf("Rainfall: %d mm\n", rainfall);
    
    // print weather conditions based on values of weather parameters
    if (temperature <= 0) {
        printf("Freezing conditions, wear warm clothes and stay indoors.\n");
    } else if (temperature > 0 && temperature <= 10) {
        printf("Cold conditions, wear layered clothes.\n");
    } else if (temperature > 10 && temperature <= 20) {
        printf("Cool conditions, wear light clothes.\n");
    } else if (temperature > 20 && temperature <= 30) {
        printf("Warm conditions, wear sunscreen and stay hydrated.\n");
    } else {
        printf("Hot conditions, avoid direct sunlight and stay hydrated.\n");
    }
    
    if (humidity <= 30) {
        printf("Dry conditions, use moisturizer and drink water regularly.\n");
    } else if (humidity > 30 && humidity <= 70) {
        printf("Moderate humidity, no special precautions needed.\n");
    } else {
        printf("High humidity, avoid heavy physical activity and stay in cool places.\n");
    }
    
    if (windSpeed <= 5) {
        printf("Calm wind conditions, no special precautions needed.\n");
    } else if (windSpeed > 5 && windSpeed <= 25) {
        printf("Moderate wind conditions, secure loose objects and avoid high places.\n");
    } else {
        printf("High wind conditions, stay away from outdoor activities and secure windows and doors.\n");
    }
    
    if (rainfall == 0) {
        printf("No rainfall, enjoy the weather!\n");
    } else if (rainfall > 0 && rainfall <= 10) {
        printf("Light rainfall, use umbrella and raincoat.\n");
    } else if (rainfall > 10 && rainfall <= 30) {
        printf("Moderate rainfall, avoid low lying areas and traffic.\n");
    } else {
        printf("Heavy rainfall, stay indoors and avoid all outdoor activities.\n");
    }
    
    return 0;
}