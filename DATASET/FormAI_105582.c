//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 100

//Define the movement functions
void moveForward(int steps);
void turnLeft(int degrees);
void turnRight(int degrees);
void moveBackward(int steps);

int main()
{
    int moves[MAX_MOVES]; //store of all the moves
    int numMoves = 0;
    srand(time(NULL)); //seed for random function

    printf("Initiating C Robot Movement Control Program...\n");

    //randomly generate movement sequence
    for(int i = 0; i < MAX_MOVES; i++)
    {
        moves[i] = rand() % 4; //0-forward, 1-left, 2-right, 3-backward
        numMoves++;
    }

    printf("The sequence of moves generated for the robot to follow is:\n");

    //output the sequence of moves
    for(int i = 0; i < numMoves; i++)
    {
        switch(moves[i])
        {
            case 0:
                printf("Move forward\n");
                break;
            case 1:
                printf("Turn left\n");
                break;
            case 2:
                printf("Turn right\n");
                break;
            case 3:
                printf("Move backward\n");
                break;
        }
    }

    printf("Starting robot movement...\n");

    //execute the movement sequence
    for(int i = 0; i < numMoves; i++)
    {
        switch(moves[i])
        {
            case 0:
                moveForward(10); //move forward 10 steps
                break;
            case 1:
                turnLeft(90); //turn left 90 degrees
                break;
            case 2:
                turnRight(90); //turn right 90 degrees
                break;
            case 3:
                moveBackward(10); //move backward 10 steps
                break;
        }
    }

    printf("Robot movement complete.\n");

    return 0;
}

void moveForward(int steps)
{
    printf("Moving forward %d steps.\n", steps);
}

void turnLeft(int degrees)
{
    printf("Turning left %d degrees.\n", degrees);
}

void turnRight(int degrees)
{
    printf("Turning right %d degrees.\n", degrees);
}

void moveBackward(int steps)
{
    printf("Moving backward %d steps.\n", steps);
}