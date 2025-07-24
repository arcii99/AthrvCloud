//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature between 10 to 30 degrees Celsius
int generateTemperature() {
    int temp = (rand() % 21) + 10;  // Generate random number from 0 to 20 and add 10 to get range from 10 to 30 degrees Celsius
    return temp;
}

// Function to generate random humidity between 40 to 80 percent
int generateHumidity() {
    int humidity = (rand() % 41) + 40;  // Generate random number from 0 to 40 and add 40 to get range from 40 to 80 percent humidity
    return humidity;
}

int main() {
    srand(time(NULL));  // Seed random number generator with current time

    int currentTemp = generateTemperature();
    int currentHumidity = generateHumidity();

    printf("Current weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", currentTemp);
    printf("Humidity: %d percent\n", currentHumidity);

    if (currentTemp >= 25 && currentHumidity >= 60) {
        printf("It's hot and humid today. You might want to stay indoors.\n");
    } else if (currentTemp <= 15 && currentHumidity >= 70) {
        printf("It's cold and damp today. You might want to wear something warm.\n");
    } else {
        printf("It's a nice day outside. Enjoy it!\n");
    }

    return 0;
}