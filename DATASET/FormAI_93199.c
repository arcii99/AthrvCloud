//FormAI DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 40

void print_generation(int generation[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c", generation[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

int count_neighbors(int generation[ROWS][COLUMNS], int row, int column) {
    int count = 0;

    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = column - 1; j <= column + 1; j++) {
            if(i < 0 || j < 0 || i >= ROWS || j >= COLUMNS || (i == row && j == column)) {
                continue;
            }

            count += generation[i][j];
        }   
    }

    return count;
}

void simulate_generation(int current_generation[ROWS][COLUMNS], int next_generation[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            int neighbors = count_neighbors(current_generation, i, j);
            
            if(current_generation[i][j] == 1) {
                next_generation[i][j] = neighbors == 2 || neighbors == 3;
            } else {
                next_generation[i][j] = neighbors == 3;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int current_generation[ROWS][COLUMNS];
    int next_generation[ROWS][COLUMNS] = {0};

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            current_generation[i][j] = rand() % 2;
        }
    }

    for(int i = 0; i < 50; i++) {
        system("clear");
        simulate_generation(current_generation, next_generation);
        print_generation(current_generation);
        printf("\n");
        memcpy(current_generation, next_generation, sizeof(current_generation));
        memset(next_generation, 0, sizeof(next_generation));
        usleep(250000);
    }

    return 0;
}