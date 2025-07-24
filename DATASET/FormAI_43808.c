//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));          // Seed for random number generator
    int temp = rand() % 50;      // Random temperature between 0 and 50 degrees Celsius
    int humidity = rand() % 100; // Random humidity between 0 and 100 percent
    
    printf("CYBERPUNK WEATHER SIMULATION\n");
    printf("==============================\n");
    printf("Temperature: %d°C\n", temp);
    printf("Humidity: %d%%\n\n", humidity);

    if (temp < 10 && humidity < 50) {
        printf("The streets are cold and dry.\n");
        printf("You can see your breath as you walk.\n");
    } else if (temp < 10 && humidity >= 50) {
        printf("The air is cold and damp.\n");
        printf("You can feel the moisture seeping into your bones.\n");
    } else if (temp >= 10 && temp < 20 && humidity < 50) {
        printf("The air is cool and dry.\n");
        printf("It's a nice day for a stroll.\n");
    } else if (temp >= 10 && temp < 20 && humidity >= 50) {
        printf("The air is cool and damp.\n");
        printf("You might want to bring an umbrella.\n");
    } else if (temp >= 20 && temp < 30 && humidity < 50) {
        printf("It's a warm and dry day.\n");
        printf("You can feel the sun on your skin.\n");
    } else if (temp >= 20 && temp < 30 && humidity >= 50) {
        printf("It's a warm and humid day.\n");
        printf("You might want to stay indoors.\n");
    } else if (temp >= 30 && humidity < 50) {
        printf("It's a hot and dry day.\n");
        printf("Drink plenty of water and stay in the shade.\n");
    } else {
        printf("It's a hot and humid day.\n");
        printf("Avoid going outside unless absolutely necessary.\n");
    }

    return 0;
}