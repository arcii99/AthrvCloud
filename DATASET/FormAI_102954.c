//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
// This is a program to monitor the temperature using Ada Lovelace's inspiration.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100 // Maximum temperature
#define MIN_TEMP 0 // Minimum temperature

int main() {

    srand(time(NULL)); // Seed the random number generator with current time

    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // Generate random temperature between MIN_TEMP and MAX_TEMP
    int count = 0; // Used to count the number of times temperature exceeds 90 degrees

    printf("Welcome to Ada Lovelace's temperature monitor!\n");
    printf("The current temperature is: %d degrees Celsius\n", temperature);

    while(1) { // Loop indefinitely

        if(temperature >= 90) { // If temperature exceeds 90 degrees

            printf("ALERT! Temperature at critical level!\n");
            count++; // Increment the counter

            if(count == 3) { // If temperature exceeds 90 degrees three times

                printf("ALERT! Emergency cooling system activated!\n");
                count = 0; // Reset the counter
            }
        }

        temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // Generate new random temperature
        printf("New temperature: %d degrees Celsius\n", temperature);

        sleep(2); // Wait for 2 seconds before generating new temperature
    }

    return 0; // End program
}