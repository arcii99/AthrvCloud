//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

typedef enum MazePiece {
    WALL,
    PATH,
    START,
    END
} MazePiece;

void initializeMaze(MazePiece maze[ROWS][COLS]) {
    int i, j;

    // Initialize all maze pieces as walls
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Set maze starting and ending points
    maze[0][0] = START;
    maze[ROWS-1][COLS-1] = END;
}

int canMoveUp(MazePiece maze[ROWS][COLS], int row, int col) {
    if(row-1 >= 0 && maze[row-1][col] == WALL) {
        return 1;
    }
    return 0;
}

int canMoveDown(MazePiece maze[ROWS][COLS], int row, int col) {
    if(row+1 < ROWS && maze[row+1][col] == WALL) {
        return 1;
    }
    return 0;
}

int canMoveLeft(MazePiece maze[ROWS][COLS], int row, int col) {
    if(col-1 >= 0 && maze[row][col-1] == WALL) {
        return 1;
    }
    return 0;
}

int canMoveRight(MazePiece maze[ROWS][COLS], int row, int col) {
    if(col+1 < COLS && maze[row][col+1] == WALL) {
        return 1;
    }
    return 0;
}

void generateMaze(MazePiece maze[ROWS][COLS], int row, int col) {
    int moves[4] = {-1, -1, -1, -1};
    int numMoves = 0;

    // Check if can move up
    if(canMoveUp(maze, row, col)) {
        moves[numMoves] = 0;
        numMoves++;
    }

    // Check if can move down
    if(canMoveDown(maze, row, col)) {
        moves[numMoves] = 1;
        numMoves++;
    }

    // Check if can move left
    if(canMoveLeft(maze, row, col)) {
        moves[numMoves] = 2;
        numMoves++;
    }

    // Check if can move right
    if(canMoveRight(maze, row, col)) {
        moves[numMoves] = 3;
        numMoves++;
    }

    // If no moves can be made, backtrack
    if(numMoves == 0) {
        return;
    }

    // Choose a random move and carve a path
    int choice = rand() % numMoves;

    switch(moves[choice]) {
        case 0: // Move up
            maze[row-1][col] = PATH;
            generateMaze(maze, row-1, col);
            break;
        case 1: // Move down
            maze[row+1][col] = PATH;
            generateMaze(maze, row+1, col);
            break;
        case 2: // Move left
            maze[row][col-1] = PATH;
            generateMaze(maze, row, col-1);
            break;
        case 3: // Move right
            maze[row][col+1] = PATH;
            generateMaze(maze, row, col+1);
            break;
    }

    // Random chance for additional moves
    if(rand() % 5 == 0) {
        generateMaze(maze, row, col);
    }
}

void printMaze(MazePiece maze[ROWS][COLS]) {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            switch(maze[i][j]) {
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf(" ");
                    break;
                case START:
                    printf("S");
                    break;
                case END:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    MazePiece maze[ROWS][COLS];

    // Seed random number generator
    srand(time(NULL));

    // Initialize maze
    initializeMaze(maze);

    // Generate maze
    generateMaze(maze, 0, 0);

    // Print maze
    printMaze(maze);

    return 0;
}