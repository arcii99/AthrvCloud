//FormAI DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void init_board(char board[BOARD_SIZE][BOARD_SIZE], int nums[BOARD_SIZE * BOARD_SIZE / 2]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int is_game_over(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int nums[BOARD_SIZE * BOARD_SIZE / 2];
    int row1, col1, row2, col2;
    int num_turns = 0;

    srand(time(NULL));
    init_board(board, nums);

    printf("Welcome to Memory Game!\n");
    printf("Match all the pairs to win!\n\n");

    while (!is_game_over(board)) {
        /* Print board */
        print_board(board);

        /* Get first card */
        printf("Enter the row and column of the first card (e.g. 1 2): ");
        scanf("%d %d", &row1, &col1);
        while (board[row1-1][col1-1] != ' ') {
            printf("That card has already been flipped!\n");
            printf("Enter the row and column of the first card (e.g. 1 2): ");
            scanf("%d %d", &row1, &col1);
        }
        board[row1-1][col1-1] = nums[(row1-1) * BOARD_SIZE / 2 + (col1-1) / 2];

        /* Get second card */
        printf("Enter the row and column of the second card (e.g. 1 2): ");
        scanf("%d %d", &row2, &col2);
        while (board[row2-1][col2-1] != ' ') {
            printf("That card has already been flipped!\n");
            printf("Enter the row and column of the second card (e.g. 1 2): ");
            scanf("%d %d", &row2, &col2);
        }
        board[row2-1][col2-1] = nums[(row2-1) * BOARD_SIZE / 2 + (col2-1) / 2];

        /* Check for match */
        if (board[row1-1][col1-1] == board[row2-1][col2-1]) {
            printf("Match found!\n");
        } else {
            printf("No match.\n");
            board[row1-1][col1-1] = ' ';
            board[row2-1][col2-1] = ' ';
        }
        
        /* Increment turn counter */
        num_turns++;
    }

    /* Game over */
    print_board(board);
    printf("Congratulations! You won in %d turns.\n", num_turns);

    return 0;
}

/* Initializes the game board with shuffled numbers */
void init_board(char board[BOARD_SIZE][BOARD_SIZE], int nums[BOARD_SIZE * BOARD_SIZE / 2]) {
    int i, j, k;
    int temp;

    /* Initialize board with empty spaces */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    /* Set up numbers */
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        nums[i] = i + 1;
    }

    /* Shuffle numbers */
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        j = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

/* Prints the game board */
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("\n");
    printf("    1   2   3   4\n");
    printf("  +---+---+---+---+\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  +---+---+---+---+\n");
    }
}

/* Determines if the game is over */
int is_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}