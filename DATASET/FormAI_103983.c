//FormAI DATASET v1.0 Category: Weather simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, choice;
    char weather[10];

    /* get user inputs */
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &temperature);
    printf("Enter the humidity: ");
    scanf("%d", &humidity);

    /* set weather conditions based on user inputs */
    if (temperature > 25) {
        strcpy(weather, "hot");
    } else if (temperature > 15) {
        if (humidity > 50) {
            strcpy(weather, "cloudy");
        } else {
            strcpy(weather, "sunny");
        }
    } else if (temperature > 5) {
        if (humidity > 70) {
            strcpy(weather, "rainy");
        } else {
            strcpy(weather, "windy");
        }
    } else {
        strcpy(weather, "snowy");
    }

    printf("\n");
    printf("Weather Simulation\n");
    printf("-------------------\n");
    printf("Temperature: %d Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Weather: %s\n", weather);

    return 0;
}