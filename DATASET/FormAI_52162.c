//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>

// Define the dimensions of the board
#define ROWS 8
#define COLS 8

// Define the player colors
#define PLAYER_1 1 //red
#define PLAYER_2 2 //black

// Define the piece types
#define EMPTY 0
#define MAN 1
#define KING 2

// Define directions of movement
#define UP_RIGHT {-1, 1}
#define UP_LEFT {-1, -1}
#define DOWN_RIGHT {1, 1}
#define DOWN_LEFT {1, -1}

// Define the struct for a board position
typedef struct {
    int row;
    int col;
} Position;

// Define the struct for a checker piece
typedef struct {
    int color;
    int type;
    Position position;
} Checker;

// Initialize the board
Checker board[ROWS][COLS] = {
    {{EMPTY, EMPTY, {0, 0}}, {MAN, PLAYER_1, {0, 1}}, {EMPTY, EMPTY, {0, 2}}, {MAN, PLAYER_1, {0, 3}}, {EMPTY, EMPTY, {0, 4}}, {MAN, PLAYER_1, {0, 5}}, {EMPTY, EMPTY, {0, 6}}, {MAN, PLAYER_1, {0, 7}}},
    {{MAN, PLAYER_1, {1, 0}}, {EMPTY, EMPTY, {1, 1}}, {MAN, PLAYER_1, {1, 2}}, {EMPTY, EMPTY, {1, 3}}, {MAN, PLAYER_1, {1, 4}}, {EMPTY, EMPTY, {1, 5}}, {MAN, PLAYER_1, {1, 6}}, {EMPTY, EMPTY, {1, 7}}},
    {{EMPTY, EMPTY, {2, 0}}, {MAN, PLAYER_1, {2, 1}}, {EMPTY, EMPTY, {2, 2}}, {MAN, PLAYER_1, {2, 3}}, {EMPTY, EMPTY, {2, 4}}, {MAN, PLAYER_1, {2, 5}}, {EMPTY, EMPTY, {2, 6}}, {MAN, PLAYER_1, {2, 7}}},
    {{EMPTY, EMPTY, {3, 0}}, {EMPTY, EMPTY, {3, 1}}, {EMPTY, EMPTY, {3, 2}}, {EMPTY, EMPTY, {3, 3}}, {EMPTY, EMPTY, {3, 4}}, {EMPTY, EMPTY, {3, 5}}, {EMPTY, EMPTY, {3, 6}}, {EMPTY, EMPTY, {3, 7}}},
    {{EMPTY, EMPTY, {4, 0}}, {EMPTY, EMPTY, {4, 1}}, {EMPTY, EMPTY, {4, 2}}, {EMPTY, EMPTY, {4, 3}}, {EMPTY, EMPTY, {4, 4}}, {EMPTY, EMPTY, {4, 5}}, {EMPTY, EMPTY, {4, 6}}, {EMPTY, EMPTY, {4, 7}}},
    {{MAN, PLAYER_2, {5, 0}}, {EMPTY, EMPTY, {5, 1}}, {MAN, PLAYER_2, {5, 2}}, {EMPTY, EMPTY, {5, 3}}, {MAN, PLAYER_2, {5, 4}}, {EMPTY, EMPTY, {5, 5}}, {MAN, PLAYER_2, {5, 6}}, {EMPTY, EMPTY, {5, 7}}},
    {{EMPTY, EMPTY, {6, 0}}, {MAN, PLAYER_2, {6, 1}}, {EMPTY, EMPTY, {6, 2}}, {MAN, PLAYER_2, {6, 3}}, {EMPTY, EMPTY, {6, 4}}, {MAN, PLAYER_2, {6, 5}}, {EMPTY, EMPTY, {6, 6}}, {MAN, PLAYER_2, {6, 7}}},
    {{MAN, PLAYER_2, {7, 0}}, {EMPTY, EMPTY, {7, 1}}, {MAN, PLAYER_2, {7, 2}}, {EMPTY, EMPTY, {7, 3}}, {MAN, PLAYER_2, {7, 4}}, {EMPTY, EMPTY, {7, 5}}, {MAN, PLAYER_2, {7, 6}}, {EMPTY, EMPTY, {7, 7}}}
};

// Print the board
void print_board() {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            switch(board[i][j].color) {
                case EMPTY:
                    printf(". ");
                    break;
                case PLAYER_1:
                    if (board[i][j].type == MAN) {
                        printf("R ");
                        break;
                    } else {
                        printf("K ");
                        break;
                    }
                case PLAYER_2:
                    if (board[i][j].type == MAN) {
                        printf("B ");
                        break;
                    } else {
                        printf("Q ");
                        break;
                    }
            }
        }
        printf("\n");
    }
}

// Move a piece on the board
void move(Checker *piece, Position new_pos) {
    board[piece->position.row][piece->position.col] = (Checker){EMPTY, EMPTY, {piece->position.row, piece->position.col}};
    piece->position = new_pos;
    board[piece->position.row][piece->position.col] = *piece;
}

// Calculate the distance between two positions
int distance(Position p1, Position p2) {
    return (int)abs((p1.row - p2.row) + (p1.col - p2.col));
}

