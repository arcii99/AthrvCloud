//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Setting up a seed for random number generation (based on current time)
    srand(time(NULL));

    // Initializing the variables for the position and direction of the vehicle
    int x = 0;
    int y = 0;
    char direction = 'E';

    // Defining the grid size and the goal position
    const int GRID_SIZE = 10;
    const int GOAL_X = 8;
    const int GOAL_Y = 9;

    // Printing initial state of the vehicle
    printf("Vehicle is at %d,%d and facing %c\n", x, y, direction);

    // Simulating the movement of the remote control vehicle
    for(int i = 0; i < 10; i++){
        // Generating a random number between 1 and 4 (inclusive) to determine the next move
        int next_move = rand() % 4 + 1;

        // Switching on the next move to determine the action and updating the vehicle position and direction
        switch(next_move){
            case 1: // Move up
                if(y < GRID_SIZE-1){
                    y++;
                }
                break;
            case 2: // Move down
                if(y > 0){
                    y--;
                }
                break;
            case 3: // Move left
                if(x > 0){
                    x--;
                }
                break;
            case 4: // Move right
                if(x < GRID_SIZE-1){
                    x++;
                }
                break;
        }

        // Updating the direction of the vehicle based on the current position and the position of the goal
        if(x < GOAL_X){
            direction = 'E';
        } else if(x > GOAL_X){
            direction = 'W';
        } else if(y < GOAL_Y){
            direction = 'N';
        } else if(y > GOAL_Y){
            direction = 'S';
        } else {
            direction = 'X';
        }

        // Printing the current state of the vehicle
        printf("Vehicle is at %d,%d and facing %c\n", x, y, direction);

        // If the vehicle has reached the goal, exit the loop
        if(x == GOAL_X && y == GOAL_Y){
            break;
        }
    }

    // Printing the final state of the vehicle
    printf("Vehicle has reached the goal at %d,%d and facing %c\n", x, y, direction);

    return 0;
}