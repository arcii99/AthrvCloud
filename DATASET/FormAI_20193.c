//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include <stdio.h>

// Defining variables
#define SIZE 8
int board[SIZE][SIZE] = {
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1}
};
int turn = 0;
int exit_val = 0;

// Function for printing board
void printBoard() {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            switch(board[i][j]) {
                case -1:
                    printf("B ");
                    break;
                case 0:
                    printf("- ");
                    break;
                case 1:
                    printf("W ");
                    break;
                case -2:
                    printf("BK ");
                    break;
                case 2:
                    printf("WK ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function for making moves
void make_move(int current_row, int current_col, int new_row, int new_col) {
    // Checking if move is valid
    if(board[new_row][new_col] == 0) {
        if(turn % 2 == 0) {
            // White player's turn
            if(board[current_row][current_col] == 1) {
                // Normal move
                if(current_row - new_row == 1 && (current_col - new_col == 1 || current_col - new_col == -1)) {
                    board[new_row][new_col] = 1;
                    board[current_row][current_col] = 0;
                }
                // Jump move
                else if(current_row - new_row == 2 && (current_col - new_col == 2 || current_col - new_col == -2)) {
                    if(board[current_row-1][(current_col+new_col)/2] == -1 || board[current_row-1][(current_col+new_col)/2] == -2) {
                        board[new_row][new_col] = 1;
                        board[current_row][current_col] = 0;
                        board[current_row-1][(current_col+new_col)/2] = 0;
                    }
                    else {
                        printf("Invalid Move!\n");
                        return;
                    }
                }
                else {
                    printf("Invalid Move!\n");
                    return;
                }
                // Promoting to king if reached opposite end
                if(new_row == 0) {
                    board[new_row][new_col] = 2;
                }
            }
            // King's move
            else if(board[current_row][current_col] == 2) {
               // Normal move
                if((current_row - new_row == 1 || new_row - current_row == 1) && (current_col - new_col == 1 || current_col - new_col == -1)) {
                    board[new_row][new_col] = 2;
                    board[current_row][current_col] = 0;
                }
                // Jump move
                else if((current_row - new_row == 2 || new_row - current_row == 2) && (current_col - new_col == 2 || current_col - new_col == -2)) {   
                    if(new_row - current_row == -2 && new_col - current_col == -2) {
                        if(board[current_row-1][current_col-1] == -1 || board[current_row-1][current_col-1] == -2) {
                            board[new_row][new_col] = 2;
                            board[current_row][current_col] = 0;
                            board[current_row-1][current_col-1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else if(new_row - current_row == -2 && new_col - current_col == 2) {
                        if(board[current_row-1][current_col+1] == -1 || board[current_row-1][current_col+1] == -2) {
                            board[new_row][new_col] = 2;
                            board[current_row][current_col] = 0;
                            board[current_row-1][current_col+1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else if(new_row - current_row == 2 && new_col - current_col == -2) {
                        if(board[current_row+1][current_col-1] == -1 || board[current_row+1][current_col-1] == -2) {
                            board[new_row][new_col] = 2;
                            board[current_row][current_col] = 0;
                            board[current_row+1][current_col-1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else if(new_row - current_row == 2 && new_col - current_col == 2) {
                        if(board[current_row+1][current_col+1] == -1 || board[current_row+1][current_col+1] == -2) {
                            board[new_row][new_col] = 2;
                            board[current_row][current_col] = 0;
                            board[current_row+1][current_col+1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else {
                        printf("Invalid Move!\n");
                        return;
                    } 
                }
                else {
                    printf("Invalid Move!\n");
                    return;
                }
            }
            else {
                printf("Invalid Move!\n");
                return;
            }
        }
        else {
            // Black player's turn
            if(board[current_row][current_col] == -1) {
                // Normal move
                if(new_row - current_row == 1 && (current_col - new_col == 1 || current_col - new_col == -1)) {
                    board[new_row][new_col] = -1;
                    board[current_row][current_col] = 0;
                }
                // Jump move
                else if(new_row - current_row == 2 && (current_col - new_col == 2 || current_col - new_col == -2)) {
                    if(board[current_row+1][(current_col+new_col)/2] == 1 || board[current_row+1][(current_col+new_col)/2] == 2) {
                        board[new_row][new_col] = -1;
                        board[current_row][current_col] = 0;
                        board[current_row+1][(current_col+new_col)/2] = 0;
                    }
                    else {
                        printf("Invalid Move!\n");
                        return;
                    }
                }
                else {
                    printf("Invalid Move!\n");
                    return;
                }
                // Promoting to king if reached opposite end
                if(new_row == (SIZE-1)) {
                    board[new_row][new_col] = -2;
                }
            }
            // King's move
            else if(board[current_row][current_col] == -2) {
                // Normal move
                if((new_row - current_row == 1 || current_row - new_row == 1) && (current_col - new_col == 1 || current_col - new_col == -1)) {
                    board[new_row][new_col] = -2;
                    board[current_row][current_col] = 0;
                }
                // Jump move
                else if((new_row - current_row == 2 || current_row - new_row == 2) && (current_col - new_col == 2 || current_col - new_col == -2)) {
                    if(new_row - current_row == -2 && new_col - current_col == -2) {
                        if(board[current_row-1][current_col-1] == 1 || board[current_row-1][current_col-1] == 2) {
                            board[new_row][new_col] = -2;
                            board[current_row][current_col] = 0;
                            board[current_row-1][current_col-1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else if(new_row - current_row == -2 && new_col - current_col == 2) {
                        if(board[current_row-1][current_col+1] == 1 || board[current_row-1][current_col+1] == 2) {
                            board[new_row][new_col] = -2;
                            board[current_row][current_col] = 0;
                            board[current_row-1][current_col+1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else if(new_row - current_row == 2 && new_col - current_col == -2) {
                        if(board[current_row+1][current_col-1] == 1 || board[current_row+1][current_col-1] == 2) {
                            board[new_row][new_col] = -2;
                            board[current_row][current_col] = 0;
                            board[current_row+1][current_col-1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else if(new_row - current_row == 2 && new_col - current_col == 2) {
                        if(board[current_row+1][current_col+1] == 1 || board[current_row+1][current_col+1] == 2) {
                            board[new_row][new_col] = -2;
                            board[current_row][current_col] = 0;
                            board[current_row+1][current_col+1] = 0;
                        }
                        else {
                            printf("Invalid Move!\n");
                            return; 
                        }
                    }
                    else {
                        printf("Invalid Move!\n");
                        return; 
                    }
                }
                else {
                    printf("Invalid Move!\n");
                    return;
                }
            }
            else {
                printf("Invalid Move!\n");
                return;
            }
        }
        turn++;
    }
    else {
        printf("Invalid Move!\n");
        return;
    }
}

// Function for checking if game is over
int game_over() {
    int white = 0, black = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == 1 || board[i][j] == 2) {
                white++;
            }
            if(board[i][j] == -1 || board[i][j] == -2) {
                black++;
            }
        }
    }
    if(white == 0) {
        printf("Black Wins!\n");
        return 1;
    }
    else if(black == 0) {
        printf("White Wins!\n");
        return 1;
    }
    else {
        return 0;
    }
}

// Main function
int main() {
    // Variables
    int current_row, current_col, new_row, new_col;

    // Printing initial board
    printf("-------------------------\n");
    printf("Welcome to Checkers Game!\n");
    printf("-------------------------\n");
    printf("White starts first.\n");
    printf("-------------------------\n");
    printBoard();

    // Main game loop
    while(exit_val == 0) {
        // Taking input from player
        printf("Enter current position (row, col):\n");
        scanf("%d %d", &current_row, &current_col);
        printf("Enter new position (row, col):\n");
        scanf("%d %d", &new_row, &new_col);

        // Making move
        make_move(current_row, current_col, new_row, new_col);
        printBoard();

        // Checking if game is over
        if(game_over() == 1) {
            printf("-------------------------\n");
            printf("Thank you for playing!\n");
            printf("-------------------------\n");
            exit_val = 1;
        }
    }

    return 0;
}