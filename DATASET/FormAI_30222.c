//FormAI DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float rand_FloatRange(float a, float b) {
    float randnum = (float)rand()/(float)(RAND_MAX);
    return (randnum*(b-a))+a;
}

int main() {
    int i;
    float windSpeed, temperature, humidity, rainfall;
    srand(time(0));
  
    printf("==========================================\n");
    printf(" Welcome to the Weather Simulation Program\n");
    printf("==========================================\n\n");
  
    for(i=1; i<=7; i++) {
        printf("\n\n--------------------DAY %d--------------------\n\n", i);
        
        // Generate random values for weather parameters
        windSpeed = rand_FloatRange(0, 70);
        temperature = rand_FloatRange(-20, 50);
        humidity = rand_FloatRange(0, 100);
        rainfall = rand_FloatRange(0, 20);

        // Print the generated weather data  
        printf("Wind Speed: %.2f km/h\n", windSpeed);
        printf("Temperature: %.2f C\n", temperature);
        printf("Humidity: %.2f%%\n", humidity);
        printf("Rainfall: %.2f mm\n", rainfall);

        // Determine and print the weather condition based on weather parameters
        if(windSpeed <= 10 && temperature <= 10 && humidity >= 60 && rainfall > 5) {
            printf("Weather Condition: Heavy Snowfall\n");
        } else if(windSpeed >= 50 && temperature <= 0 && humidity <= 40) {
            printf("Weather Condition: Blizzards\n");
        } else if(windSpeed >= 60 && temperature >= 30 && rainfall <= 5) {
            printf("Weather Condition: Heat Wave\n");
        } else if(temperature > 42 || humidity > 90 || rainfall > 15) {
            printf("Weather Condition: Dangerous Weather Conditions\n");
        } else if(rainfall > 5 && temperature <= 10 && humidity >= 60) {
            printf("Weather Condition: Cold and Rainy weather\n");
        } else {
            printf("Weather Condition: Normal\n");
        }
    }
    return 0;
}