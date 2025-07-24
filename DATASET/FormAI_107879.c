//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 25;
    int humidity = 70;
    int wind_speed = 20;
    int pressure = 1013;

    printf("Today's weather forecast:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Pressure: %d hPa\n", pressure);

    // Simulate random weather changes
    srand(time(NULL));
    int random_number = rand() % 4; // Generate number between 0 and 3

    if (random_number == 0) {
        printf("Uh-oh, weather alert!\n");
        printf("A thunderstorm is approaching.\n");
        temperature -= 10;
        humidity += 20;
        wind_speed += 30;
        pressure -= 50;
    } else if (random_number == 1) {
        printf("The weather is changing...\n");
        printf("There might be rain later.\n");
        temperature -= 5;
        humidity += 10;
        wind_speed += 10;
        pressure -= 20;
    } else if (random_number == 2) {
        printf("Beautiful day today!\n");
        printf("Enjoy the sunshine.\n");
        temperature += 5;
        humidity -= 10;
        wind_speed -= 5;
        pressure += 10;
    } else {
        printf("The sky is getting dark...\n");
        printf("Looks like a cold front is coming.\n");
        temperature -= 8;
        humidity += 5;
        wind_speed += 15;
        pressure -= 30;
    }

    // Display new weather conditions
    printf("\nUpdated conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Pressure: %d hPa\n", pressure);

    return 0;
}