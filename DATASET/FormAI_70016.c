//FormAI DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double temperature, humidity, pressure, wind_speed, wind_direction_X, wind_direction_Y;
    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate random weather readings within appropriate ranges
    temperature = (rand() % 31) - 10; // Temperatures range from -10 to 20 degrees Celsius
    humidity = (rand() % 71) + 30; // Humidity ranges from 30 to 100 percent
    pressure = (rand() % 126) + 950; // Pressure ranges from 950 to 1075 millibars
    wind_speed = (rand() % 46) + 5; // Wind speed ranges from 5 to 50 kilometers per hour
    wind_direction_X = (rand() % 3) - 1; // Wind direction in the X axis ranges from -1 to 1
    wind_direction_Y = (rand() % 3) - 1; // Wind direction in the Y axis ranges from -1 to 1

    // Print out the weather readings
    printf("Temperature: %.1f Celsius\n", temperature);
    printf("Humidity: %.1f percent\n", humidity);
    printf("Pressure: %.1f millibars\n", pressure);
    printf("Wind Speed: %.1f km/h\n", wind_speed);
    printf("Wind Direction (X, Y): (%.0f, %.0f)\n", wind_direction_X, wind_direction_Y);

    return 0;
}