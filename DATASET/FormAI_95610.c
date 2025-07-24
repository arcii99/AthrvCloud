//FormAI DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n\n\t\t[Welcome to Weather Simulator]\n\n");
    printf("Today's weather forecast: ");
    
    srand(time(NULL)); // Randomize seed
    
    int temp = rand() % 50 - 20; // Temperature ranging from -20℃ to 29℃
    int humidity = rand() % 101; // Humidity ranging from 0% to 100%
    int windSpeed = rand() % 101; // Wind speed ranging from 0mph to 100mph
    int precipitation = rand() % 51; // Precipitation ranging from 0mm to 50mm
    int cloudCoverage = rand() % 101; // Cloud coverage ranging from 0% to 100%
    
    if(temp < 0)
        printf("%d℃, frosty.\n", temp);
    else if(temp < 15)
        printf("%d℃, chilly.\n", temp);
    else if(temp < 25)
        printf("%d℃, warm.\n", temp);
    else
        printf("%d℃, hot.\n", temp);
    
    printf("Humidity: %d%%\n", humidity);
    
    if(windSpeed < 10)
        printf("Wind speed: %d mph, breezy.\n", windSpeed);
    else if(windSpeed < 30)
        printf("Wind speed: %d mph, windy.\n", windSpeed);
    else
        printf("Wind speed: %d mph, gale.\n", windSpeed);
        
    if(precipitation < 5)
        printf("Precipitation: %d mm, dry.\n", precipitation);
    else if(precipitation < 20)
        printf("Precipitation: %d mm, light rain.\n", precipitation);
    else if(precipitation < 35)
        printf("Precipitation: %d mm, moderate rain.\n", precipitation);
    else
        printf("Precipitation: %d mm, heavy rain.\n", precipitation);
    
    if(cloudCoverage < 30)
        printf("Cloud coverage: %d%%, clear sky.\n", cloudCoverage);
    else if(cloudCoverage < 70)
        printf("Cloud coverage: %d%%, partly cloudy.\n", cloudCoverage);
    else
        printf("Cloud coverage: %d%%, mostly cloudy.\n", cloudCoverage);
    
    printf("\nThank you for using Weather Simulator.");
    
    return 0;
}