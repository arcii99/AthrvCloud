//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));
    float temperature = (float)(rand() % 100);

    printf("Welcome to the Surrealist Temperature Monitor!\n");
    printf("Your current temperature reading is: %0.1fC\n", temperature);

    while(1) {
        float variance = (float)(rand() % 10);
        int direction = rand() % 2;

        //if direction is 0, subtract the variance from temperature
        if(direction == 0) {
            temperature -= variance;
        } 
        //if direction is 1, add the variance to temperature
        else {
            temperature += variance;
        }

        printf("The temperature is now %0.1fC\n", temperature);

        if(temperature < 0) {
            printf("The temperature has dropped below freezing!\n");
        } 
        else if(temperature > 100) {
            printf("The temperature is dangerously high!\n");
            printf("Alert! Alert! Initiating emergency cooling procedures...\n");
        }

        //wait for a random amount of time
        int delay = rand() % 10;
        printf("Waiting for %d seconds...\n\n", delay);
        sleep(delay);
    }

    return 0;
}