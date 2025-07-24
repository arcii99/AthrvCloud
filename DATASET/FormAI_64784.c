//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

int main() {
    bool matrix[ROWS][COLS] = { {false, false, false}, {true, true, false}, {false, true, true} };
    int cluster_count = 0;

    // Your goal is to count how many clusters of 'true' values are in the matrix.
    // A cluster is formed by adjacent 'true' values. Diagonal adjacency doesn't count.

    // To solve the puzzle, you will need to implement a clustering algorithm.
    // Let's start by defining a function that checks whether a cell has an 'on' neighbor:

    bool has_on_neighbor(bool matrix[ROWS][COLS], int row, int col) {
        // Check the four neighbors (up, right, down, left)
        if (row > 0 && matrix[row-1][col])
            return true;
        if (col < COLS-1 && matrix[row][col+1])
            return true;
        if (row < ROWS-1 && matrix[row+1][col])
            return true;
        if (col > 0 && matrix[row][col-1])
            return true;
        return false;
    }

    // Now let's write the actual clustering algorithm.
    // For each 'true' cell, we will visit all its 'on' neighbors and the neighbors' neighbors,
    // until we find no more 'on' neighbors.

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (matrix[row][col]) {
                // Found a 'true' cell!
                ++cluster_count;
                matrix[row][col] = false; // mark as visited

                // DFS to visit all 'on' neighbors
                int queue[ROWS*COLS*2];
                int head = 0, tail = 0;
                queue[tail++] = row;
                queue[tail++] = col;
                while (head < tail) {
                    int r = queue[head++];
                    int c = queue[head++];
                    if (has_on_neighbor(matrix, r, c)) {
                        if (r > 0 && matrix[r-1][c]) {
                            matrix[r-1][c] = false;
                            queue[tail++] = r-1;
                            queue[tail++] = c;
                        }
                        if (c < COLS-1 && matrix[r][c+1]) {
                            matrix[r][c+1] = false;
                            queue[tail++] = r;
                            queue[tail++] = c+1;
                        }
                        if (r < ROWS-1 && matrix[r+1][c]) {
                            matrix[r+1][c] = false;
                            queue[tail++] = r+1;
                            queue[tail++] = c;
                        }
                        if (c > 0 && matrix[r][c-1]) {
                            matrix[r][c-1] = false;
                            queue[tail++] = r;
                            queue[tail++] = c-1;
                        }
                    }
                }
            }
        }
    }

    printf("Found %d clusters.\n", cluster_count); // should print "Found 2 clusters."
    
    return 0;
}