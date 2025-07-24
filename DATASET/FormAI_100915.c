//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random temperature values
float generateTemp() {
    float temp = (float)(rand() % 50) - 10; // generates temp between -10°C and 40°C
    return temp;
}

int main() {
    srand(time(0)); // seeding the random number generator
    
    float currentTemp = generateTemp(); // generating the initial temperature value
    
    // main loop to continuously monitor temperature
    while (1) {
        printf("Current temperature is %.2f°C.\n", currentTemp);
        
        if (currentTemp >= 30.0) {
            printf("Temperature is too high! Cooling system activated.\n");
            // code to activate cooling system
        } else if (currentTemp <= 10.0) {
            printf("Temperature is too low! Heating system activated.\n");
            // code to activate heating system
        }
        
        // wait for 5 seconds before generating new temperature value
        int delay = 5 * CLOCKS_PER_SEC;
        clock_t start_time = clock();
        while (clock() < start_time + delay);
        
        // update current temperature value
        currentTemp = generateTemp();
    }
    
    return 0;
}