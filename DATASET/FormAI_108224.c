//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct piece {
    char symbol;
    int row;
    int col;
} Piece;

void initialize_board(Piece board[][BOARD_SIZE]);
void print_board(Piece board[][BOARD_SIZE]);
bool is_valid_move(Piece board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
bool is_jump_move(Piece board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
void make_move(Piece board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
int count_remaining_pieces(Piece board[][BOARD_SIZE], char symbol);
bool is_game_over(Piece board[][BOARD_SIZE]);
char get_winner(Piece board[][BOARD_SIZE]);

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);

    int turn = 0;
    while (!is_game_over(board)) {
        printf("=========== Turn %d ===========\n", turn++);
        int start_row, start_col, end_row, end_col;

        // Get starting coordinates
        printf("Enter the starting row and column of the piece: ");
        scanf("%d %d", &start_row, &start_col);

        // Get ending coordinates
        printf("Enter the ending row and column of the piece: ");
        scanf("%d %d", &end_row, &end_col);

        if (!is_valid_move(board, start_row, start_col, end_row, end_col)) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        make_move(board, start_row, start_col, end_row, end_col);
        print_board(board);
    }

    char winner = get_winner(board);
    printf("Game over. ");
    if (winner == ' ')
        printf("It's a tie!\n");
    else
        printf("The winner is %c!\n", winner);

    return 0;
}

void initialize_board(Piece board[][BOARD_SIZE]) {
    // Black pieces
    board[0][1] = (Piece) {'b', 0, 1};
    board[0][3] = (Piece) {'b', 0, 3};
    board[0][5] = (Piece) {'b', 0, 5};
    board[0][7] = (Piece) {'b', 0, 7};
    board[1][0] = (Piece) {'b', 1, 0};
    board[1][2] = (Piece) {'b', 1, 2};
    board[1][4] = (Piece) {'b', 1, 4};
    board[1][6] = (Piece) {'b', 1, 6};
    board[2][1] = (Piece) {'b', 2, 1};
    board[2][3] = (Piece) {'b', 2, 3};
    board[2][5] = (Piece) {'b', 2, 5};
    board[2][7] = (Piece) {'b', 2, 7};

    // White pieces
    board[5][0] = (Piece) {'w', 5, 0};
    board[5][2] = (Piece) {'w', 5, 2};
    board[5][4] = (Piece) {'w', 5, 4};
    board[5][6] = (Piece) {'w', 5, 6};
    board[6][1] = (Piece) {'w', 6, 1};
    board[6][3] = (Piece) {'w', 6, 3};
    board[6][5] = (Piece) {'w', 6, 5};
    board[6][7] = (Piece) {'w', 6, 7};
    board[7][0] = (Piece) {'w', 7, 0};
    board[7][2] = (Piece) {'w', 7, 2};
    board[7][4] = (Piece) {'w', 7, 4};
    board[7][6] = (Piece) {'w', 7, 6};
}

void print_board(Piece board[][BOARD_SIZE]) {
    printf("    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j].symbol);
        }
        printf(" %d\n", i);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    0   1   2   3   4   5   6   7\n");
}

bool is_valid_move(Piece board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    if (board[start_row][start_col].symbol == ' ') // No piece to move
        return false;
    if (board[end_row][end_col].symbol != ' ') // End position is not empty
        return false;
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE)
        return false; // Out of bounds

    // Make sure we are moving diagonally
    int dr = end_row - start_row;
    int dc = end_col - start_col;
    if (abs(dr) != abs(dc))
        return false;

    // Normal move
    if (!is_jump_move(board, start_row, start_col, end_row, end_col)) {
        if (board[start_row][start_col].symbol == 'w') { // White moves up
            if (dr <= 0)
                return false;
        } else { // Black moves down
            if (dr >= 0)
                return false;
        }
    }

    return true;
}

bool is_jump_move(Piece board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    int dr = end_row - start_row;
    int dc = end_col - start_col;

    // Check if there is a piece to jump over
    if (abs(dr) > 1 && abs(dc) > 1) {
        int mid_row = (start_row + end_row) / 2;
        int mid_col = (start_col + end_col) / 2;
        if (board[mid_row][mid_col].symbol == ' ')
            return false;
        if (board[mid_row][mid_col].symbol == board[start_row][start_col].symbol)
            return false;
        return true;
    }
    return false;
}

void make_move(Piece board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    // Update piece's position
    Piece piece = board[start_row][start_col];
    board[end_row][end_col] = piece;
    board[start_row][start_col].symbol = ' ';

    // Check if piece gets kinged
    if ((piece.symbol == 'w' && end_row == 0) || (piece.symbol == 'b' && end_row == BOARD_SIZE - 1))
        board[end_row][end_col].symbol = 'K';

    // Remove jumped piece
    int dr = end_row - start_row;
    int dc = end_col - start_col;
    if (abs(dr) > 1 && abs(dc) > 1) {
        int mid_row = (start_row + end_row) / 2;
        int mid_col = (start_col + end_col) / 2;
        board[mid_row][mid_col].symbol = ' ';
    }
}

int count_remaining_pieces(Piece board[][BOARD_SIZE], char symbol) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].symbol == symbol || board[i][j].symbol == symbol + 32)
                count++;
        }
    }
    return count;
}

bool is_game_over(Piece board[][BOARD_SIZE]) {
    return count_remaining_pieces(board, 'w') == 0 || count_remaining_pieces(board, 'b') == 0;
}

char get_winner(Piece board[][BOARD_SIZE]) {
    int white_count = count_remaining_pieces(board, 'w') + count_remaining_pieces(board, 'W');
    int black_count = count_remaining_pieces(board, 'b') + count_remaining_pieces(board, 'B');
    if (white_count > black_count)
        return 'w';
    else if (black_count > white_count)
        return 'b';
    else
        return ' ';
}