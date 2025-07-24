//FormAI DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int board[][BOARD_SIZE]) {
    printf("---------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %d ", board[i][j]);
        }
        printf("|\n---------------------\n");
    }
}

void shuffle(int cards[]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int j = rand() % (BOARD_SIZE * BOARD_SIZE);
        int tmp = cards[i];
        cards[i] = cards[j];
        cards[j] = tmp;
    }
}

int main() {
    int cards[BOARD_SIZE * BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        cards[i] = i / 2;
    }
    shuffle(cards);
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[i * BOARD_SIZE + j];
        }
    }
    print_board(board);
    return 0;
}