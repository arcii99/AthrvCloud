//FormAI DATASET v1.0 Category: Chess AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Enumeration for the chess pieces */
enum Piece {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};

/* Enumeration for the colors of the pieces */
enum Color {
    WHITE,
    BLACK
};

/* Structure for a piece on the chess board */
typedef struct {
    enum Piece piece;    // The type of the piece
    enum Color color;    // The color of the piece
    int x;               // The x-coordinate of the piece on the board
    int y;               // The y-coordinate of the piece on the board
    bool moved;          // Whether the piece has moved before
} PieceOnBoard;

/* Function to initialize the chess board */
void initialize_board(PieceOnBoard chess_board[][8]) {
    /* Setting up the initial positions of the white pieces */
    chess_board[0][0] = (PieceOnBoard) {ROOK, WHITE, 0, 0, false};
    chess_board[0][1] = (PieceOnBoard) {KNIGHT, WHITE, 0, 1, false};
    chess_board[0][2] = (PieceOnBoard) {BISHOP, WHITE, 0, 2, false};
    chess_board[0][3] = (PieceOnBoard) {QUEEN, WHITE, 0, 3, false};
    chess_board[0][4] = (PieceOnBoard) {KING, WHITE, 0, 4, false};
    chess_board[0][5] = (PieceOnBoard) {BISHOP, WHITE, 0, 5, false};
    chess_board[0][6] = (PieceOnBoard) {KNIGHT, WHITE, 0, 6, false};
    chess_board[0][7] = (PieceOnBoard) {ROOK, WHITE, 0, 7, false};
    for (int j = 0; j < 8; j++) {
        chess_board[1][j] = (PieceOnBoard) {PAWN, WHITE, 1, j, false};
    }

    /* Setting up the initial positions of the black pieces */
    chess_board[7][0] = (PieceOnBoard) {ROOK, BLACK, 7, 0, false};
    chess_board[7][1] = (PieceOnBoard) {KNIGHT, BLACK, 7, 1, false};
    chess_board[7][2] = (PieceOnBoard) {BISHOP, BLACK, 7, 2, false};
    chess_board[7][3] = (PieceOnBoard) {QUEEN, BLACK, 7, 3, false};
    chess_board[7][4] = (PieceOnBoard) {KING, BLACK, 7, 4, false};
    chess_board[7][5] = (PieceOnBoard) {BISHOP, BLACK, 7, 5, false};
    chess_board[7][6] = (PieceOnBoard) {KNIGHT, BLACK, 7, 6, false};
    chess_board[7][7] = (PieceOnBoard) {ROOK, BLACK, 7, 7, false};
    for (int j = 0; j < 8; j++) {
        chess_board[6][j] = (PieceOnBoard) {PAWN, BLACK, 6, j, false};
    }
}

/* Function to print the chess board */
void print_board(PieceOnBoard chess_board[][8]) {
    printf("\n");
    printf("   0  1  2  3  4  5  6  7\n");
    printf(" ------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d| ", i);
        for (int j = 0; j < 8; j++) {
            if (chess_board[i][j].piece == ROOK) {
                printf("R ");
            } else if (chess_board[i][j].piece == KNIGHT) {
                printf("N ");
            } else if (chess_board[i][j].piece == BISHOP) {
                printf("B ");
            } else if (chess_board[i][j].piece == QUEEN) {
                printf("Q ");
            } else if (chess_board[i][j].piece == KING) {
                printf("K ");
            } else if (chess_board[i][j].piece == PAWN) {
                printf("P ");
            } else {
                printf(". ");
            }
        }
        printf("|\n");
    }
    printf(" ------------------------\n");
    printf("\n");
}

/* Function to simulate a move on the chess board */
void simulate_move(PieceOnBoard chess_board[][8], int from_x, int from_y, int to_x, int to_y) {
    chess_board[to_x][to_y] = (PieceOnBoard) {
        chess_board[from_x][from_y].piece,
        chess_board[from_x][from_y].color,
        to_x,
        to_y,
        true
    };
    chess_board[from_x][from_y] = (PieceOnBoard) {0};
}

