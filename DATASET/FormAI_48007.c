//FormAI DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 8
#define COLUMNS 8

typedef enum {EMPTY, WHITE, BLACK} Piece;
typedef enum {FALSE, TRUE} Boolean;
typedef enum {NO, YES} Capture;

Piece board[ROWS][COLUMNS];
int turn_num = 1;

/* Function to display the board */
void display_board() {
    printf("      a   b   c   d   e   f   g   h\n");
    printf("     --- --- --- --- --- --- --- ---\n");
    for (int i = 0; i < ROWS; i++) {
        printf(" %d |", i+1);
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == EMPTY) {
                printf("   |");
            } else if (board[i][j] == WHITE) {
                printf(" w |");
            } else if (board[i][j] == BLACK) {
                printf(" b |");
            }
        }
        printf(" %d\n", i+1);
        printf("     --- --- --- --- --- --- --- ---\n");
    }
    printf("      a   b   c   d   e   f   g   h\n");
}

/* Function to make a move */
Boolean make_move(int from_row, int from_column, int to_row, int to_column, Capture capture) {
    if (board[from_row][from_column] == EMPTY) {
        printf("*** Error: No piece to move! ***\n");
        return FALSE;
    } else if (board[to_row][to_column] != EMPTY) {
        printf("*** Error: Cannot move to a non-empty square! ***\n");
        return FALSE;
    } else {
        Piece piece = board[from_row][from_column];
        if (capture == YES) {
            board[(from_row+to_row)/2][(from_column+to_column)/2] = EMPTY;
        }
        board[from_row][from_column] = EMPTY;
        board[to_row][to_column] = piece;
        return TRUE;
    }
}

/* Function to check if a move is valid */
Boolean is_valid_move(int from_row, int from_column, int to_row, int to_column, Capture capture) {
    if (abs(from_row-to_row) != abs(from_column-to_column)) {
        printf("*** Error: Invalid move! ***\n");
        return FALSE;
    } else if (abs(from_row-to_row) == 1) {
        if (capture == YES) {
            printf("*** Error: Cannot capture on a single move! ***\n");
            return FALSE;
        } else {
            if ((board[from_row][from_column] == WHITE && to_row < from_row) ||
                (board[from_row][from_column] == BLACK && to_row > from_row)) {
                printf("*** Error: Invalid move! ***\n");
                return FALSE;
            } else if (board[to_row][to_column] != EMPTY) {
                printf("*** Error: Cannot move to a non-empty square! ***\n");
                return FALSE;
            } else {
                return TRUE;
            }
        }
    } else {
        // check if there is a piece between the from square and the to square
        for (int i = from_row+1, j = from_column+1; i < to_row; i++, j++) {
            if (board[i][j] != EMPTY) {
                printf("*** Error: Cannot jump over a piece! ***\n");
                return FALSE;
            }
        }
        for (int i = from_row+1, j = from_column-1; i < to_row; i++, j--) {
            if (board[i][j] != EMPTY) {
                printf("*** Error: Cannot jump over a piece! ***\n");
                return FALSE;
            }
        }
        for (int i = from_row-1, j = from_column+1; i > to_row; i--, j++) {
            if (board[i][j] != EMPTY) {
                printf("*** Error: Cannot jump over a piece! ***\n");
                return FALSE;
            }
        }
        for (int i = from_row-1, j = from_column-1; i > to_row; i--, j--) {
            if (board[i][j] != EMPTY) {
                printf("*** Error: Cannot jump over a piece! ***\n");
                return FALSE;
            }
        }
        if (capture == YES) {
            if (board[(from_row+to_row)/2][(from_column+to_column)/2] == EMPTY ||
                board[(from_row+to_row)/2][(from_column+to_column)/2] == board[from_row][from_column]) {
                printf("*** Error: Cannot capture an empty square or a square occupied by your own piece! ***\n");
                return FALSE;
            }
        }
        if ((board[from_row][from_column] == WHITE && to_row < from_row) ||
            (board[from_row][from_column] == BLACK && to_row > from_row)) {
            printf("*** Error: Invalid move! ***\n");
            return FALSE;
        } else if (board[to_row][to_column] != EMPTY) {
            printf("*** Error: Cannot move to a non-empty square! ***\n");
            return FALSE;
        } else {
            return TRUE;
        }
    }
}

/* Function to check if the game is over */
Boolean is_game_over() {
    int white_count = 0;
    int black_count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == WHITE) {
                white_count++;
            } else if (board[i][j] == BLACK) {
                black_count++;
            }
        }
    }
    if (white_count == 0) {
        printf("Black wins!\n");
        return TRUE;
    } else if (black_count == 0) {
        printf("White wins!\n");
        return TRUE;
    } else {
        return FALSE;
    }
}

/* Function to switch turns */
void switch_turn() {
    if (turn_num % 2 == 1) {
        printf("Black's turn.\n");
    } else {
        printf("White's turn.\n");
    }
    turn_num++;
}

/* Main function */
int main() {
    // set up the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if ((i+j) % 2 == 0 && i < 3) {
                board[i][j] = BLACK;
            } else if ((i+j) % 2 == 0 && i > 4) {
                board[i][j] = WHITE;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
    display_board();
    while (!is_game_over()) {
        switch_turn();
        int from_row, from_column, to_row, to_column;
        printf("Enter coordinates of piece to move (row column): ");
        scanf("%d %d", &from_row, &from_column);
        printf("Enter coordinates of destination square (row column): ");
        scanf("%d %d", &to_row, &to_column);
        // check if the move is valid and make the move
        Capture capture;
        if (abs(from_row-to_row) == 2) {
            capture = YES;
        } else {
            capture = NO;
        }
        if (is_valid_move(from_row-1, from_column-1, to_row-1, to_column-1, capture)) {
            make_move(from_row-1, from_column-1, to_row-1, to_column-1, capture);
            display_board();
        } else {
            switch_turn();
        }
    }
    return 0;
}