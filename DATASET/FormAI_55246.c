//FormAI DATASET v1.0 Category: Chess AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants for the chess board
#define BOARD_SIZE 8
#define BLACK 1
#define WHITE 2

// Struct for a chess move
typedef struct move {
    int fromX, fromY, toX, toY;
} Move;

// Struct for the chess board
typedef struct board {
    int grid[BOARD_SIZE][BOARD_SIZE];
    int turn;
} Board;

// Function to initialize the chess board
void initBoard(Board* board) {
    // Set the pieces for white
    board->grid[0][0] = WHITE + 2;  // Rook
    board->grid[0][1] = WHITE + 1;  // Knight
    board->grid[0][2] = WHITE + 2;  // Bishop
    board->grid[0][3] = WHITE + 5;  // Queen
    board->grid[0][4] = WHITE + 6;  // King
    board->grid[0][5] = WHITE + 2;  // Bishop
    board->grid[0][6] = WHITE + 1;  // Knight
    board->grid[0][7] = WHITE + 2;  // Rook
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->grid[1][i] = WHITE + 3;  // Pawns
    }

    // Set the pieces for black
    board->grid[7][0] = BLACK + 2;  // Rook
    board->grid[7][1] = BLACK + 1;  // Knight
    board->grid[7][2] = BLACK + 2;  // Bishop
    board->grid[7][3] = BLACK + 5;  // Queen
    board->grid[7][4] = BLACK + 6;  // King
    board->grid[7][5] = BLACK + 2;  // Bishop
    board->grid[7][6] = BLACK + 1;  // Knight
    board->grid[7][7] = BLACK + 2;  // Rook
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->grid[6][i] = BLACK + 3;  // Pawns
    }

    board->turn = WHITE;  // White moves first
}

// Function to print the chess board
void printBoard(Board* board) {
    printf("\t");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %d  ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\t-----------------\n");
        printf("%d\t|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board->grid[i][j]);
        }
        printf("\n");
    }
    printf("\t-----------------\n");
}

// Function to get possible moves for a given piece
void getMoves(Board* board, int x, int y, Move moves[], int* numMoves) {
    *numMoves = 0;
    int piece = board->grid[x][y];
    if (piece == BLACK + 1 || piece == WHITE + 1) {  // Knight
        if (x - 2 >= 0 && y - 1 >= 0 && board->grid[x - 2][y - 1] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x - 2, y - 1};
            (*numMoves)++;
        }
        if (x - 2 >= 0 && y + 1 < BOARD_SIZE && board->grid[x - 2][y + 1] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x - 2, y + 1};
            (*numMoves)++;
        }
        if (x - 1 >= 0 && y - 2 >= 0 && board->grid[x - 1][y - 2] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x - 1, y - 2};
            (*numMoves)++;
        }
        if (x - 1 >= 0 && y + 2 < BOARD_SIZE && board->grid[x - 1][y + 2] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x - 1, y + 2};
            (*numMoves)++;
        }
        if (x + 1 < BOARD_SIZE && y - 2 >= 0 && board->grid[x + 1][y - 2] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x + 1, y - 2};
            (*numMoves)++;
        }
        if (x + 1 < BOARD_SIZE && y + 2 < BOARD_SIZE && board->grid[x + 1][y + 2] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x + 1, y + 2};
            (*numMoves)++;
        }
        if (x + 2 < BOARD_SIZE && y - 1 >= 0 && board->grid[x + 2][y - 1] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x + 2, y - 1};
            (*numMoves)++;
        }
        if (x + 2 < BOARD_SIZE && y + 1 < BOARD_SIZE && board->grid[x + 2][y + 1] / 2 != piece / 2) {
            moves[*numMoves] = (Move) {x, y, x + 2, y + 1};
            (*numMoves)++;
        }
    } else if (piece == BLACK + 2 || piece == WHITE + 2) {  // Rook
        for (int i = x - 1; i >= 0; i--) {
            if (board->grid[i][y] == 0) {
                moves[*numMoves] = (Move) {x, y, i, y};
                (*numMoves)++;
            } else if (board->grid[i][y] / 2 != piece / 2) {
                moves[*numMoves] = (Move) {x, y, i, y};
                (*numMoves)++;
                break;
            } else {
                break;
            }
        }
        for (int i = x + 1; i < BOARD_SIZE; i++) {
            if (board->grid[i][y] == 0) {
                moves[*numMoves] = (Move) {x, y, i, y};
                (*numMoves)++;
            } else if (board->grid[i][y] / 2 != piece / 2) {
                moves[*numMoves] = (Move) {x, y, i, y};
                (*numMoves)++;
                break;
            } else {
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (board->grid[x][i] == 0) {
                moves[*numMoves] = (Move) {x, y, x, i};
                (*numMoves)++;
            } else if (board->grid[x][i] / 2 != piece / 2) {
                moves[*numMoves] = (Move) {x, y, x, i};
                (*numMoves)++;
                break;
            } else {
                break;
            }
        }
        for (int i = y + 1; i < BOARD_SIZE; i++) {
            if (board->grid[x][i] == 0) {
                moves[*numMoves] = (Move) {x, y, x, i};
                (*numMoves)++;
            } else if (board->grid[x][i] / 2 != piece / 2) {
                moves[*numMoves] = (Move) {x, y, x, i};
                (*numMoves)++;
                break;
            } else {
                break;
            }
        }
    }
}

