//FormAI DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature[24], i;
    float humidity[24], average_temp, average_hum;
    srand(time(0));
    
    // generate random temperature and humidity data for 24 hours
    for (i = 0; i < 24; i++)
    {
        temperature[i] = (rand() % 20) + 10;  // temperature range from 10 to 30 degrees Celsius
        humidity[i] = (rand() % 50) + 50;     // humidity range from 50 to 100 percent
    }
    
    // calculate average temperature and humidity
    average_temp = 0;
    average_hum = 0;
    
    for (i = 0; i < 24; i++)
    {
        average_temp += temperature[i];
        average_hum += humidity[i];
    }
    
    average_temp /= 24;
    average_hum /= 24;
    
    // print temperature and humidity data
    printf("Weather Simulation Program\n");
    printf("Temperature\tHumidity\n");
    
    for (i = 0; i < 24; i++)
    {
        printf("%d°C\t\t%.0f%%\n", temperature[i], humidity[i]);
    }
    
    // print average temperature and humidity
    printf("Average Temperature: %.1f°C\n", average_temp);
    printf("Average Humidity: %.1f%%\n", average_hum);
    
    return 0;
}