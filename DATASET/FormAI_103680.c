//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 //maze width
#define HEIGHT 10 //maze height
#define VISITED 0 //cell visited
#define WALL 1 //cell wall
#define PATH 2 //cell path

int maze[HEIGHT][WIDTH]; //matrix to store maze cells

void printMaze() { //function to print the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else if (maze[i][j] == PATH) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void createMaze(int x, int y) { //function to create the maze recursively
    int dx[4] = {0, 0, -1, 1}; //neighbor cells
    int dy[4] = {-1, 1, 0, 0};

    maze[x][y] = VISITED; //mark current cell as visited

    int directions[4] = {0, 1, 2, 3}; //shuffle direction array 
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    for (int i = 0; i < 4; i++) { //check each neighbor cell
        int nx = x + dx[directions[i]];
        int ny = y + dy[directions[i]];

        if (nx < 0 || ny < 0 || nx >= HEIGHT || ny >= WIDTH) { //out of bounds
            continue;
        }

        if (maze[nx][ny] == VISITED) { //already visited
            continue;
        }

        if (directions[i] == 0) { //up
            maze[x][y - 1] = PATH;
        } else if (directions[i] == 1) { //down
            maze[x][y + 1] = PATH;
        } else if (directions[i] == 2) { //left
            maze[x - 1][y] = PATH;
        } else if (directions[i] == 3) { //right
            maze[x + 1][y] = PATH;
        }
        createMaze(nx, ny); //recursively create maze
    }
}

int main() {
    srand(time(NULL)); //initialize random seed

    for (int i = 0; i < HEIGHT; i++) { //initialize maze with walls
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }

    createMaze(1, 1); //start creating maze from the first cell recursively
    printMaze(); //print the maze
    return 0;
}