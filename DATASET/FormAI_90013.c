//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define MAX_SPEED 5
#define NUM_CARS 5
#define TICKS 50

int road[ROAD_LENGTH];

void printRoad() {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i] == -1) {
            printf("_ ");
        } else {
            printf("%d ", road[i]);
        }
    }
    printf("\n");
}

void initializeCars() {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARS; i++) {
        int pos = rand() % ROAD_LENGTH;
        while (road[pos] != -1) {
            pos++;
            if (pos == ROAD_LENGTH) {
                pos = 0;
            }
        }
        road[pos] = MAX_SPEED;
    }
}

void moveCars() {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i] == -1) {
            continue;
        }

        int dist = 0;
        for (int j = i + 1; j < ROAD_LENGTH; j++) {
            if (road[j] != -1) {
                dist = j - i - 1;
                break;
            }
        }
        if (dist == 0 && road[i] < MAX_SPEED) {
            road[i]++;
        } else if (dist < road[i]) {
            road[i] = dist;
        } else {
            road[i] = MAX_SPEED;
        }
    }

    for (int i = ROAD_LENGTH - 1; i >= 0; i--) {
        if (road[i] == -1) {
            continue;
        }

        int newPos = i + road[i];
        if (newPos >= ROAD_LENGTH) {
            newPos -= ROAD_LENGTH;
            road[i] = -1;

            int j;
            for (j = i + 1; j < ROAD_LENGTH; j++) {
                if (road[j] != -1) {
                    break;
                }
            }
            road[newPos] = road[j];
            road[j] = -1;
        } else {
            road[newPos] = road[i];
            road[i] = -1;
        }
    }
}

int main() {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = -1;
    }
    
    initializeCars();

    for (int i = 0; i < TICKS; i++) {
        printf("Tick %d:\n", i + 1);
        printRoad();
        moveCars();
    }

    return 0;
}