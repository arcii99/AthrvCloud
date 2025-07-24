//FormAI DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, wind_speed;
    srand(time(NULL)); // initializes the random number generator
    
    printf("Welcome to the Weather Simulator!\n\n");
    printf("Today's weather report: \n\n");
    
    // generate random values for temperature, humidity, and wind speed
    temperature = rand() % 50 - 10; // temperature range: -10 to 39 Celsius
    humidity = rand() % 101; // humidity range: 0 to 100%
    wind_speed = rand() % 40; // wind speed range: 0 to 39 km/h
    
    printf("Temperature: %d Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    
    // determine weather conditions based on the generated values
    if (temperature < 0)
    {
        printf("Weather Conditions: Very Cold\n");
    }
    else if (temperature >= 0 && temperature < 10)
    {
        printf("Weather Conditions: Cold\n");
    }
    else if (temperature >= 10 && temperature < 20)
    {
        printf("Weather Conditions: Cool\n");
    }
    else if (temperature >= 20 && temperature < 30)
    {
        printf("Weather Conditions: Mild\n");
    }
    else if (temperature >= 30 && temperature < 40)
    {
        printf("Weather Conditions: Hot\n");
    }
    else
    {
        printf("Weather Conditions: Very Hot\n");
    }
    
    // determine precipitation based on humidity and wind speed
    if (humidity > 80 && wind_speed > 20)
    {
        printf("Precipitation: Heavy Rain\n");
    }
    else if (humidity > 60 && wind_speed > 10)
    {
        printf("Precipitation: Light Rain\n");
    }
    else if (humidity > 40 && wind_speed > 5)
    {
        printf("Precipitation: Drizzle\n");
    }
    else if (humidity < 40 || wind_speed < 5)
    {
        printf("Precipitation: None\n");
    }
    
    printf("\nThank you for using the Weather Simulator!");
    
    return 0;
}