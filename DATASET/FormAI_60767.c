//FormAI DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set the seed for random number generation

    printf("Welcome to the Surreal Weather Simulator\n\n");

    int temperature = rand() % 50 - 20; // generate a random temperature between -20°C and 30°C
    int humidity = rand() % 100; // generate a random humidity between 0% and 100%
    int wind_speed = rand() % 50; // generate a random wind speed between 0 km/h and 50 km/h
    int precipitation_chance = rand() % 100; // generate a random precipitation chance between 0% and 100%

    printf("Current temperature: %d°C\n", temperature);
    printf("Current humidity: %d%%\n", humidity);
    printf("Current wind speed: %d km/h\n", wind_speed);
    printf("Current precipitation chance: %d%%\n", precipitation_chance);

    if (temperature < 0 && precipitation_chance > 50) {
        printf("It's freezing cold outside and it's snowing heavily! Stay warm and safe!\n");
    } else if (temperature < 0) {
        printf("It's freezing cold outside! Don't forget to wear warm clothes!\n");
    } else if (temperature > 30 && precipitation_chance > 50 && humidity > 50) {
        printf("It's scorching hot outside and it's raining cats and dogs! Stay cool and dry!\n");
    } else if (temperature > 30 && humidity > 50) {
        printf("It's scorching hot outside! Don't forget to stay hydrated!\n");
    } else if (temperature > 20 && wind_speed > 30) {
        printf("It's windy outside! Hold on to your hats!\n");
    } else if (precipitation_chance > 50 && humidity > 50) {
        printf("It's raining outside! Don't forget your umbrella!\n");
    } else {
        printf("It's a beautiful day outside! Enjoy the weather!\n");
    }

    return 0;
}