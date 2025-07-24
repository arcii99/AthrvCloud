//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

void printMaze(char maze[][COLS]);
void generateMaze(char maze[][COLS]);

int main() {
    char maze[ROWS][COLS];

    srand(time(NULL));

    generateMaze(maze);

    printMaze(maze);

    return 0;
}

void generateMaze(char maze[][COLS]) {
    // Initialize maze to be all walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Choose a random starting point
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;

    maze[startRow][startCol] = ' ';

    // Segments that are part of the maze and open spaces
    int mazeSegments = 1;
    int openSpaces = 0;

    while (mazeSegments < (ROWS*COLS)/4) {
        // Choose a random point adjacent to a maze segment
        int row = -1;
        int col = -1;
        while (row < 0 || row >= ROWS || col < 0 || col >= COLS ||
               (maze[row][col] != '#' && maze[row][col] != ' ')) {
            int direction = rand() % 4;
            if (direction == 0) {
                // North
                row = startRow - 1;
                col = startCol;
            } else if (direction == 1) {
                // East
                row = startRow;
                col = startCol + 1;
            } else if (direction == 2) {
                // South
                row = startRow + 1;
                col = startCol;
            } else {
                // West
                row = startRow;
                col = startCol - 1;
            }
        }

        // Count open spaces and maze segments around the point
        int countOpenSpaces = 0;
        int countMazeSegments = 0;
        if (maze[row-1][col] == ' ') {
            countOpenSpaces++;
        } else if (maze[row-1][col] == '#') {
            countMazeSegments++;
        }
        if (maze[row+1][col] == ' ') {
            countOpenSpaces++;
        } else if (maze[row+1][col] == '#') {
            countMazeSegments++;
        }
        if (maze[row][col-1] == ' ') {
            countOpenSpaces++;
        } else if (maze[row][col-1] == '#') {
            countMazeSegments++;
        }
        if (maze[row][col+1] == ' ') {
            countOpenSpaces++;
        } else if (maze[row][col+1] == '#') {
            countMazeSegments++;
        }

        // If there is only one open space and three maze segments
        // around the point, mark the point as part of the maze
        if (countOpenSpaces == 1 && countMazeSegments == 3) {
            maze[row][col] = ' ';
            startRow = row;
            startCol = col;
            mazeSegments++;
        }
    }
}

void printMaze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}