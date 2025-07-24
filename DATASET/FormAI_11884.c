//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define NUM_OF_STATES 3
#define MAX_CARS 15

int main() {
    int currentState = GREEN;
    int nextSwitch = 30;
    int carsWaiting = 0;
    int carsCrossed = 0;
    unsigned int seed = time(NULL);

    srand(seed);

    while(1) {
        if(currentState == GREEN) {
            printf("\nGreen Light: Go!");
            wait(10); // simulate cars crossing
            carsCrossed += rand() % (MAX_CARS - carsWaiting);
            carsWaiting = 0;

            if(rand() % 100 < 30) {
                carsWaiting = rand() % MAX_CARS;
                printf("\nCars waiting at green: %d", carsWaiting);
            }

            currentState = YELLOW;
            nextSwitch = 5;
        } else if(currentState == YELLOW) {
            printf("\nYellow Light: Caution!");
            wait(3); // simulate time to switch
            currentState = RED;
            nextSwitch = 10;
        } else {
            printf("\nRed Light: Stop!");
            wait(1); // simulate pedestrians crossing
            currentState = GREEN;
            nextSwitch = 30;
        }

        if(carsCrossed >= 100) {
            printf("\nTraffic controller shutting down, 100 cars crossed.");
            break;
        }

        printf("\nNext light switch in %d seconds.", nextSwitch);

        while(nextSwitch) {
            printf("\nTime remaining: %d seconds", nextSwitch);
            wait(1);
            nextSwitch--;
        }
    }

    return 0;
}

void wait(int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) {}
}