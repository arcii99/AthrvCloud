//FormAI DATASET v1.0 Category: Weather simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, pressure;
    time_t t;
    srand((unsigned) time(&t));

    // generate random weather values
    temperature = rand() % 51 - 15;  // range from -15°C to 35°C
    humidity = rand() % 101;         // range from 0% to 100%
    pressure = rand() % 501 + 1000;  // range from 1000hPa to 1500hPa

    // display weather report
    printf("Today's weather report:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);

    // determine weather conditions
    if (temperature < 0 && pressure >= 1010 && pressure <= 1030) {
        printf("The weather is cold and mild.\n");
    } else if (temperature < 0 && pressure > 1030) {
        printf("The weather is cold and dry.\n");
    } else if (temperature < 0 && pressure < 1010) {
        printf("The weather is cold and wet.\n");
    } else if (temperature >= 0 && temperature <= 15) {
        printf("The weather is cool and fresh.\n");
    } else if (temperature > 15 && temperature <= 25 && humidity < 75) {
        printf("The weather is warm and sunny.\n");
    } else if (temperature > 15 && temperature <= 25 && humidity >= 75) {
        printf("The weather is warm and humid.\n");
    } else if (temperature > 25 && pressure > 1000 && pressure <= 1020 && humidity < 75) {
        printf("The weather is hot and dry.\n");
    } else if (temperature > 25 && pressure > 1020 && humidity < 75) {
        printf("The weather is hot and sunny.\n");
    } else if (temperature > 25 && pressure <= 1000 && humidity >= 75) {
        printf("The weather is hot and humid.\n");
    } else {
        printf("The weather conditions are unclear.\n");
    }

    return 0;
}