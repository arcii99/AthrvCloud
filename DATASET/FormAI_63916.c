//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 50
#define MAX_LANE_LENGTH 15

int lanes[3][MAX_LANE_LENGTH];
int carCount[3] = { 0 };
int moveQueue[500][3];
int moveCount = 0;

// Function to initialize the lanes with cars randomly
void initLanes() {
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_LANE_LENGTH; j++) {
            if (rand() % 2 == 1) {
                lanes[i][j] = 1;
                carCount[i]++;
            }
            else {
                lanes[i][j] = 0;
            }
        }
    }
}

// Function to print the current state of the lanes
void printLanes() {
    printf("\n------------------------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_LANE_LENGTH; j++) {
            if (lanes[i][j] == 1) {
                printf("C ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("------------------------------\n");
}

// Function to move all the cars in the moveQueue
void moveCars() {
    for (int i = 0; i < moveCount; i++) {
        int lane = moveQueue[i][0];
        int position = moveQueue[i][1];
        int direction = moveQueue[i][2];
        if (direction == 0) { // move left
            if (position > 0 && lanes[lane][position - 1] == 0) {
                lanes[lane][position] = 0;
                lanes[lane][position - 1] = 1;
            }
        }
        else { // move right
            if (position < MAX_LANE_LENGTH - 1 && lanes[lane][position + 1] == 0) {
                lanes[lane][position] = 0;
                lanes[lane][position + 1] = 1;
            }
        }
    }
}

int main() {
    initLanes();
    printLanes();

    while (1) {
        // Move cars randomly
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < MAX_LANE_LENGTH; j++) {
                if (lanes[i][j] == 1) {
                    int randMove = rand() % 3 - 1;
                    if (randMove == -1) { // move left
                        if (j > 0 && lanes[i][j-1] == 0) {
                            moveQueue[moveCount][0] = i;
                            moveQueue[moveCount][1] = j;
                            moveQueue[moveCount][2] = 0;
                            moveCount++;
                        }
                    }
                    else if (randMove == 1) { // move right
                        if (j < MAX_LANE_LENGTH - 1 && lanes[i][j+1] == 0) {
                            moveQueue[moveCount][0] = i;
                            moveQueue[moveCount][1] = j;
                            moveQueue[moveCount][2] = 1;
                            moveCount++;
                        }
                    }
                }
            }
        }

        // Move all the cars in the moveQueue
        moveCars();

        // Print the current state of the lanes
        printLanes();

        // Exit if all the lanes are empty
        if (carCount[0] + carCount[1] + carCount[2] == 0) {
            break;
        }

        // Reset the moveQueue
        moveCount = 0;
    }

    return 0;
}