//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int temperature, windSpeed, humidity, chanceOfRain;
    char* weatherCondition;

    srand(time(NULL));

    temperature = rand() % 50 - 10;
    windSpeed = rand() % 30;
    humidity = rand() % 100;
    chanceOfRain = rand() % 100;

    if (temperature < 0){
        weatherCondition = "Snowy";
    }
    else if (temperature >= 0 && temperature < 15){
        weatherCondition = "Rainy";
    }
    else{
        weatherCondition = "Sunny";
    }

    printf("Today's weather is %s with a temperature of %d°C, ", weatherCondition, temperature);
    printf("wind speed of %d km/h, humidity level at %d%%, and a %d%% chance of rain.\n", windSpeed, humidity, chanceOfRain);

    return 0;
}