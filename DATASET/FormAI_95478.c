//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP -10

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // generate random temperature between MIN_TEMP and MAX_TEMP
    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    
    // determine weather conditions based on temperature
    char* condition;
    if (temperature >= 30) {
        condition = "Hot";
    } else if (temperature >= 15) {
        condition = "Warm";
    } else if (temperature >= 0) {
        condition = "Cool";
    } else {
        condition = "Cold";
    }
    
    // print temperature and weather condition
    printf("Today's temperature: %d°C\n", temperature);
    printf("Weather conditions: %s\n", condition);
    
    return 0;
}