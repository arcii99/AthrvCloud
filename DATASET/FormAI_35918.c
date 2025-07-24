//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 10

typedef enum { EMPTY, X, O } Cell;

typedef struct {
    Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
    int x, y;
} Move;

typedef struct {
    Move move;
    int score;
} Node;

bool is_board_full(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool has_player_won(Board *board, Cell player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board->cells[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return true;
        }
    }
    // Check diagonals
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[i][i] == player) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return true;
    }
    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[i][BOARD_SIZE - i - 1] == player) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return true;
    }
    return false;
}

int evaluate_board(Board *board, Cell player) {
    if (has_player_won(board, player)) {
        return 10;
    }
    if (has_player_won(board, player == X ? O : X)) {
        return -10;
    }
    return 0;
}

int minimax(Board *board, Cell player, int depth) {
    if (has_player_won(board, X)) {
        return -10 + depth;
    }
    if (has_player_won(board, O)) {
        return 10 - depth;
    }
    if (is_board_full(board)) {
        return 0;
    }
    if (depth == MAX_DEPTH) {
        return evaluate_board(board, player);
    }

    int best_score = player == X ? -1000000 : 1000000;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] == EMPTY) {
                board->cells[i][j] = player;
                int score = minimax(board, player == X ? O : X, depth + 1);
                board->cells[i][j] = EMPTY;
                if (player == X) {
                    best_score = score > best_score ? score : best_score;
                } else {
                    best_score = score < best_score ? score : best_score;
                }
            }
        }
    }
    return best_score;
}

Node minimax_find_best_move(Board *board, Cell player) {
    int best_score = player == X ? -1000000 : 1000000;
    Node best_node;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] == EMPTY) {
                board->cells[i][j] = player;
                int score = minimax(board, player == X ? O : X, 0);
                board->cells[i][j] = EMPTY;
                if ((player == X && score > best_score) ||
                    (player == O && score < best_score)) {
                    best_score = score;
                    best_node.move.x = i;
                    best_node.move.y = j;
                    best_node.score = score;
                }
            }
        }
    }
    return best_node;
}

void print_board(Board *board) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board->cells[i][j]) {
            case X:
                printf("X ");
                break;
            case O:
                printf("O ");
                break;
            default:
                printf("_ ");
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Board board = {.cells = {
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
    }};
    bool over = false;
    Cell current_player = X;
    while (!over) {
        print_board(&board);
        if (has_player_won(&board, X)) {
            printf("X wins!\n");
            break;
        }
        if (has_player_won(&board, O)) {
            printf("O wins!\n");
            break;
        }
        if (is_board_full(&board)) {
            printf("Tie game.\n");
            break;
        }
        Node best_move = minimax_find_best_move(&board, current_player);
        printf("%c chooses (%d, %d)\n",
               current_player == X ? 'X' : 'O', best_move.move.x, best_move.move.y);
        board.cells[best_move.move.x][best_move.move.y] = current_player;
        current_player = current_player == X ? O : X;
    }
    print_board(&board);
    return 0;
}