//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
bool player1_turn = true;

void initialize_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j)%2 == 0) {
                if(i<3) {
                    board[i][j] = 'o';
                } else if(i>4) {
                    board[i][j] = 'x';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("-----------------\n");
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

bool is_valid_move(int row1, int col1, int row2, int col2) {
    if(board[row2][col2] != ' ') {
        return false;
    }

    if(player1_turn) {
        if(row2-row1 == 1 && abs(col2-col1) == 1) {
            return true;
        }

        if(row2-row1 == 2 && abs(col2-col1) == 2 && board[row1+1][col1+(col2-col1)/2] == 'o') {
            board[row1+1][col1+(col2-col1)/2] = ' ';
            return true;
        }

        if(row1-row2 == 2 && abs(col2-col1) == 2 && board[row1-1][col1+(col2-col1)/2] == 'o') {
            board[row1-1][col1+(col2-col1)/2] = ' ';
            return true;
        }

        if(board[row1][col1] == 'O') {
            int i = row1 + 1;
            int j = col1 + 1;
            while(i<row2 && j<col2) {
                if(board[i][j] != ' ') {
                    return false;
                }
                i++;
                j++;
            }

            if(i == row2 && j == col2) {
                return true;
            }
        }

        if(board[row1][col1] == 'O') {
            int i = row1 + 1;
            int j = col1 - 1;
            while(i<row2 && j>col2) {
                if(board[i][j] != ' ') {
                    return false;
                }
                i++;
                j--;
            }

            if(i == row2 && j == col2) {
                return true;
            }
        }
    } else {
        if(row1-row2 == 1 && abs(col2-col1) == 1) {
            return true;
        }

        if(row1-row2 == 2 && abs(col2-col1) == 2 && board[row1-1][col1+(col2-col1)/2] == 'x') {
            board[row1-1][col1+(col2-col1)/2] = ' ';
            return true;
        }

        if(row2-row1 == 2 && abs(col2-col1) == 2 && board[row1+1][col1+(col2-col1)/2] == 'x') {
            board[row1+1][col1+(col2-col1)/2] = ' ';
            return true;
        }

        if(board[row1][col1] == 'X') {
            int i = row1 - 1;
            int j = col1 + 1;
            while(i>row2 && j<col2) {
                if(board[i][j] != ' ') {
                    return false;
                }
                i--;
                j++;
            }

            if(i == row2 && j == col2) {
                return true;
            }
        }

        if(board[row1][col1] == 'X') {
            int i = row1 - 1;
            int j = col1 - 1;
            while(i>row2 && j>col2) {
                if(board[i][j] != ' ') {
                    return false;
                }
                i--;
                j--;
            }

            if(i == row2 && j == col2) {
                return true;
            }
        }
    }

    return false;
}

bool is_game_over() {
    int x_count = 0;
    int o_count = 0;

    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 'x' || board[i][j] == 'X') {
                x_count++;
            }
            else if(board[i][j] == 'o' || board[i][j] == 'O') {
                o_count++;
            }
        }
    }

    return x_count == 0 || o_count == 0;
}

int main() {
    initialize_board();
    print_board();

    while(!is_game_over()) {
        printf("Player %d's turn\n", player1_turn ? 1 : 2);

        int row1, col1, row2, col2;

        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row1, &col1);

        printf("Enter the row and column of the position you want to move to: ");
        scanf("%d %d", &row2, &col2);

        if(is_valid_move(row1, col1, row2, col2)) {
            board[row2][col2] = board[row1][col1];
            board[row1][col1] = ' ';
            player1_turn = !player1_turn;
        } else {
            printf("Invalid move. Try again.\n");
        }

        print_board();
    }

    printf("Game over.\n");

    return 0;
}