//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    // Initialize random seed
    srand(time(0)); 

    // Generate random temperature between -10 and 30 degrees Celsius 
    int temp = (rand() % 41) - 10; 

    // Determine weather conditions based on temperature
    if (temp > 25) {
        printf("It's scorching hot out there at %d degrees Celsius!\n", temp);
    } else if (temp > 15) {
        printf("It's a beautiful day with a temperature of %d degrees Celsius.\n", temp);
    } else if (temp > 5) {
        printf("It's a bit chilly outside with a temperature of %d degrees Celsius.\n", temp);
    } else {
        printf("It's freezing cold out there at %d degrees Celsius!\n", temp);
    }

    // Generate random wind speed between 0 and 50 km/h
    int wind_speed = rand() % 51; 

    // Determine wind conditions based on wind speed 
    if (wind_speed > 35) {
        printf("Hold onto your hats! There are gale force winds today with speeds up to %d km/h.\n", wind_speed);
    } else if (wind_speed > 15) {
        printf("It's quite breezy outside with wind speeds up to %d km/h.\n", wind_speed);
    } else {
        printf("There's hardly any wind today with speeds up to %d km/h.\n", wind_speed);
    }

    // Generate random humidity level between 0 and 100%
    int humidity = rand() % 101; 

    // Determine humidity conditions based on humidity level
    if (humidity > 75) {
        printf("It's very humid outside today with a humidity level up to %d%%.\n", humidity);
    } else if (humidity > 50) {
        printf("It's slightly humid outside today with a humidity level up to %d%%.\n", humidity);
    } else {
        printf("It's not very humid at all with a humidity level up to %d%%.\n", humidity);
    }

    return 0; 
}