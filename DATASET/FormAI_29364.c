//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define NUM_VEHICLES 5
#define MAX_SPEED 5

void printState(int* state) {
    printf("|");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (state[i] != -1) {
            printf(" %d |", state[i]);
        } else {
            printf(" X |");
        }
    }
    printf("\n");
}

void move(int* state, int i) {
    if (state[i] == -1) {
        return;
    }
    int speed = rand() % MAX_SPEED + 1;
    if (i + speed >= ROAD_LENGTH) {
        state[i] = -1;
        return;
    }
    if (state[i + speed] != -1) {
        return;
    }
    state[i + speed] = state[i];
    state[i] = -1;
}

int main() {
    srand(time(NULL));
    int state[ROAD_LENGTH];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        state[i] = -1;
    }
    for (int i = 0; i < NUM_VEHICLES; i++) {
        int pos = rand() % ROAD_LENGTH;
        while (state[pos] != -1) {
            pos = rand() % ROAD_LENGTH;
        }
        state[pos] = i;
    }
    printf("Initial state:\n");
    printState(state);
    for (int t = 1; t <= 10; t++) {
        printf("Time %d:\n", t);
        for (int i = 0; i < ROAD_LENGTH; i++) {
            move(state, i);
        }
        printState(state);
    }
    return 0;
}