//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    printf("Welcome to the cheerful weather simulator!\n");
    printf("-------------------------------------------\n\n");

    int temperature = rand() % 101 - 50; // Generate a random temperature between -50 and 50

    if (temperature >= 30) {
        printf("It's a scorcher today! The temperature is %d degrees Celsius.\n", temperature);
    } else if (temperature >= 20) {
        printf("It's a beautiful spring day! The temperature is %d degrees Celsius.\n", temperature);
    } else if (temperature >= 10) {
        printf("It's a bit chilly out! The temperature is %d degrees Celsius.\n", temperature);
    } else {
        printf("Brrr, it's freezing! The temperature is %d degrees Celsius.\n", temperature);
    }

    int precipitation_chance = rand() % 101; // Generate a random chance of precipitation between 0 and 100

    if (precipitation_chance >= 80) {
        printf("Looks like it might rain today.\n");
    } else {
        printf("No rain in the forecast today!\n");
    }

    char *wind_directions[] = {"North", "East", "South", "West"}; // Array of wind directions
    int wind_index = rand() % 4; // Generate a random index for wind direction array

    printf("The wind is blowing from the %s today.\n", wind_directions[wind_index]);

    printf("\nThanks for using the cheerful weather simulator! Have a great day!\n");

    return 0;
}