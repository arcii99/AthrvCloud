//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Generate random temperature between -10 and 40 degrees Celsius
    int temp = (rand() % 51) - 10;
    
    // Generate random wind speed between 0 and 30 km/h
    int wind_speed = rand() % 31;
    
    // Generate random humidity between 0% and 100%
    int humidity = rand() % 101;
    
    // Simulate weather conditions for a few cities
    printf("Weather Simulation\n");
    printf("==================\n");
    printf("\n");
    
    printf("Vancouver, Canada\n");
    printf("Temperature: %d C\n", temp);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Humidity: %d %%\n", humidity);
    printf("\n");
    
    printf("Los Angeles, USA\n");
    printf("Temperature: %d C\n", temp);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Humidity: %d %%\n", humidity);
    printf("\n");
    
    printf("Tokyo, Japan\n");
    printf("Temperature: %d C\n", temp);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Humidity: %d %%\n", humidity);
    
    return 0; // End program
}