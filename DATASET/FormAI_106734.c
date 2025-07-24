//FormAI DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp, humidity, windspeed;

    srand(time(NULL)); // initialize random number generator with current time

    // generate random weather conditions
    temp = rand() % 101 - 50; // generate temperature between -50 and 50 degrees Celsius
    humidity = rand() % 101; // generate humidity between 0 and 100%
    windspeed = rand() % 101; // generate windspeed between 0 and 100 km/h

    // print out the weather conditions
    printf("The current temperature is %d degrees Celsius.\n", temp);
    printf("The current humidity is %d%%.\n", humidity);
    printf("The current windspeed is %d km/h.\n", windspeed);

    // give some simulation feedback
    if (temp > 30 && humidity > 60) {
        printf("It's hot and humid, expect some rain.\n");
    } else if (temp < -20 && windspeed > 50) {
        printf("It's freezing and windy, avoid going outside.\n");
    } else {
        printf("The weather seems fairly normal today.\n");
    }

    return 0;
}