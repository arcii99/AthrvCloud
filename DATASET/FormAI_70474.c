//FormAI DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void initialize(char life[][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int random = rand() % 10;
            life[i][j] = (random < 3) ? 'X' : ' ';
            printf("%c ", life[i][j]);
        }
        printf("\n");
    }
}

void update(char life[][COLS]) {
    char newLife[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int count = 0;
            for(int x = i-1; x <= i+1; x++) {
                for(int y = j-1; y <= j+1; y++) {
                    if(x >= 0 && y >= 0 && x < ROWS && y < COLS && !(x == i && y == j)) {
                        if(life[x][y] == 'X') count++;
                    }
                }
            }
            if(life[i][j] == 'X' && (count == 2 || count == 3)) {
                newLife[i][j] = 'X';
            } else if(life[i][j] == ' ' && count == 3) {
                newLife[i][j] = 'X';
            } else {
                newLife[i][j] = ' ';
            }
            printf("%c ", newLife[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            life[i][j] = newLife[i][j];
        }
    }
}

int main() {
    char life[ROWS][COLS];
    initialize(life);
    printf("Generation: 0\n");
    for(int i = 1; i <= 10; i++) {
        update(life);
        printf("Generation: %d\n", i);
    }
    return 0;
}