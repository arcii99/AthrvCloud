//FormAI DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define PLAYER_ONE_CHAR 'O'
#define PLAYER_TWO_CHAR 'X'

enum players {
    PLAYER_ONE = 1,
    PLAYER_TWO = 2
};

struct piece {
    char type;
    int player;
};

void print_board(struct piece board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n   0  1  2  3  4  5  6  7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("[%c]", board[i][j].type);
        }
        printf("\n");
    }
}

bool can_capture(struct piece board[BOARD_SIZE][BOARD_SIZE], int i, int j, int player) {
    if (board[i][j].type == PLAYER_ONE_CHAR) {
        if (i-2 >= 0 && j-2 >= 0 && board[i-1][j-1].type == PLAYER_TWO_CHAR && board[i-2][j-2].type == ' ') {
            return true;
        }
        if (i-2 >= 0 && j+2 < BOARD_SIZE && board[i-1][j+1].type == PLAYER_TWO_CHAR && board[i-2][j+2].type == ' ') {
            return true;
        }
    } else if (board[i][j].type == PLAYER_TWO_CHAR) {
        if (i+2 < BOARD_SIZE && j-2 >= 0 && board[i+1][j-1].type == PLAYER_ONE_CHAR && board[i+2][j-2].type == ' ') {
            return true;
        }
        if (i+2 < BOARD_SIZE && j+2 < BOARD_SIZE && board[i+1][j+1].type == PLAYER_ONE_CHAR && board[i+2][j+2].type == ' ') {
            return true;
        }
    }
    return false;
}

bool can_move(struct piece board[BOARD_SIZE][BOARD_SIZE], int i, int j, int player) {
    if (board[i][j].type == PLAYER_ONE_CHAR) {
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1].type == ' ') {
            return true;
        }
        if (i-1 >= 0 && j+1 < BOARD_SIZE && board[i-1][j+1].type == ' ') {
            return true;
        }
    } else if (board[i][j].type == PLAYER_TWO_CHAR) {
        if (i+1 < BOARD_SIZE && j-1 >= 0 && board[i+1][j-1].type == ' ') {
            return true;
        }
        if (i+1 < BOARD_SIZE && j+1 < BOARD_SIZE && board[i+1][j+1].type == ' ') {
            return true;
        }
    }
    return false;
}

void capture(struct piece board[BOARD_SIZE][BOARD_SIZE], int i, int j, int player) {
    if (board[i][j].type == PLAYER_ONE_CHAR) {
        if (i-2 >= 0 && j-2 >= 0 && board[i-1][j-1].type == PLAYER_TWO_CHAR && board[i-2][j-2].type == ' ') {
            board[i-1][j-1].type = ' ';
            board[i-2][j-2].type = PLAYER_ONE_CHAR;
        }
        if (i-2 >= 0 && j+2 < BOARD_SIZE && board[i-1][j+1].type == PLAYER_TWO_CHAR && board[i-2][j+2].type == ' ') {
            board[i-1][j+1].type = ' ';
            board[i-2][j+2].type = PLAYER_ONE_CHAR;
        }
    } else if (board[i][j].type == PLAYER_TWO_CHAR) {
        if (i+2 < BOARD_SIZE && j-2 >= 0 && board[i+1][j-1].type == PLAYER_ONE_CHAR && board[i+2][j-2].type == ' ') {
            board[i+1][j-1].type = ' ';
            board[i+2][j-2].type = PLAYER_TWO_CHAR;
        }
        if (i+2 < BOARD_SIZE && j+2 < BOARD_SIZE && board[i+1][j+1].type == PLAYER_ONE_CHAR && board[i+2][j+2].type == ' ') {
            board[i+1][j+1].type = ' ';
            board[i+2][j+2].type = PLAYER_TWO_CHAR;
        }
    }
}

void move_piece(struct piece board[BOARD_SIZE][BOARD_SIZE], int i, int j, int new_i, int new_j) {
    struct piece temp = board[i][j];
    board[i][j].type = ' ';
    board[new_i][new_j] = temp;
}

bool has_moves(struct piece board[BOARD_SIZE][BOARD_SIZE], int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].player == player && (can_move(board, i, j, player) || can_capture(board, i, j, player))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    struct piece board[BOARD_SIZE][BOARD_SIZE] = {0};
    int turn = PLAYER_ONE;
    
    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) {
                if (i < 3) {
                    board[i][j].type = PLAYER_TWO_CHAR;
                    board[i][j].player = PLAYER_TWO;
                } else if (i > 4) {
                    board[i][j].type = PLAYER_ONE_CHAR;
                    board[i][j].player = PLAYER_ONE;
                }
            }
        }
    }
    
    // Game loop
    while (true) {
        // Print board
        print_board(board);
        
        // Check if game is over
        if (!has_moves(board, PLAYER_ONE)) {
            printf("\nPlayer Two wins!\n");
            break;
        }
        if (!has_moves(board, PLAYER_TWO)) {
            printf("\nPlayer One wins!\n");
            break;
        }
        
        // Get move from player
        int i, j, new_i, new_j;
        printf("\nPlayer %d's turn!\n", turn);
        printf("Enter piece to move (row, col): ");
        scanf("%d,%d", &i, &j);
        printf("Enter new position (row, col): ");
        scanf("%d,%d", &new_i, &new_j);
        
        // Check if move/capture is valid
        if ((new_i < 0 || new_i >= BOARD_SIZE || new_j < 0 || new_j >= BOARD_SIZE) ||
            (board[new_i][new_j].type != ' ') ||
            (board[i][j].player != turn) ||
            (!can_move(board, i, j, turn) && !can_capture(board, i, j, turn))) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // Move or capture piece
        if (abs(i-new_i) == 2 && abs(j-new_j) == 2) {
            capture(board, i, j, turn);
            if (!can_capture(board, new_i, new_j, turn)) {
                turn = (turn == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
            }
        } else {
            move_piece(board, i, j, new_i, new_j);
            turn = (turn == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        }
    }
    
    return 0;
}