//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 50, y = 50; // initial coordinates of the robot
    int i, j, k;
    char move;
    srand(time(NULL));
    
    printf("The robot is at (%d,%d)\n", x, y); // print initial coordinates
    
    for(i = 0; i < 5; i++) // perform 5 random movements
    {
        k = rand() % 4; // generate random number for movement direction
        
        switch(k)
        {
            case 0: // move up
                x--;
                move = 'U';
                break;
                
            case 1: // move down
                x++;
                move = 'D';
                break;
                
            case 2: // move left
                y--;
                move = 'L';
                break;
                
            case 3: // move right
                y++;
                move = 'R';
                break;
        }
        
        printf("Moved %c, now at (%d,%d)\n", move, x, y); // print movement details
    }
    
    return 0;
}