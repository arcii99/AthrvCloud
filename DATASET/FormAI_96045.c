//FormAI DATASET v1.0 Category: Checkers Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0,-1, 0,-1, 0,-1, 0,-1},
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 1, 0, 1, 0, 1, 0, 1},
    { 1, 0, 1, 0, 1, 0, 1, 0},
    { 0, 1, 0, 1, 0, 1, 0, 1}
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case -1:
                    printf(" B ");
                    break;
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf(" W ");
                    break;
                case -2:
                    printf(" b ");
                    break;
                case 2:
                    printf(" w ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int valid_move(int player, int row, int col, int dest_row, int dest_col) {
    if (row < 0 || col < 0 || dest_row < 0 || dest_col < 0 || 
        row >= BOARD_SIZE || col >= BOARD_SIZE || dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE)
        return 0;

    if (board[dest_row][dest_col] != 0)
        return 0;

    if (player == -1) {
        if (dest_row > row)
            return 0;
        if (row - dest_row != 1 || abs(col - dest_col) != 1)
            return 0;
    } else if (player == 1) {
        if (dest_row < row)
            return 0;
        if (dest_row - row != 1 || abs(col - dest_col) != 1)
            return 0;
    }

    return 1;
}

int get_player_piece(int player) {
    if (player == -1)
        return -2;
    else if (player == 1)
        return 2;
    return 0;
}

int can_capture(int player) {
    int piece = get_player_piece(player);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == piece) {
                if (valid_move(player, i, j, i+2, j+2) && board[i+1][j+1] != 0 && board[i+1][j+1] != piece)
                    return 1;
                if (valid_move(player, i, j, i+2, j-2) && board[i+1][j-1] != 0 && board[i+1][j-1] != piece)
                    return 1;
                if (valid_move(player, i, j, i-2, j+2) && board[i-1][j+1] != 0 && board[i-1][j+1] != piece)
                    return 1;
                if (valid_move(player, i, j, i-2, j-2) && board[i-1][j-1] != 0 && board[i-1][j-1] != piece)
                    return 1;
            }
        }
    }
    return 0;
}

int move_piece(int player, int row, int col, int dest_row, int dest_col) {
    if (!valid_move(player, row, col, dest_row, dest_col))
        return 0;

    int piece = board[row][col];
    board[row][col] = 0;
    board[dest_row][dest_col] = piece;

    if (player == -1 && dest_row == 0)
        board[dest_row][dest_col] = -2;
    else if (player == 1 && dest_row == BOARD_SIZE-1)
        board[dest_row][dest_col] = 2;

    if (abs(row - dest_row) == 2 && abs(col - dest_col) == 2) {
        int capture_row = (row + dest_row) / 2;
        int capture_col = (col + dest_col) / 2;
        board[capture_row][capture_col] = 0;
        if (can_capture(player)) {
            board[dest_row][dest_col] = 0;
            board[row][col] = piece;
            board[capture_row][capture_col] = get_player_piece(-player);
            return 2;
        }
    }

    return 1;
}

int main() {
    int current_player = 1;
    while (1) {
        system("clear");
        printf("Current Player: %s\n", current_player == 1 ? "White" : "Black");
        print_board();

        if (!can_capture(current_player)) {
            printf("Enter location of piece to move (row col): ");
            int row, col;
            scanf("%d %d", &row, &col);

            int piece = board[row][col];
            if (piece == 0 || (current_player == -1 && piece == 1) || (current_player == 1 && piece == -1) ||
                (current_player == -1 && piece == 2) || (current_player == 1 && piece == -2)) {
                printf("Invalid piece selected.\n");
                continue;
            }

            printf("Enter destination of piece (row col): ");
            int dest_row, dest_col;
            scanf("%d %d", &dest_row, &dest_col);

            int result = move_piece(current_player, row, col, dest_row, dest_col);
            if (result == 0) {
                printf("Invalid move.\n");
                continue;
            } else if (result == 2) {
                printf("Capture made!\n");
                if (!can_capture(current_player)) {
                    current_player = -current_player;
                    continue;
                }
            }
        } else {
            printf("A capture must be made! Enter location of piece to move (row col): ");
            int row, col;
            scanf("%d %d", &row, &col);

            int piece = board[row][col];
            if (piece == 0 || (current_player == -1 && piece == 1) || (current_player == 1 && piece == -1) ||
                (current_player == -1 && piece == 2) || (current_player == 1 && piece == -2)) {
                printf("Invalid piece selected.\n");
                continue;
            }

            printf("Enter the destination of the capture (row col): ");
            int dest_row, dest_col;
            scanf("%d %d", &dest_row, &dest_col);

            int result = move_piece(current_player, row, col, dest_row, dest_col);
            if (result == 0 || result == 1) {
                printf("Invalid capture.\n");
                continue;
            } else if (result == 2) {
                printf("Capture made!\n");
            }
        }

        if (!can_capture(current_player)) {
            current_player = -current_player;
        }

        int white_count = 0, black_count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 1 || board[i][j] == 2) {
                    white_count++;
                } else if (board[i][j] == -1 || board[i][j] == -2) {
                    black_count++;
                }
            }
        }

        if (white_count == 0) {
            printf("Black wins!\n");
            break;
        } else if (black_count == 0) {
            printf("White wins!\n");
            break;
        }
    }

    return 0;
}