//FormAI DATASET v1.0 Category: Chess engine ; Style: scientific
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLUMNS 8

char board[ROWS][COLUMNS] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
};

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(int from_row, int from_col, int to_row, int to_col) {
    char piece = board[from_row][from_col];
    char dest_piece = board[to_row][to_col];
    
    // check if move is within board boundaries
    if (from_row < 0 || from_row >= ROWS || from_col < 0 || from_col >= COLUMNS
        || to_row < 0 || to_row >= ROWS || to_col < 0 || to_col >= COLUMNS) {
        return false;
    }

    // check if move is onto a friendly piece
    if (dest_piece != ' ' && piece != 'k' && dest_piece == piece) {
        return false;
    }

    // check if move is legally possible for the piece
    switch (piece) {
        case 'p':
            if (from_col == to_col) {
                if (dest_piece == ' ') {
                    return (to_row == from_row + 1 || (from_row == 1 && to_row == 3));
                } else {
                    return (to_row == from_row + 1 && abs(from_col - to_col) == 1);
                }
            } else {
                return (to_row == from_row + 1 && abs(from_col - to_col) == 1 && dest_piece != ' ');
            }
            break;
        case 'P':
            if (from_col == to_col) {
                if (dest_piece == ' ') {
                    return (to_row == from_row - 1 || (from_row == 6 && to_row == 4));
                } else {
                    return (to_row == from_row - 1 && abs(from_col - to_col) == 1);
                }
            } else {
                return (to_row == from_row - 1 && abs(from_col - to_col) == 1 && dest_piece != ' ');
            }
            break;
        case 'r':
        case 'R':
            if (from_row == to_row) {
                int start = from_col < to_col ? from_col : to_col;
                int end = from_col > to_col ? from_col : to_col;
                for (int i = start + 1; i < end; i++) {
                    if (board[from_row][i] != ' ') {
                        return false;
                    }
                }
                return true;
            } else if (from_col == to_col) {
                int start = from_row < to_row ? from_row : to_row;
                int end = from_row > to_row ? from_row : to_row;
                for (int i = start + 1; i < end; i++) {
                    if (board[i][from_col] != ' ') {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
            break;
        case 'n':
        case 'N':
            return ((abs(from_row - to_row) == 2 && abs(from_col - to_col) == 1) 
                    || (abs(from_row - to_row) == 1 && abs(from_col - to_col) == 2));
            break;
        case 'b':
        case 'B':
            if (abs(from_row - to_row) != abs(from_col - to_col)) {
                return false;
            }
            int row_dir = from_row < to_row ? 1 : -1;
            int col_dir = from_col < to_col ? 1 : -1;
            for (int i = from_row + row_dir, j = from_col + col_dir; 
                i != to_row && j != to_col; i += row_dir, j += col_dir) {
                if (board[i][j] != ' ') {
                    return false;
                }
            }
            return true;
            break;
        case 'q':
        case 'Q':
            if (from_row == to_row || from_col == to_col) {
                return is_valid_move(from_row, from_col, to_row, to_col);
            } else {
                return is_valid_move(from_row, from_col, to_row, from_col)
                    && is_valid_move(to_row, from_col, to_row, to_col);
            }
            break;
        case 'k':
        case 'K':
            if (abs(from_row - to_row) <= 1 && abs(from_col - to_col) <= 1) {
                return true;    
            }
            return false;
            break;
        default:
            return false;
    }
}

bool is_in_check(char king, int king_row, int king_col) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != ' ' && board[i][j] != king) {
                if (is_valid_move(i, j, king_row, king_col)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int from_row, from_col, to_row, to_col;
    char player = 'w';

    while (true) {
        print_board();

        printf("Enter move for %c player (example: 'e2 e4'): ", player);
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        if (is_valid_move(from_row, from_col, to_row, to_col)) {
            char piece = board[from_row][from_col];
            board[from_row][from_col] = ' ';
            board[to_row][to_col] = piece;

            if (is_in_check(player == 'w' ? 'K' : 'k', to_row, to_col)) {
                printf("Illegal move - will result in check\n");
                board[from_row][from_col] = piece;
                board[to_row][to_col] = ' ';
            } else {
                player = player == 'w' ? 'b' : 'w';
            }
        } else {
            printf("Illegal move\n");
        }
    }

    return 0;
}