//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void displayWeather(int temp, int humidity);
void simulateWeather();

int main()
{
    //call the async function to simulate weather
    simulateWeather();

    //wait for the weather simulation to complete
    printf("\n\nWeather simulation is in progress. Please wait...\n\n");
    sleep(10);
    printf("\nWeather simulation completed successfully!\n\n");

    return 0;
}

//function to display weather data on console
void displayWeather(int temp, int humidity)
{
    printf("Temperature: %d%cC\n", temp, 248);
    printf("Humidity: %d%\n", humidity);
}

//the async function to simulate weather
void simulateWeather()
{
    //initialize random generator
    srand(time(NULL));

    //initialize weather variables
    int temp = 0;
    int humidity = 0;

    printf("Starting weather simulation...\n\n");

    //loop through weather simulation
    for(int i = 1; i <= 10; i++)
    {
        //generate random temperature and humidity
        temp = rand() % 20 + 15;
        humidity = rand() % 60 + 40;

        //display weather on console
        printf("Simulation #%d:\n", i);
        displayWeather(temp, humidity);
        printf("------------------------\n");

        //simulating a delay between 1 to 4 seconds
        sleep(rand() % 4 + 1);
    }
}