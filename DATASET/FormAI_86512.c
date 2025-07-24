//FormAI DATASET v1.0 Category: Chess engine ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 8   // Change this value to change board size
#define MAX_DEPTH 4    // Max search depth for AI

// Define chess piece characters
#define EMPTY '-'
#define PAWN 'P'
#define BISHOP 'B'
#define KNIGHT 'N'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

/**
 * Struct to represent a chess move
 * Stores the starting and ending positions of the moved piece
 */
typedef struct {
    int fromRow, fromCol;
    int toRow, toCol;
} Move;

/**
 * Struct to represent a chess piece
 * Stores the type of piece (B, K, N, P, Q, R) and its color (0 = black, 1 = white)
 */
typedef struct {
    char type;
    int color;
} Piece;

/**
 * Struct to represent a chess board
 * Stores a 2D array of Piece structs and the current player (0 = black, 1 = white)
 */
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
} Board;

/**
 * Function to initialize a new chess board
 * Sets up the initial piece placement and sets currentPlayer to 1 (white)
 */
void initializeBoard(Board* board) {
    // Set up pawns
    for (int col = 0; col < BOARD_SIZE; col++) {
        board->board[1][col] = (Piece){.type = PAWN, .color = 0};
        board->board[6][col] = (Piece){.type = PAWN, .color = 1};
    }

    // Set up other pieces
    board->board[0][0] = (Piece){.type = ROOK, .color = 0};
    board->board[0][1] = (Piece){.type = KNIGHT, .color = 0};
    board->board[0][2] = (Piece){.type = BISHOP, .color = 0};
    board->board[0][3] = (Piece){.type = QUEEN, .color = 0};
    board->board[0][4] = (Piece){.type = KING, .color = 0};
    board->board[0][5] = (Piece){.type = BISHOP, .color = 0};
    board->board[0][6] = (Piece){.type = KNIGHT, .color = 0};
    board->board[0][7] = (Piece){.type = ROOK, .color = 0};
    board->board[7][0] = (Piece){.type = ROOK, .color = 1};
    board->board[7][1] = (Piece){.type = KNIGHT, .color = 1};
    board->board[7][2] = (Piece){.type = BISHOP, .color = 1};
    board->board[7][3] = (Piece){.type = QUEEN, .color = 1};
    board->board[7][4] = (Piece){.type = KING, .color = 1};
    board->board[7][5] = (Piece){.type = BISHOP, .color = 1};
    board->board[7][6] = (Piece){.type = KNIGHT, .color = 1};
    board->board[7][7] = (Piece){.type = ROOK, .color = 1};

    // Set current player to white
    board->currentPlayer = 1;
}

/**
 * Function to print the current state of the chess board to the console
 */
void printBoard(Board* board) {
    printf("\n   A B C D E F G H\n");
    printf("  +---------------+\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d | ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->board[row][col].type == EMPTY) {
                printf("- ");
            } else {
                printf("%c ", board->board[row][col].type);
            }
        }
        printf("| %d\n", row + 1);
    }
    printf("  +---------------+\n");
    printf("   A B C D E F G H\n\n");
}

/**
 * Function to check if a given move is valid on a given chess board
 * Returns 1 if the move is valid, 0 otherwise
 */
int isValidMove(Board* board, Move move) {
    // Check if the piece being moved belongs to the current player
    if (board->board[move.fromRow][move.fromCol].color != board->currentPlayer) {
        return 0;
    }

    // Check if the move is within the bounds of the board
    if (move.fromRow < 0 || move.fromRow >= BOARD_SIZE || move.toRow < 0 || move.toRow >= BOARD_SIZE ||
        move.fromCol < 0 || move.fromCol >= BOARD_SIZE || move.toCol < 0 || move.toCol >= BOARD_SIZE) {
        return 0;
    }

    // Check if the piece being moved is actually moving
    if (move.fromRow == move.toRow && move.fromCol == move.toCol) {
        return 0;
    }

    // Check if the destination square already has a piece of the same color
    if (board->board[move.toRow][move.toCol].color == board->currentPlayer) {
        return 0;
    }

    // TODO: check if the move is legal according to the rules of chess

    return 1;
}

/**
 * Function to make a given move on a given chess board
 * Assumes that the move is valid
 */
