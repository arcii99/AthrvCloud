//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate maze
void generateMaze(char maze[][50], int n) {
    // Fill maze with walls
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            maze[i][j] = '#';
        }
    }

    // Generate random starting and ending points
    srand(time(NULL));
    int startx = rand()%(n-2)+1;
    int starty = rand()%(n-2)+1;
    int endx = rand()%(n-2)+1;
    int endy = rand()%(n-2)+1;

    // Make sure starting and ending points are not on walls
    while(maze[startx][starty] == '#' || maze[endx][endy] == '#') {
        startx = rand()%(n-2)+1;
        starty = rand()%(n-2)+1;
        endx = rand()%(n-2)+1;
        endy = rand()%(n-2)+1;
    }

    // Create path from starting to ending point using random directions
    int currx = startx;
    int curry = starty;
    while(currx != endx || curry != endy) {
        // Generate random direction
        int dir = rand()%4;
        if(dir == 0) {
            // Move up
            if(currx-1 >= 0 && maze[currx-1][curry] == '#') {
                maze[currx-1][curry] = ' ';
                currx--;
            }
        } else if(dir == 1) {
            // Move down
            if(currx+1 < n && maze[currx+1][curry] == '#') {
                maze[currx+1][curry] = ' ';
                currx++;
            }
        } else if(dir == 2) {
            // Move left
            if(curry-1 >= 0 && maze[currx][curry-1] == '#') {
                maze[currx][curry-1] = ' ';
                curry--;
            }
        } else {
            // Move right
            if(curry+1 < n && maze[currx][curry+1] == '#') {
                maze[currx][curry+1] = ' ';
                curry++;
            }
        }
    }

    // Add starting and ending points to maze
    maze[startx][starty] = 'S';
    maze[endx][endy] = 'E';
}

// Function to print maze
void printMaze(char maze[][50], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[50][50];
    generateMaze(maze, 10); // Generate a 10x10 maze
    printMaze(maze, 10);
    return 0;
}