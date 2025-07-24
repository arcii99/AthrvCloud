//FormAI DATASET v1.0 Category: Weather simulation ; Style: ephemeral
#include <stdio.h>    // standard input/output library
#include <stdlib.h>   // standard library
#include <time.h>     // time library

int main() {
    srand(time(NULL));  // set random seed

    // generate random temperature in Celsius
    int temp_celsius = (rand() % 34) - 10;

    // convert Celsius to Fahrenheit
    float temp_fahrenheit = (temp_celsius * 9/5.0) + 32;

    // set chance of precipitation as a percentage
    int chance_of_precipitation = rand() % 101;

    // randomly set sky conditions
    char* sky_conditions;
    int rand_int = rand() % 4;
    switch(rand_int) {
        case 0:
            sky_conditions = "Clear";
            break;
        case 1:
            sky_conditions = "Partly Cloudy";
            break;
        case 2:
            sky_conditions = "Mostly Cloudy";
            break;
        case 3:
            sky_conditions = "Overcast";
            break;
    }

    // output the weather simulation
    printf("Today's weather is: \n");
    printf("Temperature: %d degrees Celsius, or %.1f degrees Fahrenheit \n", temp_celsius, temp_fahrenheit);
    printf("Sky conditions: %s \n", sky_conditions);
    printf("Chance of precipitation: %d%% \n", chance_of_precipitation);

    return 0;
}