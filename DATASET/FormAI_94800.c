//FormAI DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
void shuffle(int arr[], int size);
int check_win(int revealed[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int num_moves = 0;
    int first_choice_row, first_choice_col, second_choice_row, second_choice_col;
    initialize_board(board);
    srand(time(NULL));
    shuffle((int *)board, ROWS*COLS);
    printf("Welcome to the Memory Game!\n");
    while (1) {
        print_board(board, revealed);
        printf("Please enter the row and column of your first choice: ");
        scanf("%d %d", &first_choice_row, &first_choice_col);
        if (revealed[first_choice_row][first_choice_col]) {
            printf("This tile has already been revealed, please choose another one.\n");
            continue;
        }
        revealed[first_choice_row][first_choice_col] = 1;
        print_board(board, revealed);
        printf("Please enter the row and column of your second choice: ");
        scanf("%d %d", &second_choice_row, &second_choice_col);
        if (revealed[second_choice_row][second_choice_col]) {
            printf("This tile has already been revealed, please choose another one.\n");
            revealed[first_choice_row][first_choice_col] = 0;
            continue;
        }
        num_moves++;
        revealed[second_choice_row][second_choice_col] = 1;
        print_board(board, revealed);
        if (board[first_choice_row][first_choice_col] != board[second_choice_row][second_choice_col]) {
            printf("Sorry, these tiles do not match.\n");
            revealed[first_choice_row][first_choice_col] = revealed[second_choice_row][second_choice_col] = 0;
        } else {
            printf("Congratulations, you have found a match!\n");
        }
        if (check_win(revealed)) {
            printf("You win! It took you %d moves.\n", num_moves);
            exit(0);
        }
    }
    return 0;
}

void initialize_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = (i*COLS+j)/2;
        }
    }
}

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void shuffle(int arr[], int size) {
    int i, j, temp;
    for (i = size-1; i > 0; i--) {
        j = rand() % (i+1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int check_win(int revealed[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}