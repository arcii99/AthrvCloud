//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

void percolate(int x, int y) {
    if (x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE) return;
    if (visited[x][y] || map[x][y] == 0) return;
    
    visited[x][y] = 1;
    
    percolate(x-1, y); // percolate up
    percolate(x+1, y); // percolate down
    percolate(x, y-1); // percolate left
    percolate(x, y+1); // percolate right
}

int is_percolated() {
    int i, j;
    
    // reset visited array
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            visited[i][j] = 0;
        }
    }
    
    for (i = 0; i < MAX_SIZE; i++) {
        if (map[0][i] == 1) percolate(0, i);
    }
    
    for (i = 0; i < MAX_SIZE; i++) {
        if (visited[MAX_SIZE-1][i]) return 1;
    }
    
    return 0;
}

int main() {
    srand(time(NULL));
    
    // Initialize map with random 1s and 0s
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (rand() % 2 == 0) map[i][j] = 1;
            else map[i][j] = 0;
        }
    }
    
    // Print initial map
    printf("Initial Map:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    // Percolate until it percolates or until 10000 tries
    int percolated = 0;
    for (i = 0; i < 10000; i++) {
        if (is_percolated()) {
            percolated = 1;
            break;
        }
        
        // Randomly choose a cell and update it
        int x = rand() % MAX_SIZE;
        int y = rand() % MAX_SIZE;
        map[x][y] = 1;
    }
    
    if (percolated) {
        printf("Percolation!\n");
    } else {
        printf("Did not percolate.\n");
    }
    
    // Print final map
    printf("Final Map:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}