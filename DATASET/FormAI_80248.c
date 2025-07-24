//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define NUM_MOVES 10

// function to randomly generate a move
int random_move() {
    int move = rand() % 4;  // generates a random number between 0 and 3
    return move;
}

int main() {
    srand(time(NULL));  // initializes random number generator
    
    int vehicle[2] = {0, 0};  // initial position of vehicle
    int remote[NUM_MOVES];  // array to store remote control commands
    
    // fill remote array with random moves
    for (int i = 0; i < NUM_MOVES; i++) {
        remote[i] = random_move();
    }
    
    // simulate the vehicle movement based on remote control commands
    for (int i = 0; i < NUM_MOVES; i++) {
        switch (remote[i]) {
            case 0:  // move up
                if (vehicle[0] > 0) {
                    vehicle[0]--;
                }
                break;
            case 1:  // move down
                if (vehicle[0] < ROWS - 1) {
                    vehicle[0]++;
                }
                break;
            case 2:  // move left
                if (vehicle[1] > 0) {
                    vehicle[1]--;
                }
                break;
            case 3:  // move right
                if (vehicle[1] < COLS - 1) {
                    vehicle[1]++;
                }
                break;
        }
        
        // print the new position of the vehicle
        printf("Moved %d spaces %s\n", i+1, (remote[i]==0)?"up":(remote[i]==1)?"down":(remote[i]==2)?"left":"right");
        printf("New position of vehicle: (%d, %d)\n", vehicle[0], vehicle[1]);
    }
    
    return 0;
}