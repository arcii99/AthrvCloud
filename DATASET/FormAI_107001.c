//FormAI DATASET v1.0 Category: Chess engine ; Style: genious
/* 
A innovative Chess engine program developed in C
Author: A.I.
*/

#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1

int current_player = WHITE; // current player
char board[8][8] = {
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
                   }; // initial chess board

// function to print the chess board in console
void print_board() {
    printf("  a b c d e f g h\n");
    for(int i = 7; i >= 0; i--) {
        printf("%d ", i+1);
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("  a b c d e f g h\n");
}

// function to get the piece at given coordinates
char get_piece(int x, int y) {
    return board[x][y];
}

// function to check if a move is valid or not
int is_valid_move(int x1, int y1, int x2, int y2) {
    char piece = get_piece(x1, y1);
    char dest = get_piece(x2, y2);
    
    if(piece == 'P') {
        if(y1 == y2) { // move straight
            if(x2 - x1 == 1) { // move one square
                if(dest == ' ') { // destination should be empty for a pawn move
                    return 1;
                }
            }
            else if(x2 - x1 == 2 && x1 == 1) { // move two squares from initial position
                if(dest == ' ' && get_piece(x1+1, y1) == ' ') { // intermediate square should be empty
                    return 1;
                }
            }
        }
        else if(abs(y2 - y1) == 1 && x2 - x1 == 1) { // diagonal move to capture opponent's piece
            if(dest != ' ' && islower(dest)) { 
                return 1;
            }
        }
    }
    else if(piece == 'R') {
        if(x1 == x2) { // move horizontal
            int start = y1 < y2 ? y1 : y2;
            int end = y1 < y2 ? y2 : y1;
            for(int i = start+1 ; i < end; i++) {
                if(get_piece(x1, i) != ' ') {
                    return 0;
                }
            }
            if(dest == ' ' || islower(dest)) {
                return 1;
            }
        }
        else if(y1 == y2) { // move vertical
            int start = x1 < x2 ? x1 : x2;
            int end = x1 < x2 ? x2 : x1;
            for(int i = start+1; i < end; i++) {
                if(get_piece(i, y1) != ' ') {
                    return 0;
                }
            }
            if(dest == ' ' || islower(dest)) {
                return 1;
            }
        }
    }
    else if(piece == 'N') {
        if((abs(x2-x1) == 2 && abs(y2-y1) == 1) || (abs(x2-x1) == 1 && abs(y2-y1) == 2)) { // move in 'L' shape
            if(dest == ' ' || islower(dest)) {
                return 1;
            }
        }
    }
    else if(piece == 'B') {
        if(abs(x2-x1) == abs(y2-y1)) { // move diagonal
            int i = x1 < x2 ? x1 : x2;
            int j = y1 < y2 ? y1 : y2;
            int xinc = x1 < x2 ? 1 : -1;
            int yinc = y1 < y2 ? 1 : -1;
            while(i != x2 && j != y2) {
                if(i != x1 && j != y1 && get_piece(i, j) != ' ') {
                    return 0;
                }
                i += xinc; j += yinc;
            }
            if(dest == ' ' || islower(dest)) {
                return 1;
            }
        }
    }
    else if(piece == 'Q') {
        if(x1 == x2 || y1 == y2) { // move like rook
            return is_valid_move(x1, y1, x2, y2);
        }
        else if(abs(x2-x1) == abs(y2-y1)) { // move like bishop
            return is_valid_move(x1, y1, x2, y2);
        }
    }
    else if(piece == 'K') {
        if(abs(x2-x1) < 2 && abs(y2-y1) < 2) { // move one square in any direction
            if(dest == ' ' || islower(dest)) {
                return 1;
            }
        }
    }
    return 0;
}

// function to move a piece to given coordinates and return 1 if move is successful else 0
int move_piece(int x1, int y1, int x2, int y2) {
    if(is_valid_move(x1, y1, x2, y2)) {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
        return 1;
    }
    return 0;
}

int main() {
    printf("Welcome to Genius Chess Engine!\nLet's start the game\n");
    print_board();
    while(1) {
        char input[5];
        printf("Enter move: ");
        scanf("%s", input);
        int x1 = input[1] - '1';
        int y1 = input[0] - 'a';
        int x2 = input[3] - '1';
        int y2 = input[2] - 'a';
        int success = move_piece(x1, y1, x2, y2);
        if(success) {
            current_player = (current_player == WHITE) ? BLACK : WHITE;
            printf("\nMove Successful!\n");
            print_board();
        }
        else {
            printf("\nInvalid Move!\n");
        }
    }
    return 0;
}