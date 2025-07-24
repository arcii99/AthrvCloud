//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 3

int Elevators[ELEVATORS];

void reset_elevators() {
    int i;
    for(i = 0; i < ELEVATORS; i++) {
        Elevators[i] = 1;
    }
}

void print_elevators() {
    int i;
    for(i = 0; i < ELEVATORS; i++) {
        printf("Elevator %d is on floor %d\n", i+1, Elevators[i]);
    }
}

void move_elevators() {
    int i;
    for(i = 0; i < ELEVATORS; i++) {
        if(rand() % 2 == 1 && Elevators[i] != FLOORS) {
            Elevators[i]++;
            printf("Elevator %d moved up to floor %d\n", i+1, Elevators[i]);
        } else if(Elevators[i] != 1) {
            Elevators[i]--;
            printf("Elevator %d moved down to floor %d\n", i+1, Elevators[i]);
        }
    }
}

int main() {
    srand(time(NULL));
    reset_elevators();
    int i;
    for(i = 0; i < 10; i++) {
        printf("------------------\n");
        printf("Time: %d\n", i+1);
        print_elevators();
        move_elevators();
    }
    return 0;
}