/* Function to check whether a move is valid */
bool is_move_valid(PieceOnBoard chess_board[][8], int from_x, int from_y, int to_x, int to_y) {
    if (!chess_board[from_x][from_y].moved) {
        if (chess_board[from_x][from_y].piece == KING) {
            if (to_y == from_y + 2) {
                /* Castling king side */
                if (chess_board[from_x][from_y + 1].piece == 0 &&
                    chess_board[from_x][from_y + 2].piece == 0 &&
                    !chess_board[from_x][from_y + 3].moved) {
                        return true;
                } else {
                    return false;
                }
            } else if (to_y == from_y - 2) {
                /* Castling queen side */
                if (chess_board[from_x][from_y - 1].piece == 0 &&
                    chess_board[from_x][from_y - 2].piece == 0 &&
                    chess_board[from_x][from_y - 3].piece == 0 &&
                    !chess_board[from_x][from_y - 4].moved) {
                        return true;
                } else {
                    return false;
                }
            }
        }
    }
    /* Check if the piece is moving to the same position */
    if (from_x == to_x && from_y == to_y) {
        return false;
    }
    /* Check if there is a piece of the same color at the destination */
    if (chess_board[to_x][to_y].color == chess_board[from_x][from_y].color) {
        return false;
    }
    switch(chess_board[from_x][from_y].piece) {
        case KING:
            /* Check if the move is legal for the king */
            return (to_x == from_x && abs(to_y - from_y) == 1) ||
                   (to_y == from_y && abs(to_x - from_x) == 1) ||
                   (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1);
            break;
        case QUEEN:
            /* Check if the move is legal for the queen */
            if (to_x == from_x || to_y == from_y ||
                abs(to_x - from_x) == abs(to_y - from_y)) {
                    int i, j;
                    if (to_x == from_x) {
                        /* Moving vertically */
                        i = to_y < from_y ? to_y + 1 : from_y + 1;
                        j = to_y < from_y ? from_y - 1 : to_y - 1;
                        while (i < j) {
                            if (chess_board[to_x][i].piece != 0) {
                                return false;
                            }
                            i++;
                        }
                    } else if (to_y == from_y) {
                        /* Moving horizontally */
                        i = to_x < from_x ? to_x + 1 : from_x + 1;
                        j = to_x < from_x ? from_x - 1 : to_x - 1;
                        while (i < j) {
                            if (chess_board[i][to_y].piece != 0) {
                                return false;
                            }
                            i++;
                        }
                    } else {
                        /* Diagonal move */
                        int delta_x = to_x - from_x;
                        int delta_y = to_y - from_y;
                        i = to_x < from_x ? to_x + 1 : from_x + 1;
                        j = to_y < from_y ? to_y + 1 : from_y + 1;
                        bool negative_x = delta_x < 0 ? true : false;
                        bool negative_y = delta_y < 0 ? true : false;
                        while (i != to_x && j != to_y) {
                            if (chess_board[i][j].piece != 0) {
                                return false;
                            }
                            if (negative_x) {
                                i--;
                            } else {
                                i++;
                            }
                            if (negative_y) {
                                j--;
                            } else {
                                j++;
                            }
                        }
                    }
                    return true;
            } else {
                return false;
            }
            break;
        case ROOK:
            /* Check if the move is legal for the rook */
            if (to_x == from_x || to_y == from_y) {
                int i, j;
                if (to_x == from_x) {
                    /* Moving vertically */
                    i = to_y < from_y ? to_y + 1 : from_y + 1;
                    j = to_y < from_y ? from_y - 1 : to_y - 1;
                    while (i < j) {
                        if (chess_board[to_x][i].piece != 0) {
                            return false;
                        }
                        i++;
                    }
                } else if (to_y == from_y) {
                    /* Moving horizontally */
                    i = to_x < from_x ? to_x + 1 : from_x + 1;
                    j = to_x < from_x ? from_x - 1 : to_x - 1;
                    while (i < j) {
                        if (chess_board[i][to_y].piece != 0) {
                            return false;
                        }
                        i++;
                    }
                }
                return true;
            } else {
                return false;
            }
            break;
        case BISHOP:
            /* Check if the move is legal for the bishop */
            if (abs(to_x - from_x) == abs(to_y - from_y)) {
                int delta_x = to_x - from_x;
                int delta_y = to_y - from_y;
                int i = to_x < from_x ? to_x + 1 : from_x + 1;
                int j = to_y < from_y ? to_y + 1 : from_y + 1;
                bool negative_x = delta_x < 0 ? true : false;
                bool negative_y = delta_y < 0 ? true : false;
                while (i != to_x && j != to_y) {
                    if (chess_board[i][j].piece != 0) {
                        return false;
                    }
                    if (negative_x) {
                        i--;
                    } else {
                        i++;
                    }
                    if (negative_y) {
                        j--;
                    } else {
                        j++;
                    }
                }
                return true;
            } else {
                return false;
            }
            break;
        case KNIGHT:
            /* Check if the move is legal for the knight */
            return (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1) ||
                   (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2);
            break;
        case PAWN:
            /* Check if the move is legal for the pawn */
            if (chess_board[from_x][from_y].color == WHITE) {
                if (from_x == 1) {
                    /* Initial move for the white pawn */
                    if (to_y == from_y) {
                        if (to_x == from_x + 1 || to_x == from_x + 2) {
                            if (to_x == from_x + 2 && chess_board[from_x + 1][from_y].piece != 0) {
                                return false;
                            } else {
                                return true;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if (to_x == from_x + 1 && abs(to_y - from_y) == 1) {
                            if (chess_board[to_x][to_y].piece != 0 &&
                                chess_board[to_x][to_y].color != chess_board[from_x][from_y].color) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                } else {
                    /* Any other move for the white pawn */
                    if (to_y == from_y) {
                        if (to_x == from_x + 1) {
                            if (chess_board[to_x][to_y].piece == 0) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if (to_x == from_x + 1 && abs(to_y - from_y) == 1) {
                            if (chess_board[to_x][to_y].piece != 0 &&
                                chess_board[to_x][to_y].color != chess_board[from_x][from_y].color) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                }
            } else {
                if (from_x == 6) {
                    /* Initial move for the black pawn */
                    if (to_y == from_y) {
                        if (to_x == from_x - 1 || to_x == from_x - 2) {
                            if (to_x == from_x - 2 && chess_board[from_x - 1][from_y].piece != 0) {
                                return false;
                            } else {
                                return true;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if (to_x == from_x - 1 && abs(to_y - from_y) == 1) {
                            if (chess_board[to_x][to_y].piece != 0 &&
                                chess_board[to_x][to_y].color != chess_board[from_x][from_y].color) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                } else {
                    /* Any other move for the black pawn */
                    if (to_y == from_y) {
                        if (to_x == from_x - 1) {
                            if (chess_board[to_x][to_y].piece == 0) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if (to_x == from_x - 1 && abs(to_y - from_y) == 1) {
                            if (chess_board[to_x][to_y].piece != 0 &&
                                chess_board[to_x][to_y].color != chess_board[from_x][from_y].color) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                }
            }
            break;
    }
    return false;
}

/* Main function */
int main() {
    PieceOnBoard chess_board[8][8];
    initialize_board(chess_board);
    int turn = WHITE;
    int from_x, from_y, to_x, to_y;
    bool is_game_over = false;
    while (!is_game_over) {
        print_board(chess_board);
        printf("%s's turn\n", turn == WHITE ? "White" : "Black");
        printf("Enter the coordinates of the piece you want to move: ");
        scanf("%d %d", &from_x, &from_y);
        printf("Enter the coordinates of the square you want to move to: ");
        scanf("%d %d", &to_x, &to_y);
        if (is_move_valid(chess_board, from_x, from_y, to_x, to_y)) {
            simulate_move(chess_board, from_x, from_y, to_x, to_y);
            if (turn == WHITE) {
                turn = BLACK;
            } else {
                turn = WHITE;
            }
        } else {
            printf("That move is not valid. Try another move.\n");
        }
    }
    return 0;
}