//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 20

enum Weather {SUNNY, CLOUDY, RAINY, SNOWY};

int main()
{
    int i, j, k, count;
    enum Weather weatherMap[ROWS][COLUMNS];
    srand(time(NULL));

    //initialize the weather map with random values
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS; j++)
        {
            weatherMap[i][j] = rand() % 4;
        }
    }

    //print the weather map
    printf("\nWeather Forecast:\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS; j++)
        {
            switch(weatherMap[i][j])
            {
                case SUNNY: printf("SUNNY "); break;
                case CLOUDY: printf("CLOUDY "); break;
                case RAINY: printf("RAINY "); break;
                case SNOWY: printf("SNOWY "); break;
            }
        }
        printf("\n");
    }

    //check for patterns
    count = 0;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS-2; j++)
        {
            if(weatherMap[i][j] == SUNNY && weatherMap[i][j+1] == SUNNY && weatherMap[i][j+2] == SUNNY)
            {
                count++;
            }
            if(weatherMap[i][j] == CLOUDY && weatherMap[i][j+1] == CLOUDY && weatherMap[i][j+2] == CLOUDY)
            {
                count++;
            }
            if(weatherMap[i][j] == RAINY && weatherMap[i][j+1] == RAINY && weatherMap[i][j+2] == RAINY)
            {
                count++;
            }
            if(weatherMap[i][j] == SNOWY && weatherMap[i][j+1] == SNOWY && weatherMap[i][j+2] == SNOWY)
            {
                count++;
            }
        }
    }
    printf("\nPatterns Found: %d\n", count);

    //check for temperature extremes
    count = 0;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS; j++)
        {
            k = rand() % 101;
            switch(weatherMap[i][j])
            {
                case SUNNY: if(k > 80) count++; break;
                case CLOUDY: if(k < 40) count++; break;
                case RAINY: if(k < 30) count++; break;
                case SNOWY: if(k < 20) count++; break;
            }
        }
    }
    printf("\nTemperature Extremes: %d\n", count);

    return 0;
}