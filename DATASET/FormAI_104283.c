//FormAI DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, windSpeed, rainfall;
    srand(time(NULL)); // initialize random seed based on time
    printf("Weather Simulation:\n\n");
    for(int i = 0; i < 7; i++) { // simulate 7 days of weather
        temperature = rand() % 40; // generate random temperature between 0 and 39 degrees Celsius
        humidity = rand() % 100; // generate random humidity between 0% and 99%
        windSpeed = rand() % 20; // generate random wind speed between 0 and 19 meters per second
        rainfall = rand() % 100; // generate random rainfall between 0mm and 99mm
        printf("Day %d:\nTemperature: %d degC\nHumidity: %d%%\nWind Speed: %d m/s\nRainfall: %d mm\n\n", i+1, temperature, humidity, windSpeed, rainfall);
    }
    return 0;
}