//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void generateMaze(char maze[ROWS][COLS]);
void displayMaze(char maze[ROWS][COLS]);

int main() 
{
    char maze[ROWS][COLS];
  
    // Initialise the maze with walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Generate the maze
    generateMaze(maze);

    // Display the maze
    displayMaze(maze);

    return 0;
}

void generateMaze(char maze[ROWS][COLS])
{
    srand(time(NULL));
    int startX = rand() % (ROWS/2)*2 + 1;
    int startY = rand() % (COLS/2)*2 + 1;
    maze[startX][startY] = 'S';
    int visited = 1;

    while(visited < (ROWS/2)*(COLS/2)) {
        // Get a random unvisited cell
        int x = rand() % (ROWS/2)*2 + 1;
        int y = rand() % (COLS/2)*2 + 1;
        
        if(maze[x][y] == '#') {
            // Randomly choose a neighbor of the current cell
            int neighbors[4][2] = {{-2,0}, {0,-2}, {2,0}, {0,2}};
            int randIndex;
            while(1) {
                randIndex = rand() % 4;
                if(x+neighbors[randIndex][0]>=1 && x+neighbors[randIndex][0]<ROWS-1 
                    && y+neighbors[randIndex][1]>=1 && y+neighbors[randIndex][1]<COLS-1
                    && maze[x+neighbors[randIndex][0]][y+neighbors[randIndex][1]] == '#') {
                    break;
                }
            }
            // Knock down the wall between the current cell and the chosen neighbor
            maze[x+neighbors[randIndex][0]/2][y+neighbors[randIndex][1]/2] = ' ';
            maze[x][y] = ' ';
            visited++;
        }
    }
    int endX = rand() % (ROWS/2)*2 + 1;
    int endY = rand() % (COLS/2)*2 + 1;
    maze[endX][endY] = 'E';
}

void displayMaze(char maze[ROWS][COLS]) 
{
    printf("\nHere is your Procedurally Generated Maze, Enjoy! :)\n\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}