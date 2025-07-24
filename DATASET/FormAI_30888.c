//FormAI DATASET v1.0 Category: Weather simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random seed with time
    srand(time(NULL));

    // Set variables for temperature and precipitation
    int temp = 70;
    int rain_chance = 0;

    printf("Welcome to your weather simulation!\n\n");

    // Loop through 7 days
    for (int i = 1; i <= 7; i++) {
        printf("Day %d:\n", i);

        // Get random chance of rain between 0 and 100
        rain_chance = rand() % 101;

        // Determine if it will rain or not based on chance 
        if (rain_chance <= 30) {
            printf("It will rain today.\n");
        } else {
            printf("It will not rain today.\n");
        }

        // Get random temperature between 60 and 80 degrees
        temp = rand() % 21 + 60;

        printf("The temperature today is %d degrees.\n\n", temp);
    }

    printf("Thanks for using your weather simulation!\n");
    return 0;
}