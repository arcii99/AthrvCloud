//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generation 
    
    int maze[10][10]; // 2D array for maze
    int i, j;
    
    // Initialize maze to all walls
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Randomly generate room in top row
    int start = rand() % 10;
    maze[0][start] = 0;
    
    // Randomly generate room in bottom row
    int end = rand() % 10;
    maze[9][end] = 0;
    
    // Generate maze
    int current_row = 0;
    int current_col = start;
    
    while (current_row < 9) {
        int option = rand() % 2; // randomly choose to move left or right
        
        if (option == 0 && current_col > 0) { // move left
            maze[current_row][current_col - 1] = 0; // remove left wall
            current_col--;
        }
        else if (option == 1 && current_col < 9) { // move right
            maze[current_row][current_col + 1] = 0; // remove right wall
            current_col++;
        }
        else { // stop moving left or right, move down
            maze[current_row + 1][current_col] = 0; // remove bottom wall
            current_row++;
        }
    }
    
    // Print maze
    printf(" ");
    for (i = 0; i < 10; i++) {
        printf("_ ");
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("|");
        for (j = 0; j < 10; j++) {
            if (maze[i][j] == 1) {
                printf("_|");
            }
            else {
                printf(" |");
            }
        }
        printf("\n");
    }
    
    printf(" ");
    for (i = 0; i < 10; i++) {
        printf("_ ");
    }
    printf("\n");
    
    return 0;
}