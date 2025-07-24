//FormAI DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY_SPACE '-'
#define PLAYER_ONE 'o'
#define PLAYER_ONE_KING 'O'
#define PLAYER_TWO 'x'
#define PLAYER_TWO_KING 'X'

char** create_board() {
    char** board = (char**) malloc(sizeof(char*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (char*) malloc(sizeof(char) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SPACE;
            if ((i + j) % 2 == 1) {
                if (i < 3)
                    board[i][j] = PLAYER_TWO;
                else if (i > 4)
                    board[i][j] = PLAYER_ONE;
            }
        }
    }
    return board;
}

void print_board(char** board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_piece(char** board, int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY_SPACE;
    if (to_row == 0 && board[to_row][to_col] == PLAYER_ONE)
        board[to_row][to_col] = PLAYER_ONE_KING;
    else if (to_row == BOARD_SIZE - 1 && board[to_row][to_col] == PLAYER_TWO)
        board[to_row][to_col] = PLAYER_TWO_KING;
}

int is_valid_move(char** board, int from_row, int from_col, int to_row, int to_col, char player) {
    int row_diff = abs(from_row - to_row);
    int col_diff = abs(from_col - to_col);
    char enemy, enemy_king;
    if (player == PLAYER_ONE || player == PLAYER_ONE_KING) {
        enemy = PLAYER_TWO;
        enemy_king = PLAYER_TWO_KING;
    } else {
        enemy = PLAYER_ONE;
        enemy_king = PLAYER_ONE_KING;
    }
    if (board[to_row][to_col] != EMPTY_SPACE)
        return 0;
    if (row_diff == 1 && col_diff == 1)
        return 1;
    if (row_diff == 2 && col_diff == 2) {
        int jumped_row = (from_row + to_row) / 2;
        int jumped_col = (from_col + to_col) / 2;
        if (board[jumped_row][jumped_col] == enemy || board[jumped_row][jumped_col] == enemy_king)
            return 1;
    }
    return 0;
}

int is_any_valid_move(char** board, int row, int col, char player) {
    if (player == PLAYER_ONE || board[row][col] == PLAYER_ONE_KING) {
        if (row < BOARD_SIZE - 1) {
            if (col > 0) {
                if (is_valid_move(board, row, col, row+1, col-1, player))
                    return 1;
            }
            if (col < BOARD_SIZE - 1) {
                if (is_valid_move(board, row, col, row+1, col+1, player))
                    return 1;
            }
        }
        if (board[row][col] == PLAYER_ONE_KING && row > 0) {
            if (col > 0) {
                if (is_valid_move(board, row, col, row-1, col-1, player))
                    return 1;
            }
            if (col < BOARD_SIZE - 1) {
                if (is_valid_move(board, row, col, row-1, col+1, player))
                    return 1;
            }
        }   
    } else {
        if (row > 0) {
            if (col > 0) {
                if (is_valid_move(board, row, col, row-1, col-1, player))
                    return 1;
            }
            if (col < BOARD_SIZE - 1) {
                if (is_valid_move(board, row, col, row-1, col+1, player))
                    return 1;
            }
        }
        if (board[row][col] == PLAYER_TWO_KING && row < BOARD_SIZE - 1) {
            if (col > 0) {
                if (is_valid_move(board, row, col, row+1, col-1, player))
                    return 1;
            }
            if (col < BOARD_SIZE - 1) {
                if (is_valid_move(board, row, col, row+1, col+1, player))
                    return 1;
            } 
        }
    }
    return 0;
}

int game_over(char** board) {
    int player_one_pieces = 0;
    int player_two_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_ONE || board[i][j] == PLAYER_ONE_KING)
                player_one_pieces++;
            else if (board[i][j] == PLAYER_TWO || board[i][j] == PLAYER_TWO_KING)
                player_two_pieces++;
        }
    }
    if (player_one_pieces == 0 || player_two_pieces == 0)
        return 1;
    int player_one_moves = 0;
    int player_two_moves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_ONE || board[i][j] == PLAYER_ONE_KING)
                player_one_moves += is_any_valid_move(board, i, j, PLAYER_ONE);
            else if (board[i][j] == PLAYER_TWO || board[i][j] == PLAYER_TWO_KING)
                player_two_moves += is_any_valid_move(board, i, j, PLAYER_TWO);
        }
    }
    if (player_one_moves == 0 || player_two_moves == 0)
        return 1;
    return 0;
}

void run_game() {
    char** board = create_board();
    char* current_player = "Player One";
    int current_row, current_col, dest_row, dest_col;
    while (!game_over(board)) {
        printf("\n%s's turn:\n", current_player);
        print_board(board);
        printf("Enter the position of the piece you want to move:\n");
        scanf("%d %d", &current_row, &current_col);
        if (!is_any_valid_move(board, current_row, current_col, (current_player == "Player One") ? PLAYER_ONE : PLAYER_TWO)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        printf("Enter the position of the destination:\n");
        scanf("%d %d", &dest_row, &dest_col);
        if (!is_valid_move(board, current_row, current_col, dest_row, dest_col, (current_player == "Player One") ? PLAYER_ONE : PLAYER_TWO)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        move_piece(board, current_row, current_col, dest_row, dest_col);
        if (board[dest_row][dest_col] == PLAYER_ONE_KING || board[dest_row][dest_col] == PLAYER_TWO_KING)
            printf("King crowned!\n");
        current_player = (current_player == "Player One") ? "Player Two" : "Player One";
    }
    printf("\nGame over!\n");
    print_board(board);
    if (game_over(board) == 1) {
        int player_one_pieces = 0, player_two_pieces = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == PLAYER_ONE || board[i][j] == PLAYER_ONE_KING)
                    player_one_pieces++;
                else if (board[i][j] == PLAYER_TWO || board[i][j] == PLAYER_TWO_KING)
                    player_two_pieces++;
            }
        }
        if (player_one_pieces > player_two_pieces)
            printf("Player One wins!");
        else if (player_two_pieces > player_one_pieces)
            printf("Player Two wins!");
        else
            printf("Draw game!");
    }
}

int main() {
    run_game();
    return 0;
}