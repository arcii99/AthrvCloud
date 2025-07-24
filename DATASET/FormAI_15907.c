//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAZE_SIZE 20
#define WALL '*'
#define PATH ' '
#define START 'S'
#define END 'E'

// define coordinate to store a position
typedef struct coord_t {
    int x;
    int y;
} Coord;

// create a maze of size 'n'
void createMaze(char maze[][MAZE_SIZE], int n, Coord *start, Coord *end) {
    // initialize borders
    for (int i = 0; i < n; i++) {
        maze[0][i] = WALL;
        maze[n-1][i] = WALL;
        maze[i][0] = WALL;
        maze[i][n-1] = WALL;
    }
    srand(time(NULL));
    // create random walls
    for (int i = 2; i < n-2; i++) {
        for (int j = 2; j < n-2; j++) {
            if (rand() % (n / 2) == 0) { 
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }
    // Set start point
    int x = rand() % (n-4) + 2;
    maze[1][x] = START;
    start->x = x;
    start->y = 1;
    // Set end point
    x = rand() % (n-4) + 2;
    maze[n-2][x] = END;
    end->x = x;
    end->y = n-2;
}

// print maze
void printMaze(char maze[][MAZE_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", maze[i]); 
    }
    printf("\n");
}

// check if coord is a path
bool isPath(char maze[][MAZE_SIZE], Coord coord) {
    return maze[coord.y][coord.x] == PATH;
}

// check if coord is the end point
bool isEnd(Coord coord, Coord end) {
    return coord.x == end.x && coord.y == end.y;
}

// check if coord is within the maze boundaries
bool inBound(Coord coord, int n) {
    return coord.x >= 0 && coord.x < n && coord.y >= 0 && coord.y < n;
}

// check if coord is a valid move
bool isValidMove(char maze[][MAZE_SIZE], Coord coord, int n) {
    return inBound(coord, n) && isPath(maze, coord);   
}

// solve maze using backtracking algorithm
bool solveMaze(char maze[][MAZE_SIZE], int n, Coord curr, Coord end) {
    if (isEnd(curr, end)) {
        return true; // reached end, maze is solved
    }
    // mark current position as visited
    maze[curr.y][curr.x] = '.';
    Coord validMoves[] = {{curr.x-1, curr.y}, {curr.x+1, curr.y}, {curr.x, curr.y-1}, {curr.x, curr.y+1}};
    for (int i = 0; i < 4; i++) {
        if (isValidMove(maze, validMoves[i], n)) {
            if (solveMaze(maze, n, validMoves[i], end)) {
                return true; // found solution from current move
            }
        }
    }
    maze[curr.y][curr.x] = ' '; // backtrack and reset mark
    return false; // current move doesn't lead to solution
}

int main() {
    char maze[MAZE_SIZE][MAZE_SIZE];
    Coord start, end;
    memset(maze, WALL, sizeof maze); // initialize maze with walls as boundaries
    createMaze(maze, MAZE_SIZE, &start, &end);
    printMaze(maze, MAZE_SIZE);
    if (solveMaze(maze, MAZE_SIZE, start, end)) {
        printf("Maze is solved!\n");
        printMaze(maze, MAZE_SIZE);
    } else {
        printf("Cannot solve maze!\n");
    }
    return 0;
}