//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_TEMP 25 // define the room temperature

// function to generate a random temperature between 20 and 30
int generate_temperature() {
    int temp_rand = rand() % 11; // temperature can vary up to 10 degrees
    int temp = ROOM_TEMP + temp_rand - 5; // temperature can be up to 5 degrees above or below room temperature
    return temp;
}

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    
    int temperature = generate_temperature(); // generate initial temperature
    int counter = 0; // counter for number of times temperature is monitored
    
    printf("Starting temperature monitoring...\n");

    while (counter < 10) { // monitor temperature for 10 iterations
        printf("Temperature reading %d: %d degrees C\n", counter+1, temperature);
        
        if (temperature < ROOM_TEMP - 2) {
            printf("WARNING: Temperature is too low!\n");
        } else if (temperature > ROOM_TEMP + 2) {
            printf("WARNING: Temperature is too high!\n");
        } else {
            printf("Temperature is within normal range.\n");
        }
        
        temperature = generate_temperature(); // generate new temperature reading
        counter++; // increment counter
    }
    
    printf("Temperature monitoring complete.\n");
    return 0;
}