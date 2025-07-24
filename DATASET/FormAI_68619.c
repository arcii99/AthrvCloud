//FormAI DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 20

int count_live_neighbors(int i, int j, int generation[][COLUMNS]) {
    int count = 0;
    if (i > 0 && j > 0 && generation[i - 1][j - 1])
        count++;
    if (i > 0 && generation[i - 1][j])
        count++;
    if (i > 0 && j < COLUMNS - 1 && generation[i - 1][j + 1])
        count++;
    if (j > 0 && generation[i][j - 1])
        count++;
    if (j < COLUMNS - 1 && generation[i][j + 1])
        count++;
    if (i < ROWS - 1 && j > 0 && generation[i + 1][j - 1])
        count++;
    if (i < ROWS - 1 && generation[i + 1][j])
        count++;
    if (i < ROWS - 1 && j < COLUMNS - 1 && generation[i + 1][j + 1])
        count++;
    return count;
}

void generate_next_generation(int current_generation[][COLUMNS], int next_generation[][COLUMNS]) {
    int live_neighbors;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            live_neighbors = count_live_neighbors(i, j, current_generation);
            if (current_generation[i][j]) {
                if(live_neighbors == 2 || live_neighbors == 3)
                    next_generation[i][j] = 1;
                else
                    next_generation[i][j] = 0;
            } else {
                if(live_neighbors == 3)
                    next_generation[i][j] = 1;
                else
                    next_generation[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            current_generation[i][j] = next_generation[i][j];
        }
    }
}

void print_generation(int generation[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", generation[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

int main() {
    // randomly initialize the first generation
    int first_generation[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            first_generation[i][j] = rand() % 2;
        }
    }
    
    int next_generation[ROWS][COLUMNS];
    while(1) {
        system("clear");
        print_generation(first_generation);
        generate_next_generation(first_generation, next_generation);
    }

    return 0;
}