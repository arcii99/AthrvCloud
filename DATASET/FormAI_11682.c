//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
/* REMOTE CONTROL VEHICLE SIMULATION */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_INSTRUCTIONS 10

typedef struct {
    int x;
    int y;
} Position;

int map[MAP_SIZE][MAP_SIZE];

int main() {
    srand(time(NULL));

    // initialize map with random obstacles
    for(int i=0; i<MAP_SIZE; i++) {
        for(int j=0; j<MAP_SIZE; j++) {
            map[i][j] = rand() % 2;
        }
    }

    Position rcv_pos = {rand() % MAP_SIZE, rand() % MAP_SIZE}; // place rcv randomly on map
    Position target_pos = {rand() % MAP_SIZE, rand() % MAP_SIZE}; // place target randomly on map

    printf("Starting position: (%d,%d)\n", rcv_pos.x, rcv_pos.y);
    printf("Target position: (%d,%d)\n", target_pos.x, target_pos.y);

    int num_instructions = rand() % MAX_INSTRUCTIONS + 1; // generate random number of instructions

    printf("Number of instructions: %d\n", num_instructions);

    for(int i=0; i<num_instructions; i++) {
        int direction = rand() % 4; // generate random direction
        if(direction == 0 && rcv_pos.y > 0) { // move up
            rcv_pos.y--;
        } else if(direction == 1 && rcv_pos.y < MAP_SIZE-1) { // move down
            rcv_pos.y++;
        } else if(direction == 2 && rcv_pos.x > 0) { // move left
            rcv_pos.x--;
        } else if(direction == 3 && rcv_pos.x < MAP_SIZE-1) { // move right
            rcv_pos.x++;
        }
        if(rcv_pos.x == target_pos.x && rcv_pos.y == target_pos.y) { // reached the target
            printf("Target reached in %d instructions!\n", i+1);
            return 0;
        }
        printf("Instruction %d: (%d,%d)\n", i+1, rcv_pos.x, rcv_pos.y);
    }

    printf("Target not reached in %d instructions\n", num_instructions);

    return 0;
}