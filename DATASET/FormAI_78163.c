//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator using the current timestamp
    int temperature = rand() % 51 - 10; // random temperature between -10 and 40 degrees Celsius
    char* weather; // variable to hold the weather condition
    switch (rand() % 4) { // random number between 0 and 3 to determine the weather condition
        case 0:
            weather = "sunny";
            break;
        case 1:
            weather = "cloudy";
            break;
        case 2:
            weather = "rainy";
            break;
        case 3:
            weather = "snowy";
            break;
    }
    printf("Today's weather is %s with a temperature of %d degrees Celsius.\n", weather, temperature);
    if (temperature >= 30) { // hot weather
        printf("It's a scorcher out there! Make sure to stay hydrated.\n");
    } else if (temperature >= 20) { // warm weather
        printf("The perfect weather for a picnic or a day at the beach.\n");
    } else if (temperature >= 10) { // cool weather
        printf("A bit nippy outside, make sure to bring a jacket.\n");
    } else { // cold weather
        printf("Bundle up, it's freezing outside!\n");
    }
    return 0; // program completed successfully
}