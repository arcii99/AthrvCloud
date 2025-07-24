//FormAI DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

char current_life[ROWS][COLS];
char next_life[ROWS][COLS];

void initialize_life(char life[ROWS][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (rand() % 2 == 0) {
                life[row][col] = '*';
            } else {
                life[row][col] = '-';
            }
        }
    }
}

void print_life(char life[ROWS][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%c ", life[row][col]);
        }
        printf("\n");
    }
}

int count_live_neighbors(char life[ROWS][COLS], int row, int col) {
    int count = 0;
    int r, c;
    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !(r == row && c == col)) {
                if (life[r][c] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}

void update_life(char current[ROWS][COLS], char next[ROWS][COLS]) {
    int row, col, live_neighbors;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            live_neighbors = count_live_neighbors(current, row, col);
            if (current[row][col] == '*' && live_neighbors < 2) {
                next[row][col] = '-';
            } else if (current[row][col] == '*' && (live_neighbors == 2 || live_neighbors == 3)) {
                next[row][col] = '*';
            } else if (current[row][col] == '*' && live_neighbors > 3) {
                next[row][col] = '-';
            } else if (current[row][col] == '-' && live_neighbors == 3) {
                next[row][col] = '*';
            } else {
                next[row][col] = current[row][col];
            }
        }
    }
}

int main() {
    initialize_life(current_life);
    print_life(current_life);
    sleep(1);
    while (1) {
        system("clear");
        update_life(current_life, next_life);
        print_life(next_life);
        sleep(1);
        memcpy(current_life, next_life, sizeof(current_life));
    }
    return 0;
}