//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

bool grid[N][N]; // our grid

void printGrid() {
    // print our grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == false) {
                printf(". ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool percolates() {
    // check if water can flow from the top to the bottom
    bool visited[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == true) {
            visited[0][j] = true;
            bool connected = false;
            int current_row = 0;
            int current_col = j;
            while (connected == false && current_row != N-1) {
                current_row++;
                if (current_col > 0 && grid[current_row][current_col-1] == true && visited[current_row][current_col-1] == false) {
                    visited[current_row][current_col-1] = true;
                    current_col--;
                } else if (current_col < N-1 && grid[current_row][current_col+1] == true && visited[current_row][current_col+1] == false) {
                    visited[current_row][current_col+1] = true;
                    current_col++;
                } else if (grid[current_row][current_col] == true && visited[current_row][current_col] == false) {
                    visited[current_row][current_col] = true;
                } else {
                    connected = false;
                    break;
                }
                if (current_row == N-1 && visited[N-1][current_col] == true) {
                    connected = true;
                }
            }
            if (connected == true) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // initialize
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = false;
        }
    }

    // percolation simulation
    int max_attempts = 1000;
    int attempts = 0;
    while (attempts < max_attempts) {
        int random_row = rand() % N;
        int random_col = rand() % N;
        if (grid[random_row][random_col] == false) {
            grid[random_row][random_col] = true;
            if (percolates() == true) {
                printf("Water percolated after %d attempts.\n", attempts+1);
                break;
            }
            attempts++;
        }
    }

    if (attempts == max_attempts) {
        printf("Water did not percolate after %d attempts.\n", max_attempts);
    }

    printGrid();

    return 0;
}