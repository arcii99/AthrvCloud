//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int temperature, humidity, wind_speed;
    char weather_conditions[10];
    
    srand(time(NULL));

    temperature = rand() % 50;
    humidity = rand() % 100;
    wind_speed = rand() % 50;

    printf("Today's weather conditions: \n");

    if(temperature < 10){
        strcpy(weather_conditions, "Freezing");
    }else if(temperature >= 10 && temperature < 20){
        strcpy(weather_conditions, "Cold");
    }else if(temperature >= 20 && temperature < 30){
        strcpy(weather_conditions, "Warm");
    }else{
        strcpy(weather_conditions, "Hot");
    }

    if(humidity < 30){
        strcat(weather_conditions, ", Dry");
    }else if(humidity >= 30 && humidity < 60){
        strcat(weather_conditions, ", Average Humidity");
    }else{
        strcat(weather_conditions, ", High Humidity");
    }

    if(wind_speed < 10){
        strcat(weather_conditions, ", No Wind");
    }else if(wind_speed >= 10 && wind_speed < 30){
        strcat(weather_conditions, ", Windy");
    }else{
        strcat(weather_conditions, ", Strong Winds");
    }

    printf("%s", weather_conditions);

    return 0;
}