//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to print the bingo board
void print_board(int board[ROWS][COLS], int called_nums[]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(j == COLS - 1) {
                if(board[i][j] == -1) {
                    printf("FREE ");
                } else {
                    printf("%-4d", board[i][j]);
                }
            } else {
                if(board[i][j] == -1) {
                    printf("FREE | ");
                } else {
                    printf("%-4d| ", board[i][j]);
                }
            }
        }
        printf("\n");
        if(i != ROWS - 1) {
            printf("----|----|----|----|----\n");
        }
    }
    printf("\nCalled Numbers: ");
    for(int i = 0; i < 75; i++) {
        if(called_nums[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

// Function to check if a win condition is met
int check_win(int board[ROWS][COLS]) {
    // Check rows for win
    for(int i = 0; i < ROWS; i++) {
        int row_check = 1;
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] != -1) {
                row_check = 0;
                break;
            }
        }
        if(row_check) {
            printf("\nBingo! You won on row %d!\n", i + 1);
            return 1;
        }
    }
    // Check columns for win
    for(int i = 0; i < COLS; i++) {
        int col_check = 1;
        for(int j = 0; j < ROWS; j++) {
            if(board[j][i] != -1) {
                col_check = 0;
                break;
            }
        }
        if(col_check) {
            printf("\nBingo! You won on column %d!\n", i + 1);
            return 1;
        }
    }
    // Check diagonals for win
    if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        printf("\nBingo! You won on the \\ diagonal!\n");
        return 1;
    } else if(board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        printf("\nBingo! You won on the / diagonal!\n");
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int called_nums[75] = {0};
    // Create the board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 2 && j == 2) {
                board[i][j] = -1;
            } else {
                board[i][j] = (j * 15) + (rand() % 15) + 1;
            }
        }
    }
    // Print the initial board
    print_board(board, called_nums);
    // Game Loop
    while(!check_win(board)) {
        // Get a random number
        int num = rand() % 75;
        while(called_nums[num]) {
            num = rand() % 75;
        }
        called_nums[num] = 1;
        printf("\nNumber %d called.\n", num + 1);
        // Check the board for the called number and mark it
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == (num + 1)) {
                    board[i][j] = -1;
                }
            }
        }
        // Print the updated board
        print_board(board, called_nums);
    }
    return 0;
}