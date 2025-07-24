//FormAI DATASET v1.0 Category: Chess AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 8
#define COLS 8
#define MAX_DEPTH 6

#define EMPTY '.'
#define WHITE_PAWN 'P'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_ROOK 'R'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_ROOK 'r'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'

#define WHITE_PAWNVALUE 100
#define WHITE_KNIGHTVALUE 320
#define WHITE_BISHOPVALUE 330
#define WHITE_ROOKVALUE 500
#define WHITE_QUEENVALUE 900
#define WHITE_KINGVALUE 20000

#define BLACK_PAWNVALUE -100
#define BLACK_KNIGHTVALUE -320
#define BLACK_BISHOPVALUE -330
#define BLACK_ROOKVALUE -500
#define BLACK_QUEENVALUE -900
#define BLACK_KINGVALUE -20000

typedef struct {
    char board[ROWS][COLS];
    int whiteValue;
    int blackValue;
    int turn;
} GameState;

typedef struct {
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
    int moveValue;
} Move;

int minmax(GameState state, int depth, int alpha, int beta);
void printBoard(GameState state);
void initializeBoard(GameState* state);

int evaluate(GameState state) {
    return (state.turn == 1) ? state.whiteValue - state.blackValue : state.blackValue - state.whiteValue;
}

void makeMove(GameState* state, Move move) {
    char piece = state->board[move.fromRow][move.fromCol];

    // handle move value
    if (piece == WHITE_PAWN) {
        move.moveValue = WHITE_PAWNVALUE;
    }
    else if (piece == WHITE_KNIGHT) {
        move.moveValue = WHITE_KNIGHTVALUE;
    }
    else if (piece == WHITE_BISHOP) {
        move.moveValue = WHITE_BISHOPVALUE;
    }
    else if (piece == WHITE_ROOK) {
        move.moveValue = WHITE_ROOKVALUE;
    }
    else if (piece == WHITE_QUEEN) {
        move.moveValue = WHITE_QUEENVALUE;
    }
    else if (piece == WHITE_KING) {
        move.moveValue = WHITE_KINGVALUE;
    }
    else if (piece == BLACK_PAWN) {
        move.moveValue = BLACK_PAWNVALUE;
    }
    else if (piece == BLACK_KNIGHT) {
        move.moveValue = BLACK_KNIGHTVALUE;
    }
    else if (piece == BLACK_BISHOP) {
        move.moveValue = BLACK_BISHOPVALUE;
    }
    else if (piece == BLACK_ROOK) {
        move.moveValue = BLACK_ROOKVALUE;
    }
    else if (piece == BLACK_QUEEN) {
        move.moveValue = BLACK_QUEENVALUE;
    }
    else if (piece == BLACK_KING) {
        move.moveValue = BLACK_KINGVALUE;
    }

    // update board
    state->board[move.toRow][move.toCol] = piece;
    state->board[move.fromRow][move.fromCol] = EMPTY;

    // update value
    if (piece == WHITE_PAWN) {
        state->whiteValue += move.moveValue;
    }
    else if (piece == WHITE_KNIGHT) {
        state->whiteValue += move.moveValue;
    }
    else if (piece == WHITE_BISHOP) {
        state->whiteValue += move.moveValue;
    }
    else if (piece == WHITE_ROOK) {
        state->whiteValue += move.moveValue;
    }
    else if (piece == WHITE_QUEEN) {
        state->whiteValue += move.moveValue;
    }
    else if (piece == WHITE_KING) {
        state->whiteValue += move.moveValue;
    }
    else if (piece == BLACK_PAWN) {
        state->blackValue += move.moveValue;
    }
    else if (piece == BLACK_KNIGHT) {
        state->blackValue += move.moveValue;
    }
    else if (piece == BLACK_BISHOP) {
        state->blackValue += move.moveValue;
    }
    else if (piece == BLACK_ROOK) {
        state->blackValue += move.moveValue;
    }
    else if (piece == BLACK_QUEEN) {
        state->blackValue += move.moveValue;
    }
    else if (piece == BLACK_KING) {
        state->blackValue += move.moveValue;
    }

    // switch turn
    state->turn = (state->turn == 1) ? 2 : 1;
}

