//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Artistic C Pathfinding Algorithm

int main() {
    int rows = 10;
    int columns = 10;

    int maze[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int start_row = 1;
    int start_col = 1;
    int end_row = 8;
    int end_col = 8;

    int current_row = start_row;
    int current_col = start_col;

    int visited[10][10] = {0};
    visited[start_row][start_col] = 1;

    printf("Starting point: (%d, %d)\n", start_row, start_col);
    printf("End point: (%d, %d)\n\n", end_row, end_col);

    while (current_row != end_row || current_col != end_col) {
        // Check if can move up
        if (maze[current_row-1][current_col] == 0 && visited[current_row-1][current_col] == 0) {
            current_row--;
            visited[current_row][current_col] = 1;
            printf("Move up to (%d, %d)\n", current_row, current_col);
        }
        // Check if can move down
        else if (maze[current_row+1][current_col] == 0 && visited[current_row+1][current_col] == 0) {
            current_row++;
            visited[current_row][current_col] = 1;
            printf("Move down to (%d, %d)\n", current_row, current_col);
        }
        // Check if can move left
        else if (maze[current_row][current_col-1] == 0 && visited[current_row][current_col-1] == 0) {
            current_col--;
            visited[current_row][current_col] = 1;
            printf("Move left to (%d, %d)\n", current_row, current_col);
        }
        // Check if can move right
        else if (maze[current_row][current_col+1] == 0 && visited[current_row][current_col+1] == 0) {
            current_col++;
            visited[current_row][current_col] = 1;
            printf("Move right to (%d, %d)\n", current_row, current_col);
        }
        // If cannot move anywhere, backtrack
        else {
            if (maze[current_row-1][current_col] == 0 && visited[current_row-1][current_col] == 1) {
                current_row--;
                printf("Backtrack up to (%d, %d)\n", current_row, current_col);
            }
            else if (maze[current_row+1][current_col] == 0 && visited[current_row+1][current_col] == 1) {
                current_row++;
                printf("Backtrack down to (%d, %d)\n", current_row, current_col);
            }
            else if (maze[current_row][current_col-1] == 0 && visited[current_row][current_col-1] == 1) {
                current_col--;
                printf("Backtrack left to (%d, %d)\n", current_row, current_col);
            }
            else if (maze[current_row][current_col+1] == 0 && visited[current_row][current_col+1] == 1) {
                current_col++;
                printf("Backtrack right to (%d, %d)\n", current_row, current_col);
            }
            else {
                printf("No pathway\n");
                break;
            }
        }
    }

    return 0;
}