//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", maze[i]);
    }
}

bool isSafe(int x, int y, char maze[ROWS][COLS]) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) { // check for out of bounds
        return false;
    }
    if (maze[x][y] == '#') { // check for obstacle
        return false;
    }
    return true;
}

bool findPath(int x, int y, char maze[ROWS][COLS], int visited[ROWS][COLS]) {
    if (!isSafe(x, y, maze)) { // check if current cell is safe
        return false;
    }
    if (visited[x][y] == 1) { // check if current cell already visited
        return false;
    }
    if (x == ROWS - 1 && y == COLS - 1) { // check if current cell is destination
        maze[x][y] = 'X';
        return true;
    }
    visited[x][y] = 1; // mark current cell as visited
    maze[x][y] = '.'; // mark current cell as path
    if (findPath(x + 1, y, maze, visited)) { // move down
        return true;
    }
    if (findPath(x, y + 1, maze, visited)) { // move right
        return true;
    }
    if (findPath(x - 1, y, maze, visited)) { // move up
        return true;
    }
    if (findPath(x, y - 1, maze, visited)) { // move left
        return true;
    }
    maze[x][y] = ' '; // unmark current cell as path
    return false;
}

int main() {
    char maze[ROWS][COLS] = {
        "###################",
        "#         #       #",
        "# ####### # ##### #",
        "# #     # #S#     #",
        "# # ### # # # ### #",
        "# # # # # # #   # #",
        "# # # ### ### ### #",
        "# # #   #   #     #",
        "# # ### ##### ### #",
        "# #   #       #   #",
        "# ### ######### ###",
        "# #             # #",
        "# # ####### ### # #",
        "# #       #   # # #",
        "# ######### ### # #",
        "#     #     #     #",
        "##### # ##### #####",
        "#     #     #     #",
        "# ### ####### ### #",
        "#   #         #G  #",
        "###################"
    };

    int visited[ROWS][COLS] = {0}; // initialize visited matrix to 0

    srand(time(NULL)); // seed random number generator

    int startX = rand() % ROWS; // generate random starting X coordinate
    int startY = rand() % COLS; // generate random starting Y coordinate

    while (!findPath(startX, startY, maze, visited)) { // try to find path until successful
        startX = rand() % ROWS;
        startY = rand() % COLS;
    }

    printMaze(maze);

    return 0;
}