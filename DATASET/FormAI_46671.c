//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random temperature between -50 to 50
int generateTemperature() {
    int temp = rand() % 101 - 50;
    return temp;
}

// function to return corresponding weather condition based on temperature
char* getWeatherCondition(int temperature) {
    char* condition;
    if (temperature <= -15) {
        condition = "severe cold";
    } else if (temperature <= 0) {
        condition = "cold";
    } else if (temperature <= 10) {
        condition = "cool";
    } else if (temperature <= 20) {
        condition = "moderate";
    } else if (temperature <= 30) {
        condition = "warm";
    } else {
        condition = "hot";
    }
    return condition;
}

// main function
int main() {
    // seed for random temperature generation
    srand(time(0));

    // variables for weather simulation
    int i, j;
    int temperatures[7][24];
    char* conditions[7][24];

    // simulate weather for each day of the week
    for (i = 0; i < 7; i++) {
        // simulate weather for each hour of the day
        for (j = 0; j < 24; j++) {
            int temperature = generateTemperature();
            temperatures[i][j] = temperature;
            char* condition = getWeatherCondition(temperature);
            conditions[i][j] = condition;
        }
    }

    // print weather report
    printf("7-Day Weather Simulation Report:\n");
    for (i = 0; i < 7; i++) {
        printf("Day %d:\n", i+1);
        for (j = 0; j < 24; j++) {
            printf("\tHour %d: Temperature: %d C Condition: %s\n", j+1, temperatures[i][j], conditions[i][j]);
        }
        printf("\n");
    }
    return 0;
}