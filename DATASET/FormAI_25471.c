//FormAI DATASET v1.0 Category: Chess AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the default chessboard size
#define BOARD_SIZE 8

// Define the maximum number of moves that can be stored
#define MAX_MOVES 200

// Define the evaluation score for each chess piece
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 0

// Define the player colors
#define WHITE 0
#define BLACK 1

// Define the chess pieces
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Define structure for the chess pieces with value and color
typedef struct {
    int value;
    int color;
} Piece;

// Define the chessboard structure
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int turn; // 0 for white, 1 for black
    int moves[MAX_MOVES][4];
    int num_moves;
} Chessboard;

// Initialize the chessboard with starting positions
void init_board(Chessboard *cb) {
    // Pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        cb->board[1][i] = (Piece){ PAWN_VALUE, BLACK };
        cb->board[6][i] = (Piece){ PAWN_VALUE, WHITE };
    }

    // Rooks
    cb->board[0][0] = (Piece){ ROOK_VALUE, BLACK };
    cb->board[0][7] = (Piece){ ROOK_VALUE, BLACK };
    cb->board[7][0] = (Piece){ ROOK_VALUE, WHITE };
    cb->board[7][7] = (Piece){ ROOK_VALUE, WHITE };

    // Knights
    cb->board[0][1] = (Piece){ KNIGHT_VALUE, BLACK };
    cb->board[0][6] = (Piece){ KNIGHT_VALUE, BLACK };
    cb->board[7][1] = (Piece){ KNIGHT_VALUE, WHITE };
    cb->board[7][6] = (Piece){ KNIGHT_VALUE, WHITE };

    // Bishops
    cb->board[0][2] = (Piece){ BISHOP_VALUE, BLACK };
    cb->board[0][5] = (Piece){ BISHOP_VALUE, BLACK };
    cb->board[7][2] = (Piece){ BISHOP_VALUE, WHITE };
    cb->board[7][5] = (Piece){ BISHOP_VALUE, WHITE };

    // Queens
    cb->board[0][3] = (Piece){ QUEEN_VALUE, BLACK };
    cb->board[7][3] = (Piece){ QUEEN_VALUE, WHITE };

    // Kings
    cb->board[0][4] = (Piece){ KING_VALUE, BLACK };
    cb->board[7][4] = (Piece){ KING_VALUE, WHITE };

    // Other squares empty
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cb->board[i][j] = (Piece){ EMPTY, -1 };
        }
    }

    // White goes first
    cb->turn = WHITE;

    // No moves made yet
    cb->num_moves = 0;
}

// Print out the current state of the chessboard
void print_board(Chessboard cb) {
    char piece_symbols[] = ".PNBRQKpnbrqk";
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = cb.board[i][j].value + (cb.board[i][j].color == WHITE ? 6 : 0);
            printf("|%c ", piece_symbols[index]);
        }
        printf("| %d\n", BOARD_SIZE - i);
    }
    printf("   A  B  C  D  E  F  G  H\n\n");
}

// Check if a move is valid based on the current position and the desired move
int is_valid_move(Chessboard cb, int from_row, int from_col, int to_row, int to_col) {
    // Check if the pieces are on the board
    if (from_row < 0 || from_col < 0 || to_row < 0 || to_col < 0 || from_row >= BOARD_SIZE || from_col >= BOARD_SIZE || to_row >= BOARD_SIZE || to_col >= BOARD_SIZE) {
        return 0;
    }

    // Check if the piece is being moved to the same position
    if (from_row == to_row && from_col == to_col) {
        return 0;
    }

    // Check if there is a piece at the from position
    if (cb.board[from_row][from_col].value == EMPTY) {
        return 0;
    }

    // Check if the piece at the from position is the same color as the current player
    if (cb.board[from_row][from_col].color != cb.turn) {
        return 0;
    }

    // Check if the move is valid for the piece type
    int piece = cb.board[from_row][from_col].value;
    int color = cb.board[from_row][from_col].color;
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    switch (piece) {
        case PAWN:
            // Forward move
            if (col_diff == 0 && ((color == WHITE && row_diff == 1) || (color == BLACK && row_diff == -1))) {
                if (cb.board[to_row][to_col].value == EMPTY) {
                    return 1;
                }
            }

            // Diagonal move to capture
            if (abs(col_diff) == 1 && ((color == WHITE && row_diff == 1) || (color == BLACK && row_diff == -1))) {
                if (cb.board[to_row][to_col].value != EMPTY && cb.board[to_row][to_col].color != color) {
                    return 1;
                }
            }

            // Double forward move
            if (col_diff == 0 && ((color == WHITE && from_row == 1 && to_row == 3) || (color == BLACK && from_row == 6 && to_row == 4))) {
                if (cb.board[to_row][to_col].value == EMPTY && cb.board[from_row + (color == WHITE ? 1 : -1)][from_col].value == EMPTY) {
                    return 1;
                }
            }

            break;

        case KNIGHT:
            if ((abs(row_diff) == 1 && abs(col_diff) == 2) || (abs(row_diff) == 2 && abs(col_diff) == 1)) {
                if (cb.board[to_row][to_col].value == EMPTY || cb.board[to_row][to_col].color != color) {
                    return 1;
                }
            }
            break;

        case BISHOP:
            if (abs(row_diff) == abs(col_diff)) {
                int row_dir = row_diff > 0 ? 1 : -1;
                int col_dir = col_diff > 0 ? 1 : -1;

                int i = from_row + row_dir;
                int j = from_col + col_dir;

                while (i != to_row && j != to_col) {
                    if (cb.board[i][j].value != EMPTY) {
                        return 0;
                    }
                    i += row_dir;
                    j += col_dir;
                }

                if (cb.board[to_row][to_col].value == EMPTY || cb.board[to_row][to_col].color != color) {
                    return 1;
                }
            }
            break;

        case ROOK:
            if (row_diff == 0 || col_diff == 0) {
                int row_dir = row_diff > 0 ? 1 : (row_diff < 0 ? -1 : 0);
                int col_dir = col_diff > 0 ? 1 : (col_diff < 0 ? -1 : 0);

                int i = from_row + row_dir;
                int j = from_col + col_dir;

                while (i != to_row || j != to_col) {
                    if (cb.board[i][j].value != EMPTY) {
                        return 0;
                    }
                    i += row_dir;
                    j += col_dir;
                }

                if (cb.board[to_row][to_col].value == EMPTY || cb.board[to_row][to_col].color != color) {
                    return 1;
                }
            }
            break;

        case QUEEN:
            if (abs(row_diff) == abs(col_diff) || row_diff == 0 || col_diff == 0) {
                int row_dir = 0, col_dir = 0;

                if (row_diff != 0) {
                    row_dir = row_diff > 0 ? 1 : -1;
                }

                if (col_diff != 0) {
                    col_dir = col_diff > 0 ? 1 : -1;
                }

                int i = from_row + row_dir;
                int j = from_col + col_dir;

                while (i != to_row || j != to_col) {
                    if (cb.board[i][j].value != EMPTY) {
                        return 0;
                    }
                    i += row_dir;
                    j += col_dir;
                }

                if (cb.board[to_row][to_col].value == EMPTY || cb.board[to_row][to_col].color != color) {
                    return 1;
                }
            }
            break;

        case KING:
            if (abs(row_diff) <= 1 && abs(col_diff) <= 1) {
                if (cb.board[to_row][to_col].value == EMPTY || cb.board[to_row][to_col].color != color) {
                    return 1;
                }
            }
            break;
    }

    return 0;
}

