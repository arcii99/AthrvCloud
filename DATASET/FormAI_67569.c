//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    float temp, humidity, pressure, rainChance;
    int timeCounter = 0;
    
    srand(time(NULL)); //initialize random seed
    
    printf("Starting weather simulation...\n");
    
    while (timeCounter < 24) { //simulate 24 hours
        
        //generate random weather data
        temp = ((float)rand()/(float)(RAND_MAX)) * 40 - 10; //temperature from -10 to 30 Celsius
        humidity = ((float)rand()/(float)(RAND_MAX)) * 100; //humidity from 0 to 100%
        pressure = ((float)rand()/(float)(RAND_MAX)) * 20 + 1000; //pressure from 1000 to 1020 hPa
        rainChance = ((float)rand()/(float)(RAND_MAX)) * 100; //rain chance from 0 to 100%
        
        //print weather data
        printf("\n--- Hour %d ---\n", timeCounter);
        printf("Temperature: %.1f C\n", temp);
        printf("Humidity: %.1f %%\n", humidity);
        printf("Pressure: %.1f hPa\n", pressure);
        printf("Rain chance: %.1f %%\n", rainChance);
        
        //check weather conditions and provide suggestions
        if (temp < 0) {
            printf("It's very cold outside, make sure to dress warmly!\n");
        } else if (temp < 10) {
            printf("It's quite cold outside, a jacket would be appropriate.\n");
        } else if (temp < 20) {
            printf("It's a nice temperature outside, enjoy the weather!\n");
        } else if (temp < 30) {
            printf("It's quite warm outside, make sure to stay hydrated.\n");
        } else {
            printf("It's very hot outside, avoid prolonged exposure to the sun.\n");
        }
        
        if (humidity < 30) {
            printf("The air is quite dry, consider using a humidifier.\n");
        } else if (humidity < 60) {
            printf("The air humidity is at a comfortable level.\n");
        } else {
            printf("The air is very humid, take caution to prevent mold growth.\n");
        }
        
        if (pressure < 1005) {
            printf("The atmospheric pressure is low, be prepared for possible storms.\n");
        } else if (pressure < 1015) {
            printf("The atmospheric pressure is stable, expect clear skies.\n");
        } else {
            printf("The atmospheric pressure is high, sunny weather is likely.\n");
        }
        
        if (rainChance < 30) {
            printf("There's a low chance of rain, enjoy the clear skies!\n");
        } else if (rainChance < 60) {
            printf("There's a moderate chance of rain, consider bringing an umbrella.\n");
        } else {
            printf("There's a high chance of rain, make sure to stay dry!\n");
        }
        
        timeCounter++;
    }
    
    printf("\nWeather simulation finished.\n");
    
    return 0;
}