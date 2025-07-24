//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CARS 10
#define TRAFFIC_LIGHT_DELAY 5

typedef struct car {
    int speed;
    int position;
} Car;

void printRoad(Car road[]) {
    int i;
    for(i = 0; i < MAX_CARS; i++) {
        if(road[i].position == -1) {
            printf("- ");
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
    for(i = 0; i < MAX_CARS; i++) {
        if(road[i].position == -1) {
            printf("- ");
        } else {
            printf("%d ", road[i].speed);
        }
    }
    printf("\n");
}

void moveCars(Car road[]) {
    int i;
    for(i = MAX_CARS - 1; i > 0; i--) {
        if(road[i-1].position == -1) {
            road[i].position = -1;
        } else {
            road[i].position = road[i-1].position + road[i-1].speed;
            if(road[i].position >= MAX_CARS) {
                road[i].position = -1;
            }
        }
    }
    road[0].position += road[0].speed;
    if(road[0].position >= MAX_CARS) {
        road[0].position = -1;
    }
}

void spawnCar(Car road[]) {
    int i, j;
    int empty_pos = -1;
    for(i = 0; i < MAX_CARS; i++) {
        if(road[i].position == -1) {
            empty_pos = i;
            continue;
        }
        if(i > 0 && road[i].position == road[i-1].position + 1) {
            //there is a car in front
            break;
        }
    }
    if(i < MAX_CARS || empty_pos == -1) {
        //no space to spawn car
        return;
    }
    road[empty_pos].position = 0;
    road[empty_pos].speed = (rand() % 3) + 1; //random speed between 1 and 3
}

void simulateTraffic(Car road[], int time_steps) {
    int i;
    for (i = 0; i < time_steps; i++) {
        system("clear"); //clear terminal window
        printf("Time: %d\n", i);
        printRoad(road);
        moveCars(road);
        if(i % TRAFFIC_LIGHT_DELAY == 0) {
            spawnCar(road);
        }
        usleep(500000); //delay for half a second
    }
}

int main() {
    srand(time(NULL)); //seed random number generator
    Car road[MAX_CARS];
    memset(road, -1, sizeof road); //initialize road with empty slots
    simulateTraffic(road, 100);
    return 0;
}