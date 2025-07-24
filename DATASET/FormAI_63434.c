//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 60
#define GENERATION_DELAY 1000000L

int grid[HEIGHT][WIDTH];
int next[HEIGHT][WIDTH];

void initialize_grid() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() > RAND_MAX/2 ? 1 : 0;
        }
    }
}

void print_grid() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(grid[i][j]) {
                printf("\u2588");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int get_neighbor_count(int i, int j) {
    int count = 0, ii, jj;
    for(ii = i-1; ii <= i+1; ii++) {
        for(jj = j-1; jj <= j+1; jj++) {
            if(ii >= 0 && jj >= 0 && ii < HEIGHT && jj < WIDTH && (ii != i || jj != j)) {
                count += grid[ii][jj];
            }
        }
    }
    return count;
}

void simulate_generation() {
    int i, j, count;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            count = get_neighbor_count(i, j);
            if(grid[i][j] == 1 && (count < 2 || count > 3)) {
                next[i][j] = 0;
            } else if(grid[i][j] == 0 && count == 3) {
                next[i][j] = 1;
            } else {
                next[i][j] = grid[i][j];
            }
        }
    }
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

int main() {
    int generation = 0;
    initialize_grid();
    while(1) {
        printf("\e[1;1H\e[2J"); // clear screen
        printf("CyberPunk Game of Life Generation %d\n\n", generation++);
        print_grid();
        simulate_generation();
        usleep(GENERATION_DELAY);
    }
    return 0;
}