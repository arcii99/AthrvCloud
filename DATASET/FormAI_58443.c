//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99
#define MIN 0

int main()
{
    srand(time(NULL));
    int temperature[MAX], humidity[MAX], air_pressure[MAX];
    float wind_speed[MAX], cloud_cover[MAX], rainfall[MAX];
    
    for(int i = 0; i < MAX; i++)
    {
        temperature[i] = rand() % (MAX - MIN + 1) + MIN;
        humidity[i] = rand() % (MAX - MIN + 1) + MIN;
        air_pressure[i] = rand() % (MAX - MIN + 1) + MIN;
        wind_speed[i] = (float)rand() / RAND_MAX * (MAX - MIN) + MIN;
        cloud_cover[i] = (float)rand() / RAND_MAX;
        rainfall[i] = (float)rand() / (float)(RAND_MAX/MAX);
    }
    
    printf("Weather Simulation Report\n\n");
    printf("Date\tTemperature\tHumidity\tAir Pressure\tWind Speed\tCloud Cover\tRainfall\n");
    
    for(int i = 0; i < MAX; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%.1f\t\t%.2f\t\t%.2f\n", i+1, temperature[i], humidity[i], air_pressure[i], wind_speed[i], cloud_cover[i], rainfall[i]);
    }
    
    return 0;
}