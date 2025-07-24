//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Weather Simulator 1.0!");
    printf("\nPress any key to see the weather conditions...\n");
    getchar();

    srand(time(NULL)); // Set the seed for random number generation

    int temperature = (rand() % 50) - 10; // Generate a random temperature between -10 and 40 degrees Celsius
    int humidity = rand() % 101; // Generate a random humidity between 0 and 100 percent
    int wind_speed = rand() % 101; // Generate a random wind speed between 0 and 100 km/h
    int precipitation = rand() % 101; // Generate a random precipitation amount between 0 and 100 mm

    printf("\nToday's weather conditions:");
    printf("\nTemperature: %d degrees Celsius", temperature);
    printf("\nHumidity: %d percent", humidity);
    printf("\nWind speed: %d km/h", wind_speed);
    printf("\nPrecipitation: %d mm\n", precipitation);

    if (temperature < 0 && precipitation > 50) {
        printf("\nIt's a blizzard! Stay indoors if possible.");
    } else if (temperature < 0 && wind_speed > 80) {
        printf("\nIt's a snowstorm! Travel is not advised.");
    } else if (temperature < 0) {
        printf("\nIt's freezing outside! Bundle up!");
    } else if (temperature > 30 && humidity > 80) {
        printf("\nIt's a tropical rainforest! It's hot and humid out there!");
    } else if (temperature > 30) {
        printf("\nIt's scorching hot outside! Drink plenty of water and stay in the shade!");
    } else if (precipitation > 50) {
        printf("\nIt's pouring cats and dogs! Remember to bring an umbrella.");
    } else if (wind_speed > 80) {
        printf("\nIt's a windy day! Hold onto your hat!");
    } else {
        printf("\nEnjoy the pleasant weather!");
    }

    printf("\nThank you for using Weather Simulator 1.0!");
    return 0;
}