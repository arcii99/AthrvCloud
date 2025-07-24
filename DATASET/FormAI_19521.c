//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
// C Weather Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    float temperature, humidity, rainfall;
    srand(time(NULL)); //initialize random number generator

    printf("Welcome to the C Weather Simulation Program!\n\n");

    //RNG to generate random weather values
    temperature = (rand() % 30) + 5; //temperature between 5 and 35 degrees Celsius
    humidity = (rand() % 100) + 1; //humidity between 1 and 100 percent
    rainfall = (rand() % 10) / 10.0; //rainfall between 0.0 and 1.0 cm

    //Display weather conditions
    printf("Today's weather conditions:\n");
    printf("Temperature: %0.1f degrees Celsius\n", temperature);
    printf("Humidity: %0.1f percent\n", humidity);
    printf("Rainfall: %0.1f cm\n", rainfall);

    //Weather alerts based on the conditions
    if (temperature >= 30) {
        printf("Heat warning: The temperature is above 30 degrees Celsius!\n");
    }

    if (humidity >= 80) {
        printf("Humidity warning: The humidity is above 80 percent!\n");
    }

    if (rainfall >= 1.0) {
        printf("Rainfall warning: The rainfall is above 1.0 cm!\n");
    }

    //Forecasting the next 3 days weather conditions
    printf("\n\n3 Day Weather Forecast:\n");

    //Loop for 3 days
    for (i = 1; i <= 3; i++) {
        //Generate random weather values for each day
        temperature = (rand() % 20) + 10; //temperature between 10 and 30 degrees Celsius
        humidity = (rand() % 80) + 10; //humidity between 10 and 90 percent
        rainfall = (rand() % 5) / 10.0; //rainfall between 0.0 and 0.5 cm

        //Display weather conditions for each day
        printf("\nDay %d weather conditions:\n", i);
        printf("Temperature: %0.1f degrees Celsius\n", temperature);
        printf("Humidity: %0.1f percent\n", humidity);
        printf("Rainfall: %0.1f cm\n", rainfall);
    }

    return 0;
}