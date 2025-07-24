//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWeather(int temp, int humidity);

int main()
{
    int temp = 0;
    int humidity = 0;

    srand(time(NULL)); // Initialize random number generator

    for(int i = 0; i < 5; i++)
    {
        temp = rand() % 50 + 1; // Generate random temperature between 1 and 50 Celsius
        humidity = rand() % 100 + 1; // Generate random humidity between 1 and 100 percent

        printWeather(temp, humidity);
    }
    
    return 0;
}

void printWeather(int temp, int humidity)
{
    printf("Temperature: %dC\n", temp);
    printf("Humidity: %d%%\n", humidity);

    if(temp >= 35 && humidity >= 75)
    {
        printf("Heatstroke warning! Stay indoors and keep cool.\n");
    }
    else if(temp >= 30 && humidity >= 70)
    {
        printf("Heat warning! Be careful when outdoors and take breaks in the shade.\n");
    }
    else if(temp >= 25 && humidity >= 60)
    {
        printf("Warm and humid. Drink plenty of fluids and stay in shade if possible.\n");
    }
    else
    {
        printf("Mild and comfortable weather.\n");
    }

    printf("\n");
}