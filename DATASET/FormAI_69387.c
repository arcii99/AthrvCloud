//FormAI DATASET v1.0 Category: Checkers Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK 1
#define RED 2

int game_board[BOARD_SIZE][BOARD_SIZE]; //game board

enum move_type { NORMAL, KILL }; //move type

struct move {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
    enum move_type type;
};

struct move create_move(int from_row, int from_col, int to_row, int to_col, enum move_type type) {
    struct move m;
    m.from_row = from_row;
    m.from_col = from_col;
    m.to_row = to_row;
    m.to_col = to_col;
    m.type = type;
    return m;
}

void init_board() {
    //Initialize game board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3) {
                    game_board[row][col] = BLACK;
                } else if (row > 4) {
                    game_board[row][col] = RED;
                } else {
                    game_board[row][col] = EMPTY;
                }
            } else {
                game_board[row][col] = EMPTY;
            }
        }
    }
}

void print_board() {
    //Print game board
    printf("\n   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d |", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch(game_board[row][col]) {
                case EMPTY:
                    printf("  ");
                    break;
                case BLACK:
                    printf("b ");
                    break;
                case RED:
                    printf("r ");
                    break;
            }
        }
        printf("|\n");
    }
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
}

int validate_move(struct move m, int player) {
    //Validate if the move is valid for the player's piece
    if (m.from_row < 0 || m.from_row >= BOARD_SIZE ||
        m.from_col < 0 || m.from_col >= BOARD_SIZE ||
        m.to_row < 0 || m.to_row >= BOARD_SIZE ||
        m.to_col < 0 || m.to_col >= BOARD_SIZE) {
        return 0; //Out of bounds
    }
    if (game_board[m.to_row][m.to_col] != EMPTY) {
        return 0; //Destination is not empty
    }
    if (game_board[m.from_row][m.from_col] != player && game_board[m.from_row][m.from_col] != (player | 2)) {
        return 0; //Not player's piece
    }
    if (m.type == KILL) {
        if (player == BLACK) {
            if (m.to_row != m.from_row + 2 || (m.to_col != m.from_col + 2 && m.to_col != m.from_col - 2) ||
                game_board[m.from_row + 1][(m.from_col + m.to_col) / 2] == EMPTY ||
                game_board[m.from_row + 1][(m.from_col + m.to_col) / 2] == BLACK) {
                return 0; //Invalid kill move
            }
        } else {
            if (m.to_row != m.from_row - 2 || (m.to_col != m.from_col + 2 && m.to_col != m.from_col - 2) ||
                game_board[m.from_row - 1][(m.from_col + m.to_col) / 2] == EMPTY ||
                game_board[m.from_row - 1][(m.from_col + m.to_col) / 2] == RED) {
                return 0; //Invalid kill move
            }
        }
    } else {
        if (player == BLACK) {
            if (m.to_row != m.from_row + 1 || (m.to_col != m.from_col + 1 && m.to_col != m.from_col - 1)) {
                return 0; //Invalid move
            }
        } else {
            if (m.to_row != m.from_row - 1 || (m.to_col != m.from_col + 1 && m.to_col != m.from_col - 1)) {
                return 0; //Invalid move
            }
        }
    }
    return 1;
}

int is_game_over(int player) {
    //Check if the game is over
    int num_pieces = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (game_board[row][col] == player || game_board[row][col] == (player | 2)) {
                num_pieces++;
                if (num_pieces > 1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

struct move get_valid_move(int player) {
    //Get a valid move from the user
    int valid = 0;
    struct move m;
    while (!valid) {
        printf("Player %d's turn\n", player);
        printf("Enter move (from_row from_col to_row to_col): ");
        scanf("%d %d %d %d", &m.from_row, &m.from_col, &m.to_row, &m.to_col);
        if (game_board[m.from_row][m.from_col] == EMPTY) {
            printf("Invalid move: no piece at (%d, %d)\n", m.from_row, m.from_col);
        } else if (game_board[m.from_row][m.from_col] != player && game_board[m.from_row][m.from_col] != (player | 2)) {
            printf("Invalid move: not your piece at (%d, %d)\n", m.from_row, m.from_col);
        } else {
            if ((m.to_row + m.to_col) % 2 == 1) {
                printf("Invalid move: can only move to black squares\n");
            } else {
                if (m.to_row == m.from_row + 1 || m.to_row == m.from_row - 1) {
                    if (m.to_col == m.from_col + 1 || m.to_col == m.from_col - 1) {
                        m.type = NORMAL;
                        valid = 1;
                    } else {
                        printf("Invalid move: can only move diagonally\n");
                    }
                } else if (m.to_row == m.from_row + 2 || m.to_row == m.from_row - 2) {
                    if (m.to_col == m.from_col + 2 || m.to_col == m.from_col - 2) {
                        if (game_board[(m.from_row + m.to_row) / 2][(m.from_col + m.to_col) / 2] == (player == BLACK ? RED : BLACK)) {
                            m.type = KILL;
                            valid = 1;
                        } else {
                            printf("Invalid move: can only kill opponent's pieces\n");
                        }
                    } else {
                        printf("Invalid move: can only move diagonally\n");
                    }
                } else {
                    printf("Invalid move: can only move one or two squares\n");
                }
            }
        }
    }
    return m;
}

void perform_move(struct move m) {
    //Perform the move on the game board
    game_board[m.to_row][m.to_col] = game_board[m.from_row][m.from_col];
    game_board[m.from_row][m.from_col] = EMPTY;
    if (m.type == KILL) {
        game_board[(m.from_row + m.to_row) / 2][(m.from_col + m.to_col) / 2] = EMPTY;
    }
    if (m.to_row == 0 && game_board[m.to_row][m.to_col] == BLACK) {
        game_board[m.to_row][m.to_col] = BLACK | 2;
    }
    if (m.to_row == BOARD_SIZE - 1 && game_board[m.to_row][m.to_col] == RED) {
        game_board[m.to_row][m.to_col] = RED | 2;
    }
}

int main() {
    init_board();
    int player = BLACK;
    while (!is_game_over(player)) {
        print_board();
        struct move m = get_valid_move(player);
        while (!validate_move(m, player)) {
            printf("Invalid move: try again\n");
            m = get_valid_move(player);
        }
        perform_move(m);
        player = (player == BLACK ? RED : BLACK);
    }
    print_board();
    printf("Game over! Player %d wins!\n", player);
    return 0;
}