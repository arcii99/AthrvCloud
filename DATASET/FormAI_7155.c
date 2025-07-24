//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program simulates daily weather conditions

int main () {
    int temp, random, day = 0;
    char weather[7][20] = {"Sunny", "Rainy", "Thunderstorm", "Windy", "Cloudy", "Foggy", "Snowy"};

    srand((unsigned) time(NULL)); // Seed the random number generator with the current time
    
    printf("Day\tTemperature (C)\tWeather\n");

    while (day <= 7) { // Loop through 7 days
        temp = rand() % 36; // Generate a random temperature between 0 and 35 degrees Celsius
        random = rand() % 7; // Generate a random number between 0 and 6 to pick a weather condition from the array

        printf("%d\t%d\t\t%s\n", day, temp, weather[random]); // Print the weather conditions for the day

        day++; // Increment the day counter
    }

    return 0; // End the program
}