//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP -10
#define MAX_TEMP 40
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int temperature, humidity, i;
    char *weather;

    printf("Welcome to the weather simulation program!\n");

    for (i = 0; i < 7; i++) { // simulate the next 7 days
        temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // generate a random temperature between MIN_TEMP and MAX_TEMP
        humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY; // generate a random humidity between MIN_HUMIDITY and MAX_HUMIDITY

        // determine the weather based on temperature and humidity
        if (temperature < 0) {
            weather = "freezing";
        } else if (temperature < 10 && humidity > 80) {
            weather = "cold and rainy";
        } else if (temperature < 10) {
            weather = "cold";
        } else if (temperature < 20) {
            weather = "moderate";
        } else if (temperature < 30) {
            weather = "warm";
        } else if (temperature < 40 && humidity < 50) {
            weather = "hot and dry";
        } else if (temperature < 40) {
            weather = "hot and humid";
        } else {
            weather = "scorching";
        }

        printf("Day %d: Temperature: %d°C, Humidity: %d%%, Weather: %s\n", i+1, temperature, humidity, weather);
    }

    return 0;
}