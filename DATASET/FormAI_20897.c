//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    float tempCel = 0, tempFahr = 0, humidity = 0, pressure = 0; // variables to store temperature in celsius and fahrenheit, humidity, and pressure
    
    printf("\nWelcome to the Temperature Monitor Program!\n");

    // loop to simulate temperature and humidity sensors
    for (int i = 0; i < 10; i++) {
        // generate random temperature between -40 and 60 degrees Celsius
        tempCel = (rand() % 101) - 40; 
        
        // convert temperature to Fahrenheit
        tempFahr = (tempCel * 1.8) + 32;

        // generate random humidity between 0 and 100%
        humidity = rand() % 101;

        // generate random pressure between 900 and 1100 hPa
        pressure = (rand() % 201) + 900;

        printf("\n**READING %d**\n", i+1);
        printf("Temperature: %.2f C (%.2f F)\n", tempCel, tempFahr);
        printf("Humidity: %.2f %%\n", humidity);
        printf("Pressure: %.2f hPa\n", pressure);
        
        // handling the temperature value
        if (tempFahr < 32) {
            printf("WARNING: Freezing temperatures! Take necessary precautions.\n");
        } else if (tempFahr > 90) {
            printf("WARNING: High temperatures! Take necessary precautions.\n");
        } else {
            printf("Temperature is normal.\n");
        }

        // handling the humidity value
        if (humidity < 30) {
            printf("WARNING: Low humidity levels! Skin and respiratory problems may occur.\n");
        } else if (humidity > 80) {
            printf("WARNING: High humidity levels! Mold and mildew growth may occur.\n");
        } else {
            printf("Humidity is normal.\n");
        }

        // handling the pressure value
        if (pressure < 950) {
            printf("WARNING: Low pressure levels! Headaches and dizziness may occur.\n");
        } else if (pressure > 1050) {
            printf("WARNING: High pressure levels! Nausea and shortness of breath may occur.\n");
        } else {
            printf("Pressure is normal.\n");
        }
    }

    printf("\nExiting Temperature Monitor Program.\n");
    return 0;
}