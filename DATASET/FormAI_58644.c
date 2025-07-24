//FormAI DATASET v1.0 Category: Weather simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature
int generateTemperature(int minTemp, int maxTemp){
    int temp = (rand() % (maxTemp - minTemp + 1)) + minTemp;
    return temp;
}

// Function to generate random wind speed
int generateWindSpeed(int minSpeed, int maxSpeed){
    int windSpeed = (rand() % (maxSpeed - minSpeed + 1)) + minSpeed;
    return windSpeed;
}

// Function to generate random precipitation level
float generatePrecipitation(float minPrecip, float maxPrecip){
    float precipitation = ((float)rand()/(float)(RAND_MAX)) * (maxPrecip - minPrecip) + minPrecip;
    return precipitation;
}

int main(){
    time_t t;
    srand((unsigned) time(&t)); // Seed random number generator with time
    int minTemp = 10, maxTemp = 25; // Temperature range in Celsius
    int minWindSpeed = 0, maxWindSpeed = 15; // Wind speed range in km/h
    float minPrecipitation = 0, maxPrecipitation = 5; // Precipitation range in mm/hour
    int numDays = 5; // Number of days to simulate
    
    printf("Weather simulation for the next %d days:\n\n", numDays);
    
    for(int i=0; i<numDays; i++){
        int temperature = generateTemperature(minTemp, maxTemp);
        int windSpeed = generateWindSpeed(minWindSpeed, maxWindSpeed);
        float precipitation = generatePrecipitation(minPrecipitation, maxPrecipitation);
        
        printf("Day %d:\n", i+1);
        printf("Temperature: %d °C\n", temperature);
        printf("Wind Speed: %d km/h\n", windSpeed);
        printf("Precipitation: %.2f mm/h\n\n", precipitation);
        
        if(precipitation > 2){
            printf("It might rain today, remember to bring an umbrella.\n\n");
        }
        else{
            printf("It looks like a sunny day today, enjoy your day!\n\n");
        }
    }
    return 0;
}