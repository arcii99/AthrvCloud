//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MOVES 100
#define MAX_ROWS 5
#define MAX_COLS 5

int robotX = 0;
int robotY = 0;

void moveRobot(char move, bool *success){
    int newX = robotX, newY = robotY;
    if(move == 'U' && robotY > 0) newY--;
    else if(move == 'D' && robotY < MAX_ROWS-1) newY++;
    else if(move == 'L' && robotX > 0) newX--;
    else if(move == 'R' && robotX < MAX_COLS-1) newX++;

    if(newX == robotX && newY == robotY){
        printf("Invalid move %c!\n", move);
        *success = false;
    }else{
        printf("Robot moved %c to (%d,%d)\n", move, newX, newY);
        robotX = newX;
        robotY = newY;
        *success = true;
    }
}

int main(){
    char moves[MAX_MOVES];
    int numMoves = 0;

    printf("Welcome to Robot Movement Controller!\n");
    printf("Enter a sequence of moves (UDLR) to move the robot:\n");

    // Read user input
    while(true){
        char move = getchar();
        if(move == '\n') break;
        if(numMoves >= MAX_MOVES){
            printf("Too many moves entered!\n");
            return 1;
        }
        moves[numMoves++] = move;
    }

    // Process moves
    for(int i=0; i<numMoves; i++){
        bool success;
        moveRobot(moves[i], &success);
        if(!success){
            printf("Error: Invalid move sequence!\n");
            return 1;
        }
    }

    printf("Robot ended at (%d,%d)\n", robotX, robotY);

    return 0;
}