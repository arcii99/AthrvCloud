//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
/*
 * Percolation Simulator
 * This program simulates the percolation of liquids through a porous material.
 * It determines whether a given volume of liquid can percolate through a specified material or not.
 * The program uses Monte Carlo simulation technique to achieve this.
 * 
 * "Data! Data! Data!" he cried impatiently. "I cannot make bricks without clay."
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10            // size of the material grid
#define PERCOLATION 60  // percolation limit in percentage

void print_material(int mat[N][N]) {
    printf("Material:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", mat[i][j] ? '-' : '+');
        }
        printf("\n");
    }
}

int percolates(int mat[N][N]) {
    // check if the top row is connected to the bottom row
    for (int j = 0; j < N; j++) {
        if (mat[0][j] == 0) {
            // perform depth-first search
            int visited[N][N] = {{0}};
            visited[0][j] = 1;
            int stack[N*N][2] = {{0}};
            int top = -1;
            top++;
            stack[top][0] = 0;
            stack[top][1] = j;
            while (top >= 0) {
                int i = stack[top][0];
                int j = stack[top][1];
                top--;
                if (i > 0 && mat[i-1][j] == 0 && !visited[i-1][j]) {
                    visited[i-1][j] = 1;
                    top++;
                    stack[top][0] = i-1;
                    stack[top][1] = j;
                }
                if (j > 0 && mat[i][j-1] == 0 && !visited[i][j-1]) {
                    visited[i][j-1] = 1;
                    top++;
                    stack[top][0] = i;
                    stack[top][1] = j-1;
                }
                if (i < N-1 && mat[i+1][j] == 0 && !visited[i+1][j]) {
                    visited[i+1][j] = 1;
                    top++;
                    stack[top][0] = i+1;
                    stack[top][1] = j;
                }
                if (j < N-1 && mat[i][j+1] == 0 && !visited[i][j+1]) {
                    visited[i][j+1] = 1;
                    top++;
                    stack[top][0] = i;
                    stack[top][1] = j+1;
                }
            }
            // check if the bottom row is reachable
            for (int j = 0; j < N; j++) {
                if (mat[N-1][j] == 0 && visited[N-1][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));  // seed the random number generator
    int material[N][N] = {{0}};
    int filled = 0;
    while (1) {
        int i = rand() % N;
        int j = rand() % N;
        if (material[i][j] == 0) {
            material[i][j] = 1;
            filled++;
        }
        if (percolates(material)) {
            printf("Percolates!\n");
            print_material(material);
            break;
        }
        if (filled == N*N) {
            printf("Does not percolate!\n");
            print_material(material);
            break;
        }
        int percolation = 100 * filled / (N*N);
        if (percolation > PERCOLATION && !percolates(material)) {
            printf("Does not percolate!\n");
            print_material(material);
            break;
        }
    }
    return 0;
}