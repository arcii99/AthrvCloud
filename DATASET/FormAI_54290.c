//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // set the seed for random number generator

    // define variables for the simulation
    int temperature = 20;
    int humidity = 50;
    int windSpeed = 10;

    // define the simulation loop
    for(int i = 0; i < 7; i++)
    {
        printf("Day %d:\n", i+1);

        // determine the temperature for the day
        int tempChange = rand() % 11 - 5;
        temperature += tempChange;
        printf("Temperature: %d degrees Celsius\n", temperature);

        // determine the humidity for the day
        int humChange = rand() % 11 - 5;
        humidity += humChange;
        printf("Humidity: %d%%\n", humidity);

        // determine the windspeed for the day
        int windChange = rand() % 6 - 2;
        windSpeed += windChange;
        if(windSpeed < 0) windSpeed = 0; // make sure windspeed is not negative
        printf("Wind Speed: %d km/h\n", windSpeed);

        // print a separator line
        printf("--------------------\n");
    }

    return 0;
}