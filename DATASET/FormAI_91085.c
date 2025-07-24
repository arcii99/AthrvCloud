//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int temp, heat_index, wind_speed;
    char weather[10];
    
    // Generating temperature
    temp = (rand() % 50) - 10;
    
    // Generating wind speed
    wind_speed = rand() % 80;
    
    // Creating the weather conditions
    if(temp < 0 && wind_speed >= 50){
        sprintf(weather, "Blizzard");
    }
    else if(temp < 0 && wind_speed < 50){
        sprintf(weather, "Snow");
    }
    else if(temp >= 0 && temp < 20 && wind_speed >= 50){
        sprintf(weather, "Ice storm");
    }
    else if(temp >= 0 && temp < 20 && wind_speed >= 20 && wind_speed < 50){
        sprintf(weather, "Cold breeze");
    }
    else if(temp >= 0 && temp < 20 && wind_speed < 20){
        sprintf(weather, "Cold");
    }
    else if(temp >= 20 && temp < 30 && wind_speed >= 50){
        sprintf(weather, "Dust storm");
    }
    else if(temp >= 20 && temp < 30 && wind_speed >= 20 && wind_speed < 50){
        sprintf(weather, "Cool breeze");
    }
    else if(temp >= 20 && temp < 30 && wind_speed < 20){
        sprintf(weather, "Cool");
    }
    else if(temp >= 30 && temp < 40 && wind_speed >= 50){
        sprintf(weather, "Sand storm");
    }
    else if(temp >= 30 && temp < 40 && wind_speed >= 20 && wind_speed < 50){
        sprintf(weather, "Warm breeze");
    }
    else if(temp >= 30 && temp < 40 && wind_speed < 20){
        sprintf(weather, "Warm");
    }
    else if(temp >= 40 && wind_speed >= 50){
        sprintf(weather, "Heat storm");
    }
    else if(temp >= 40 && wind_speed >= 20 && wind_speed < 50){
        sprintf(weather, "Hot breeze");
    }
    else if(temp >= 40 && wind_speed < 20){
        sprintf(weather, "Hot");
    }
    
    // Calculating the heat index
    heat_index = -42.379 + 2.04901523*temp + 10.14333127*wind_speed - 0.22475541*temp*wind_speed - 0.00683783*temp*temp - 0.05481717*wind_speed*wind_speed + 0.00122874*temp*temp*wind_speed + 0.00085282*temp*wind_speed*wind_speed - 0.00000199*temp*temp*wind_speed*wind_speed;
    
    printf("Temperature: %dF\n", temp);
    printf("Wind Speed: %dmph\n", wind_speed);
    printf("Weather: %s\n", weather);
    printf("Heat Index: %dF\n", heat_index);
    
    return 0;
}