void makeMove(Board* board, Move move) {
    // Move the piece
    board->board[move.toRow][move.toCol] = board->board[move.fromRow][move.fromCol];
    board->board[move.fromRow][move.fromCol] = (Piece){.type = EMPTY};

    // Switch players
    board->currentPlayer = (board->currentPlayer + 1) % 2;
}

/**
 * Function to get all possible valid moves for the current player on a given chess board
 * Stores the moves in the given array and returns the number of moves found
 */
int getValidMoves(Board* board, Move validMoves[]) {
    int numMoves = 0;

    // Loop through all squares on the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            // Check if the current square contains a piece of the current player's color
            if (board->board[row][col].color == board->currentPlayer) {
                // Loop through all possible moves for the current piece
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0) {
                            continue;
                        }

                        Move move = {.fromRow = row, .fromCol = col, .toRow = row + i, .toCol = col + j};
                        if (isValidMove(board, move)) {
                            validMoves[numMoves++] = move;
                        }
                    }
                }
            }
        }
    }

    return numMoves;
}

/**
 * Function to score a given chess board for the current player
 * Positive scores are good for the current player, negative scores are good for the opponent
 */
int scoreBoard(Board* board) {
    int score = 0;

    // Add up the value of all pieces
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Piece piece = board->board[row][col];
            int value = 0;
            switch (piece.type) {
                case PAWN:
                    value = 1;
                    break;
                case BISHOP:
                case KNIGHT:
                    value = 3;
                    break;
                case ROOK:
                    value = 5;
                    break;
                case QUEEN:
                    value = 9;
                    break;
                case KING:
                    value = 100;
                    break;
            }
            if (piece.color == board->currentPlayer) {
                score += value;
            } else {
                score -= value;
            }
        }
    }

    return score;
}

/**
 * Function to perform a minimax search to find the best move for the current player
 * Returns the score of the best move found and stores the best move in the given pointer
 */
int minimax(Board board, Move* bestMove, int depth, int alpha, int beta) {
    // Base case: if depth limit is reached or the game is over, return the score
    if (depth == MAX_DEPTH) {
        return scoreBoard(&board);
    }

    Move validMoves[128] = {0};
    int numMoves = getValidMoves(&board, validMoves);

    // If there are no moves to be made, the game is over
    if (numMoves == 0) {
        return board.currentPlayer == 0 ? 10000 : -10000;
    }

    // Set default best score
    int bestScore = board.currentPlayer == 0 ? 10000 : -10000;

    // Loop through all valid moves and recursively search the tree
    for (int i = 0; i < numMoves; i++) {
        Board newBoard = board;
        makeMove(&newBoard, validMoves[i]);
        int score = minimax(newBoard, NULL, depth + 1, alpha, beta);
        if (board.currentPlayer == 0 && score < bestScore) {
            bestScore = score;
            if (bestMove != NULL) {
                *bestMove = validMoves[i];
            }
            beta = score;
        } else if (board.currentPlayer == 1 && score > bestScore) {
            bestScore = score;
            if (bestMove != NULL) {
                *bestMove = validMoves[i];
            }
            alpha = score;
        }
        if (beta <= alpha) {
            break;
        }
    }

    return bestScore;
}

/**
 * Main function to run the chess program
 */
int main() {
    // Initialize a new chess board
    Board board;
    initializeBoard(&board);

    // Print the starting board state
    printBoard(&board);

    // Loop until the game is over
    while (1) {
        Move move = {.fromRow = 0, .fromCol = 0, .toRow = 0, .toCol = 0};

        // If it's the human player's turn, get their move
        if (board.currentPlayer == 1) {
            printf("Your move (in the format 'A1 to B2'): ");
            char fromSq[2];
            char toSq[2];
            scanf("%s to %s", fromSq, toSq);
            move.fromRow = fromSq[1] - '1';
            move.fromCol = fromSq[0] - 'A';
            move.toRow = toSq[1] - '1';
            move.toCol = toSq[0] - 'A';
        } else {
            // Otherwise, have the AI make a move
            Move bestMove;
            minimax(board, &bestMove, 0, -10000, 10000);
            printf("AI move: %c%d to %c%d\n", bestMove.fromCol + 'A', bestMove.fromRow + 1, bestMove.toCol + 'A',
                   bestMove.toRow + 1);
            move = bestMove;
        }

        // Make the move and print the new board state
        if (isValidMove(&board, move)) {
            makeMove(&board, move);
            printBoard(&board);
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}