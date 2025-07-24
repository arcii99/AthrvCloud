//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze generation algorithm
int generateMaze(char maze[][50], int x, int y) {
    int i, j;
    int direction;
    int goalx, goaly;
    int visited = 0;

    int xMove[4] = { 1, -1, 0, 0 };
    int yMove[4] = { 0, 0, 1, -1 };

    // Initialize the maze
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            maze[i][j] = '#'; // wall
        }
    }

    // Set the starting point
    int startx = rand() % x;
    int starty = rand() % y;

    // Set the goal point
    if (startx < x / 2 && starty < y / 2) {
        goalx = rand() % (x / 2) + x / 2;
        goaly = rand() % (y / 2) + y / 2;
    } else if (startx < x / 2 && starty >= y / 2) {
        goalx = rand() % (x / 2) + x / 2;
        goaly = rand() % (y / 2);
    } else if (startx >= x / 2 && starty < y / 2) {
        goalx = rand() % (x / 2);
        goaly = rand() % (y / 2) + y / 2;
    } else {
        goalx = rand() % (x / 2);
        goaly = rand() % (y / 2);
    }

    maze[startx][starty] = 'S'; // starting point
    maze[goalx][goaly] = 'G'; // goal point

    // Generate the maze
    int currentx = startx;
    int currenty = starty;
    while (visited < x*y) {
        visited++;
        direction = rand() % 4;
        if (currentx + xMove[direction] >= 0 && currentx + xMove[direction] < x &&
        currenty + yMove[direction] >= 0 && currenty + yMove[direction] < y) {
            if (maze[currentx + xMove[direction]][currenty + yMove[direction]] == '#') {
                maze[currentx + xMove[direction]][currenty + yMove[direction]] = ' ';
                currentx += xMove[direction];
                currenty += yMove[direction];
            }
        }
    }

    return 0;
}

// Main function
int main() {
    char maze[50][50];
    int i, j;
    int x = 20; // maze width
    int y = 20; // maze height

    srand(time(NULL));

    generateMaze(maze, x, y);

    // Print the generated maze
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}