void undoMove(GameState* state, Move move) {
    char piece = state->board[move.toRow][move.toCol];

    // update board
    state->board[move.fromRow][move.fromCol] = piece;
    state->board[move.toRow][move.toCol] = EMPTY;

    // update value
    if (piece == WHITE_PAWN) {
        state->whiteValue -= move.moveValue;
    }
    else if (piece == WHITE_KNIGHT) {
        state->whiteValue -= move.moveValue;
    }
    else if (piece == WHITE_BISHOP) {
        state->whiteValue -= move.moveValue;
    }
    else if (piece == WHITE_ROOK) {
        state->whiteValue -= move.moveValue;
    }
    else if (piece == WHITE_QUEEN) {
        state->whiteValue -= move.moveValue;
    }
    else if (piece == WHITE_KING) {
        state->whiteValue -= move.moveValue;
    }
    else if (piece == BLACK_PAWN) {
        state->blackValue -= move.moveValue;
    }
    else if (piece == BLACK_KNIGHT) {
        state->blackValue -= move.moveValue;
    }
    else if (piece == BLACK_BISHOP) {
        state->blackValue -= move.moveValue;
    }
    else if (piece == BLACK_ROOK) {
        state->blackValue -= move.moveValue;
    }
    else if (piece == BLACK_QUEEN) {
        state->blackValue -= move.moveValue;
    }
    else if (piece == BLACK_KING) {
        state->blackValue -= move.moveValue;
    }

    // switch turn
    state->turn = (state->turn == 1) ? 2 : 1;
}

Move generateMove(GameState state) {
    Move bestMove = {0, 0, 0, 0, 0};
    int maxScore = -20000;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (state.board[i][j] == EMPTY) {
                continue;
            }

            if ((state.turn == 1 && isupper(state.board[i][j])) || (state.turn == 2 && islower(state.board[i][j]))) {
                continue;
            }

            if (state.board[i][j] == WHITE_PAWN) {
                if (i - 1 >= 0 && state.board[i - 1][j - 1] != EMPTY && islower(state.board[i - 1][j - 1])) {
                    Move move = {i, j, i - 1, j - 1, 0}; // capture left
                    makeMove(&state, move);
                    int score = minmax(state, MAX_DEPTH - 1, -20000, 20000);
                    undoMove(&state, move);

                    if (score > maxScore) {
                        maxScore = score;
                        bestMove = move;
                    }
                }

                if (i - 1 >= 0 && state.board[i - 1][j + 1] != EMPTY && islower(state.board[i - 1][j + 1])) {
                    Move move = {i, j, i - 1, j + 1, 0}; // capture right
                    makeMove(&state, move);
                    int score = minmax(state, MAX_DEPTH - 1, -20000, 20000);
                    undoMove(&state, move);

                    if (score > maxScore) {
                        maxScore = score;
                        bestMove = move;
                    }
                }

                if (i - 1 >= 0 && state.board[i - 1][j] == EMPTY) {
                    Move move = {i, j, i - 1, j, 0}; // move forward
                    makeMove(&state, move);
                    int score = minmax(state, MAX_DEPTH - 1, -20000, 20000);
                    undoMove(&state, move);

                    if (score > maxScore) {
                        maxScore = score;
                        bestMove = move;
                    }
                }
            }

            // ... more moves for other pieces ...
        }
    }

    return bestMove;
}

