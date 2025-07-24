//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateWeather(int *temperature, int *humidity, int *pressure){
    srand(time(NULL));
    *temperature = rand() % 41 - 20;
    *humidity = rand() % 101;
    *pressure = rand() % 11 + 990;
}

void printWeather(int temperature, int humidity, int pressure){
    if(temperature < 0){
        printf("It's really cold out there today, with a temperature of %d degrees Celsius.\n", temperature);
    }else if(temperature >= 0 && temperature < 8){
        printf("It's quite chilly outside with a temperature of %d degrees Celsius.\n", temperature);
    }else if(temperature >= 8 && temperature < 15){
        printf("It's cool outside with a temperature of %d degrees Celsius.\n", temperature);
    }else if(temperature >= 15 && temperature < 22){
        printf("It's a pleasant day with a temperature of %d degrees Celsius.\n", temperature);
    }else if(temperature >= 22 && temperature < 28){
        printf("It's a warm day with a temperature of %d degrees Celsius.\n", temperature);
    }else{
        printf("It's a hot day with a temperature of %d degrees Celsius.\n", temperature);
    }

    if(humidity < 30){
        printf("It's quite dry outside today with only %d%% humidity.\n", humidity);
    }else if(humidity >= 30 && humidity < 60){
        printf("The humidity outside today is comfortable at %d%%.\n", humidity);
    }else{
        printf("It's quite humid outside with %d%% humidity.\n", humidity);
    }

    if(pressure <= 1000){
        printf("It's very unlikely to have a pressure of %d hectoPascals.\n", pressure);
    }else if(pressure > 1000 && pressure <= 1010){
        printf("The air pressure outside is at a comfortable level of %d hectoPascals.\n", pressure);
    }else{
        printf("The air pressure today is quite high with a reading of %d hectoPascals.\n", pressure);
    }
}

int main(){
    int temperature, humidity, pressure;
    generateWeather(&temperature, &humidity, &pressure);
    printWeather(temperature, humidity, pressure);

    return 0;
}