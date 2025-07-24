//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 7      //Number of days in weather forecast
#define NUM_HOURS 24    //Number of hours in a day
#define TEMP_MIN 0      //Minimum temperature in Celsius
#define TEMP_MAX 45     //Max temperature in Celsius

void initializeTemperatures(int temperatures[][NUM_HOURS]);
void simulateWeather(int temperatures[][NUM_HOURS]);
void printWeatherForecast(int temperatures[][NUM_HOURS]);

int main(void) {
    int temperatures[NUM_DAYS][NUM_HOURS];   //2D array to store the temperature for each hour of every day
    
    initializeTemperatures(temperatures);    //Initialize temperature array to random values
    
    simulateWeather(temperatures);           //Simulate the weather for each hour of every day
    
    printWeatherForecast(temperatures);      //Print the weather forecast for the entire week
    
    return 0;
}

void initializeTemperatures(int temperatures[][NUM_HOURS]) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < NUM_DAYS; i++) {
        for (int j = 0; j < NUM_HOURS; j++) {
            temperatures[i][j] = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
        }
    }
}

void simulateWeather(int temperatures[][NUM_HOURS]) {
    for (int i = 0; i < NUM_DAYS; i++) {
        for (int j = 0; j < NUM_HOURS; j++) {
            int change = rand() % 11 - 5;       //Simulate a change in temperature between -5 and +5 degrees Celsius
            temperatures[i][j] += change;
            if (temperatures[i][j] < TEMP_MIN) {
                temperatures[i][j] = TEMP_MIN;  //Ensure temperature doesn't fall below minimum
            } else if (temperatures[i][j] > TEMP_MAX) {
                temperatures[i][j] = TEMP_MAX;  //Ensure temperature doesn't exceed maximum
            }
        }
    }
}

void printWeatherForecast(int temperatures[][NUM_HOURS]) {
    printf("Weather Forecast\n");
    printf("================\n");
    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d\n", i+1);
        for (int j = 0; j < NUM_HOURS; j++) {
            printf("%d:00: %d C\n", j, temperatures[i][j]);
        }
        printf("\n");
    }
}