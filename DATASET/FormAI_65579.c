//FormAI DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(char board[ROWS][COLS]) {
    printf("   ");
    for(int i = 0; i < COLS; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    printf("  --------------\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d |", i);
        for(int j = 0; j < COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  --------------\n");
    }
}

int is_game_over(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int is_valid_move(int row, int col, char board[ROWS][COLS], char copy_board[ROWS][COLS]) {
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return 0;
    }
    if(copy_board[row][col] != '-') {
        return 0;
    }
    return 1;
}

void play_game() {
    char board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
    print_board(board);
    srand(time(NULL));
    int num_moves = ROWS * COLS / 2;
    for(int i = 0; i < num_moves; i++) {
        char symbol;
        int row1, col1, row2, col2;
        do {
            row1 = rand() % ROWS;
            col1 = rand() % COLS;
        } while(board[row1][col1] != '-');
        symbol = (char)(i + 'A');
        board[row1][col1] = symbol;
        do {
            row2 = rand() % ROWS;
            col2 = rand() % COLS;
        } while(board[row2][col2] != '-');
        board[row2][col2] = symbol;
    }
    int guesses = 0;
    while(!is_game_over(board)) {
        int row1, col1, row2, col2;
        printf("Guess %d\n", guesses + 1);
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
        if(!is_valid_move(row1, col1, board, board) || !is_valid_move(row2, col2, board, board)) {
            printf("Invalid move\n");
            continue;
        }
        print_board(board);
        if(board[row1][col1] == board[row2][col2]) {
            printf("You found a match!\n");
            board[row1][col1] = ' ';
            board[row2][col2] = ' ';
        } else {
            printf("Not a match\n");
        }
        guesses++;
    }
    printf("Game over! You took %d guesses.\n", guesses);
}

int main() {
    printf("Sherlock Holmes Memory Game\n");
    play_game();
    return 0;
}