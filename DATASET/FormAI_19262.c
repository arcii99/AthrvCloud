//FormAI DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

void print(char cells[ROWS][COLS]) {
    printf("\033[2J\033[0;0H");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf(cells[i][j] ? "O " : ". ");
        }

        printf("\n");
    }
}

int count_neighbors(char cells[ROWS][COLS], int x, int y) {
    int sum = 0;

    for(int i = x - 1; i <= x + 1; i++) {
        for(int j = y - 1; j <= y + 1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && cells[i][j]) {
                sum++;
            }
        }
    }

    if(cells[x][y]) {
        sum--;
    }

    return sum;
}

void game_of_life(char cells[ROWS][COLS]) {
    char cells_copy[ROWS][COLS];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cells_copy[i][j] = cells[i][j];
        }
    }

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(cells_copy, i, j);

            if(cells_copy[i][j] && (neighbors < 2 || neighbors > 3)) {
                cells[i][j] = 0;
            }
            else if(!cells_copy[i][j] && neighbors == 3) {
                cells[i][j] = 1;
            }
        }
    }
}

void randomize(char cells[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cells[i][j] = rand() % 2;
        }
    }
}

int main() {
    char cells[ROWS][COLS];

    srand(time(NULL));
    randomize(cells);

    for(int i = 0; i < 1000; i++) {
        print(cells);
        game_of_life(cells);
    }

    return 0;
}