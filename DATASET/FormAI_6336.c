//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

// function to print current maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if move is valid
int isValidMove(char maze[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == '.') {
        return 1;
    }
    return 0;
}

// recursive function to find path
int findPath(char maze[ROWS][COLS], int row, int col) {
    // if we have reached the end of the maze
    if (row == ROWS-1 && col == COLS-1) {
        maze[row][col] = '*';
        return 1;
    }
    
    // check if move is valid
    if (isValidMove(maze, row, col)) {
        maze[row][col] = '*'; // mark current cell as visited
        
        // check each direction
        if (findPath(maze, row+1, col)) {
            return 1;
        }
        if (findPath(maze, row, col+1)) {
            return 1;
        }
        if (findPath(maze, row-1, col)) {
            return 1;
        }
        if (findPath(maze, row, col-1)) {
            return 1;
        }
        
        maze[row][col] = '.'; // mark current cell as unvisited
    }
    return 0;
}

int main() {
    char maze[ROWS][COLS] = {
        "###################",
        "#.................#",
        "######.#####.######",
        "##......####......#",
        "####.##.#.....##.##",
        "####.#..........##",
        "##......##.#......#",
        "###.###...#.#.#..##",
        "###......#...#..###",
        "###################"
    };
    
    printf("Original Maze:\n");
    printMaze(maze);
    
    if (findPath(maze, 0, 0)) {
        printf("Path Found:\n");
        printMaze(maze);
    } else {
        printf("No Path Found.\n");
    }
    
    return 0;
}