// Check if a position is a valid move for a piece
int valid_move(Checker *piece, Position new_pos) {
    // Check if the move is within the bounds of the board
    if (new_pos.row < 0 || new_pos.row >= ROWS || new_pos.col < 0 || new_pos.col >= COLS) {
        return 0;
    }
    // Check if the move is to an empty space
    if (board[new_pos.row][new_pos.col].color != EMPTY) {
        return 0;
    }
    // Check if the move is diagonal and in the correct direction
    int row_diff = piece->position.row - new_pos.row;
    int col_diff = piece->position.col - new_pos.col;
    if (piece->color == PLAYER_1) {
        if (piece->type == MAN) {
            if (abs(row_diff) != 1 || abs(col_diff) != 1) {
                return 0;
            }
            if (row_diff < 0) {
                return 0;
            }
        } else {
            if (abs(row_diff) != 1 || abs(col_diff) != 1) {
                return 0;
            }
        }
    } else {
        if (piece->type == MAN) {
            if (abs(row_diff) != 1 || abs(col_diff) != 1) {
                return 0;
            }
            if (row_diff > 0) {
                return 0;
            }
        } else {
            if (abs(row_diff) != 1 || abs(col_diff) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

// Check if a jump is valid
int valid_jump(Checker *piece, Position new_pos) {
    // Get the position of the jumped piece
    int row_diff = piece->position.row - new_pos.row;
    int col_diff = piece->position.col - new_pos.col;
    Position jumped_pos = {piece->position.row - row_diff / 2, piece->position.col - col_diff / 2};
    // Check if the jump is within the bounds of the board
    if (new_pos.row < 0 || new_pos.row >= ROWS || new_pos.col < 0 || new_pos.col >= COLS) {
        return 0;
    }
    // Check if the move is to an empty space
    if (board[new_pos.row][new_pos.col].color != EMPTY) {
        return 0;
    }
    // Check if the move is diagonal and in the correct direction
    if (piece->color == PLAYER_1) {
        if (distance(piece->position, new_pos) != 2 || row_diff >= 0) {
            return 0;
        }
        if (board[jumped_pos.row][jumped_pos.col].color == PLAYER_1) {
            return 0;
        }
    } else {
        if (distance(piece->position, new_pos) != 2 || row_diff <= 0) {
            return 0;
        }
        if (board[jumped_pos.row][jumped_pos.col].color == PLAYER_2) {
            return 0;
        }
    }
    return 1;
}

// Move a piece and take any necessary jumps
void jump(Checker *piece, Position new_pos) {
    // Move the piece
    move(piece, new_pos);
    // Check for additional jumps
    if (valid_jump(piece, (Position){piece->position.row - 2, piece->position.col + 2})) {
        jump(piece, (Position){piece->position.row - 2, piece->position.col + 2});
    } else if (valid_jump(piece, (Position){piece->position.row - 2, piece->position.col - 2})) {
        jump(piece, (Position){piece->position.row - 2, piece->position.col - 2});
    } else if (valid_jump(piece, (Position){piece->position.row + 2, piece->position.col + 2})) {
        jump(piece, (Position){piece->position.row + 2, piece->position.col + 2});
    } else if (valid_jump(piece, (Position){piece->position.row + 2, piece->position.col - 2})) {
        jump(piece, (Position){piece->position.row + 2, piece->position.col - 2});
    }
}

// Promote a checker to a king
void promote(Checker *piece) {
    if (piece->color == PLAYER_1 && piece->position.row == ROWS - 1) {
        piece->type = KING;
    } else if (piece->color == PLAYER_2 && piece->position.row == 0) {
        piece->type = KING;
    }
}

// Switch between player turns
void switch_turn(int *current_player) {
    if (*current_player == PLAYER_1) {
        *current_player = PLAYER_2;
    } else {
        *current_player = PLAYER_1;
    }
}

// Get a pointer to a piece at a given position
Checker *get_piece(Position p) {
    return &board[p.row][p.col];
}

int main() {
    int current_player = PLAYER_1;
    int game_over = 0;

    while (!game_over) {
        // Print the board and the current player
        print_board();
        printf("Current player: %s\n", current_player == PLAYER_1 ? "red" : "black");

        int valid_input = 0;
        Checker *selected_piece;
        Position selected_pos;

        // Prompt the player to select a piece to move or exit the game
        while (!valid_input) {
            printf("Enter the coordinates of the piece you want to move or type '-1' to exit: ");
            int row, col;
            scanf("%d", &row);
            if (row == -1) {
                game_over = 1;
                break;
            }
            scanf("%d", &col);
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                printf("Invalid coordinates.\n");
            } else if (board[row][col].color == EMPTY) {
                printf("There is no piece there.\n");
            } else if (board[row][col].color != current_player) {
                printf("You can only move your own pieces.\n");
            } else {
                selected_piece = &board[row][col];
                selected_pos = selected_piece->position;
                valid_input = 1;
            }
        }
        if (game_over) {
            break;
        }

        int valid_move_input = 0;
        Position new_pos;

        // Prompt the player to select a valid move or jump
        while (!valid_move_input) {
            printf("Enter the coordinates of the new position: ");
            int row, col;
            scanf("%d", &row);
            scanf("%d", &col);
            new_pos = (Position){row, col};
            if (valid_jump(selected_piece, new_pos)) {
                jump(selected_piece, new_pos);
                valid_move_input = 1;
            } else if (valid_move(selected_piece, new_pos)) {
                move(selected_piece, new_pos);
                valid_move_input = 1;
            } else {
                printf("Invalid move.\n");
            }
        }

        // Check if the piece should be promoted
        promote(selected_piece);

        // Check for game over
        int player_1_pieces = 0;
        int player_2_pieces = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j].color == PLAYER_1) {
                    player_1_pieces++;
                } else if (board[i][j].color == PLAYER_2) {
                    player_2_pieces++;
                }
            }
        }
        if (player_1_pieces == 0 || player_2_pieces == 0) {
            game_over = 1;
            printf("GAME OVER! %s wins!\n", player_1_pieces == 0 ? "Black" : "Red");
            break;
        }

        // Switch turns
        switch_turn(&current_player);
    }

    return 0;
}