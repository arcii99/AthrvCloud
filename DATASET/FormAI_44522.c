//FormAI DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp, wind_speed, humidity;

    // Get user inputs
    printf("Enter the temperature (in Celsius): ");
    scanf("%d", &temp);

    printf("Enter the wind speed (in km/h): ");
    scanf("%d", &wind_speed);

    printf("Enter the humidity (in percentage): ");
    scanf("%d", &humidity);

    // Randomize the weather condition based on the user inputs
    srand(time(NULL));
    int condition = rand() % 3; // 0 = sunny, 1 = cloudy, 2 = rainy

    // Check the weather condition based on the user inputs and the randomized condition
    if (temp > 30 && humidity > 60 && condition == 0)
    {
        printf("It's scorching hot and sunny!\n");
    }
    else if (temp > 25 && humidity > 70 && condition == 1)
    {
        printf("It's warm and cloudy.\n");
    }
    else if (temp < 20 && wind_speed > 30 && condition == 2)
    {
        printf("It's cold, windy, and rainy.\n");
    }
    else
    {
        printf("It's a normal day.\n");
    }

    return 0;
}