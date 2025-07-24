//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printWeather(int temperature, bool isRaining) {
    if (isRaining) {
        printf("It's raining and ");
    } else {
        printf("It's not raining and ");
    }
    printf("the temperature is %d degrees Celsius\n", temperature);
}

void simulateWeather(void *vargp) {
    const int MIN_TEMP = 10, MAX_TEMP = 35, PROBABILITY_OF_RAIN = 30;
    srand(time(NULL));  // initialize random seed
    
    while (true) {
        int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;  // generate random temperature
        bool isRaining = (rand() % 100) < PROBABILITY_OF_RAIN;  // generate random boolean for probability of rain
        printWeather(temperature, isRaining);  // print weather details
        
        // wait for random duration between 1 and 5 seconds before repeating
        int sleepDuration = rand() % 5 + 1;
        sleep(sleepDuration);
    }
}

int main() {
    simulateWeather(NULL);
    return 0;
}