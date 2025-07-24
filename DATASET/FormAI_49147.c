//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random float temperature between min and max Celsius
float generateTemperature(float min, float max){
    return (float)((rand()/(float)RAND_MAX) * (max-min)) + min;
}

int main(){
    //initialize random seed
    srand(time(NULL));

    //declare variables for weather conditions
    float temperature, humidity, pressure, windSpeed;
    char *windDirection[] = {"N","NE","E","SE","S","SW","W","NW"};
    int randomIndex;

    //initialize variables with random values within certain ranges
    temperature = generateTemperature(-10.0, 40.0);
    humidity = (float)((rand()/(float)RAND_MAX) * 100.0);
    pressure = (float)((rand()/(float)RAND_MAX) * 1000.0) + 800.0;
    windSpeed = (float)((rand()/(float)RAND_MAX) * 20.0);
    randomIndex = (int)(rand() % 8);

    //print weather conditions
    printf("The current temperature is %.1f°C.\n", temperature);
    printf("The current humidity is %.1f%%.\n", humidity);
    printf("The current pressure is %.1f hPa.\n", pressure);
    printf("The current wind speed is %.1f m/s, blowing towards %s.\n", windSpeed, windDirection[randomIndex]);

    return 0;
}