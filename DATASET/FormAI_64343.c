//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROAD_LENGTH 100
#define MAX_CAR_SPEED 5

typedef enum {false, true} bool;

int road[ROAD_LENGTH];
int roadCopy[ROAD_LENGTH];

void printRoad() {
    for(int i = 0; i < ROAD_LENGTH; i++) {
        if(road[i] == -1) printf("-");
        else printf("%d", road[i]);
    }
    printf("\n");
}

void simulateTraffic() {
    for(int i = 0; i < ROAD_LENGTH; i++) {
        if(road[i] != -1) {
            int speed = road[i];
            bool canAccelerate = true;
            for(int j = 1; j <= speed && i+j < ROAD_LENGTH; j++) {
                if(road[i+j] != -1 && j != 1) {
                    canAccelerate = false;
                    break;
                }
                if(speed - j <= road[i+j]) {
                    speed = road[i+j] - 1;
                }
            }
            if(canAccelerate && speed < MAX_CAR_SPEED) speed++;
            int newPos = i + speed;
            if(newPos >= ROAD_LENGTH) {
                road[i] = -1;
            } else {
                road[newPos] = speed;
                road[i] = -1;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = -1;
    }
    for(int i = 0; i < ROAD_LENGTH/2; i++) {
        int randIndex = rand() % ROAD_LENGTH;
        while(road[randIndex] != -1) {
            randIndex = rand() % ROAD_LENGTH;
        }
        road[randIndex] = rand() % MAX_CAR_SPEED + 1;
    }
    printRoad();
    for(int i = 0; i < 100; i++) {
        simulateTraffic();
        printRoad();
    }
    return 0;
}