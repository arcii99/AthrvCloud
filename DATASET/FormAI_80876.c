//FormAI DATASET v1.0 Category: Weather simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, cloudiness, wind_speed;
    srand(time(NULL));
    
    temperature = rand() % 50 - 10; // Celsius
    humidity = rand() % 100; // Percent
    cloudiness = rand() % 100; // Percent
    wind_speed = rand() % 50; // Meters per second
    
    printf("Today's weather simulation:\n\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Cloudiness: %d%%\n", cloudiness);
    printf("Wind Speed: %d m/s\n", wind_speed);
    
    return 0;
}