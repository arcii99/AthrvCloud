//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50  // Maximum temperature reading
#define MIN_TEMP 0   // Minimum temperature reading

// A function to generate a random temperature reading
int generate_temperature(){
    int range = MAX_TEMP - MIN_TEMP + 1;
    return (rand() % range) + MIN_TEMP;
}

int main(){
    srand(time(NULL));  // Seed the random number generator with the current time

    int temperature = generate_temperature();  // Generate a random temperature reading
    printf("Temperature: %d\n", temperature);

    if (temperature >= 30){
        printf("Warning! Temperature is too high.\n");
        // Send an email alert to the system administrator
        // Call a function to log the event in a file
        // Implement any other appropriate action
    }
    else if (temperature >= 20){
        printf("Temperature is within the normal range.\n");
    }
    else {
        printf("Warning! Temperature is too low.\n");
        // Send an email alert to the system administrator
        // Call a function to log the event in a file
        // Implement any other appropriate action
    }

    return 0;
}