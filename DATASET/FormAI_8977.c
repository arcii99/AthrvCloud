//FormAI DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30
#define ALIVE 'X'
#define DEAD '-'

void initialize_grid(char grid[][N]);
void display_grid(char grid[][N]);
int count_live_neighbors(char grid[][N], int i, int j);
void update_grid(char grid[][N]);

int main() {
    char grid[N][N];
    srand(time(NULL)); // seed the random number generator

    initialize_grid(grid);
    display_grid(grid);

    while(1) {
        update_grid(grid);
        display_grid(grid);
        usleep(500000); // delay 500ms
    }

    return 0;
}

void initialize_grid(char grid[][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int rand_num = rand() % 2;
            if(rand_num == 1) {
                grid[i][j] = ALIVE;
            }
            else {
                grid[i][j] = DEAD;
            }
        }
    }
}

void display_grid(char grid[][N]) {
    system("clear"); // clear the screen
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_live_neighbors(char grid[][N], int i, int j) {
    int count = 0;
    for(int x=i-1; x<=i+1; x++) {
        for(int y=j-1; y<=j+1; y++) {
            if(x<0 || x>=N || y<0 || y>=N || (x==i && y==j)) {
                continue;
            }
            if(grid[x][y] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void update_grid(char grid[][N]) {
    char new_grid[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int live_neighbors = count_live_neighbors(grid, i, j);
            if(grid[i][j] == ALIVE) {
                if(live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = DEAD;
                }
                else {
                    new_grid[i][j] = ALIVE;
                }
            }
            else {
                if(live_neighbors == 3) {
                    new_grid[i][j] = ALIVE;
                }
                else {
                    new_grid[i][j] = DEAD;
                }
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}