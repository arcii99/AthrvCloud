//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

bool visited[ROWS][COLS];
int maze[ROWS][COLS];
int startX, startY, endX, endY;

void generateMaze() {
    //Initialize all cells as unvisited
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            visited[i][j] = false;
        }
    }

    //Set random start and end points
    srand(time(NULL));
    startX = rand() % ROWS;
    startY = rand() % COLS;
    endX = rand() % ROWS;
    endY = rand() % COLS;

    //Initialize the maze with walls, "-1" means a wall
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = -1;
        }
    }

    //Start building the maze
    struct Cell {
        int x, y;
        int lastDirection;
    };

    struct Cell stack[ROWS*COLS];
    int top = -1;

    stack[++top] = (struct Cell) {startX, startY, -1};

    while(top >= 0) {
        struct Cell current = stack[top--];

        visited[current.x][current.y] = true;

        //Set current position as a passage, "0" means a passage
        maze[current.x][current.y] = 0;
        int directions[4] = {1, 2, 3, 4};

        //Shuffle the directions
        for(int i=0; i<4; i++) {
            int temp = directions[i];
            int randomIndex = rand() % 4;
            directions[i] = directions[randomIndex];
            directions[randomIndex] = temp;
        }

        for(int i=0; i<4; i++) {
            int direction = directions[i];
            int newX = current.x, newY = current.y;

            switch(direction) {
                case 1: //Up
                    if(current.x > 0) {
                        newX--;
                    }
                    break;
                case 2: //Right
                    if(current.y < COLS-1) {
                        newY++;
                    }
                    break;
                case 3: //Down
                    if(current.x < ROWS-1) {
                        newX++;
                    }
                    break;
                case 4: //Left
                    if(current.y > 0) {
                        newY--;
                    }
                    break;
            }

            //Check if the new position is visited or out of bounds
            if(newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS || visited[newX][newY]) {
                continue;
            }

            //Break walls between the cells
            if(direction != current.lastDirection) {
                if(direction == 1) {//Up
                    maze[current.x-1][current.y] = 0;
                } else if(direction == 2) {//Right
                    maze[current.x][current.y+1] = 0;
                } else if(direction == 3) {//Down
                    maze[current.x+1][current.y] = 0;
                } else if(direction == 4) {//Left
                    maze[current.x][current.y-1] = 0;
                }
            }

            stack[++top] = (struct Cell) {newX, newY, direction};
        }
    }

    //Set start and end points as passages
    maze[startX][startY] = 0;
    maze[endX][endY] = 0;
}

void printMaze() {
    printf("\n");

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == -1) {
                printf("%c", '*');
            } else if(i == startX && j == startY) {
                printf("%c", 'S');
            } else if(i == endX && j == endY) {
                printf("%c", 'E');
            } else {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze();

    return 0;
}