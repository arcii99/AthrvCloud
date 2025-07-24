//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define SHIPS 5

int board[BOARD_SIZE][BOARD_SIZE];
int ships[SHIPS][2];

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int place_ship(int size) {
    int row, col, dir, i;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
        dir = rand() % 2;
    } while (row + size > BOARD_SIZE && dir == 0 || col + size > BOARD_SIZE && dir == 1);
    for (i = 0; i < size; i++) {
        if (dir == 0) {
            ships[i][0] = row + i;
            ships[i][1] = col;
        } else {
            ships[i][0] = row;
            ships[i][1] = col + i;
        }
        if (board[ships[i][0]][ships[i][1]] != 0) {
            return 0;
        }
    }
    for (i = 0; i < size; i++) {
        board[ships[i][0]][ships[i][1]] = 1;
    }
    return 1;
}

int shoot() {
    char input[3];
    int row, col;
    do {
        printf("Enter a coordinate to shoot (e.g. A4): ");
        scanf("%s", input);
        row = input[0] - 'A';
        col = input[1] - '0';
    } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE);
    if (board[row][col] == 0) {
        printf("Miss!\n");
        return 0;
    } else {
        int i, j;
        for (i = 0; i < SHIPS; i++) {
            for (j = 0; j < 2; j++) {
                if (ships[i][0] == row && ships[i][1] == col) {
                    ships[i][0] = -1;
                    ships[i][1] = -1;
                    printf("Hit!\n");
                    return 1;
                }
            }
        }
        return 1;
    }
}

int main() {
    int i, hits = 0;

    srand(time(NULL));

    init_board();

    for (i = 0; i < SHIPS; i++) {
        int size = i + 2;
        while (!place_ship(size));
    }

    while (hits < SHIPS) {
        print_board();
        hits += shoot();
    }

    printf("You win!");

    return 0;
}