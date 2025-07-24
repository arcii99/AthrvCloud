//FormAI DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define weather conditions
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define STORMY 3
#define SNOWY 4

// define functions
void printWeather(int weather);
int randomWeather();

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // generate random weather for the next week
    int week[7];
    for (int i = 0; i < 7; i++) {
        week[i] = randomWeather();
    }
    
    // print the weather for each day of the week
    printf("Weather forecast for this week:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i+1);
        printWeather(week[i]);
    }
    
    return 0;
}

// function to print the weather condition
void printWeather(int weather) {
    if (weather == SUNNY) {
        printf("Sunny\n");
    } else if (weather == CLOUDY) {
        printf("Cloudy\n");
    } else if (weather == RAINY) {
        printf("Rainy\n");
    } else if (weather == STORMY) {
        printf("Stormy\n");
    } else if (weather == SNOWY) {
        printf("Snowy\n");
    }
}

// function to generate a random weather condition
int randomWeather() {
    int randNum = rand() % 5;
    return randNum;
}