//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 60 - 20; // generate temperature between -20 and 40 degrees Celsius
    int humidity = rand() % 100; // generate humidity between 0 and 100 percent
    float pressure = 1000 + (float)rand() / RAND_MAX * (1100 - 1000); // generate pressure between 1000 and 1100 millibars
    char sky_conditions[10];
    int cloudy = rand() % 2; // randomly determine if it is cloudy or not
    if (cloudy) {
        strcpy(sky_conditions, "Cloudy");
    } else {
        strcpy(sky_conditions, "Sunny");
    }
    printf("Today's weather report:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Pressure: %.2f millibars\n", pressure);
    printf("Sky conditions: %s\n", sky_conditions);
    return 0;
}