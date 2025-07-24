//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // declare variables
    int minTemp = -10;
    int maxTemp = 40;
    int minHumidity = 30;
    int maxHumidity = 90;
    int minPressure = 980;
    int maxPressure = 1050;
    int currTemp, currHumidity, currPressure;
    int i;

    // simulate weather for the next 7 days
    for(i=1; i<=7; i++)
    {
        // generate random weather variables
        currTemp = rand() % (maxTemp - minTemp + 1) + minTemp;
        currHumidity = rand() % (maxHumidity - minHumidity + 1) + minHumidity;
        currPressure = rand() % (maxPressure - minPressure + 1) + minPressure;

        // output weather information
        printf("Day %d:\n", i);
        printf("Temperature: %d degrees Celsius\n", currTemp);
        printf("Humidity: %d%%\n", currHumidity);
        printf("Pressure: %d hPa\n\n", currPressure);
    }

    return 0;
}