//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 8
#define KING 2
#define MAX_PIECES 12

char board[SIZE][SIZE];
int white_pieces = MAX_PIECES;
int black_pieces = MAX_PIECES;

bool is_white_turn = true;

//Returns true if the player (white or black) has no pieces left
bool is_game_over(int player_pieces) {
    return player_pieces == 0 ? true : false;
}

//Prints the current state of the board
void print_board() {
    printf("\n  ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//Initializes the board with pieces
void initialize_board() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if((i+j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = 'w';
                }
                else if(i > 4) {
                    board[i][j] = 'b';
                }
                else {
                    board[i][j] = '.';
                }
            }
            else {
                board[i][j] = '-';
            }
        }
    }
}

//Returns true if the move is valid
bool is_valid_move(int row, int col, int new_row, int new_col) {
    if(new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
        return false;
    }

    if(board[new_row][new_col] != '.' && board[new_row][new_col] != '-') {
        return false;
    }

    if(is_white_turn && board[row][col] == 'w' && new_row > row) {
        return false;
    }

    if(!is_white_turn && board[row][col] == 'b' && new_row < row) {
        return false;
    }

    if(board[row][col] == 'w' && new_row == row-1 && (new_col == col-1 || new_col == col+1)) {
        return true;
    }

    if(board[row][col] == 'b' && new_row == row+1 && (new_col == col-1 || new_col == col+1)) {
        return true;
    }

    //Check for valid jumps
    if(board[row][col] == 'w' && new_row == row-2 && (new_col == col-2 || new_col == col+2)) {
        if(board[row-1][(new_col+col)/2] == 'b') {
            return true;
        }
    }

    if(board[row][col] == 'b' && new_row == row+2 && (new_col == col-2 || new_col == col+2)) {
        if(board[row+1][(new_col+col)/2] == 'w') {
            return true;
        }
    }

    return false;
}

//Changes the state of the board based on the move
void move_piece(int row, int col, int new_row, int new_col) {
    if(abs(new_row-row) == 2) { //Jump move
        board[row][col] = '.';
        board[(new_row+row)/2][(new_col+col)/2] = '.';
        board[new_row][new_col] = is_white_turn ? 'w' : 'b';

        if(is_white_turn) {
            black_pieces--;
        }
        else {
            white_pieces--;
        }
    }
    else { //Regular move
        board[row][col] = '.';
        board[new_row][new_col] = is_white_turn ? 'w' : 'b';
    }

    if(is_white_turn && new_row == 0) { //Crown white piece
        board[new_row][new_col] = 'W';
    }
    else if(!is_white_turn && new_row == SIZE-1) { //Crown black piece
        board[new_row][new_col] = 'B';
    }

    is_white_turn = !is_white_turn; //Change the turn
}

int main() {
    initialize_board();

    while(true) {
        print_board();

        if(is_game_over(white_pieces)) {
            printf("Black wins!\n");
            break;
        }
        else if(is_game_over(black_pieces)) {
            printf("White wins!\n");
            break;
        }

        char player = is_white_turn ? 'w' : 'b';
        printf("\n%s's turn.\n", is_white_turn ? "White" : "Black");

        int row, col, new_row, new_col;
        bool valid_move = false;

        while(!valid_move) {
            printf("Enter row and column of piece to move: ");
            scanf("%d%d", &row, &col);

            printf("Enter new row and column of piece: ");
            scanf("%d%d", &new_row, &new_col);

            if(is_valid_move(row, col, new_row, new_col)) {
                move_piece(row, col, new_row, new_col);
                valid_move = true;
            }
            else {
                printf("\nInvalid move. Try again.\n");
            }
        }
    }

    return 0;
}