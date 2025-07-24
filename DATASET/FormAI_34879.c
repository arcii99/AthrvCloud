//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 //size of the tic-tac-toe board

char board[SIZE][SIZE]; //the tic-tac-toe board

//function to print the tic-tac-toe board
void print_board() {
    printf("-------------\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
}

//function to check if a player has won the game
int check_winner(char player) {
    //check rows
    for(int i=0; i<SIZE; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    //check columns
    for(int i=0; i<SIZE; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    //check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    //no winner yet
    return 0;
}

//recursive function to make a move for the AI player
int make_move(char player) {
    //base case: check if the game is over
    if(check_winner('X') == 1) {
        printf("X wins!\n");
        return -10;
    } else if(check_winner('O') == 1) {
        printf("O wins!\n");
        return 10;
    } else {
        int best_score;
        int best_row = -1;
        int best_col = -1;
        if(player == 'O') {
            best_score = 10000;
        } else {
            best_score = -10000;
        }
        //iterate over all possible moves
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                if(board[i][j] == '_') {
                    board[i][j] = player;
                    int score = make_move(player == 'O' ? 'X' : 'O');
                    board[i][j] = '_';
                    //maximize/minimize score
                    if(player == 'O' && score < best_score) {
                        best_score = score;
                        best_row = i;
                        best_col = j;
                    }
                    if(player == 'X' && score > best_score) {
                        best_score = score;
                        best_row = i;
                        best_col = j;
                    }
                }
            }
        }
        //make the best move
        if(best_row != -1 && best_col != -1) {
            board[best_row][best_col] = player;
        }
        return best_score;
    }
}

int main() {
    //initialize board
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = '_';
        }
    }
    //make the first move
    make_move('X');
    //print final board
    print_board();
    return 0;
}