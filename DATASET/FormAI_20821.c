//FormAI DATASET v1.0 Category: Temperature monitor ; Style: satisfied
/* This program monitors the temperature of a device and alerts the user if it exceeds a certain threshold */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 80 // maximum temperature threshold
#define INTERVAL 5 // time interval in seconds between temperature readings

int main() {
    float temperature = 0.0; // initialize temperature variable
    char unit[10]; // initialize unit variable
    int counter = 0; // initialize counter variable

    printf("\n--------Temperature Monitor--------\n\n");

    while (1) { // infinite loop
        printf("Enter the temperature value in Celsius (or 'q' to quit): ");
        scanf("%f", &temperature); // read temperature input from user
        fgets(unit, 10, stdin); // clear the input buffer

        if (unit[0] == 'q') { // check if user entered 'q'
            printf("\nExiting program...\n");
            break; // exit loop if true
        }

        if (temperature > MAX_TEMP) { // check if temperature exceeds maximum threshold
            printf("WARNING: Temperature exceeds maximum threshold of %d°C!\n", MAX_TEMP);
        } else {
            printf("Temperature is within acceptable range.\n");
        }

        counter++; // increment counter variable
        printf("Temperature reading #%d: %.2f°C\n\n", counter, temperature);

        sleep(INTERVAL); // wait for specified time interval before checking temperature again
    }

    return 0; // exit program
}