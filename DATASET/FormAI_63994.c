//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialize random seed using time
    
    // array of weather conditions
    char *weather[5] = {
        "Sunny",
        "Cloudy",
        "Rainy",
        "Windy",
        "Snowy"
    };
    
    int day = 0; // initialize day to 0
    
    while (1) { // infinite loop
        
        // pick a random weather condition
        int index = rand() % 5;
        char *condition = weather[index];
        
        // generate a random temperature between -20 to 40 degrees celsius
        int temp = rand() % 61 - 20;
        
        printf("Day %d - %s, %d degrees Celsius\n", day, condition, temp);
        day++; // increment day
        
        // wait for 1 second before printing the next day's weather
        sleep(1);
    }
    
    return 0;
}