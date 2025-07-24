//FormAI DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

int map[MAP_SIZE][MAP_SIZE] = {0}; // initializing map to all 0s

int main() {
    int robotX = 0; // starting position of robot
    int robotY = 0;
    int count = 0; // keep track of number of moves

    srand(time(NULL)); // initializing random number generator

    // create obstacles
    for (int i = 0; i < MAP_SIZE; i++) {
        int obstacleX = rand() % MAP_SIZE;
        int obstacleY = rand() % MAP_SIZE;
        if (obstacleX != robotX && obstacleY != robotY) { // if obstacle does not overlap with robot
            map[obstacleX][obstacleY] = 1; // set obstacle in map
        }
    }

    // print initial map
    printf("Starting position: (%d, %d)\n", robotX, robotY);
    printf("Initial map:\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == robotX && j == robotY) { // if current position is robot's
                printf(" R ");
            } else if (map[i][j] == 1) { // if current position has obstacle
                printf(" X ");
            } else { // if current position is empty
                printf(" O ");
            }
        }
        printf("\n");
    }

    // move robot until it reaches goal (bottom-right corner)
    while (robotX != MAP_SIZE - 1 || robotY != MAP_SIZE - 1) {
        int direction = rand() % 4; // generate random direction

        switch (direction) {
            case 0: // move up
                if (robotX > 0 && map[robotX - 1][robotY] != 1) { // if move does not overlap with obstacle or go out of bounds
                    robotX--;
                    count++;
                }
                break;
            case 1: // move down
                if (robotX < MAP_SIZE - 1 && map[robotX + 1][robotY] != 1) {
                    robotX++;
                    count++;
                }
                break;
            case 2: // move left
                if (robotY > 0 && map[robotX][robotY - 1] != 1) {
                    robotY--;
                    count++;
                }
                break;
            case 3: // move right
                if (robotY < MAP_SIZE - 1 && map[robotX][robotY + 1] != 1) {
                    robotY++;
                    count++;
                }
                break;
        }

        // print map after each move
        printf("\nMove %d: Robot moved in direction %d\n", count, direction);
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                if (i == robotX && j == robotY) { // if current position is robot's
                    printf(" R ");
                } else if (map[i][j] == 1) { // if current position has obstacle
                    printf(" X ");
                } else { // if current position is empty
                    printf(" O ");
                }
            }
            printf("\n");
        }
    }

    printf("\n\nROBOT REACHED GOAL!!! Total moves: %d\n", count);

    return 0;
}