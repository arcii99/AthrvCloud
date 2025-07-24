//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // To generate random numbers based on current time

    float temperature = (float)(rand() % 20 + 10); // Temperature range: 10-30 degree Celsius
    float humidity = (float)(rand() % 50 + 50); // Humidity range: 50-100 percent
    float windspeed = (float)(rand() % 10 + 5); // Wind speed range: 5-15 meters per second
    int precipitation = rand() % 2; // 0 for no precipitation, 1 for precipitation
    
    printf("Today's Weather Report:\n");
    printf("Temperature: %.2f C\n", temperature);
    printf("Humidity: %.2f %%\n", humidity);
    printf("Wind Speed: %.2f m/s\n", windspeed);
    
    if (precipitation == 0)
        printf("No Precipitation Today!\n");
    else
    {
        float rainrate = (float)(rand() % 5 + 1) / 10; // Rain rate range: 0.1-0.5 millimeters per hour
        printf("Rain rate: %.2f mm/hour\n", rainrate);
    }

    return 0;
}