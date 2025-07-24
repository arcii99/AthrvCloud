//FormAI DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random temperature */
int generateTemperature() {
    int temperature;
    int min = -10;
    int max = 30;

    temperature = (rand() % (max - min + 1)) + min;

    return temperature;
}

/* Function to generate random weather condition */
char *generateWeather() {
    char *weather[] = {"clear", "cloudy", "rainy", "stormy"};
    int randomIndex = rand() % 4;

    return weather[randomIndex];
}

/* Function to print weather report */
void printWeatherReport(int temperature, char *weather) {
    printf("The current weather is %s with a temperature of %d degrees Celsius.\n\n", weather, temperature);
}

/* Main function */
int main() {
    srand(time(NULL)); // Set seed for random function with current time

    int temperature;
    char *weather;

    printf("Welcome to the Medieval Weather Simulator!\n");

    while (1) {
        printf("Press any key to get the latest weather report.\n");
        getchar();

        temperature = generateTemperature();
        weather = generateWeather();

        printWeatherReport(temperature, weather);
    }

    return 0;
}