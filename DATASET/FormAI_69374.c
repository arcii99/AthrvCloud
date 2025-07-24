//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int temperature, wind_speed, humidity;
    char weather_type[10];

    srand(time(0)); // Seed the randomizer with the current time

    // Generate random values for temperature, wind_speed, and humidity
    temperature = rand() % 101 - 50;  // Temperature ranges from -50°C to 50°C
    wind_speed = rand() % 51;  // Wind speed ranges from 0 km/h to 50 km/h
    humidity = rand() % 101;  // Humidity ranges from 0% to 100%

    // Generate a random weather type based on the temperature, wind_speed, and humidity
    if(temperature < 0)
        strcpy(weather_type, "Snowy");
    else if(temperature > 35)
        strcpy(weather_type, "Heatwave");
    else if(humidity > 70)
        strcpy(weather_type, "Rainy");
    else if(wind_speed > 30)
        strcpy(weather_type, "Windy");
    else
        strcpy(weather_type, "Sunny");

    // Print the weather report
    printf("Temperature: %d°C\nWind Speed: %d km/h\nHumidity: %d%%\n", temperature, wind_speed, humidity);
    printf("Weather: %s\n", weather_type);

    return 0;
}