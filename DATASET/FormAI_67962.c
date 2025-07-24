//FormAI DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to generate random temperature */
float generateTemperature() {
    float temp = ((float)rand()/(float)(RAND_MAX))*(40.0-(-10.0))+(-10.0); // temperature range from -10C to 40C
    return temp;
}

/* function to generate random weather condition */
char* generateWeather() {
    int weather = rand()%3+1; // generates random number from 1 to 3
    switch(weather) {
        case 1:
            return "Sunny";
        case 2:
            return "Cloudy";
        case 3:
            return "Rainy";
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    /* variables for weather simulation */
    float temperature;
    char* weatherCondition;
    int i, j;
    
    printf("Weather Simulation Report\n\n");
    
    /* simulate weather for each day in a month */
    for(i=1;i<=30;i++) {
        temperature = generateTemperature();
        weatherCondition = generateWeather();
        
        printf("Day %d: Temperature - %.2fC\t Weather Condition - %s\n", i, temperature, weatherCondition);
        
        /* simulate hourly weather for each day */
        for(j=1;j<=24;j++) {
            printf("\t Hour %d: Temperature - %.2fC\t Weather Condition - %s\n", j, generateTemperature(), generateWeather());
        }
        
        printf("\n");
    }
    
    return 0;
}