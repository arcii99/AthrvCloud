//FormAI DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50   //maximum temperature (in Celsius)
#define MIN_TEMP 10   //minimum temperature (in Celsius)

int main()
{
    int temperature;
    char weather_condition[20];
    srand(time(0));

    temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    if(temperature <= 15)
    {
        strcpy(weather_condition, "Cold");
    }
    else if(temperature >= 16 && temperature <= 25)
    {
        strcpy(weather_condition, "Moderate");
    }
    else if(temperature >= 26 && temperature <= 35)
    {
        strcpy(weather_condition, "Warm");
    }
    else
    {
        strcpy(weather_condition, "Hot");
    }

    printf("The temperature today is %d C and the weather condition is %s.\n", temperature, weather_condition);

    return 0;
}