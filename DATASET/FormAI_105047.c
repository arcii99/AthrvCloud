//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int temperature = 20;
    int humidity = 60;
    int pressure = 1013;

    srand(time(NULL)); // Initialize random seed

    printf("Weather Simulation Program\n\n");

    printf("Initial Conditions: Temperature = %d C, Humidity = %d%%, Pressure = %d hPa\n\n", temperature, humidity, pressure);

    printf("-----------------------------------------------------------------------------\n");

    for(int i=1; i<=10; i++){

        int randomTemperatureChange = rand() % 5 + 1; // Generate a random integer between 1 and 5
        int randomHumidityChange = rand() % 5 + 1; // Generate a random integer between 1 and 5
        int randomPressureChange = rand() % 5 + 1; // Generate a random integer between 1 and 5

        // Add or subtract the random values from the current values
        if(rand() % 2 == 0){
            temperature += randomTemperatureChange;
            humidity -= randomHumidityChange;
            pressure += randomPressureChange;
        } else {
            temperature -= randomTemperatureChange;
            humidity += randomHumidityChange;
            pressure -= randomPressureChange;
        }
        
        // Make sure temperature, humidity, and pressure stay within reasonable ranges
        if(temperature < -20) temperature = -20;
        if(temperature > 40) temperature = 40;
        if(humidity < 0) humidity = 0;
        if(humidity > 100) humidity = 100;
        if(pressure < 800) pressure = 800;
        if(pressure > 1200) pressure = 1200;
        
        printf("Conditions after %d hour(s): Temperature = %d C, Humidity = %d%%, Pressure = %d hPa\n", i, temperature, humidity, pressure);
        printf("-----------------------------------------------------------------------------\n");
    }

    return 0;
}