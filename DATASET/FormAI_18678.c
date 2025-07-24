//FormAI DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(int board[ROWS][COLS]);
void display_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
int check_win(int revealed[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    initialize_board(board);
    srand(time(NULL));
    int first_row_selected, first_col_selected, second_row_selected, second_col_selected;
    while (1) {
        display_board(board, revealed);
        printf("Select the row and column of the first card: ");
        scanf("%d %d", &first_row_selected, &first_col_selected);
        if (revealed[first_row_selected][first_col_selected]) {
            printf("Card already revealed. Please select another one.\n");
            continue;
        }
        revealed[first_row_selected][first_col_selected] = 1;
        display_board(board, revealed);
        printf("Select the row and column of the second card: ");
        scanf("%d %d", &second_row_selected, &second_col_selected);
        if (revealed[second_row_selected][second_col_selected]) {
            printf("Card already revealed. Please select another one.\n");
            revealed[first_row_selected][first_col_selected] = 0;
            continue;
        }
        revealed[second_row_selected][second_col_selected] = 1;
        display_board(board, revealed);
        if (board[first_row_selected][first_col_selected] == board[second_row_selected][second_col_selected]) {
            printf("Match!\n");
            if (check_win(revealed)) {
                printf("Congratulations! You won the game.\n");
                return 0;
            }
        } else {
            printf("Not a match. Try again.\n");
            revealed[first_row_selected][first_col_selected] = 0;
            revealed[second_row_selected][second_col_selected] = 0;
        }
    }
}

void initialize_board(int board[ROWS][COLS]) {
    int used[ROWS * COLS / 2] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int card_value;
            do {
                card_value = rand() % (ROWS * COLS / 2);
            } while (used[card_value] >= 2);
            board[i][j] = card_value;
            used[card_value]++;
        }
    }
}

void display_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("?\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(int revealed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}