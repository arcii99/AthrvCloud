//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define BLACK 'B'
#define WHITE 'W'
#define KING 'K'

typedef enum {false, true} bool;

typedef struct {
    char state;
    bool is_king;
} Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3)
                board[i][j].state = WHITE;
            else if ((i + j) % 2 == 0 && i > 4)
                board[i][j].state = BLACK;
            else
                board[i][j].state = EMPTY;

            board[i][j].is_king = false;
        }
    }
}

void display_board() {
    int i, j;
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j].state);
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G   H\n");
}

bool is_valid_move(int from_x, int from_y, int to_x, int to_y, char player) {
    if (to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE)
        return false;
    if (board[to_x][to_y].state != EMPTY)
        return false;

    int diff_x = to_x - from_x;
    int diff_y = to_y - from_y;
    if (player == BLACK && diff_x > 0)
        return false;
    if (player == WHITE && diff_x < 0)
        return false;

    if (abs(diff_x) == 1 && abs(diff_y) == 1)
        return true;

    if (abs(diff_x) == 2 && abs(diff_y) == 2) {
        int middle_x = (from_x + to_x) / 2;
        int middle_y = (from_y + to_y) / 2;
        if (board[middle_x][middle_y].state != EMPTY && board[middle_x][middle_y].state != player)
            return true;
    }

    return false;
}

void make_move(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y].state = EMPTY;
    if ((board[to_x][to_y].state == BLACK && to_x == BOARD_SIZE - 1) ||
            (board[to_x][to_y].state == WHITE && to_x == 0)) {
        board[to_x][to_y].is_king = true;
        board[to_x][to_y].state = KING;
    }
}

bool has_valid_move(char player) {
    int i, j, to_x, to_y;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].state == player || board[i][j].state == KING) {
                to_x = i + 1;
                to_y = j + 1;
                if (is_valid_move(i, j, to_x, to_y, player))
                    return true;
                to_x = i + 1;
                to_y = j - 1;
                if (is_valid_move(i, j, to_x, to_y, player))
                    return true;
                to_x = i - 1;
                to_y = j + 1;
                if (is_valid_move(i, j, to_x, to_y, player))
                    return true;
                to_x = i - 1;
                to_y = j - 1;
                if (is_valid_move(i, j, to_x, to_y, player))
                    return true;
            }
        }
    }
    return false;
}

int count_pieces(char player) {
    int i, j, count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].state == player || board[i][j].state == KING)
                count++;
        }
    }
    return count;
}

int main() {
    initialize_board();

    char current_player = BLACK;

    while (count_pieces(BLACK) != 0 && count_pieces(WHITE) != 0) {
        display_board();
        printf("Player %c's turn.\n", current_player);

        bool has_move = false;
        int from_x, from_y, to_x, to_y;
        do {
            printf("Enter the coordinates of the piece you want to move (e.g. 1A): ");
            scanf("%d%c", &from_x, &from_y);
            from_y -= 'A';
            from_x--;

            printf("Enter the coordinates of where you want to move the piece (e.g. 2B): ");
            scanf("%d%c", &to_x, &to_y);
            to_y -= 'A';
            to_x--;

            if (is_valid_move(from_x, from_y, to_x, to_y, current_player)) {
                make_move(from_x, from_y, to_x, to_y);
                has_move = true;
            } else {
                printf("Invalid move, please try again.\n");
            }
        } while (!has_move);

        if (has_valid_move(current_player)) {
            if (current_player == BLACK)
                current_player = WHITE;
            else
                current_player = BLACK;
        } else {
            printf("Player %c has no valid moves and loses!\n", current_player);
            break;
        }
    }

    display_board();
    if (count_pieces(BLACK) == 0)
        printf("Player WHITE wins!\n");
    else
        printf("Player BLACK wins!\n");

    return 0;
}