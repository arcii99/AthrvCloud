//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TEMP 40.0 //maximum possible temperature in celcius
#define MIN_TEMP -10.0 //minimum possible temperature in celcius
#define MAX_HUMIDITY 100 //maximum possible humidity value
#define MIN_HUMIDITY 0 //minimum possible humidity value
#define MAX_WIND_SPEED 120 //maximum possible wind speed value in km/h
#define MIN_WIND_SPEED 0 //minimum possible wind speed value in km/h
#define MAX_RAIN_CHANCE 100 //maximum possible chance of rain value
#define MIN_RAIN_CHANCE 0 //minimum possible chance of rain value

int main(){
    srand(time(NULL)); //seed for random number generator
    float temperature, humidity, wind_speed;
    int rain_chance;
    
    //simulate weather conditions for the next 7 days
    for(int i = 1; i <= 7; i++){
        
        //generate random values for temperature, humidity, wind_speed and rain_chance
        temperature = (rand() / (double)RAND_MAX) * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
        humidity = (rand() / (double)RAND_MAX) * (MAX_HUMIDITY - MIN_HUMIDITY) + MIN_HUMIDITY;
        wind_speed = (rand() / (double)RAND_MAX) * (MAX_WIND_SPEED - MIN_WIND_SPEED) + MIN_WIND_SPEED;
        rain_chance = (int)((rand() / (double)RAND_MAX) * (MAX_RAIN_CHANCE - MIN_RAIN_CHANCE) + MIN_RAIN_CHANCE);
        
        //print out the weather conditions for each day
        printf("\n\n=================== Day %d ===================\n\n", i);
        printf("Temperature: %.1f C\n", temperature);
        printf("Humidity: %.0f %%\n", humidity);
        printf("Wind Speed: %.1f km/h\n", wind_speed);
        printf("Chance of Rain: %d %%\n", rain_chance);
        
        //check if it is raining on the current day
        if(rain_chance > 50){
            printf("\nIt is raining today!!\n");
        }
    }
    
    return 0;
}