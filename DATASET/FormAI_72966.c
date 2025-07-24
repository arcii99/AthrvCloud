//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'.','.','#','.','#','.','#','#','.','.'},
    {'#','#','#','.','#','.','.','.','#','#'},
    {'#','.','.','.','.','#','#','.','.','#'},
    {'#','#','#','#','.','#','B','#','.','#'},
    {'#','.','.','#','.','#','.','#','.','#'},
    {'#','#','.','#','.','#','.','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#'},
};

bool find_path(int row, int col) 
{ 
    if (maze[row][col] == 'B') { 
        return true; // End of the maze.
    } 

    if (maze[row][col] == '#') { 
        return false; // Dead end.
    } 

    if (maze[row][col] == '.') {
        maze[row][col] = 'X'; // Mark the visited spot.
    }

    if ((row > 0 && find_path(row - 1, col)) || // Check up.
        (row < ROW - 1 && find_path(row + 1, col)) || // Check down.
        (col > 0 && find_path(row, col - 1)) || // Check left.
        (col < COL - 1 && find_path(row, col + 1))) { // Check right.
        return true;
    }

    maze[row][col] = '.'; // Unmark the visited spot.
    return false; 
} 

void print_maze() 
{ 
    for (int i = 0; i < ROW; i++) { 
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]); 
        }
        printf("\n"); 
    }
} 

int main() 
{ 
    printf("Initial Maze\n"); 
    print_maze(); 

    if (find_path(1, 1)) { // Starting position.
        printf("\nPath Found!\n"); 
    } else { 
        printf("\nNo Path Found.\n"); 
    } 

    printf("Final Maze\n"); 
    print_maze(); 

    return 0; 
}