//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    
    srand(time(NULL)); // set the seed for random number generator
    
    int distance = rand() % 100 + 1; // generate a random distance between 1 and 100
    
    printf("Your vehicle is starting at position 0.\n");
    printf("The distance to your target is: %d meters.\n", distance);
    
    int position = 0; // starting position of the vehicle
    int moves = 0; // number of moves taken
    
    while(position < distance)
    {
        int action = rand() % 2; // decide randomly between move and wait
        
        if(action == 0) // move forward
        {
            int moveAmount = rand() % 10 + 1; // generate a random move amount between 1 and 10
            position += moveAmount;
            printf("Move forward %d meters. ", moveAmount);
            
            if(position >= distance) // check if the vehicle has reached the target
            {
                printf("Congratulations! You reached the target in %d moves!\n", moves);
                break;
            }
        }
        else // wait
        {
            printf("Wait for a moment. ");
        }
        
        int waitTime = rand() % 3 + 1; // generate a random wait time between 1 and 3 seconds
        printf("Wait for %d seconds.\n", waitTime);
        
        moves++; // increase the number of moves taken
    }
    
    if(position < distance) // if the vehicle did not reach the target
    {
        printf("Mission failed. The vehicle stopped at position %d after %d moves.\n", position, moves);
    }
    
    return 0;
}