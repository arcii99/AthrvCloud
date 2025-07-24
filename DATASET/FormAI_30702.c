//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void weatherSim(int day, int temp, int humidity, int windSpeed) {
    // base case
    if (day > 365) {
        return;
    } else {
        printf("Day %d - Temperature: %d degrees Fahrenheit, Humidity: %d%%, Wind Speed: %dmph\n", day, temp, humidity, windSpeed);
        // recursive calls with random values for temperature, humidity, and wind speed
        weatherSim(day+1, (rand() % 50) + 10, (rand() % 70) + 30, (rand() % 10) + 5);
    }
}

int main() {
    srand(time(NULL));
    // starting values for temperature, humidity, and wind speed
    int temp = 50;
    int humidity = 50;
    int windSpeed = 10;
    // calling the recursive function to simulate a year of weather
    weatherSim(1, temp, humidity, windSpeed);
    return 0;
}