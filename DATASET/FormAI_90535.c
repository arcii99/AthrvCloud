//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator

    int days = 30; // simulation for 30 days
    float temp_max = 40.0; // maximum temperature in celsius
    float pressure_max = 1500.0; // maximum air pressure in hPa
    float humidity_max = 100.0; // maximum humidity in percentage

    float temp_avg = 30.0; // average temperature in celsius
    float pressure_avg = 1000.0; // average air pressure in hPa
    float humidity_avg = 50.0; // average humidity in percentage

    // simulate weather conditions for each day
    for(int i=1; i<=days; i++)
    {
        // generate random weather values
        float temp = ((float)rand()/(float)(RAND_MAX)) * temp_max; // temperature 
        float pressure = ((float)rand()/(float)(RAND_MAX)) * pressure_max; // air pressure
        float humidity = ((float)rand()/(float)(RAND_MAX)) * humidity_max; // humidity

        // calculate deviation from average values
        float temp_dev = temp - temp_avg; // temperature deviation
        float pressure_dev = pressure - pressure_avg; // air pressure deviation
        float humidity_dev = humidity - humidity_avg; // humidity deviation

        // output the weather conditions for the day
        printf("Day %d - Temperature: %.2fC (%+.2fC), Pressure: %.2fhPa (%+.2fhPa), Humidity: %.2f%% (%+.2f%%)\n", i, temp, temp_dev, pressure, pressure_dev, humidity, humidity_dev);
    }

    return 0;
}