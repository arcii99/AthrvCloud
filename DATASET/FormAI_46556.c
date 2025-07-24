//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, temp;
    float temperature[24], humidity[24], pressure[24];
    time_t current_time;
    struct tm* time_info;
    char time_string[9];
    
    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);
    
    // Seed random number generator
    srand((unsigned) time(NULL));
    
    // Generate random weather data for each hour
    for(i=0; i<24; i++)
    {
        temperature[i] = (float) (rand() % (40 + 1 - (-20))) + (-20); // Temperature range from -20 to 40 degrees celsius
        humidity[i] = (float) rand() / (float) RAND_MAX; // Humidity range from 0 to 1
        pressure[i] = (float) (rand() % (1100 + 1 - 900)) + 900; // Pressure range from 900 to 1100 millibars
    }
    
    // Print weather data for each hour
    printf("Weather simulation for %02d:%02d:%02d\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
    printf("Hour  Temperature  Humidity  Pressure\n");
    for(i=0; i<24; i++)
    {
        // Convert hour to string format
        sprintf(time_string, "%02d:00:00", i);
        printf("%s  %7.2fC  %6.2f   %7.2fmb\n", time_string, temperature[i], humidity[i], pressure[i]);
    }
    
    // Sort temperature data using bubble sort algorithm
    for(i=0; i<23; i++)
    {
        for(j=0; j<24-i-1; j++)
        {
            if(temperature[j] > temperature[j+1])
            {
                // Swap temperature values
                temp = temperature[j];
                temperature[j] = temperature[j+1];
                temperature[j+1] = temp;
                
                // Swap humidity values
                temp = humidity[j];
                humidity[j] = humidity[j+1];
                humidity[j+1] = temp;
                
                // Swap pressure values
                temp = pressure[j];
                pressure[j] = pressure[j+1];
                pressure[j+1] = temp;
            }
        }
    }
    
    // Print sorted temperature data
    printf("\nTemperature data sorted in ascending order:\n");
    printf("Temperature  Humidity  Pressure\n");
    for(i=0; i<24; i++)
    {
        printf("%7.2fC  %6.2f   %7.2fmb\n", temperature[i], humidity[i], pressure[i]);
    }
    
    return 0;
}