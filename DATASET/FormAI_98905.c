//FormAI DATASET v1.0 Category: Checkers Game ; Style: genious
#include <stdio.h>

/* defining the dimensions of the board */
#define DIM 8

/* defining the colors and symbols of the pieces */
#define BLACK 'B'
#define WHITE 'W'
#define CROWN_BLACK 'b'
#define CROWN_WHITE 'w'
#define EMPTY '*'

/* printing the board */
void print_board(char board[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* initializing the board */
void init_board(char board[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if ((i + j) % 2 == 0) { /* only black squares are filled with pieces */
                if (i < 3)
                    board[i][j] = WHITE; /* top three rows are filled with WHITE pieces */
                else if (i > 4)
                    board[i][j] = BLACK; /* bottom three rows are filled with BLACK pieces */
                else
                    board[i][j] = EMPTY; /* the rest of the squares are empty */
            }
            else {
                board[i][j] = EMPTY; /* white squares are empty */
            }
        }
    }
}

/* checking if the move is valid */
int is_valid_move(char board[][DIM], int row, int col, int new_row, int new_col, char color) {
    if (row < 0 || row >= DIM || col < 0 || col >= DIM || new_row < 0 || new_row >= DIM || new_col < 0 || new_col >= DIM)
        return 0; /* move is out of bounds */

    if (board[new_row][new_col] == EMPTY && ((new_row + new_col) % 2 == 0)) { /* new square is empty and it is black */
        /* check if the move is diagonal */
        int dr = new_row - row;
        int dc = new_col - col;
        if (color == WHITE && dr == -1 && (dc == 1 || dc == -1)) { /* white only moves diagonally down */
            return 1;
        }
        if (color == BLACK && dr == 1 && (dc == 1 || dc == -1)) { /* black only moves diagonally up */
            return 1;
        }
        /* check if the move is a jump (capture of an opponent's piece) */
        if ((dr == -2 || dr == 2) && (dc == 2 || dc == -2)) {
            int mid_row = (row + new_row) / 2; /* get the row of the piece that is being jumped */
            int mid_col = (col + new_col) / 2; /* get the column of the piece that is being jumped */
            if (board[mid_row][mid_col] != EMPTY && ((mid_row + mid_col) % 2 == 0) && (board[mid_row][mid_col] != color &&
                board[mid_row][mid_col] != (color == WHITE ? CROWN_BLACK : CROWN_WHITE))) /* the piece being jumped is not of the same color as the moving piece */
            {
                return 1;
            }
        }
    }
    return 0;
}

/* checking if the move is a jump */
int is_jump(char board[][DIM], int row, int col, int new_row, int new_col) {
    int dr = new_row - row;
    int dc = new_col - col;
    if ((dr == -2 || dr == 2) && (dc == 2 || dc == -2)) {
        return 1;
    }
    return 0;
}

/* check if a piece can jump */
int can_jump(char board[][DIM], int row, int col, char color) {
    int dirs[4] = {-1, 1};
    if (color == BLACK || board[row][col] == CROWN_BLACK) { /* black and crowned black can only jump up */
        dirs[0] = 1;
    }
    if (color == WHITE || board[row][col] == CROWN_WHITE) { /* white and crowned white can only jump down */
        dirs[1] = -1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int d_row = dirs[i];
            int d_col = dirs[j];
            if (is_valid_move(board, row, col, row + 2 * d_row, col + 2 * d_col, color)) {
                return 1;
            }
        }
    }
    return -1;
}

/* check if there are any moves left */
int has_moves(char board[][DIM], char color) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (board[i][j] == color || board[i][j] == (color == WHITE ? CROWN_WHITE : CROWN_BLACK)) {
                if (can_jump(board, i, j, color) == 1) { /* if there is a jump available return 1 */
                    return 1;
                }
                for (int k = -1; k <= 1; k += 2) { /* check moves that are one square away */
                    if (is_valid_move(board, i, j, i + k, j + k, color) || is_valid_move(board, i, j, i + k, j - k, color)) {
                        return 1;
                    }
                }
            }
        }
    }
    return -1; /* no moves left */
}

/* make a move */
void make_move(char board[][DIM], int row, int col, int new_row, int new_col) {
    char temp = board[row][col];
    board[row][col] = EMPTY;
    board[new_row][new_col] = temp;
    /* check if the piece has reached the other side to get crowned */
    if (new_row == 0 && board[new_row][new_col] == WHITE) {
        board[new_row][new_col] = CROWN_WHITE;
    }
    if (new_row == DIM - 1 && board[new_row][new_col] == BLACK) {
        board[new_row][new_col] = CROWN_BLACK;
    }
    /* if the move is a jump remove opponent's piece */
    if (is_jump(board, row, col, new_row, new_col)) {
        int mid_row = (row + new_row) / 2;
        int mid_col = (col + new_col) / 2;
        board[mid_row][mid_col] = EMPTY;
    }
}

/* get user input as a move */
void get_move(int *row, int *col, int *new_row, int *new_col) {
    char input[10];
    printf("Enter move (e.g. 1,2 -> 2,3): ");
    fgets(input, 10, stdin);
    sscanf(input, "%d,%d -> %d,%d", row, col, new_row, new_col);
    (*row)--;
    (*col)--;
    (*new_row)--;
    (*new_col)--;
}

/* play the game */
void play_game(void) {
    char board[DIM][DIM];
    init_board(board);
    char color = BLACK; /* black always goes first */
    while (has_moves(board, color) == 1) {
        printf("It's %s's turn!\n", (color == BLACK ? "BLACK" : "WHITE"));
        print_board(board);
        int row, col, new_row, new_col;
        do { /* get valid input from user */
            get_move(&row, &col, &new_row, &new_col);
            if (!(is_valid_move(board, row, col, new_row, new_col, color))) {
                printf("Invalid move! Try again.\n");
            }
        } while (!(is_valid_move(board, row, col, new_row, new_col, color)));
        make_move(board, row, col, new_row, new_col); /* make the move */
        /* change the player's turn */
        if (color == BLACK) {
            color = WHITE;
        }
        else {
            color = BLACK;
        }
    }
    printf("GAME OVER!\n");
    print_board(board);
    printf("%s WON!\n", (color == BLACK ? "WHITE" : "BLACK"));
}

int main(void) {
    play_game();
    return 0;
}