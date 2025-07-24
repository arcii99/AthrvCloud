//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10 /* Define maze size */
#define COL 10

char maze[ROW][COL] = { /* The maze */
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool visited[ROW][COL];

/* Function to print the maze */
void printMaze() 
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

/* Function to find the route */
bool findRoute(int x, int y) 
{
    if (maze[x][y] == 'G') { /* We reached the Goal */
        return true;
    }

    if (maze[x][y] == '#' || visited[x][y] == true) { /* Wall or already visited */
        return false;
    }

    visited[x][y] = true;

    if (x != 0) { /* Check upwards */
        if (findRoute(x - 1, y) == true) {
            maze[x][y] = 'o';
            return true;
            }
    }

    if (y != 0) { /* Check left */
        if (findRoute(x, y - 1) == true) {
            maze[x][y] = 'o';
            return true;
        }
    }

    if (y != COL - 1) { /* Check right */
        if (findRoute(x, y + 1) == true) {
            maze[x][y] = 'o';
            return true;
        }
    }

    if (x != ROW - 1) { /* Check downwards */
        if (findRoute(x + 1, y) == true) {
            maze[x][y] = 'o';
            return true;
        }
    }

    return false;
}

int main() 
{
    int start_x, start_y;

    printf("Welcome to the Maze Route Finder! The maze is:\n");

    printMaze();

    printf("\nEnter the row and column of the starting position (separated by a space): ");

    scanf("%d %d", &start_x, &start_y);

    visited[start_x][start_y] = true;

    printf("Calculating route...\n");

    if (findRoute(start_x, start_y) == true) {
        printf("The route is:\n");
        printMaze();
    } 

    else {
        printf("No route found.\n");
    }

    return 0;
}