//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 0, y = 0, dir = 0;
    srand(time(NULL));
    
    printf("Starting position: (%d, %d)\n", x, y);
    
    for(int i = 0; i < 10; i++) {
        int move = rand() % 3 - 1; // randomly move -1, 0, or 1 units in either direction
        dir = (dir + move + 4) % 4; // update direction (N = 0, E = 1, S = 2, W = 3)
        
        switch (dir) {
            case 0: // move north
                y++;
                break;
            case 1: // move east
                x++;
                break;
            case 2: // move south
                y--;
                break;
            case 3: // move west
                x--;
                break;
            default: 
                printf("Error: Invalid direction");
                return 1;
        }
        
        printf("Movement #%d: (%d, %d)\n", i+1, x, y);
    }
    
    return 0;
}