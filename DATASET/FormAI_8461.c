//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

enum {
    EMPTY,
    PLAYER_ONE,
    PLAYER_TWO,
    PLAYER_ONE_KING,
    PLAYER_TWO_KING
};

void init_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3)
                    board[i][j] = PLAYER_ONE;
                else if (i > 4)
                    board[i][j] = PLAYER_TWO;
                else
                    board[i][j] = EMPTY;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board() {
    int i, j;

    printf("------------------------\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("|");

        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf("   |");
                    break;
                case PLAYER_ONE:
                    printf(" x |");
                    break;
                case PLAYER_TWO:
                    printf(" o |");
                    break;
                case PLAYER_ONE_KING:
                    printf(" X |");
                    break;
                case PLAYER_TWO_KING:
                    printf(" O |");
                    break;
                default:
                    break;
            }
        }

        printf("\n");
        printf("------------------------\n");
    }
}

int validate_movement(int x1, int y1, int x2, int y2, int player) {
    int dx, dy;

    if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
        return 0;

    if (board[x2][y2] != EMPTY)
        return 0;

    dx = x2 - x1;
    dy = y2 - y1;

    if (player == PLAYER_ONE || board[x1][y1] == PLAYER_ONE_KING) {
        if (dx == -1 && (dy == -1 || dy == 1))
            return 1;

        if (dx == -2 && (dy == -2 || dy == 2) && board[x1 - 1][(y1 + y2) / 2] == PLAYER_TWO)
            return 2;
    }

    if (player == PLAYER_TWO || board[x1][y1] == PLAYER_TWO_KING) {
        if (dx == 1 && (dy == -1 || dy == 1))
            return 1;

        if (dx == 2 && (dy == -2 || dy == 2) && board[x1 + 1][(y1 + y2) / 2] == PLAYER_ONE)
            return 2;
    }

    return 0;
}

int check_king(int x, int y) {
    if (board[x][y] == PLAYER_ONE && x == 0)
        return PLAYER_ONE_KING;

    if (board[x][y] == PLAYER_TWO && x == BOARD_SIZE - 1)
        return PLAYER_TWO_KING;

    return board[x][y];
}

void move_piece(int x1, int y1, int x2, int y2) {
    int player = board[x1][y1];
    int king = check_king(x2, y2);

    board[x1][y1] = EMPTY;

    if (king)
        board[x2][y2] = king;
    else
        board[x2][y2] = player;
}

int check_end_game() {
    int i, j;

    int player_one_piece = 0;
    int player_two_piece = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_ONE || board[i][j] == PLAYER_ONE_KING)
                player_one_piece++;

            if (board[i][j] == PLAYER_TWO || board[i][j] == PLAYER_TWO_KING)
                player_two_piece++;
        }
    }

    if (player_one_piece == 0 || player_two_piece == 0)
        return 1;

    return 0;
}

int main() {
    int x1, y1, x2, y2;
    int player = PLAYER_ONE;
    int movement_valid;
    int capture_valid;

    init_board();

    while (1) {
        print_board();

        printf("\n");

        printf("Player %d's turn\n", player == PLAYER_ONE ? 1 : 2);

        printf("Enter x of piece to move: ");
        scanf("%d", &x1);

        printf("Enter y of piece to move: ");
        scanf("%d", &y1);

        printf("Enter x of destination: ");
        scanf("%d", &x2);

        printf("Enter y of destination: ");
        scanf("%d", &y2);

        movement_valid = validate_movement(x1, y1, x2, y2, player);
        capture_valid = 0;

        if (!movement_valid) {
            printf("Invalid movement.\n");
            continue;
        }

        if (movement_valid == 2) {
            capture_valid = 1;
        }

        if (capture_valid) {
            int dx = x2 - x1;
            int dy = y2 - y1;

            board[x1][y1] = EMPTY;
            board[x1 + dx / 2][y1 + dy / 2] = EMPTY;
            board[x2][y2] = player;
        } else {
            move_piece(x1, y1, x2, y2);
        }

        if (player == PLAYER_ONE)
            player = PLAYER_TWO;
        else
            player = PLAYER_ONE;

        if (check_end_game()) {
            printf("Game over.\n");
            break;
        }
    }

    return 0;
}