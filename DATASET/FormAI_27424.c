//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

#define ROW 10 // number of rows in maze
#define COL 10 // number of columns in maze

typedef struct {
    int row;
    int col;
} Coordinate;

// maze
int maze[ROW][COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,1,1,1,0,1,0,1},
    {1,1,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,1,0,1},
    {1,1,1,1,0,1,0,0,0,1},
    {1,0,0,1,0,1,0,1,1,1},
    {1,1,0,1,0,1,0,1,0,0},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,0,1,1,1,0,1},
    {0,0,0,0,1,1,0,0,0,1}
};

// function prototypes
bool solveMaze(Coordinate start, Coordinate end);
bool isValidMove(Coordinate pos);
void printMaze();

int main() {
    Coordinate start = {1, 0}; // starting position
    Coordinate end = {9, 9}; // ending position

    printf("Maze:\n");
    printMaze();

    if (solveMaze(start, end)) {
        printf("Solution found!\n");
        printMaze();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

// depth-first search algorithm
bool solveMaze(Coordinate start, Coordinate end) {
    if (start.row < 0 || start.row >= ROW || start.col < 0 || start.col >= COL) {
        return false;
    }

    if (maze[start.row][start.col] == 0) {
        return false;
    }

    if (start.row == end.row && start.col == end.col) {
        return true;
    }

    bool found = false;
    maze[start.row][start.col] = 0; // mark as visited

    Coordinate move[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // left, down, right, up
    for (int i = 0; i < 4; i++) {
        Coordinate next = {start.row + move[i].row, start.col + move[i].col};
        if (isValidMove(next)) {
            found = solveMaze(next, end);
            if (found) {
                break;
            }
        }
    }

    if (!found) {
        maze[start.row][start.col] = 1; // mark as unvisited
    }

    return found;
}

// check if the move is valid
bool isValidMove(Coordinate pos) {
    return (pos.row >= 0 && pos.row < ROW && pos.col >= 0 && pos.col < COL && maze[pos.row][pos.col] == 1);
}

// print maze
void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("\033[30;47m  \033[0m"); // visited
            } else if (maze[i][j] == 1) {
                printf("\033[30;40m  \033[0m"); // unvisited
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}