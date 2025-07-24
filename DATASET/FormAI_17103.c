//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// define the board size
#define BOARD_SIZE 8

// define the player symbols
#define PLAYER_1 'x'
#define PLAYER_2 'o'

// define the piece types
#define EMPTY 0
#define P1_PIECE 1
#define P2_PIECE 2
#define P1_KING 3
#define P2_KING 4

// function to initialize the board
void init_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    // zero out the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // place player 1's pieces
    board[0][1] = P1_PIECE;
    board[0][3] = P1_PIECE;
    board[0][5] = P1_PIECE;
    board[0][7] = P1_PIECE;
    board[1][0] = P1_PIECE;
    board[1][2] = P1_PIECE;
    board[1][4] = P1_PIECE;
    board[1][6] = P1_PIECE;
    board[2][1] = P1_PIECE;
    board[2][3] = P1_PIECE;
    board[2][5] = P1_PIECE;
    board[2][7] = P1_PIECE;

    // place player 2's pieces
    board[5][0] = P2_PIECE;
    board[5][2] = P2_PIECE;
    board[5][4] = P2_PIECE;
    board[5][6] = P2_PIECE;
    board[6][1] = P2_PIECE;
    board[6][3] = P2_PIECE;
    board[6][5] = P2_PIECE;
    board[6][7] = P2_PIECE;
    board[7][0] = P2_PIECE;
    board[7][2] = P2_PIECE;
    board[7][4] = P2_PIECE;
    board[7][6] = P2_PIECE;
}

// function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("  0 1 2 3 4 5 6 7\n");
    printf("  ---------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case P1_PIECE:
                    printf("%c", PLAYER_1);
                    break;
                case P2_PIECE:
                    printf("%c", PLAYER_2);
                    break;
                case P1_KING:
                    printf("%c", PLAYER_1);
                    break;
                case P2_KING:
                    printf("%c", PLAYER_2);
                    break;
            }
            printf("|");
        }
        printf("%d\n", i);
        printf(" |---------------|\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

// function to check if a move is valid
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int x_start, int y_start, int x_end, int y_end)
{
    // check if the start and end positions are on the board
    if (x_start < 0 || x_start >= BOARD_SIZE || y_start < 0 || y_start >= BOARD_SIZE ||
        x_end < 0 || x_end >= BOARD_SIZE || y_end < 0 || y_end >= BOARD_SIZE) {
        return 0;
    }

    // check if the end position is empty
    if (board[x_end][y_end] != EMPTY) {
        return 0;
    }

    // get the piece types of the start and end positions
    int start_piece = board[x_start][y_start];
    int end_piece = board[x_end][y_end];

    // check if the start position has a piece of the current player
    if (player == 1 && (start_piece != P1_PIECE && start_piece != P1_KING)) {
        return 0;
    }
    else if (player == 2 && (start_piece != P2_PIECE && start_piece != P2_KING)) {
        return 0;
    }

    // check if the piece is moving diagonally
    int x_diff = x_end - x_start;
    int y_diff = y_end - y_start;
    if (abs(x_diff) != abs(y_diff)) {
        return 0;
    }

    // check if the piece is moving forward or backward, depending on its type
    if (player == 1 && start_piece == P1_PIECE && x_diff > 0) {
        return 0;
    }
    else if (player == 2 && start_piece == P2_PIECE && x_diff < 0) {
        return 0;
    }

    // check if the piece is moving more than one space
    if (abs(x_diff) > 1) {
        return 0;
    }

    // check if the piece is jumping over an enemy piece
    if (abs(x_diff) == 1) {
        if (player == 1) {
            if (end_piece != EMPTY && end_piece != P2_PIECE && end_piece != P2_KING) {
                return 0;
            }
        }
        else if (player == 2) {
            if (end_piece != EMPTY && end_piece != P1_PIECE && end_piece != P1_KING) {
                return 0;
            }
        }
    }
    else if (abs(x_diff) == 2) {
        int x_middle = (x_start + x_end) / 2;
        int y_middle = (y_start + y_end) / 2;
        int middle_piece = board[x_middle][y_middle];
        if (player == 1) {
            if (middle_piece != P2_PIECE && middle_piece != P2_KING) {
                return 0;
            }
        }
        else if (player == 2) {
            if (middle_piece != P1_PIECE && middle_piece != P1_KING) {
                return 0;
            }
        }
    }

    // all checks passed, move is valid
    return 1;
}

// function to make a move
void make_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int x_start, int y_start, int x_end, int y_end)
{
    // move the piece
    int piece = board[x_start][y_start];
    board[x_start][y_start] = EMPTY;
    board[x_end][y_end] = piece;

    // check if the piece needs to be promoted to a king
    if (player == 1 && x_end == 7 && piece == P1_PIECE) {
        board[x_end][y_end] = P1_KING;
    }
    else if (player == 2 && x_end == 0 && piece == P2_PIECE) {
        board[x_end][y_end] = P2_KING;
    }

    // check if the piece jumped over an enemy piece
    int x_diff = x_end - x_start;
    int y_diff = y_end - y_start;
    if (abs(x_diff) == 2) {
        int x_middle = (x_start + x_end) / 2;
        int y_middle = (y_start + y_end) / 2;
        board[x_middle][y_middle] = EMPTY;
    }
}

// function to check if a player can move
int can_move(int board[BOARD_SIZE][BOARD_SIZE], int player)
{
    // loop through the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // check if there is a piece of the current player at this position
            if (player == 1 && (board[i][j] == P1_PIECE || board[i][j] == P1_KING)) {
                // check if the piece can move
                if (is_valid_move(board, player, i, j, i+1, j+1) ||
                    is_valid_move(board, player, i, j, i+1, j-1) ||
                    is_valid_move(board, player, i, j, i+2, j+2) ||
                    is_valid_move(board, player, i, j, i+2, j-2)) {
                    return 1;
                }
            }
            else if (player == 2 && (board[i][j] == P2_PIECE || board[i][j] == P2_KING)) {
                // check if the piece can move
                if (is_valid_move(board, player, i, j, i-1, j+1) ||
                    is_valid_move(board, player, i, j, i-1, j-1) ||
                    is_valid_move(board, player, i, j, i-2, j+2) ||
                    is_valid_move(board, player, i, j, i-2, j-2)) {
                    return 1;
                }
            }
        }
    }

    // no moves found, player can't move
    return 0;
}

// function to switch the player
int switch_player(int player)
{
    if (player == 1) {
        return 2;
    }
    else {
        return 1;
    }
}

// main function
int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;

    // initialize the board
    init_board(board);

    // loop until the game is over
    while (1) {
        // print the board
        print_board(board);

        // check if the current player can move
        if (!can_move(board, player)) {
            printf("Player %d can't move! Game over.\n", player);
            break;
        }

        // get the player's move
        int x_start, y_start, x_end, y_end;
        printf("Player %d's turn:\n", player);
        printf("Enter the start position (x y): ");
        scanf("%d %d", &x_start, &y_start);
        printf("Enter the end position (x y): ");
        scanf("%d %d", &x_end, &y_end);

        // check if the move is valid
        if (!is_valid_move(board, player, x_start, y_start, x_end, y_end)) {
            printf("Invalid move!\n");
            continue;
        }

        // make the move
        make_move(board, player, x_start, y_start, x_end, y_end);

        // switch the player
        player = switch_player(player);
    }

    return 0;
}