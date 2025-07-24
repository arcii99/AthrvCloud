//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generation

    int temperature = rand() % 101 - 50; // Random temperature between -50 and 50 C
    int humidity = rand() % 101; // Random humidity percentage between 0 and 100
    int wind_speed = rand() % 101; // Random wind speed in km/h between 0 and 100
    int clouds = rand() % 101; // Random cloud coverage percentage between 0 and 100

    printf("Today's weather simulation:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Cloud Coverage: %d%%\n", clouds);

    // Determine weather conditions based on the variables
    if (temperature < 0) {
        printf("It's too cold!\n");
    }
    else if (temperature < 20 && humidity > 80) {
        printf("It's warm and humid.\n");
    }
    else if (temperature < 30 && humidity < 50 && wind_speed < 30 && clouds < 50) {
        printf("It's a perfect day!\n");
    }
    else if (temperature >= 30 && humidity > 50 && clouds >= 50) {
        printf("It's hot and humid with a chance of thunderstorms.\n");
    }
    else if (wind_speed > 80) {
        printf("It's very windy!\n");
    }
    else {
        printf("It's just another day.\n");
    }

    return 0;
}