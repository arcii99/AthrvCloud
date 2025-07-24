//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, windSpeed;
    srand(time(NULL));

    printf("Welcome to the Weather Simulator!\n\n");

    for(int i = 1; i <= 5; i++)
    {
        temperature = rand() % 61 - 20;
        humidity = rand() % 101;
        windSpeed = rand() % 61;

        printf("Day %d:\n", i);
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n\n", windSpeed);
    }

    printf("Thank you for using the Weather Simulator.\n");
    return 0;
}