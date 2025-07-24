//FormAI DATASET v1.0 Category: Robot movement control ; Style: Cyberpunk
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 

int main() 
{
    //Start program
    printf("Initialization Sequence Initiated.\n");
    printf("Cyberpunk C Robot Movement Control Program online.\n");
    
    //Initialize variables
    bool isRunning = true;
    int x = 0;
    int y = 0;
    int direction = 0;
    srand(time(NULL)); //Seed for random function
    
    //Main loop
    while(isRunning)
    {
        //Generate random movement
        int movement = rand() % 4;
        
        //Update robot position based on movement
        if(movement == 0)
        {
            printf("Moving North.\n");
            y++;
        }
        else if(movement == 1)
        {
            printf("Moving East.\n");
            x++;
        }
        else if(movement == 2)
        {
            printf("Moving South.\n");
            y--;
        }
        else if(movement == 3)
        {
            printf("Moving West.\n");
            x--;
        }
        
        //Update direction based on movement
        if(movement == 0 || movement == 2)
        {
            direction = movement;
        }
        else if(movement == 1)
        {
            direction = (direction + 1) % 4;
        }
        else if(movement == 3)
        {
            direction = (direction - 1 + 4) % 4;
        }
        
        //Print current position and direction
        printf("Current position: (%d,%d)\n", x, y);
        if(direction == 0)
        {
            printf("Current direction: North.\n");
        }
        else if(direction == 1)
        {
            printf("Current direction: East.\n");
        }
        else if(direction == 2)
        {
            printf("Current direction: South.\n");
        }
        else if(direction == 3)
        {
            printf("Current direction: West.\n");
        }
        
        //Wait for one second before next movement
        printf("Waiting for next movement.\n");
        sleep(1);
    }
    
    //End program
    printf("Shutdown Sequence Initiated.\n");
    printf("Cyberpunk C Robot Movement Control Program offline.\n");
    return 0;
}