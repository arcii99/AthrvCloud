//FormAI DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 8

void initialize_board(int board[ROWS][COLS], int value_count[MAX_VALUE]) {
    // Initialize the board with random values
    srand(time(NULL));
    int num_values_assigned[MAX_VALUE] = {0};
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int value = rand() % MAX_VALUE + 1;
            while (num_values_assigned[value-1] >= 2) {
                value = rand() % MAX_VALUE + 1;
            }
            board[row][col] = value;
            num_values_assigned[value-1]++;
            value_count[value-1]++;
        }
    }
}

void print_board(int board[ROWS][COLS], int hidden[ROWS][COLS]) {
    // Print the current state of the game board
    printf("  ");
    for (int col = 0; col < COLS; col++) {
        printf("%d ", col+1);
    }
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%d ", row+1);
        for (int col = 0; col < COLS; col++) {
            if (hidden[row][col] == 0) {
                printf("* ");
            } else {
                printf("%d ", board[row][col]);
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    int hidden[ROWS][COLS] = {0};
    int value_count[MAX_VALUE] = {0};
    int row1, col1, row2, col2;
    int num_turns = 0;
    
    initialize_board(board, value_count);
    printf("Welcome to the Memory Game!\n");
    print_board(board, hidden);
    
    while (1) {
        if (num_turns == ROWS*COLS/2) {
            printf("Congratulations! You won the game in %d turns.\n", num_turns);
            break;
        }
        printf("Enter the row and column of your first choice (separated by a space): ");
        scanf("%d %d", &row1, &col1);
        hidden[row1-1][col1-1] = 1;
        print_board(board, hidden);
        printf("Enter the row and column of your second choice (separated by a space): ");
        scanf("%d %d", &row2, &col2);
        hidden[row2-1][col2-1] = 1;
        print_board(board, hidden);
        num_turns++;
        if (board[row1-1][col1-1] != board[row2-1][col2-1]) {
            hidden[row1-1][col1-1] = 0;
            hidden[row2-1][col2-1] = 0;
            printf("Sorry, those do not match.\n");
        } else {
            printf("Match found!\n");
            if (value_count[board[row1-1][col1-1]-1] == 2) {
                printf("Congratulations, you have found both matches for the value %d!\n", board[row1-1][col1-1]);
            }
        }
    }
    
    return 0;
}