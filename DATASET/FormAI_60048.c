//FormAI DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

/* define piece types */
#define EMPTY 0
#define RED 1
#define BLACK 2
#define KING 3

/* function prototypes */
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int move_piece(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
void capture_piece(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);

int main() {
    /* initialize the board */
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    /* print the initial board setup */
    printf("Initial Board:\n");
    print_board(board);

    /* allow the user to make moves until the game ends */
    int current_player = RED;
    while(1) {
        printf("\nCurrent Player: %s\n", (current_player == RED) ? "Red" : "Black");

        /* get the user's desired move */
        int start_row, start_col, end_row, end_col;
        printf("Enter start row: ");
        scanf("%d", &start_row);
        printf("Enter start column: ");
        scanf("%d", &start_col);
        printf("Enter end row: ");
        scanf("%d", &end_row);
        printf("Enter end column: ");
        scanf("%d", &end_col);

        /* move the piece */
        if(move_piece(board, start_row, start_col, end_row, end_col)) {
            /* switch to the other player */
            current_player = (current_player == RED) ? BLACK : RED;

            /* print the updated board */
            printf("\nUpdated Board:\n");
            print_board(board);
        } else {
            printf("\nInvalid move, try again.\n");
        }
    }

    return 0;
}

/* initializes the board to the standard setup for checkers */
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            /* set up the red pieces */
            if(row < 3 && (row + col) % 2 == 0) {
                board[row][col] = RED;
            }
            /* set up the black pieces */
            else if(row > 4 && (row + col) % 2 == 0) {
                board[row][col] = BLACK;
            }
            /* empty squares */
            else {
                board[row][col] = EMPTY;
            }
        }
    }
}

/* prints the current state of the board */
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    /* print column numbers */
    printf("  ");
    for(int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");

    /* print horizontal line */
    printf("  ");
    for(int col = 0; col < BOARD_SIZE; col++) {
        printf("--");
    }
    printf("\n");

    /* print each row */
    for(int row = 0; row < BOARD_SIZE; row++) {
        /* print row number */
        printf("%d|", row);

        /* print each square */
        for(int col = 0; col < BOARD_SIZE; col++) {
            switch(board[row][col]) {
                case EMPTY:
                    printf("  ");
                    break;
                case RED:
                    printf("R ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case KING:
                    printf("K ");
                    break;
            }
        }

        /* end the row */
        printf("|%d\n", row);
    }

    /* print horizontal line */
    printf("  ");
    for(int col = 0; col < BOARD_SIZE; col++) {
        printf("--");
    }
    printf("\n");

    /* print column numbers */
    printf("  ");
    for(int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
}

/* moves a piece from start position to end position, returns 1 if successful */
int move_piece(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    /* make sure the move is valid */
    if(!is_valid_move(board, start_row, start_col, end_row, end_col)) {
        return 0;
    }

    /* move the piece */
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = EMPTY;

    /* check if a piece was captured */
    if(abs(end_row - start_row) == 2) {
        capture_piece(board, start_row, start_col, end_row, end_col);
    }

    return 1;
}

/* checks if a move is valid */
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    /* make sure the start and end positions are on the board */
    if(start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
       end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return 0;
    }

    /* make sure the end position is empty */
    if(board[end_row][end_col] != EMPTY) {
        return 0;
    }

    /* get the starting piece type */
    int piece_type = board[start_row][start_col];

    /* make sure the player is only moving their own pieces */
    if(piece_type != RED && piece_type != BLACK && piece_type != KING) {
        return 0;
    }

    /* check if a regular piece is moving normally */
    if(piece_type == RED) {
        if(end_row == start_row - 1 && abs(end_col - start_col) == 1) {
            return 1;
        } else if(end_row == start_row - 2 && abs(end_col - start_col) == 2 &&
                  board[(start_row+end_row)/2][(start_col+end_col)/2] == BLACK) {
            return 1;
        }
    } else if(piece_type == BLACK) {
        if(end_row == start_row + 1 && abs(end_col - start_col) == 1) {
            return 1;
        } else if(end_row == start_row + 2 && abs(end_col - start_col) == 2 &&
                  board[(start_row+end_row)/2][(start_col+end_col)/2] == RED) {
            return 1;
        }
    } else if(piece_type == KING) {
        /* check if a king is moving normally */
        if(abs(end_row - start_row) == 1 && abs(end_col - start_col) == 1) {
            return 1;
        }
        /* check if a king is making a capture */
        else if(abs(end_row - start_row) == 2 && abs(end_col - start_col) == 2 &&
                (board[(start_row+end_row)/2][(start_col+end_col)/2] == RED ||
                 board[(start_row+end_row)/2][(start_col+end_col)/2] == BLACK)) {
            return 1;
        }
    }

    /* if none of the conditions are met, the move is not valid */
    return 0;
}

/* captures a piece and removes it from the board */
void capture_piece(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    board[(start_row+end_row)/2][(start_col+end_col)/2] = EMPTY;
}