//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
/* Traffic Flow Simulation */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_SPEED 5
#define MAX_POSITION 50
#define MAX_RUNTIME 100

/* Function to generate random number between min and max values */
int random_num(int min, int max) {
    return (rand() % (max - min)) + min;
}

/* Function to print current position of each car */
void print_position(int runtime, int position[], int num_cars) {
    printf("Time %d:\n", runtime);
    for(int i = 0; i < num_cars; i++) {
        for(int j = 0; j < position[i]; j++)
            printf("-");
        printf(">%d\n", i);
    }
}

int main() {
    srand(time(NULL));  // initialize random seed

    int num_cars = random_num(1, MAX_CARS);  // generate number of cars
    int position[num_cars], speed[num_cars];

    // initialize starting position and speed of each car
    for(int i = 0; i < num_cars; i++) {
        position[i] = random_num(1, MAX_POSITION);
        speed[i] = random_num(1, MAX_SPEED);
    }

    // run simulation
    for(int t = 1; t <= MAX_RUNTIME; t++) {
        for(int i = 0; i < num_cars; i++) {
            position[i] += speed[i];
            if(position[i] > MAX_POSITION)  // check for out of bounds
                position[i] = 1;

            // check for collision
            for(int j = 0; j < num_cars; j++) {
                if(i != j && position[i] == position[j]) {
                    speed[i] = speed[j] = 0;
                    break;
                }
            }
        }
        print_position(t, position, num_cars);  // print current position
    }

    return 0;
}