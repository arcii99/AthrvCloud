//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define BLOCK 219
#define EMPTY ' '

int grid[SIZE][SIZE], visited[SIZE][SIZE], top = -1, stack[SIZE * SIZE];
int colors[SIZE * SIZE], color_count = 0;

void push(int x, int y) {
    stack[++top] = x * SIZE + y;
}

int pop() {
    return stack[top--];
}

void dfs(int source_x, int source_y) {
    push(source_x, source_y);
    visited[source_x][source_y] = 1;
    colors[color_count] = grid[source_x][source_y];
    
    while (top != -1) {
        int current = pop();
        int x = current / SIZE, y = current % SIZE;
        
        if (x > 0 && !visited[x - 1][y] && grid[x - 1][y] == grid[x][y]) {
            push(x - 1, y);
            visited[x - 1][y] = 1;
            colors[color_count] = grid[x - 1][y];
        }
        if (y > 0 && !visited[x][y - 1] && grid[x][y - 1] == grid[x][y]) {
            push(x, y - 1);
            visited[x][y - 1] = 1;
            colors[color_count] = grid[x][y - 1];
        }
        if (x < SIZE - 1 && !visited[x + 1][y] && grid[x + 1][y] == grid[x][y]) {
            push(x + 1, y);
            visited[x + 1][y] = 1;
            colors[color_count] = grid[x + 1][y];
        }
        if (y < SIZE - 1 && !visited[x][y + 1] && grid[x][y + 1] == grid[x][y]) {
            push(x, y + 1);
            visited[x][y + 1] = 1;
            colors[color_count] = grid[x][y + 1];
        }
    }
}

int main() {
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            visited[i][j] = 0;
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                color_count++;
            }
        }
    }
    
    printf(" ");
    for (int i = 0; i < SIZE; i++) printf("_ ");
    printf("\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("%c", BLOCK);
            } else {
                printf("%c", EMPTY);
            }
            
            if (j < SIZE - 1 && colors[i * SIZE + j] != colors[i * SIZE + j + 1]) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
        if (i < SIZE - 1) {
            printf("|");
            for (int j = 0; j < SIZE; j++) {
                if (colors[i * SIZE + j] != colors[(i + 1) * SIZE + j]) {
                    printf("_");
                } else {
                    printf(" ");
                }
                printf(" ");
            }
            printf("|\n");
        }
    }
    printf(" ");
    for (int i = 0; i < SIZE; i++) printf("_ ");
    printf("\n");
    
    return 0;
}