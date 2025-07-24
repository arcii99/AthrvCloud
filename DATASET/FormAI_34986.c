//FormAI DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0; // Robot position
    
    while (1) {
        char direction;
        printf("Enter direction (N, S, E, W): ");
        scanf("%c", &direction); // Get user input
        
        switch (direction) {
            case 'N':
                y += 1; // Move north
                break;
            case 'S':
                y -= 1; // Move south
                break;
            case 'E':
                x += 1; // Move east
                break;
            case 'W':
                x -= 1; // Move west
                break;
            default:
                printf("Invalid direction\n");
                continue;
        }
        
        printf("Robot position: (%d, %d)\n", x, y); // Output current position
    }
    
    return 0;
}