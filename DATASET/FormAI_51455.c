//FormAI DATASET v1.0 Category: Physics simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Happy Physics Simulation!\n");
    printf("This program simulates how happy a ball is when it bounces on the ground.\n\n");

    srand(time(0));
    float height = 10.0;
    float energy_loss = rand() % 11 / 100.0; // Random number between 0 and 0.1

    printf("Starting height: %.2f\n", height);
    printf("Energy loss: %.2f\n", energy_loss);
    printf("\n");

    int count = 0;
    while (height > 0.5){
        count++;
        float velocity = 0.9 * sqrt(2 * 9.81 * height); // sqrt(2gh)
        height = (height * (1 - energy_loss)); // energy loss
        printf("Bounce #%d:\n", count);
        printf("Velocity: %.2f m/s\n", velocity);
        printf("Height: %.2f m\n", height);
        printf("\n");
    }

    printf("The ball is no longer happy and has stopped bouncing.\n");
    printf("It bounced %d times before coming to a stop.\n", count);

    return 0;
}