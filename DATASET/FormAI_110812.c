//FormAI DATASET v1.0 Category: Chess AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
    bool isCheck;
    char pieces[2];
} GameState;

bool isValidMove(GameState *state, Position start, Position end);
bool performMove(GameState *state, Position start, Position end);

void initBoard(GameState *state) {
    // Initialize the board with pieces in their starting positions
    state->board[0][0] = state->board[0][7] = 'r';
    state->board[0][1] = state->board[0][6] = 'n';
    state->board[0][2] = state->board[0][5] = 'b';
    state->board[0][3] = 'q';
    state->board[0][4] = 'k';
    state->board[7][0] = state->board[7][7] = 'R';
    state->board[7][1] = state->board[7][6] = 'N';
    state->board[7][2] = state->board[7][5] = 'B';
    state->board[7][3] = 'Q';
    state->board[7][4] = 'K';
    for (int i = 0; i < BOARD_SIZE; i++) {
        state->board[1][i] = 'p';
        state->board[6][i] = 'P';
    }
}

void printBoard(GameState *state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", state->board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

bool isCheck(GameState *state) {
    // This function determines if the current player is in check
    // and sets the isCheck flag in the state accordingly
    Position kingPos;
    char opposingPieces[6] = {'p', 'n', 'b', 'r', 'q', 'k'};
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == state->pieces[0]) {
                kingPos = (Position){i, j};
                break;
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == state->pieces[1]) {
                Position opposingPiece = (Position){i, j};
                if (isValidMove(state, opposingPiece, kingPos)) {
                    state->isCheck = true;
                    return true;
                }
            }
        }
    }
    state->isCheck = false;
    return false;
}

bool isGameOver(GameState *state) {
    // This function determines if the game is over due to checkmate or stalemate
    bool hasValidMove = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == state->pieces[0]) {
                for (int x = 0; x < BOARD_SIZE; x++) {
                    for (int y = 0; y < BOARD_SIZE; y++) {
                        if (isValidMove(state, (Position){i, j}, (Position){x, y})) {
                            hasValidMove = true;
                            goto break_all;  // use goto to break out of nested loops
                        }
                    }
                }
            }
        }
    }
    break_all:
    if (!hasValidMove) {
        if (state->isCheck) {
            printf("Checkmate. %c wins!\n", state->turn == 'w' ? 'b' : 'w');
        } else {
            printf("Stalemate. Game over!\n");
        }
        return true;
    }
    return false;
}

bool isValidMove(GameState *state, Position start, Position end) {
    if (start.row < 0 || start.row >= BOARD_SIZE ||
        start.col < 0 || start.col >= BOARD_SIZE ||
        end.row < 0 || end.row >= BOARD_SIZE ||
        end.col < 0 || end.col >= BOARD_SIZE) {
        return false;
    }
    if (start.row == end.row && start.col == end.col) {
        return false;
    }
    char piece = state->board[start.row][start.col];
    if (piece == '.') {
        return false;
    }
    char destPiece = state->board[end.row][end.col];
    if (isupper(piece) == isupper(destPiece)) {
        return false;
    }
    bool isValid = false;
    switch (piece) {
        case 'p':
        case 'P':
            // check pawn moves
            int dir = (piece == 'p') ? 1 : -1;
            if (start.col == end.col && destPiece == '.') {
                if (end.row - start.row == dir) {
                    isValid = true;
                } else if (start.row == ((piece == 'p') ? 1 : 6) &&
                           end.row - start.row == 2 * dir &&
                           state->board[start.row + dir][start.col] == '.') {
                    isValid = true;
                }
            } else if (abs(start.col - end.col) == 1 &&
                       end.row - start.row == dir &&
                       islower(destPiece) != islower(piece)) {
                isValid = true;
            }
            break;
        case 'n':
        case 'N':
            // check knight moves
            if (abs(start.row - end.row) + abs(start.col - end.col) == 3 &&
                abs(start.row - end.row) != 0 && abs(start.col - end.col) != 0) {
                isValid = true;
            }
            break;
        case 'b':
        case 'B':
            // check bishop moves
            if (abs(start.row - end.row) == abs(start.col - end.col)) {
                int i = start.row < end.row ? 1 : -1,
                    j = start.col < end.col ? 1 : -1;
                for (int x = start.row + i, y = start.col + j;
                     x != end.row && y != end.col;
                     x += i, y += j) {
                    if (state->board[x][y] != '.') {
                        return false;
                    }
                }
                isValid = true;
            }
            break;
        case 'r':
        case 'R':
            // check rook moves
            if (start.row == end.row || start.col == end.col) {
                int i = start.row == end.row ? 0 : (start.row < end.row ? 1 : -1),
                    j = start.col == end.col ? 0 : (start.col < end.col ? 1 : -1),
                    x = start.row + i, y = start.col + j;
                while (x != end.row || y != end.col) {
                    if (state->board[x][y] != '.') {
                        return false;
                    }
                    x += i; y += j;
                }
                isValid = true;
            }
            break;
        case 'q':
        case 'Q':
            // check queen moves
            if (abs(start.row - end.row) == abs(start.col - end.col) ||
                start.row == end.row || start.col == end.col) {
                int i = abs(start.row - end.row) > 1 ? (start.row < end.row ? 1 : -1) : 0,
                    j = abs(start.col - end.col) > 1 ? (start.col < end.col ? 1 : -1) : 0,
                    x = start.row + i, y = start.col + j;
                while (x != end.row || y != end.col) {
                    if (state->board[x][y] != '.') {
                        return false;
                    }
                    x += i; y += j;
                }
                isValid = true;
            }
            break;
        case 'k':
        case 'K':
            // check king moves
            if (abs(start.row - end.row) <= 1 && abs(start.col - end.col) <= 1) {
                isValid = true;
            }
            break;
    }
    if (isValid) {
        GameState nextState = *state;
        performMove(&nextState, start, end);
        return !isCheck(&nextState);
    }
    return false;
}

bool performMove(GameState *state, Position start, Position end) {
    char piece = state->board[start.row][start.col];
    state->board[end.row][end.col] = piece;
    state->board[start.row][start.col] = '.';
    if (piece == 'K') {
        state->pieces[0] = 'k';
    } else if (piece == 'k') {
        state->pieces[0] = 'K';
    }
    state->turn = (state->turn == 'w') ? 'b' : 'w';
    return true;
}

int main() {
    GameState state = {
        .board = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                  {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                  {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                  {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}},
        .turn = 'w',
        .isCheck = false,
        .pieces = {'K', 'k'}
    };
    initBoard(&state);
    while (!isGameOver(&state)) {
        printBoard(&state);
        printf("%c's turn: ", state.turn);
        char startCol, endCol;
        int startRow, endRow;
        scanf(" %c%d %c%d", &startCol, &startRow, &endCol, &endRow);
        Position start = (Position){BOARD_SIZE - startRow, startCol - 'a'},
                 end = (Position){BOARD_SIZE - endRow, endCol - 'a'};
        if (isValidMove(&state, start, end)) {
            performMove(&state, start, end);
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}