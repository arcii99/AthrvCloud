//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for weather conditions
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define SNOWY 3

// Function prototypes
void printWeather(int weather);
int generateWeather();

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate the weather and print it
    int weather = generateWeather();
    printWeather(weather);

    return 0;
}

void printWeather(int weather)
{
    // Print the weather conditions
    printf("Today's weather is: ");
    switch(weather)
    {
        case SUNNY:
            printf("Sunny\n");
            break;
        case CLOUDY:
            printf("Cloudy\n");
            break;
        case RAINY:
            printf("Rainy\n");
            break;
        case SNOWY:
            printf("Snowy\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

int generateWeather()
{
    // Generate a random number between 0 and 3
    int num = rand() % 4;

    // Return the corresponding weather condition
    switch(num)
    {
        case 0:
            return SUNNY;
        case 1:
            return CLOUDY;
        case 2:
            return RAINY;
        case 3:
            return SNOWY;
        default:
            return -1;
    }
}