// Move a piece from one position to another
int move_piece(Chessboard *cb, int from_row, int from_col, int to_row, int to_col) {
    // Check if the move is valid
    if (!is_valid_move(*cb, from_row, from_col, to_row, to_col)) {
        return 0;
    }

    // Store the move in the list of moves made
    cb->moves[cb->num_moves][0] = from_row;
    cb->moves[cb->num_moves][1] = from_col;
    cb->moves[cb->num_moves][2] = to_row;
    cb->moves[cb->num_moves][3] = to_col;
    cb->num_moves++;

    // Move the piece
    cb->board[to_row][to_col] = cb->board[from_row][from_col];
    cb->board[from_row][from_col] = (Piece){ EMPTY, -1 };

    // Switch turns
    cb->turn = cb->turn == WHITE ? BLACK : WHITE;

    return 1;
}

// Evaluate the current position on the board for a given color
int evaluate_position(Chessboard cb, int color) {
    int score = 0;

    // Evaluate the score for each piece
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece p = cb.board[i][j];

            if (p.value == PAWN && p.color == color) {
                score += PAWN_VALUE;
            }

            if (p.value == KNIGHT && p.color == color) {
                score += KNIGHT_VALUE;
            }

            if (p.value == BISHOP && p.color == color) {
                score += BISHOP_VALUE;
            }

            if (p.value == ROOK && p.color == color) {
                score += ROOK_VALUE;
            }

            if (p.value == QUEEN && p.color == color) {
                score += QUEEN_VALUE;
            }

            if (p.value == KING && p.color == color) {
                score += KING_VALUE;
            }
        }
    }

    return score;
}

// Find the best move to make for the current player
int *find_best_move(Chessboard *cb) {
    int *best_move = malloc(sizeof(int) * 4);
    int best_score = -1000;

    // Check every possible move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                for (int l = 0; l < BOARD_SIZE; l++) {
                    if (is_valid_move(*cb, i, j, k, l)) {
                        Chessboard new_board = *cb;
                        move_piece(&new_board, i, j, k, l);
                        int score = evaluate_position(new_board, new_board.turn);
                        if (score > best_score) {
                            best_score = score;
                            best_move[0] = i;
                            best_move[1] = j;
                            best_move[2] = k;
                            best_move[3] = l;
                        }
                    }
                }
            }
        }
    }

    return best_move;
}

int main() {
    Chessboard cb;
    init_board(&cb);

    printf("Starting position:\n");
    print_board(cb);

    printf("Make a move (e.g. 'e2 e4', or 'quit' to exit): ");
    char input[100];
    while (scanf("%s", input)) {
        if (strcmp(input, "quit") == 0) {
            break;
        }

        int from_col = input[0] - 'a';
        int from_row = BOARD_SIZE - (input[1] - '0');
        int to_col = input[2] - 'a';
        int to_row = BOARD_SIZE - (input[3] - '0');

        if (!move_piece(&cb, from_row, from_col, to_row, to_col)) {
            printf("Invalid move.\n");
        } else {
            printf("New position:\n");
            print_board(cb);

            if (cb.turn == BLACK) {
                printf("Thinking...\n");
                int *best_move = find_best_move(&cb);
                move_piece(&cb, best_move[0], best_move[1], best_move[2], best_move[3]);
                printf("Best move: %c%d%c%d\n", best_move[1] + 'a', BOARD_SIZE - best_move[0], best_move[3] + 'a', BOARD_SIZE - best_move[2]);
                printf("New position:\n");
                print_board(cb);
            }

            printf("Make a move (e.g. 'e2 e4', or 'quit' to exit): ");
        }
    }

    return 0;
}