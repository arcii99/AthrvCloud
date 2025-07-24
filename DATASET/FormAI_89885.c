//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature;
    int humidity;
    int wind_speed;
    int pressure;
    int precipitation;
    char weather_condition[20];

    srand(time(NULL)); //seed the random number generator with current time

    //generate random values for weather parameters
    temperature = rand() % 61 - 30; //range: -30 to 30 Celsius
    humidity = rand() % 101; //range: 0% to 100%
    wind_speed = rand() % 101; //range: 0km/h to 100km/h
    pressure = rand() % 1001 + 900; //range: 900hPa to 1900hPa
    precipitation = rand() % 101; //range: 0mm to 100mm

    //determine weather condition based on temperature and precipitation
    if (temperature < 0)
        strcpy(weather_condition, "snow");
    else if (temperature >= 0 && temperature < 10)
        if (precipitation > 50)
            strcpy(weather_condition, "sleet");
        else
            strcpy(weather_condition, "drizzle");
    else if (temperature >= 10 && temperature < 20)
        if (precipitation > 50)
            strcpy(weather_condition, "heavy rain");
        else
            strcpy(weather_condition, "light rain");
    else
        if (precipitation > 50)
            strcpy(weather_condition, "thunderstorm");
        else
            strcpy(weather_condition, "clear sky");

    //output weather information
    printf("Temperature: %d Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %dkm/h\n", wind_speed);
    printf("Pressure: %dhPa\n", pressure);
    printf("Precipitation: %dmm\n", precipitation);
    printf("Weather Condition: %s\n", weather_condition);

    return 0;
}