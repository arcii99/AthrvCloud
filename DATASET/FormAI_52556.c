//FormAI DATASET v1.0 Category: Weather simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    printf("---------------------------------\n");
    printf("Welcome to Medieval Weather Sim!\n");
    printf("---------------------------------\n");
    printf("\n");

    // Seed random number generator
    srand(time(NULL));

    // Get a random number between 0 and 100
    int weather = rand() % 101;

    // Variables for precipitation type
    int rain = 0;
    int snow = 0;

    // Determine precipitation type based on weather percentage
    if(weather >= 60){
        printf("The weather is cloudy with a chance of rain.\n");
        rain = 1;
    }
    else if(weather <= 30){
        printf("The weather is cold with a chance of snow.\n");
        snow = 1;
    }
    else{
        printf("The weather is mild and clear.\n");
    }
    printf("\n");

    // Temperature range in medieval times was between 10 and 30 degrees Celsius
    int min_temp = 10;
    int max_temp = 30;

    // Generate a random temperature within the range
    int temperature = (rand() % (max_temp - min_temp + 1)) + min_temp;
    printf("The temperature is %d°C.\n", temperature);
    printf("\n");

    // Wind speeds varied quite a bit in medieval times so we'll use a random number between 0 and 50 km/h
    int wind_speed = rand() % 51;
    printf("The wind speed is %dkm/h.\n", wind_speed);
    printf("\n");

    // Check for stormy conditions
    if(rain && wind_speed >= 30){
        printf("It looks like a thunderstorm is brewing!\n");
    }
    else if(snow && wind_speed >= 20){
        printf("Beware! A blizzard may be coming!\n");
    }

    return 0;
}