//FormAI DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 30

void display(int grid[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[j][i] == 1) {
                printf(" o ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int grid[WIDTH][HEIGHT] = {0};
    
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int random = rand() % 100;
            if (random < 30) {
                grid[i][j] = 1;
            }
        }
    }
    
    display(grid);

    while(1) {
        int temp[WIDTH][HEIGHT] = {0};

        for (int i = 1; i < WIDTH - 1; i++) {
            for (int j = 1; j < HEIGHT - 1; j++) {
                int count = 0;

                if (grid[i-1][j-1] == 1) count++;
                if (grid[i-1][j] == 1) count++;
                if (grid[i-1][j+1] == 1) count++;
                if (grid[i][j-1] == 1) count++;
                if (grid[i][j+1] == 1) count++;
                if (grid[i+1][j-1] == 1) count++;
                if (grid[i+1][j] == 1) count++;
                if (grid[i+1][j+1] == 1) count++;

                if (grid[i][j] == 1 && count < 2) {
                    temp[i][j] = 0;
                } else if (grid[i][j] == 1 && (count == 2 || count == 3)) {
                    temp[i][j] = 1;
                } else if (grid[i][j] == 1 && count > 3) {
                    temp[i][j] = 0;
                } else if (grid[i][j] == 0 && count == 3) {
                    temp[i][j] = 1;
                }
            }
        }

        for (int i = 1; i < WIDTH - 1; i++) {
            for (int j = 1; j < HEIGHT - 1; j++) {
                grid[i][j] = temp[i][j];
            }
        }

        display(grid);
    }
    
    return 0;
}