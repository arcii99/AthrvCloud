//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// structure to hold x-, y- coordinates of a cell
struct cell {
    int x, y;
};

// function prototypes
void printMaze(char maze[ROWS][COLS]);
int findRoute(char maze[ROWS][COLS], struct cell start, struct cell end, int visited[ROWS][COLS]);

int main() {
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#'},
        {'#', '#', '#', ' ', '#', '#', ' ', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', '#', '#', '#'},
        {'#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // set start cell coordinates
    struct cell start = {1, 1};

    // set end cell coordinates
    struct cell end = {8, 8};

    // mark visited cells as 0 (unvisited)
    int visited[ROWS][COLS] = {0};

    // find the route from start to end cell
    int routeExists = findRoute(maze, start, end, visited);

    // print the maze and the route if found
    printMaze(maze);
    if (routeExists) {
        printf("The route from start to end exists.\n");
    } else {
        printf("The route from start to end does not exist.\n");
    }

    return 0;
}

// recursive function to find the route using depth-first search algorithm
int findRoute(char maze[ROWS][COLS], struct cell current, struct cell end, int visited[ROWS][COLS]) {
    // check if current cell is the end cell
    if (current.x == end.x && current.y == end.y) {
        return 1; // exit condition (found the end cell)
    }

    // mark current cell as visited
    visited[current.x][current.y] = 1;

    // possible moves: up, down, left, right
    struct cell moves[4] = {{current.x-1, current.y}, {current.x+1, current.y}, {current.x, current.y-1}, {current.x, current.y+1}};
    
    // iterate over the possible moves and check if they are valid
    for (int i = 0; i < 4; i++) {
        // check if move is within the maze boundaries and is a valid move
        if (moves[i].x >= 0 && moves[i].x < ROWS && moves[i].y >= 0 && moves[i].y < COLS && !visited[moves[i].x][moves[i].y] && maze[moves[i].x][moves[i].y] != '#') {
            // mark the move as explored
            visited[moves[i].x][moves[i].y] = 1;

            // recursive call to explore the move
            if (findRoute(maze, moves[i], end, visited)) {
                // if the end cell is found in the recursive call, mark the route in the maze and return success
                maze[moves[i].x][moves[i].y] = '.';
                return 1;
            } else {
                // if the route is not found in the recursive call, mark the cell as unexplored again
                visited[moves[i].x][moves[i].y] = 0;
            }
        }
    }

    return 0; // exit condition (no route found)
}

// function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}