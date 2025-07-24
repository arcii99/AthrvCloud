//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random temperature between -40 and 120 degrees Fahrenheit
    int temp = rand() % 161 - 40;
    
    // Generate a random humidity level between 0 and 100 percent
    int humidity = rand() % 101;
    
    // Determine the weather condition based on the temperature and humidity
    char* condition;
    if (temp < 32) {
        if (humidity >= 70) {
            condition = "snowstorm";
        } else if (humidity >= 50) {
            condition = "snow";
        } else {
            condition = "cold and clear";
        }
    } else if (temp < 50) {
        if (humidity >= 70) {
            condition = "freezing rain";
        } else if (humidity >= 50) {
            condition = "rain";
        } else {
            condition = "cool and clear";
        }
    } else if (temp < 80) {
        if (humidity >= 70) {
            condition = "thunderstorm";
        } else if (humidity >= 50) {
            condition = "cloudy";
        } else {
            condition = "sunny";
        }
    } else {
        if (humidity >= 70) {
            condition = "heat wave";
        } else if (humidity >= 50) {
            condition = "hot and muggy";
        } else {
            condition = "hot and dry";
        }
    }
    
    // Print out the weather report
    printf("Today's weather is %s with a temperature of %d degrees Fahrenheit and a humidity level of %d percent.\n", condition, temp, humidity);
    
    return 0;
}