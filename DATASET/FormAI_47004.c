//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

int maze[ROW][COL];

void generate_maze() {
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
                maze[i][j] = 1; // Mark borders as walls
            }
            else if (i % 2 == 0 && j % 2 == 0) {
                maze[i][j] = 0; // Set every other cell as a possible path
            }
            else {
                maze[i][j] = 1; // Mark all other cells as walls
            }
        }
    }

    // Choose a random starting cell on the top row
    int x = rand() % (ROW - 2) + 1;
    int y = 0;

    // Mark the starting cell as a path
    maze[x][y] = 0;
    
    // Create a stack to keep track of visited cells
    int visited[ROW * COL][2];
    int top = 0;
    visited[top][0] = x;
    visited[top][1] = y;
    top++;
    
    // Create directions array to randomly choose a direction to move in each iteration
    int dirs[4][2] = {{-2, 0}, {0, 2}, {2, 0}, {0, -2}};
    
    // Loop until all possible paths have been visited
    while (top > 0) {
        int rand_dir = rand() % 4; // Choose a random direction
        int new_x = visited[top - 1][0] + dirs[rand_dir][0];
        int new_y = visited[top - 1][1] + dirs[rand_dir][1];
        
        // Check if new cell is a valid path
        if (new_x > 0 && new_x < ROW - 1 && new_y > 0 && new_y < COL - 1 && maze[new_x][new_y] == 1) {
            // Mark the new cell as a path and the cell in between as a path too
            maze[visited[top - 1][0] + dirs[rand_dir][0] / 2][visited[top - 1][1] + dirs[rand_dir][1] / 2] = 0;
            maze[new_x][new_y] = 0;
            
            // Add the new cell to the visited stack
            visited[top][0] = new_x;
            visited[top][1] = new_y;
            top++;
        }
        else {
            // If there are no possible paths in this direction pop the visited cell from the stack
            top--;
        }
    }
}

void print_maze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf("\u2588\u2588");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    generate_maze();
    print_maze();
    return 0;
}