//FormAI DATASET v1.0 Category: Checkers Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = {
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '}
};

void print_board() {
    printf("\n   1 2 3 4 5 6 7 8\n");
    for(int row = 0; row < 8; row++) {
        printf("%d  ", row+1);
        for(int col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("%d\n", row+1);
    }
    printf("   1 2 3 4 5 6 7 8\n\n");
}

int main() {
    printf("Welcome to Checkers!\n\n");
    printf("Here is the starting board:\n");
    print_board();

    int turn = 0; // 0 = red turn, 1 = black turn

    while(1) {
        if(turn == 0) {
            printf("Red's turn\n");

            int from_row, from_col, to_row, to_col;
            while(1) { // get move from player
                printf("Enter coordinates of piece to move (row col): ");
                scanf("%d %d", &from_row, &from_col);

                if(board[from_row-1][from_col-1] == 'r' || board[from_row-1][from_col-1] == 'R') {
                    break; // valid piece selected
                } else {
                    printf("Invalid piece selected\n");
                }
            }

            while(1) {
                printf("Enter coordinates to move to (row col): ");
                scanf("%d %d", &to_row, &to_col);

                // check if move is valid
                if((to_row-from_row == 1 && abs(to_col-from_col) == 1) && board[to_row-1][to_col-1] == ' ') { // move one space diagonally
                    board[to_row-1][to_col-1] = 'r'; // move piece
                    board[from_row-1][from_col-1] = ' '; // remove piece from original position
                    break; // valid move
                } else {
                    printf("Invalid move selected\n");
                }
            }

            turn = 1; // switch to black's turn
        } else {
            printf("Black's turn\n");

            int from_row, from_col, to_row, to_col;
            while(1) { // get move from player
                printf("Enter coordinates of piece to move (row col): ");
                scanf("%d %d", &from_row, &from_col);

                if(board[from_row-1][from_col-1] == 'b' || board[from_row-1][from_col-1] == 'B') {
                    break; // valid piece selected
                } else {
                    printf("Invalid piece selected\n");
                }
            }

            while(1) {
                printf("Enter coordinates to move to (row col): ");
                scanf("%d %d", &to_row, &to_col);

                // check if move is valid
                if((from_row-to_row == 1 && abs(to_col-from_col) == 1) && board[to_row-1][to_col-1] == ' ') { // move one space diagonally
                    board[to_row-1][to_col-1] = 'b'; // move piece
                    board[from_row-1][from_col-1] = ' '; // remove piece from original position
                    break; // valid move
                } else {
                    printf("Invalid move selected\n");
                }
            }

            turn = 0; // switch to red's turn
        }

        print_board(); // print board after move
    }

    return 0;
}