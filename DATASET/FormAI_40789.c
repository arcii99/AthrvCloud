//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>

#define BOARD_SIZE 8

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int get_piece_color(char piece);
int move_piece(char board[BOARD_SIZE][BOARD_SIZE], int cur_row, int cur_col, int next_row, int next_col);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int cur_row, int cur_col, int next_row, int next_col, int color);
int is_piece(char piece);
int check_if_capture(char board[BOARD_SIZE][BOARD_SIZE], int cur_row, int cur_col, int next_row, int next_col, int color);
int is_end_game(char board[BOARD_SIZE][BOARD_SIZE], int color);

int main()
{
    // initialize the board
    char board[BOARD_SIZE][BOARD_SIZE] = {{'r','n','b','q','k','b','n','r'},
                                          {'p','p','p','p','p','p','p','p'},
                                          {' ',' ',' ',' ',' ',' ',' ',' '},
                                          {' ',' ',' ',' ',' ',' ',' ',' '},
                                          {' ',' ',' ',' ',' ',' ',' ',' '},
                                          {' ',' ',' ',' ',' ',' ',' ',' '},
                                          {'P','P','P','P','P','P','P','P'},
                                          {'R','N','B','Q','K','B','N','R'}};

    int cur_row, cur_col, next_row, next_col;

    // print the board initially
    print_board(board);

    // loop to accept moves until game ends
    while(1) {
        printf("Enter current row, column and next row, column separated by spaces:\n");
        scanf("%d %d %d %d", &cur_row, &cur_col, &next_row, &next_col);

        // check if move is valid and move the piece if so
        if(is_valid_move(board, cur_row, cur_col, next_row, next_col, get_piece_color(board[cur_row][cur_col]))) {
            move_piece(board, cur_row, cur_col, next_row, next_col);

            // print the board after each move
            print_board(board);

            // check if endgame condition is met, exit the loop if so
            if(is_end_game(board, get_piece_color(board[cur_row][cur_col]))) {
                break;
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    printf("Game over!\n");

    return 0;
}

// function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// function to get the color of the piece
int get_piece_color(char piece)
{
    if(piece >= 'a' && piece <= 'z') {
        return 1; // black piece
    } else {
        return 0; // white piece
    }
}

// function to move the piece on the board
int move_piece(char board[BOARD_SIZE][BOARD_SIZE], int cur_row, int cur_col, int next_row, int next_col)
{
    board[next_row][next_col] = board[cur_row][cur_col];
    board[cur_row][cur_col] = ' ';

    return 1;
}

// function to check if the move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int cur_row, int cur_col, int next_row, int next_col, int color)
{
    // check if the move is within the board limits
    if(next_row < 0 || next_row > BOARD_SIZE - 1 || next_col < 0 || next_col > BOARD_SIZE - 1) {
        return 0;
    }

    // check if there is a piece at the current location and that it is of the player's color
    if(!is_piece(board[cur_row][cur_col]) || get_piece_color(board[cur_row][cur_col]) != color) {
        return 0;
    }

    // check if the piece can move to the next location
    switch(board[cur_row][cur_col]) {
        case 'P': // white pawn
            if(cur_col == next_col && board[next_row][next_col] == ' ' && next_row == cur_row - 1) {
                return 1;
            } else if(cur_col == next_col && cur_row == 6 && board[next_row][next_col] == ' ' && next_row == cur_row - 2) {
                return 1;
            } else if(abs(cur_col - next_col) == 1 && board[next_row][next_col] != ' ' && get_piece_color(board[next_row][next_col]) != color && next_row == cur_row - 1) {
                return 1;
            }

            return 0;

        case 'p': // black pawn
            if(cur_col == next_col && board[next_row][next_col] == ' ' && next_row == cur_row + 1) {
                return 1;
            } else if(cur_col == next_col && cur_row == 1 && board[next_row][next_col] == ' ' && next_row == cur_row + 2) {
                return 1;
            } else if(abs(cur_col - next_col) == 1 && board[next_row][next_col] != ' ' && get_piece_color(board[next_row][next_col]) != color && next_row == cur_row + 1) {
                return 1;
            }

            return 0;

        case 'R': // white rook
        case 'r': // black rook
            if(cur_row == next_row && cur_col != next_col) {
                int i, step;
                if(next_col > cur_col) {
                    step = 1;
                } else {
                    step = -1;
                }

                for(i = cur_col + step; i != next_col; i += step) {
                    if(board[cur_row][i] != ' ') {
                        return 0;
                    }
                }

                return 1;
            } else if(cur_row != next_row && cur_col == next_col) {
                int i, step;
                if(next_row > cur_row) {
                    step = 1;
                } else {
                    step = -1;
                }

                for(i = cur_row + step; i != next_row; i += step) {
                    if(board[i][cur_col] != ' ') {
                        return 0;
                    }
                }

                return 1;
            }

            return 0;

        case 'N': // white knight
        case 'n': // black knight
            if((abs(cur_row - next_row) == 2 && abs(cur_col - next_col) == 1) || (abs(cur_row - next_row) == 1 && abs(cur_col - next_col) == 2)) {
                return 1;
            }

            return 0;

        case 'B': // white bishop
        case 'b': // black bishop
            if(abs(cur_row - next_row) != abs(cur_col - next_col)) {
                return 0;
            }

            int i, step_row, step_col;
            if(next_row > cur_row) {
                step_row = 1;
            } else {
                step_row = -1;
            }

            if(next_col > cur_col) {
                step_col = 1;
            } else {
                step_col = -1;
            }

            for(i = 1; i < abs(cur_row - next_row); i++) {
                if(board[cur_row + i*step_row][cur_col + i*step_col] != ' ') {
                    return 0;
                }
            }

            return 1;

        case 'Q': // white queen
        case 'q': // black queen
            if(is_valid_move(board, cur_row, cur_col, next_row, cur_col, color) || is_valid_move(board, cur_row, cur_col, cur_row, next_col, color)) {
                return 1;
            } else if(is_valid_move(board, cur_row, cur_col, next_row, next_col, color)) {
                return 1;
            } else {
                return 0;
            }

        case 'K': // white king
        case 'k': // black king
            if(abs(cur_row - next_row) <= 1 && abs(cur_col - next_col) <= 1) {
                return 1;
            }

            return 0;

        default:
            return 0;
    }
}

// function to check if the given character is a piece
int is_piece(char piece)
{
    switch(piece) {
        case 'P':
        case 'p':
        case 'R':
        case 'r':
        case 'N':
        case 'n':
        case 'B':
        case 'b':
        case 'Q':
        case 'q':
        case 'K':
        case 'k':
            return 1;

        default:
            return 0;
    }
}

// function to check if the move is a capture move
int check_if_capture(char board[BOARD_SIZE][BOARD_SIZE], int cur_row, int cur_col, int next_row, int next_col, int color)
{
    if(board[next_row][next_col] != ' ' && get_piece_color(board[next_row][next_col]) != color) {
        return 1;
    }

    return 0;
}

// function to check if endgame condition is met
int is_end_game(char board[BOARD_SIZE][BOARD_SIZE], int color)
{
    int i, j, king_row = -1, king_col = -1;

    // find the king's position
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 'K' && color == 0) {
                king_row = i;
                king_col = j;
            } else if(board[i][j] == 'k' && color == 1) {
                king_row = i;
                king_col = j;
            }
        }
    }

    // check if the king is in check
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(is_valid_move(board, i, j, king_row, king_col, color) && check_if_capture(board, i, j, king_row, king_col, color)) {
                return 0;
            }
        }
    }

    return 1;
}