// Function to make a move on the chess board
void makeMove(Board* board, Move move) {
    int piece = board->grid[move.fromX][move.fromY];
    board->grid[move.fromX][move.fromY] = 0;
    board->grid[move.toX][move.toY] = piece;
    board->turn = (board->turn == BLACK) ? WHITE : BLACK;
}

// Function to evaluate a position on the chess board
int evaluatePosition(Board board) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int piece = board.grid[i][j];
            if (piece == BLACK + 1) {  // Knight
                score -= 3;
            } else if (piece == WHITE + 1) {
                score += 3;
            } else if (piece == BLACK + 2) {  // Rook
                score -= 5;
            } else if (piece == WHITE + 2) {
                score += 5;
            }
        }
    }
    return score;
}

// Function to find the best move for the AI to make
Move findBestMove(Board board, int depth) {
    Move bestMove;
    int bestValue = (board.turn == BLACK) ? 9999 : -9999;
    int numMoves;
    Move moves[100];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.grid[i][j] != 0 && board.grid[i][j] / 2 == board.turn / 2) {
                getMoves(&board, i, j, moves, &numMoves);
                for (int k = 0; k < numMoves; k++) {
                    Board newBoard = board;
                    makeMove(&newBoard, moves[k]);
                    int value = minimax(newBoard, depth - 1, -10000, 10000);
                    if ((board.turn == BLACK && value < bestValue) || (board.turn == WHITE && value > bestValue)) {
                        bestValue = value;
                        bestMove = moves[k];
                    }
                }
            }
        }
    }
    return bestMove;
}

// Function for the minimax algorithm with alpha-beta pruning
int minimax(Board board, int depth, int alpha, int beta) {
    if (depth == 0) {
        return evaluatePosition(board);
    }
    int numMoves;
    Move moves[100];
    getMoves(&board, 0, 0, moves, &numMoves);
    if (board.turn == BLACK) {
        int bestValue = -9999;
        for (int i = 0; i < numMoves; i++) {
            Board newBoard = board;
            makeMove(&newBoard, moves[i]);
            int value = minimax(newBoard, depth - 1, alpha, beta);
            if (value > bestValue) {
                bestValue = value;
            }
            if (value > alpha) {
                alpha = value;
            }
            if (beta <= alpha) {
                break;
            }
        }
        return bestValue;
    } else {
        int bestValue = 9999;
        for (int i = 0; i < numMoves; i++) {
            Board newBoard = board;
            makeMove(&newBoard, moves[i]);
            int value = minimax(newBoard, depth - 1, alpha, beta);
            if (value < bestValue) {
                bestValue = value;
            }
            if (value < beta) {
                beta = value;
            }
            if (beta <= alpha) {
                break;
            }
        }
        return bestValue;
    }
}

int main() {
    Board board;
    initBoard(&board);
    while (true) {
        printBoard(&board);
        if (board.turn == BLACK) {
            printf("Black's turn.\n");
        } else {
            printf("White's turn.\n");
        }
        if (board.turn == BLACK) {
            Move move = findBestMove(board, 3);
            makeMove(&board, move);
        } else {
            printf("Enter your move (ex. e2 e4): ");
            char input[50];
            fgets(input, 50, stdin);
            int fromX = input[1] - '0';
            int fromY = input[0] - 'a';
            int toX = input[4] - '0';
            int toY = input[3] - 'a';
            Move move = (Move) {fromX, fromY, toX, toY};
            makeMove(&board, move);
        }
    }
    return 0;
}