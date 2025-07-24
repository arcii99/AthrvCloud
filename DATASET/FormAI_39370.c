//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp, humidity;
    srand(time(NULL));
    printf("Welcome to the Weather Simulator! \n\n");
    printf("Enter the desired temperature: \n");
    scanf("%d", &temp);
    printf("Enter the desired humidity (in percentage): \n");
    scanf("%d", &humidity);
    printf("\n\n");

    int currentTemp = (rand() % 20) + temp - 10; // Random temperature between temp-10 and temp+10
    int currentHumidity = (rand() % 40) + humidity - 20; // Random humidity between humidity-20 and humidity+20
    printf("Current Temperature: %d \n", currentTemp);
    printf("Current Humidity: %d%%\n", currentHumidity);

    if (currentTemp <= temp-5) {
        printf("\n\n WARNING! Temperature is too low! Please stay indoors and wear warm clothes.\n");
    }
    if (currentTemp >= temp+5) {
        printf("\n\n WARNING! Temperature is too high! Please stay indoors and keep yourself hydrated.\n");
    }
    if (currentHumidity <= humidity-10) {
        printf("\n\n WARNING! Humidity is too low! You may experience dry skin and eyes. Use a humidifier if possible.\n");
    }
    if (currentHumidity >= humidity+10) {
        printf("\n\n WARNING! Humidity is too high! You may experience difficulty in breathing. Use a dehumidifier if possible.\n");
    }

    printf("\n\n Program End. Stay Safe!\n");
    return 0;
}