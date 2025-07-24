//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define Constants
#define MAX_LANE_SIZE 10
#define MIN_CAR_SPEED 30
#define MAX_CAR_SPEED 80
#define MIN_CAR_DISTANCE 5
#define MAX_CAR_DISTANCE 20

//Define Structures
struct car {
    int lane;
    int position;
    int speed;
};

//Function Prototypes
void initTrafficFlow();
void updateTrafficFlow();
void printTrafficFlow();
int getRandomInt(int, int);

//Global Variables
struct car trafficFlow[3][MAX_LANE_SIZE];
int timeStep = 0;

//Main Function
int main() {
    initTrafficFlow();
    printf("Initial Traffic Flow:\n");
    printTrafficFlow();
    while(timeStep < 20) {
        updateTrafficFlow();
        printf("Traffic Flow at Time Step %d:\n", timeStep);
        printTrafficFlow();
        timeStep++;
    }
    return 0;
}

//Initialize Traffic Flow
void initTrafficFlow() {
    srand(time(0));
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < MAX_LANE_SIZE; j++) {
            trafficFlow[i][j].lane = i;
            trafficFlow[i][j].position = j+1;
            trafficFlow[i][j].speed = getRandomInt(MIN_CAR_SPEED, MAX_CAR_SPEED);
        }
    }
}

//Update Traffic Flow
void updateTrafficFlow() {
    int i, j, k, l;
    struct car tempCar;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < MAX_LANE_SIZE; j++) {
            if(trafficFlow[i][j].position == MAX_LANE_SIZE) {
                trafficFlow[i][j].position = 1;
            }
            else {
                for(k = i; k < 3; k++) {
                    for(l = j+1; l < MAX_LANE_SIZE; l++) {
                        if(trafficFlow[k][l].position - trafficFlow[i][j].position <= getRandomInt(MIN_CAR_DISTANCE, MAX_CAR_DISTANCE)) {
                            //Cars are too close, so current car slows down
                            if(trafficFlow[i][j].speed > trafficFlow[k][l].speed) {
                                trafficFlow[i][j].speed = trafficFlow[k][l].speed;
                            }
                            //Cars are not too close, so current car speeds up
                            else if(trafficFlow[i][j].speed < trafficFlow[k][l].speed) {
                                trafficFlow[i][j].speed += getRandomInt(1, 5);
                                if(trafficFlow[i][j].speed > MAX_CAR_SPEED) {
                                    trafficFlow[i][j].speed = MAX_CAR_SPEED;
                                }
                            }
                            else {
                                //Cars are at equal speed, do nothing
                            }
                        }
                    }
                }
                //Move car based on new speed
                tempCar = trafficFlow[i][j];
                trafficFlow[tempCar.lane][(tempCar.position+tempCar.speed-1)%MAX_LANE_SIZE] = tempCar;
                trafficFlow[i][j].position += trafficFlow[i][j].speed;
            }
        }
    }
}

//Print Current Traffic Flow
void printTrafficFlow() {
    int i, j;
    for(i = 0; i < 3; i++) {
        printf("Lane %d: ", i+1);
        for(j = 0; j < MAX_LANE_SIZE; j++) {
            printf("%c ", (j % 2 == 0) ? '|' : '-');
            if(trafficFlow[i][j].position == MAX_LANE_SIZE) {
                printf("%c", '>');
            }
            else {
                printf("%d", trafficFlow[i][j].position);
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Get Random Integer within Range [min, max]
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}