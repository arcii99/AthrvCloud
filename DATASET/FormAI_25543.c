//FormAI DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

char board[BOARD_SIZE][BOARD_SIZE];
char visible[BOARD_SIZE][BOARD_SIZE];
int pairs_found = 0;

char symbols[NUM_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

void init_board() {
    int i, j, n;
    char symbol;
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
            visible[i][j] = 0;
        }
    }
    for (n = 0; n < NUM_PAIRS; n++) {
        symbol = symbols[n];
        for (i = 0; i < 2; i++) {
            int x, y;
            do {
                x = rand() % BOARD_SIZE;
                y = rand() % BOARD_SIZE;
            } while (board[x][y] != 0);
            board[x][y] = symbol;
        }
    }
}

void draw_board() {
    int i, j;
    putchar('\n');
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d", i);
    }
    putchar('\n');
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (j == 0) {
                printf("%d", i);
            }
            if (visible[i][j]) {
                printf(" %c", board[i][j]);
            } else {
                printf(" *");
            }
        }
        putchar('\n');
    }
}

void play_turn() {
    int x1, y1, x2, y2;
    do {
        printf("Enter two coordinates (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    } while (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
             x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE ||
             (x1 == x2 && y1 == y2));
    visible[x1][y1] = 1;
    visible[x2][y2] = 1;
    if (board[x1][y1] == board[x2][y2]) {
        printf("Found a matching pair!\n");
        pairs_found++;
    } else {
        visible[x1][y1] = 0;
        visible[x2][y2] = 0;
        printf("Oops, try again.\n");
    }
}

int main() {
    printf("Welcome to the Memory Game!\n");
    init_board();
    while (pairs_found < NUM_PAIRS) {
        draw_board();
        play_turn();
    }
    printf("Congratulations, you found all the pairs!\n");
    return 0;
}