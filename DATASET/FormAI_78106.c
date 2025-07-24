//FormAI DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp;
    srand(time(NULL)); // seed the random number generator with the current time

    for (int i = 0; i < 50; i++) { // take 50 temperature readings
        temp = rand() % 101; // generate a random temperature between 0 and 100 degrees Celsius
        printf("Temperature reading %d: %d degrees Celsius\n", i+1, temp);
        if (temp > 37) { // if the temperature is above 37 degrees, print a warning
            printf("*** WARNING *** Temperature is above 37 degrees Celsius\n");
        }
    }

    return 0;
}