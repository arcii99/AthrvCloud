//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE];

typedef struct {
    int x,y;
} Position;

void initializeMaze() {
    int i,j;
    for(i=0; i<MAZE_SIZE; i++) {
        for(j=0; j<MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze() {
    int i,j;
    for(i=0; i<MAZE_SIZE; i++) {
        for(j=0; j<MAZE_SIZE; j++) {
            if(maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int getValidRandom(int min, int max) {
    int valid = 0;
    int randNum;
    while(!valid) {
        randNum = rand() % (max + 1 - min) + min;
        if(randNum >= min && randNum <= max) {
            valid = 1;
        }
    }
    return randNum;
}

int isPositionValid(Position position) {
    if(position.x < 0 || position.y < 0 || position.x >= MAZE_SIZE || position.y >= MAZE_SIZE) {
        return 0;
    }
    if(maze[position.x][position.y] == 0) {
        return 0;
    }
    return 1;
}

void generateMaze() {
    Position currentPosition = {.x = 0, .y = 0};
    maze[currentPosition.x][currentPosition.y] = 0;

    while(1) {
        Position possibleMoves[4] = {
            {.x = currentPosition.x-1, .y = currentPosition.y},
            {.x = currentPosition.x+1, .y = currentPosition.y},
            {.x = currentPosition.x, .y = currentPosition.y-1},
            {.x = currentPosition.x, .y = currentPosition.y+1}
        };
        int validMoves[4] = {0,0,0,0};
        int i;
        for(i=0; i<4; i++) {
            if(isPositionValid(possibleMoves[i])) {
                validMoves[i] = 1;
            }
        }
        int validCount = 0;
        for(i=0; i<4; i++) {
            if(validMoves[i]) {
                validCount++;
            }
        }
        if(validCount == 0) {
            break;
        }

        int chosenIndex = getValidRandom(0,3);
        while(!validMoves[chosenIndex]) {
            chosenIndex = getValidRandom(0,3);
        }
        Position chosenPosition = possibleMoves[chosenIndex];
        maze[chosenPosition.x][chosenPosition.y] = 0;
        currentPosition = chosenPosition;
    }
}

int main() {
    initializeMaze();
    srand(time(NULL));
    generateMaze();
    printMaze();
    return 0;
}