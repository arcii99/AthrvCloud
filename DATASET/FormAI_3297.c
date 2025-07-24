//FormAI DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Generate a different seed for rand every time the program runs using the current time 
    int temperature = rand() % 100; // Generate a random temperature between 0 and 100 degrees Celsius
    int humidity = rand() % 100; // Generate a random humidity between 0% and 100%
    int chanceOfRain = rand() % 100; // Generate a random chance of rain between 0% and 100%

    // Print out the current weather conditions
    printf("Today's weather conditions:\n");
    printf("Temperature: %dC\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Chance of rain: %d%%\n", chanceOfRain);

    // Determine what type of weather is occurring based on the current conditions 
    if (temperature >= 30 && humidity >= 80 && chanceOfRain >= 50) {
        printf("It's hot and muggy with a high chance of thunderstorms.\n");
    } else if (temperature >= 30 && humidity >= 80 && chanceOfRain < 50) {
        printf("It's hot and muggy, but there's a chance it will stay dry.\n");
    } else if (temperature >= 30 && humidity < 80 && chanceOfRain >= 50) {
        printf("It's hot and humid with a high chance of thunderstorms.\n");
    } else if (temperature >= 30 && humidity < 80 && chanceOfRain < 50) {
        printf("It's hot and dry, but there's a chance it will rain.\n");
    } else if (temperature < 30 && humidity >= 80 && chanceOfRain >= 50) {
        printf("It's cool and muggy with a high chance of thunderstorms.\n");
    } else if (temperature < 30 && humidity >= 80 && chanceOfRain < 50) {
        printf("It's cool and muggy with the possibility of dry weather.\n");
    } else if (temperature < 30 && humidity < 80 && chanceOfRain >= 50) {
        printf("It's cool and humid with a high chance of rain.\n");
    } else if (temperature < 30 && humidity < 80 && chanceOfRain < 50) {
        printf("It's cool and dry, but there's a chance it might rain.\n");
    }

    return 0;
}