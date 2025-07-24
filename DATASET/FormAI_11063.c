//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    
    int temperature = rand() % 50 - 10; // generate initial temperature between -10°C to 40°C
    int windSpeed = rand() % 30; // generate initial wind speed between 0 to 20 km/h
    int precipitation = rand() % 101; // generate initial precipitation between 0 to 100 mm
    
    printf("Weather Simulation\n");
    printf("==================\n");
    
    printf("\nInitial Conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Wind Speed: %d km/h\n", windSpeed);
    printf("Precipitation: %d mm\n", precipitation);
    
    int i;
    for(i = 1; i <= 7; i++) {
        printf("\nDay %d:\n", i);
        
        temperature += rand() % 11 - 5; // change temperature by up to 5°C in either direction
        if(temperature > 40) { // temperature cannot exceed 40°C
            temperature = 40;
        } else if(temperature < -10) { // temperature cannot be below -10°C
            temperature = -10;
        }
        printf("Temperature: %d°C\n", temperature);
        
        windSpeed += rand() % 11 - 5; // change wind speed by up to 5 km/h in either direction
        if(windSpeed < 0) { // wind speed cannot be negative
            windSpeed = 0;
        } else if(windSpeed > 30) { // wind speed cannot exceed 30 km/h
            windSpeed = 30;
        }
        printf("Wind Speed: %d km/h\n", windSpeed);
        
        precipitation += rand() % 21 - 10; // change precipitation by up to 10 mm in either direction
        if(precipitation < 0) { // precipitation cannot be negative
            precipitation = 0;
        } else if(precipitation > 100) { // precipitation cannot exceed 100 mm
            precipitation = 100;
        }
        printf("Precipitation: %d mm\n", precipitation);
    }
    
    return 0;
}