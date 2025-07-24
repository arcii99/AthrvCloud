//FormAI DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_MIN -20  // minimum temperature reading
#define TEMP_MAX 50   // maximum temperature reading
#define THRESHOLD 30  // temperature threshold for warning message

// function to generate a random temperature
int generateTemp() {
    int temp = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    return temp;
}

// function to display the temperature
void displayTemp(int temp) {
    printf("Temperature reading: %dC\n", temp);
    if(temp >= THRESHOLD) {
        printf("WARNING: High temperature detected!\n");
    }
}

int main() {
    srand(time(NULL));  // seed random number generator with current time

    printf("Futuristic Temperature Monitor\n\n");

    for(int i = 0; i < 10; i++) {
        int temp = generateTemp();
        displayTemp(temp);
        printf("--------------------\n");
    }

    return 0;
}