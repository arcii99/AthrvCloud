//FormAI DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, wind_speed, humidity;
    char weather_description[20];
    srand(time(0));
    temperature = rand() % 51 - 10; // temperature range from -10 to 40 degrees Celsius
    wind_speed = rand() % 61; // wind speed range from 0 to 60 km/h
    humidity = rand() % 101; // humidity range from 0 to 100%
    
    if (temperature < -5 && wind_speed >= 40 && humidity >= 80) {
        sprintf(weather_description, "Blizzard");
    } else if (temperature < 0 && wind_speed >= 20 && humidity >= 70) {
        sprintf(weather_description, "Snowstorm");
    } else if (temperature < -5 && wind_speed < 40 && humidity >= 90) {
        sprintf(weather_description, "Snowy");
    } else if (temperature < 10 && wind_speed >= 30 && humidity >= 80) {
        sprintf(weather_description, "Rainy and Windy");
    } else if (temperature >= 10 && temperature < 20 && wind_speed >= 20 && humidity >= 70) {
        sprintf(weather_description, "Rainy");
    } else if (temperature >= 20 && wind_speed >= 20 && humidity >= 70) {
        sprintf(weather_description, "Hot and Humid");
    } else if (temperature < 10 && wind_speed < 30 && humidity >= 70) {
        sprintf(weather_description, "Foggy");
    } else {
        sprintf(weather_description, "Sunny");
    }
    
    printf("Today's weather: %s with a temperature of %d degrees Celsius, a wind speed of %d km/h, and a humidity of %d%%.", weather_description, temperature, wind_speed, humidity);
    
    return 0;
}