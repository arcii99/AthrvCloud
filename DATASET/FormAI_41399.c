//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int temperature = rand() % 50 - 20;
    int humidity = rand() % 100;
    int wind_speed = rand() % 80;
    char* wind_direction;
    int random_direction = rand() % 4;

    switch(random_direction){
        case 0:
            wind_direction = "North";
            break;
        case 1:
            wind_direction = "South";
            break;
        case 2:
            wind_direction = "East";
            break;
        case 3:
            wind_direction = "West";
            break;
    }

    printf("Welcome to the Weather Simulation Program!\n");
    printf("Today's forecast: \n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d mph\n", wind_speed);
    printf("Wind Direction: %s\n", wind_direction);

    printf("Wait a minute...something's not right.\n");

    int throw_curse = rand() % 5;

    switch(throw_curse){
        case 0:
            printf("It's raining cats and dogs!\n");
            break;
        case 1:
            printf("Looks like a tornado's coming!\n");
            break;
        case 2:
            printf("A thunderstorm's brewing...\n");
            break;
        case 3:
            printf("Be on the lookout for hail the size of golf balls!\n");
            break;
        case 4:
            printf("This is an earthquake simulation...run for cover!\n");
            break;
    }

    printf("\n\nDon't worry, it's just a joke. Your real weather conditions are:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d mph\n", wind_speed);
    printf("Wind Direction: %s\n", wind_direction);

    return 0;
}