//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); // Seed for random number generator
    
    int temperature = rand() % 50; // Random temperature between 0 and 50 degrees Celsius
    int humidity = rand() % 100; // Random humidity percentage
    int chance_of_rain = rand() % 101; // Random chance of rain percentage

    // Output weather information
    printf("Today's weather:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Chance of rain: %d%%\n", chance_of_rain);
    
    // Determine whether it will rain or not
    if(chance_of_rain > 50) {
        printf("It is likely to rain today.\n");
    }
    else {
        printf("It is unlikely to rain today.\n");
    }
    
    return 0;
}