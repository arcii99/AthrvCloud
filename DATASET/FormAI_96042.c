//FormAI DATASET v1.0 Category: Weather simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // generate random temperature between -10 and 40 degrees Celsius
    int temp = rand() % 51 - 10;

    // generate random wind speed between 0 and 20 meters per second
    int wind_speed = rand() % 21;

    // generate random precipitation type (0: none, 1: rain, 2: snow)
    int precipitation_type = rand() % 3;

    // output current weather conditions
    printf("Temperature: %d degrees Celsius\n", temp);
    printf("Wind speed: %d m/s\n", wind_speed);

    if (precipitation_type == 0) {
        printf("No precipitation\n");
    } else if (precipitation_type == 1) {
        // generate random rainfall amount between 0 and 10 millimeters per hour
        int rainfall_amount = rand() % 11;
        printf("Rainfall: %d mm/hour\n", rainfall_amount);
    } else if (precipitation_type == 2) {
        // generate random snowfall amount between 0 and 20 centimeters per hour
        int snowfall_amount = rand() % 21;
        printf("Snowfall: %d cm/hour\n", snowfall_amount);
    }

    return 0;
}