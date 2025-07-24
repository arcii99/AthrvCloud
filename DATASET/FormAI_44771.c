//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTERSECTION_SIZE 5
#define MAX_SPEED 50
#define CAR_PROBABILITY 0.5
#define SECONDS_PER_STEP 2

typedef struct {
    int position;
    int speed;
    int distanceToIntersection;
} Car;

int main() {
    srand(time(NULL));

    int intersection[INTERSECTION_SIZE] = {0};
    int time = 0;
    int carCount = 0;
    int carsPassed = 0;

    while (carsPassed < 10) {
        printf("Time: %d\n", time);

        // Add new cars to the simulation
        if (rand() < CAR_PROBABILITY * RAND_MAX) {
            Car newCar = {0, rand() % MAX_SPEED + 1, rand() % INTERSECTION_SIZE};
            if (intersection[newCar.distanceToIntersection] == 0) {
                carCount++;
                intersection[newCar.distanceToIntersection] = newCar.speed;
                printf("New car added: position=%d, speed=%d, distanceToIntersection=%d\n",
                       newCar.position, newCar.speed, newCar.distanceToIntersection);
            }
        }

        // Update position of all cars and remove cars that have left the simulation.
        for (int i = INTERSECTION_SIZE - 1; i >= 0; i--) {
            if (intersection[i] == 0) {
                continue;
            }

            int newPosition = i + intersection[i];
            if (newPosition >= INTERSECTION_SIZE) {
                intersection[i] = 0;
                carsPassed++;
                carCount--;
            } else {
                intersection[newPosition] = intersection[i];
                intersection[i] = 0;
            }
        }

        // Print the position of all cars at the current time step
        for (int i = INTERSECTION_SIZE - 1; i >= 0; i--) {
            if (intersection[i] == 0) {
                printf("_ ");
            } else {
                printf("%d ", intersection[i]);
            }
        }
        printf("\n");

        time += SECONDS_PER_STEP;

        printf("\n");
    }

    printf("Simulation complete: %d cars passed the intersection.\n", carsPassed);

    return 0;
}