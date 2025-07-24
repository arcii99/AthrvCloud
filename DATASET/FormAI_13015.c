//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>

#define SIZE 8

typedef enum { EMPTY, BLACK, WHITE } piece;

piece board[SIZE][SIZE]; // initialize board array

void initialize_board() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if ((row + col) % 2 == 0) {
                board[row][col] = EMPTY;
            } else if (row < 3) {
                board[row][col] = WHITE;
            } else if (row > 4) {
                board[row][col] = BLACK;
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
}

void print_board() {
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY) {
                printf(" - ");
            } else if (board[row][col] == WHITE) {
                printf(" W ");
            } else {
                printf(" B ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

piece get_current_player_turn() {
    int white_count = 0, black_count = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == WHITE) {
                white_count++;
            } else if (board[row][col] == BLACK) {
                black_count++;
            }
        }
    }
    if (white_count > black_count) {
        return BLACK;
    }
    return WHITE;
}

int check_move_validity(int start_row, int start_col, int end_row, int end_col, piece player) {
    piece opponent = (player == WHITE) ? BLACK : WHITE;
    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) {
        return 0;
    }
    if (board[end_row][end_col] != EMPTY) {
        return 0;
    }
    if ((start_row - end_row) == 1 && abs(start_col - end_col) == 1) { // Piece can move one space diagonally
        return 1;
    }
    if ((start_row - end_row) == 2 && abs(start_col - end_col) == 2) { // Piece can jump over opponent
        if (board[start_row - (start_row - end_row)/2][start_col - (start_col - end_col)/2] == opponent) {
            return 2; // Return 2 to indicate jump move
        }
    }
    return 0;
}

void make_move(int start_row, int start_col, int end_row, int end_col) {
    piece curr_piece = board[start_row][start_col];
    board[start_row][start_col] = EMPTY;
    board[end_row][end_col] = curr_piece;
    if (abs(start_row - end_row) == 2 && abs(start_col - end_col) == 2) { // Jump move
        board[start_row - (start_row - end_row)/2][start_col - (start_col - end_col)/2] = EMPTY;
    }
}

int check_win() {
    int white_count = 0, black_count = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == WHITE) {
                white_count++;
            } else if (board[row][col] == BLACK) {
                black_count++;
            }
        }
    }
    if (white_count == 0) { // Black wins if there are no white pieces left
        return BLACK;
    } else if (black_count == 0) { // White wins if there are no black pieces left
        return WHITE;
    }
    return EMPTY; // Game is not over yet
}

int main() {
    initialize_board();
    print_board();
    int game_status = check_win();
    piece curr_player;
    while (game_status == EMPTY) {
        curr_player = get_current_player_turn();
        printf("Current player: %s\n", (curr_player == WHITE) ? "White" : "Black");
        int start_row, start_col, end_row, end_col, valid_move;
        do {
            printf("Enter starting row and column of piece: ");
            scanf("%d%d", &start_row, &start_col);
        } while (board[start_row][start_col] != curr_player);
        do {
            printf("Enter ending row and column of move: ");
            scanf("%d%d", &end_row, &end_col);
            valid_move = check_move_validity(start_row, start_col, end_row, end_col, curr_player);
            if (!valid_move) {
                printf("Invalid move. Please try again.\n");
            } else if (valid_move == 2) {
                printf("Jump move made!\n");
            }
        } while (!valid_move);
        make_move(start_row, start_col, end_row, end_col);
        print_board();
        game_status = check_win();
    }
    printf("%s wins!\n", (game_status == WHITE) ? "White" : "Black");
    return 0;
}