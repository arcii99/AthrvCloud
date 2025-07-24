//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Initialize variables
    int current_pos = 0; // initialize robot's current position as 0
    srand(time(NULL)); // seed random number generator
    
    // Move robot randomly for 50 attempts
    for (int i = 0; i < 50; i++) {
        int move = rand() % 3 - 1; // randomly generate -1, 0, or +1
        
        switch (move) {
            case -1: // if move is -1, move robot left by 1
                current_pos--;
                printf("Robot moved left by 1. Current position: %d\n", current_pos);
                break;
            case 0: // if move is 0, robot does not move
                printf("Robot did not move. Current position: %d\n", current_pos);
                break;
            case 1: // if move is +1, move robot right by 1
                current_pos++;
                printf("Robot moved right by 1. Current position: %d\n", current_pos);
                break;
        }
    }
    
    // Return 0 to indicate program successfully completed
    return 0;
}