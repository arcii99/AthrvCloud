//FormAI DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_world(int world[ROWS][COLS]){
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", world[i][j] ? 'X' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbours(int world[ROWS][COLS], int row, int col){
    int count = 0;
    
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(!(i==0 && j==0) && row+i>=0 && row+i<ROWS && col+j>=0 && col+j<COLS) {
                count += world[row+i][col+j];
            }
        }
    }

    return count;
}

void generate_initial_world(int world[ROWS][COLS]){
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            world[i][j] = (rand() % 2);
        }
    }
    printf("Initial World: \n");
    print_world(world);
}

void next_generation(int world[ROWS][COLS]){
    int new_world[ROWS][COLS];

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int n = count_neighbours(world, i, j);
            if (world[i][j] && n >= 2 && n <= 3) {
                new_world[i][j] = 1;
            } else if (!world[i][j] && n == 3) {
                new_world[i][j] = 1;
            } else {
                new_world[i][j] = 0;
            }
        }
    }

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            world[i][j] = new_world[i][j];
        }
    }

    printf("Next Generation: \n");
    print_world(world);
}

int main(){
    int world[ROWS][COLS];

    generate_initial_world(world);

    for(int i=0; i<5; i++) {
        next_generation(world);
    }

    return 0;
}