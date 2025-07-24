//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // seed random number generator
    int temperature = 0;
    int humidity = 0;
    char* weather = NULL;
    int chance_of_rain = 0;
    int wind_speed = 0;

    printf("Welcome to the wacky weather simulator!\n\n");

    // generate temperature and humidity values
    temperature = rand() % 100;
    humidity = rand() % 100;

    // determine the weather based on temperature and humidity
    if (temperature < 32) {
        weather = "snowy";
        chance_of_rain = 5;
        wind_speed = 10;
    } else if (temperature < 60) {
        weather = "cloudy";
        chance_of_rain = 50;
        wind_speed = 15;
    } else if (temperature < 85) {
        weather = "sunny";
        chance_of_rain = 10;
        wind_speed = 5;
    } else {
        weather = "hot";
        chance_of_rain = 0;
        wind_speed = 0;
    }

    // print out the weather report
    printf("The current temperature is %d degrees Fahrenheit and the humidity is %d%%.\n", temperature, humidity);
    printf("The weather today is %s with a chance of rain at %d%% and winds of %d mph.\n\n", weather, chance_of_rain, wind_speed);

    // simulate rain if chance of rain is greater than 0
    if (chance_of_rain > 0) {
        printf("Oh no, it's starting to rain!\n");
        for (int i = 10; i > 0; i--) {
            printf("Drip ");
            usleep(500000);
            printf("drop ");
            usleep(500000);
        }
        printf("...and it's finished!\n\n");
    } else {
        printf("Looks like it's going to be a dry one today!\n\n");
    }

    // simulate wind if wind speed is greater than 0
    if (wind_speed > 0) {
        printf("Hold onto your hats, folks! The wind is really picking up!\n");
        for (int i = 0; i < 5; i++) {
            printf("Woooosh!\n");
            usleep(750000);
        }
        printf("Phew, that was close! The wind has settled down now.\n\n");
    } else {
        printf("Not much wind today. Nothing to worry about!\n\n");
    }

    // say goodbye to the user
    printf("Thanks for using the wacky weather simulator! Come back soon!\n");

    return 0;
}