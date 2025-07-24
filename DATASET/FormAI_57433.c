//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool MATRIX[10][10];
const int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};

void printMatrix() {
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    printf("---------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%d |", i);
        for (int j = 0; j < 10; j++) {
            if (MATRIX[i][j])
                printf("X|");
            else
                printf(" |");
        }
        printf("\n");
    }
    printf("\n");
}

int root(int arr[], int i) {
    while (arr[i] != i) {
        i = arr[i];
    }
    return i;
}

void doUnion(int arr[], int size[], int a, int b) {
    int rootA = root(arr, a);
    int rootB = root(arr, b);
    
    if (rootA == rootB)
        return;
    
    if (size[rootA] < size[rootB]) {
        arr[rootA] = rootB;
        size[rootB] += size[rootA];
    } else {
        arr[rootB] = rootA;
        size[rootA] += size[rootB];
    }
}

void percolate() {
    int arr[100];
    int size[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
        size[i] = 1;
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (!MATRIX[i][j])
                continue;
            for (int d = 0; d < 4; d++) {
                int row = i + direction[d][0];
                int col = j + direction[d][1];
                if (row < 0 || row >= 10 || col < 0 || col >= 10 || !MATRIX[row][col])
                    continue;
                int a = i*10 + j;
                int b = row*10 + col;
                doUnion(arr, size, a, b);
            }
        }
    }
    
    bool percolate = false;
    int root0 = root(arr, 0);
    for (int i = 1; i < 10; i++) {
        if (root(arr, i) == root0) {
            percolate = true;
            break;
        }
    }
    
    if (percolate) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolates...\n");
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MATRIX[i][j] = rand()%2;
        }
    }
    printMatrix();
    percolate();
    return 0;
}