//FormAI DATASET v1.0 Category: Weather simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Defining variables for temperatures and time
    int temp, minTemp = 18, maxTemp = 36, timeInterval = 10, totalTime = 60;

    // Initializing time
    time_t t;
    srand((unsigned)time(&t));

    // Loop for generating weather simulation for 1 hour
    for(int i=0; i<totalTime; i+=timeInterval){
        printf("\n\n\n************************************\n");
        printf("         CURRENT WEATHER            \n");
        printf("************************************\n");

        // Generating random temperature within the given range
        temp = rand() % (maxTemp - minTemp + 1) + minTemp;

        // Simulation of sunny weather
        if(temp >= 28 && temp <= 36){
            printf("Current Temperature: %d C\n", temp);
            printf("Weather Condition: Sunny\n");
            printf("Wind Speed: 5 km/h\n");
            printf("Humidity: 50 percent\n");
        }
        // Simulation of cloudy weather
        else if(temp >= 18 && temp <= 27){
            printf("Current Temperature: %d C\n", temp);
            printf("Weather Condition: Cloudy\n");
            printf("Wind Speed: 10 km/h\n");
            printf("Humidity: 70 percent\n");
        }
        // Simulation of rainy weather
        else if(temp >= 0 && temp <= 17){
            printf("Current Temperature: %d C\n", temp);
            printf("Weather Condition: Rainy\n");
            printf("Wind Speed: 15 km/h\n");
            printf("Humidity: 90 percent\n");
        }

        // Delay for next iteration
        printf("\n\nNext update in %d minutes\n", timeInterval);
        printf("************************************\n\n");
        sleep(timeInterval*60);
    }

    return 0;
}