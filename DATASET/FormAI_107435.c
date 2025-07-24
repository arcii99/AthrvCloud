//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TEMPERATURE 120
#define MIN_TEMPERATURE -20
#define MAX_WIND_SPEED 50
#define MAX_HUMIDITY 100

int main()
{
    srand(time(NULL));

    int temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    int wind_speed = rand() % (MAX_WIND_SPEED + 1);
    int humidity = rand() % (MAX_HUMIDITY + 1);
    float feels_like_temperature = 0.0;

    printf("Today's Temperature: %dF\n", temperature);
    printf("Wind Speed: %dmph\n", wind_speed);
    printf("Humidity: %d%%\n", humidity);

    if (temperature > 80)
    {
        feels_like_temperature = temperature - (1.5 * humidity / 100 * (temperature - 68));
    }
    else if (temperature < 50)
    {
        feels_like_temperature = temperature + (0.3 * wind_speed) - (0.7 * humidity / 100) + 4;
    }
    else
    {
        feels_like_temperature = temperature + (0.4 * wind_speed) + (0.5 * humidity / 100);
    }

    printf("Feels like: %.2fF\n", feels_like_temperature);

    if (feels_like_temperature > 100)
    {
        printf("It's really hot outside! Stay hydrated and in the shade.\n");
    }
    else if (feels_like_temperature > 80)
    {
        printf("It's a bit warm outside. Wear loose, lightweight clothing and stay in the shade.\n");
    }
    else if (feels_like_temperature > 60)
    {
        printf("It's a nice day outside. Enjoy the weather!\n");
    }
    else if (feels_like_temperature > 40)
    {
        printf("It's a bit chilly outside. Bring a jacket.\n");
    }
    else
    {
        printf("It's really cold outside. Bundle up!\n");
    }

    return 0;
}