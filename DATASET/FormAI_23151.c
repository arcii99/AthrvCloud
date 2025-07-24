//FormAI DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    printf("\n  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'A'+i);
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    int revealed[ROWS][COLS] = {0};
    int bombs = 10;
    srand(time(NULL));
    printf("***Welcome to Minesweeper!***\n");
    printf("This game is played on a 10x10 board. You have to uncover all squares except the ones with bombs in them.\n");
    printf("Enter the row and column indices of the square you want to reveal (ex: A2).\n");
    //place bombs on board
    for (int i = 0; i < bombs; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        while (board[row][col] == -1) { //make sure no two bombs are placed in the same spot
            row = rand() % ROWS;
            col = rand() % COLS;
        }
        board[row][col] = -1;
    }
    //fill in numbers on board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] != -1) { //if not a bomb
                for (int i = row-1; i <= row+1; i++) {
                    for (int j = col-1; j <= col+1; j++) {
                        if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == -1) { //if neighboring cell has bomb
                            board[row][col]++;
                        }
                    }
                }
            }
        }
    }
    //play game
    while (1) {
        print_board(board, revealed);
        int row, col;
        printf("Enter indices: ");
        scanf(" %c%d", &row, &col);
        row = row - 'A';
        col--;
        if (board[row][col] == -1) {
            printf("Oh no! You revealed a bomb! Game over.\n");
            revealed[row][col] = 1;
            print_board(board, revealed);
            break;
        } else {
            revealed[row][col] = 1;
            if (board[row][col] == 0) { //if neighboring cells also have zero value, reveal them as well
                for (int i = row-1; i <= row+1; i++) {
                    for (int j = col-1; j <= col+1; j++) {
                        if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !revealed[i][j]) {
                            revealed[i][j] = 1;
                        }
                    }
                }
            }
            int count_revealed = 0;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (revealed[i][j]) {
                        count_revealed++;
                    }
                }
            }
            if (count_revealed == ROWS * COLS - bombs) {
                printf("Congratulations! You revealed all the squares without detonating a bomb.\n");
                print_board(board, revealed);
                break;
            }
        }
    }
    return 0;
}