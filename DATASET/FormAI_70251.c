//FormAI DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    int temperature = 70 + (rand() % 31); // Generate a random temperature between 70 and 100 degrees Fahrenheit
    float humidity = (rand() % 51) / 100.0; // Generate a random humidity between 0.0 and 0.5
    float wind_speed = 5.0 + (rand() % 16); // Generate a random wind speed between 5 and 20 mph

    printf("Current weather conditions:\n");
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Humidity: %.2f\n", humidity);
    printf("Wind Speed: %.2f mph\n", wind_speed);

    return 0;
}