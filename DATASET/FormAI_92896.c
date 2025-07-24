//FormAI DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20
#define NUM_PAIRS 10
#define NUM_MOVES 30

void init_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);
void shuffle_pairs(int pairs[], int n);
int play_game(int board[][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    int score = play_game(board);
    printf("Game over! Final score: %d\n", score);
    return 0;
}

void init_board(int board[][BOARD_SIZE]) {
    int pairs[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        pairs[i] = i / 2 + 1;
    }
    shuffle_pairs(pairs, NUM_PAIRS * 2);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < NUM_PAIRS; i++) {
        board[i / (BOARD_SIZE / 2)][i % (BOARD_SIZE / 2)] = pairs[i];
        board[i / (BOARD_SIZE / 2)][(BOARD_SIZE - 1) - (i % (BOARD_SIZE / 2))] = pairs[i + NUM_PAIRS];
    }
}

void print_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void shuffle_pairs(int pairs[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }
}

int play_game(int board[][BOARD_SIZE]) {
    int prev_row = -1, prev_col = -1;
    int revealed[BOARD_SIZE][BOARD_SIZE];
    int score = 0, moves = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            revealed[i][j] = 0;
        }
    }

    while (moves < NUM_MOVES) {
        print_board(board, revealed);

        int row, col;
        printf("Enter row and column separated by a space: ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && !revealed[row][col]) {
            revealed[row][col] = 1;
            if (prev_row != -1 && prev_col != -1) {
                if (board[row][col] == board[prev_row][prev_col]) {
                    printf("Match!\n");
                    score += 100;
                } else {
                    printf("No match.\n");
                    revealed[prev_row][prev_col] = 0;
                    revealed[row][col] = 0;
                    score -= 50;
                }
                prev_row = -1;
                prev_col = -1;
            } else {
                prev_row = row;
                prev_col = col;
            }

            moves++;
        } else {
            printf("Invalid move.\n");
        }

        int all_revealed = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (!revealed[i][j]) {
                    all_revealed = 0;
                    break;
                }
            }
        }
        if (all_revealed) {
            break;
        }
    }

    return score;
}