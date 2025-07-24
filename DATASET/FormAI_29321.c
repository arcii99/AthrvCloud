//FormAI DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int new_grid[ROWS][COLS];

void init_grid() {
    srand(time(NULL));
    printf("Initializing the grid...\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int val = rand()%2;
            grid[i][j] = val;
            printf("%d ", val);
        }
        printf("\n");
    }
    printf("\n");
}

void update_grid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbor_count = 0;
            for(int ni=-1; ni<=1; ni++) {
                for(int nj=-1; nj<=1; nj++) {
                    if(ni == 0 && nj == 0) {
                        continue;
                    }
                    int row = i + ni;
                    int col = j + nj;
                    if(row < 0 || col < 0 || row >= ROWS || col >= COLS) {
                        continue;
                    }
                    neighbor_count += grid[row][col];
                }
            }
            if(grid[i][j] == 1 && neighbor_count < 2) {
                new_grid[i][j] = 0;
            } else if(grid[i][j] == 1 && (neighbor_count == 2 || neighbor_count == 3)) {
                new_grid[i][j] = 1;
            } else if(grid[i][j] == 1 && neighbor_count > 3) {
                new_grid[i][j] = 0;
            } else if(grid[i][j] == 0 && neighbor_count == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void print_grid() {
    printf("Printing the grid...\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", (grid[i][j] == 1) ? '#' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    init_grid();
    int count = 0;
    while(count < 10) {
        printf("Generation %d\n", count+1);
        update_grid();
        print_grid();
        count++;
    }
    return 0;
}