//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0
#define TIME_DELAY 3 // in seconds

// function to generate random temperature
float generateTemperature() {
    float temp = (float)rand()/(float)(RAND_MAX/MAX_TEMPERATURE); // generating random temperature
    return temp;
}

// function to check and display current temperature status
void checkTemperature(float currTemp) {
    if(currTemp >= 90) {
        printf("High Temperature Alert! Current Temperature: %.2f\n", currTemp);
    } else if(currTemp > 70 && currTemp < 90) {
        printf("Moderate Temperature Alert! Current Temperature: %.2f\n", currTemp);
    } else {
        printf("Normal Temperature: %.2f\n", currTemp);
    }
}

// main function
int main() {
    srand(time(NULL)); // seeding random number generator with current time
    
    float currTemp = generateTemperature(); // initializing current temperature
    
    printf("Starting Temperature Monitor...\n");
    
    do {
        checkTemperature(currTemp); // checking and displaying current temperature status
        sleep(TIME_DELAY); // delay for TIME_DELAY seconds
        currTemp = generateTemperature(); // generating new current temperature
    } while(1);
    
    return 0;
}