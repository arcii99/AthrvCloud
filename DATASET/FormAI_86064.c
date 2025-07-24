//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, wind_speed;
    int max_temp = 35, max_humidity = 100, max_wind_speed = 30;
    srand(time(NULL));
    temperature = rand() % (max_temp - 10 + 1) + 10; // Generating random temperature between 10 to 35 degree Celsius
    humidity = rand() % (max_humidity + 1); // Generating random humidity between 0 to 100 percent
    wind_speed = rand() % (max_wind_speed + 1); // Generating random wind speed between 0 to 30 km/h
    
    printf("Today's weather simulation: \n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    
    if(temperature > 30 && wind_speed < 20 && humidity < 70) // Checking for hot and calm weather conditions
    {
        printf("It is hot and calm today! Stay hydrated and indoors if possible.\n");
    }
    else if(temperature < 20 && humidity > 80) // Checking for cold and humid weather conditions
    {
        printf("It is cold and humid today! Don't forget to carry an umbrella and wear warm clothes.\n");
    }
    else // If neither of the above conditions satisfy
    {
        printf("Looks like a pleasant day today! Enjoy the weather.\n");
    }
    
    return 0;
}