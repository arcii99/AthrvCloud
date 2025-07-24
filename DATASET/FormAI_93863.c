//FormAI DATASET v1.0 Category: Chess AI ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// chess board representation
char board[BOARD_SIZE][BOARD_SIZE];

// determine if a position is safe for a move
bool is_safe(int row, int col, char color) {
    // check if there is no piece in the current position
    if(board[row][col] != ' ') {
        return false;
    }

    // check if there is a piece of opposite color attacking the current position
    int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for(int i = 0; i < 8; i++) {
        int r = row + dr[i];
        int c = col + dc[i];

        if(r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] != ' ') {
            if((color == 'w' && islower(board[r][c])) || (color == 'b' && isupper(board[r][c]))) {
                switch(tolower(board[r][c])) {
                    case 'p':
                        if(i == 1 && color == 'w') {
                            return true;
                        } else if(i == 5 && color == 'b') {
                            return true;
                        }
                        break;
                    case 'r':
                        if(i == 0 || i == 2 || i == 4 || i == 6) {
                            return true;
                        }
                        break;
                    case 'n':
                        if(i == 1 || i == 7) {
                            return true;
                        }
                        break;
                    case 'b':
                        if(i == 0 || i == 2 || i == 4 || i == 6) {
                            return true;
                        }
                        break;
                    case 'q':
                        return true;
                        break;
                    case 'k':
                        if(i >= 0 && i < 8) {
                            return true;
                        }
                        break;
                }
            }
        }
    }

    return false;
}

// determine if the current player can make a move
bool can_move(char color) {
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            if(toupper(board[row][col]) == color) {
                for(int dest_row = 0; dest_row < BOARD_SIZE; dest_row++) {
                    for(int dest_col = 0; dest_col < BOARD_SIZE; dest_col++) {
                        if(is_safe(dest_row, dest_col, color)) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

// generate a random move for the current player
void generate_move(char color, int *row, int *col, int *dest_row, int *dest_col) {
    while(true) {
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
        if(toupper(board[*row][*col]) == color) {
            *dest_row = rand() % BOARD_SIZE;
            *dest_col = rand() % BOARD_SIZE;
            if(is_safe(*dest_row, *dest_col, color)) {
                break;
            }
        }
    }
}

// print the current state of the board
void print_board() {
    printf("  a b c d e f g h\n");
    for(int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row + 1);
        for(int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("%d", row + 1);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main() {
    // initialize the board
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }

    // place the pieces
    board[0][0] = board[0][7] = 'r';
    board[0][1] = board[0][6] = 'n';
    board[0][2] = board[0][5] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[7][0] = board[7][7] = 'R';
    board[7][1] = board[7][6] = 'N';
    board[7][2] = board[7][5] = 'B';
    board[7][3] = 'Q';
    board[7][4] = 'K';
    for(int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }

    // set the initial turn to white
    char turn = 'w';

    // play the game
    while(true) {
        print_board();
        if(!can_move(turn)) {
            if(turn == 'w') {
                printf("Black wins!\n");
            } else {
                printf("White wins!\n");
            }
            break;
        }
        int row, col, dest_row, dest_col;
        generate_move(turn, &row, &col, &dest_row, &dest_col);
        printf("%c moves from %c%d to %c%d\n", turn, col + 'a', row + 1, dest_col + 'a', dest_row + 1);
        board[dest_row][dest_col] = board[row][col];
        board[row][col] = ' ';
        if(turn == 'w') {
            turn = 'b';
        } else {
            turn = 'w';
        }
    }

    return 0;
}