int minmax(GameState state, int depth, int alpha, int beta) {
    if (depth == 0) {
        return evaluate(state);
    }

    if (state.turn == 1) { // white
        int maxScore = -20000;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (state.board[i][j] == EMPTY) {
                    continue;
                }

                if (islower(state.board[i][j])) {
                    continue;
                }

                // ... more conditions ...

                // depth pruning
                if (depth == MAX_DEPTH - 1) {
                    // get move value
                    int moveValue = 0;

                    if (state.board[i][j] == WHITE_PAWN) {
                        moveValue = WHITE_PAWNVALUE;
                    }
                    else if (state.board[i][j] == WHITE_KNIGHT) {
                        moveValue = WHITE_KNIGHTVALUE;
                    }
                    else if (state.board[i][j] == WHITE_BISHOP) {
                        moveValue = WHITE_BISHOPVALUE;
                    }
                    else if (state.board[i][j] == WHITE_ROOK) {
                        moveValue = WHITE_ROOKVALUE;
                    }
                    else if (state.board[i][j] == WHITE_QUEEN) {
                        moveValue = WHITE_QUEENVALUE;
                    }
                    else if (state.board[i][j] == WHITE_KING) {
                        moveValue = WHITE_KINGVALUE;
                    }
                }

                // apply move
                for (int k = 0; k < ROWS; k++) {
                    for (int l = 0; l < COLS; l++) {
                        if (state.board[k][l] == EMPTY || islower(state.board[k][l])) {
                            continue;
                        }

                        // ... more conditions ...

                        Move move = {i, j, k, l, 0};
                        makeMove(&state, move);

                        // recurse into min-max
                        int score = minmax(state, depth - 1, alpha, beta);
                        maxScore = (score > maxScore) ? score : maxScore;

                        // alpha-beta pruning
                        if (maxScore >= beta) {
                            undoMove(&state, move);
                            return maxScore;
                        }

                        alpha = (maxScore > alpha) ? maxScore : alpha;

                        // undo move
                        undoMove(&state, move);
                    }
                }
            }
        }

        return maxScore;
    }
    else if (state.turn == 2) { // black
        int minScore = 20000;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (state.board[i][j] == EMPTY) {
                    continue;
                }

                if (isupper(state.board[i][j])) {
                    continue;
                }

                // ... more conditions ...

                // apply move
                for (int k = 0; k < ROWS; k++) {
                    for (int l = 0; l < COLS; l++) {
                        if (state.board[k][l] == EMPTY || isupper(state.board[k][l])) {
                            continue;
                        }

                        // ... more conditions ...

                        Move move = {i, j, k, l, 0};
                        makeMove(&state, move);

                        // recurse into min-max
                        int score = minmax(state, depth - 1, alpha, beta);
                        minScore = (score < minScore) ? score : minScore;

                        // alpha-beta pruning
                        if (minScore <= alpha) {
                            undoMove(&state, move);
                            return minScore;
                        }

                        beta = (minScore < beta) ? minScore : beta;

                        // undo move
                        undoMove(&state, move);
                    }
                }
            }
        }

        return minScore;
    }

    return 0;
}

void printBoard(GameState state) {
    printf("  a b c d e f g h\n");
    printf("  ----------------\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d|", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c|", state.board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  ----------------\n");
    printf("  a b c d e f g h\n");
}

void initializeBoard(GameState* state) {
    state->whiteValue = 0;
    state->blackValue = 0;
    state->turn = 1;

    // initialize board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 1) {
                state->board[i][j] = WHITE_PAWN;
                state->whiteValue += WHITE_PAWNVALUE;
            }
            else if (i == ROWS - 2) {
                state->board[i][j] = BLACK_PAWN;
                state->blackValue += BLACK_PAWNVALUE;
            }
            else {
                state->board[i][j] = EMPTY;
            }
        }
    }

    // add pieces
    state->board[0][0] = WHITE_ROOK;
    state->board[0][1] = WHITE_KNIGHT;
    state->board[0][2] = WHITE_BISHOP;
    state->board[0][3] = WHITE_QUEEN;
    state->board[0][4] = WHITE_KING;
    state->board[0][5] = WHITE_BISHOP;
    state->board[0][6] = WHITE_KNIGHT;
    state->board[0][7] = WHITE_ROOK;

    state->board[7][0] = BLACK_ROOK;
    state->board[7][1] = BLACK_KNIGHT;
    state->board[7][2] = BLACK_BISHOP;
    state->board[7][3] = BLACK_QUEEN;
    state->board[7][4] = BLACK_KING;
    state->board[7][5] = BLACK_BISHOP;
    state->board[7][6] = BLACK_KNIGHT;
    state->board[7][7] = BLACK_ROOK;

    // calculate initial value
    state->whiteValue += WHITE_ROOKVALUE * 2 + WHITE_KNIGHTVALUE * 2 + WHITE_BISHOPVALUE * 2 + WHITE_QUEENVALUE + WHITE_KINGVALUE;
    state->blackValue += BLACK_ROOKVALUE * 2 + BLACK_KNIGHTVALUE * 2 + BLACK_BISHOPVALUE * 2 + BLACK_QUEENVALUE + BLACK_KINGVALUE;
}

int main() {
    srand(time(NULL)); // seed random number generator

    GameState state;

    initializeBoard(&state);
    printBoard(state);

    while (1) {
        if (state.turn == 1) {
            printf("White's move: ");
            Move move;
            scanf("%d%d%d%d", &move.fromRow, &move.fromCol, &move.toRow, &move.toCol);
            makeMove(&state, move);
        }
        else if (state.turn == 2) {
            Move move = generateMove(state);
            printf("Black's move: %d%d %d%d\n", move.fromRow, move.fromCol, move.toRow, move.toCol);
            makeMove(&state, move);
        }

        printBoard(state);
    }

    return 0;
}