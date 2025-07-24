//FormAI DATASET v1.0 Category: Chess AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Coords;

typedef struct {
    char value;
    char color;
} Piece;

typedef struct {
    Piece *board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} GameState;

void renderBoard(GameState *state) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] != NULL) {
                printf("%c ", state->board[i][j]->value);
            }
            else {
                printf(". ");
            }
        }
        printf("%d\n", BOARD_SIZE - i);
    }
    printf("  a b c d e f g h\n");
}

void initGame(GameState *state) {
    state->turn = 'w';
    memset(state->board, 0, sizeof(state->board));

    state->board[0][0] = malloc(sizeof(Piece));
    state->board[0][0]->value = 'r';
    state->board[0][0]->color = 'b';

    state->board[0][7] = malloc(sizeof(Piece));
    state->board[0][7]->value = 'r';
    state->board[0][7]->color = 'b';

    state->board[0][1] = malloc(sizeof(Piece));
    state->board[0][1]->value = 'n';
    state->board[0][1]->color = 'b';

    state->board[0][6] = malloc(sizeof(Piece));
    state->board[0][6]->value = 'n';
    state->board[0][6]->color = 'b';

    state->board[0][2] = malloc(sizeof(Piece));
    state->board[0][2]->value = 'b';
    state->board[0][2]->color = 'b';

    state->board[0][5] = malloc(sizeof(Piece));
    state->board[0][5]->value = 'b';
    state->board[0][5]->color = 'b';

    state->board[0][3] = malloc(sizeof(Piece));
    state->board[0][3]->value = 'q';
    state->board[0][3]->color = 'b';

    state->board[0][4] = malloc(sizeof(Piece));
    state->board[0][4]->value = 'k';
    state->board[0][4]->color = 'b';

    for (int j = 0; j < BOARD_SIZE; j++) {
        state->board[1][j] = malloc(sizeof(Piece));
        state->board[1][j]->value = 'p';
        state->board[1][j]->color = 'b';
    }

    state->board[7][0] = malloc(sizeof(Piece));
    state->board[7][0]->value = 'r';
    state->board[7][0]->color = 'w';

    state->board[7][7] = malloc(sizeof(Piece));
    state->board[7][7]->value = 'r';
    state->board[7][7]->color = 'w';

    state->board[7][1] = malloc(sizeof(Piece));
    state->board[7][1]->value = 'n';
    state->board[7][1]->color = 'w';

    state->board[7][6] = malloc(sizeof(Piece));
    state->board[7][6]->value = 'n';
    state->board[7][6]->color = 'w';

    state->board[7][2] = malloc(sizeof(Piece));
    state->board[7][2]->value = 'b';
    state->board[7][2]->color = 'w';

    state->board[7][5] = malloc(sizeof(Piece));
    state->board[7][5]->value = 'b';
    state->board[7][5]->color = 'w';

    state->board[7][3] = malloc(sizeof(Piece));
    state->board[7][3]->value = 'q';
    state->board[7][3]->color = 'w';

    state->board[7][4] = malloc(sizeof(Piece));
    state->board[7][4]->value = 'k';
    state->board[7][4]->color = 'w';

    for (int j = 0; j < BOARD_SIZE; j++) {
        state->board[6][j] = malloc(sizeof(Piece));
        state->board[6][j]->value = 'p';
        state->board[6][j]->color = 'w';
    }
}

void destroyGame(GameState *state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] != NULL) {
                free(state->board[i][j]);
            }
        }
    }
}

Coords parseCoords(char *coords) {
    Coords c;
    c.x = BOARD_SIZE - (coords[1] - '0');
    c.y = coords[0] - 'a';
    return c;
}

char getOpponent(char color) {
    if (color == 'w') {
        return 'b';
    }
    return 'w';
}

int isBoardEmpty(GameState *state, int x, int y) {
    return state->board[x][y] == NULL;
}

int isSquareOccupiedByOpponent(GameState *state, int x, int y, char opponent) {
    if (!isBoardEmpty(state, x, y) && state->board[x][y]->color == opponent) {
        return 1;
    }
    return 0;
}

int isSquareOccupiedByFriendly(GameState *state, int x, int y, char friendly) {
    if (!isBoardEmpty(state, x, y) && state->board[x][y]->color == friendly) {
        return 1;
    }
    return 0;
}

int canMove(GameState *state, char color, Coords source, Coords dest) {
    int dx = dest.x - source.x;
    int dy = dest.y - source.y;

    Piece *piece = state->board[source.x][source.y];

    if (piece == NULL || piece->color != color) {
        return 0;
    }

    char opponent = getOpponent(color);

    switch (piece->value) {
        case 'p':
            if (color == 'w') {
                if (dx == -1 && dy == 0 && isBoardEmpty(state, dest.x, dest.y)) {
                    return 1;
                }
                if (dx == -2 && dy == 0 && source.x == 6 && isBoardEmpty(state, dest.x, dest.y) && isBoardEmpty(state, source.x - 1, source.y)) {
                    return 1;
                }
                if (dx == -1 && (dy == -1 || dy == 1) && isSquareOccupiedByOpponent(state, dest.x, dest.y, opponent)) {
                    return 1;
                }
            }
            else if (color == 'b') {
                if (dx == 1 && dy == 0 && isBoardEmpty(state, dest.x, dest.y)) {
                    return 1;
                }
                if (dx == 2 && dy == 0 && source.x == 1 && isBoardEmpty(state, dest.x, dest.y) && isBoardEmpty(state, source.x + 1, source.y)) {
                    return 1;
                }
                if (dx == 1 && (dy == -1 || dy == 1) && isSquareOccupiedByOpponent(state, dest.x, dest.y, opponent)) {
                    return 1;
                }
            }
            break;
        case 'r':
            if (dx == 0 || dy == 0) {
                int inc = dx == 0 ? dy / abs(dy) : dx / abs(dx);
                int i = source.x + inc, j = source.y + inc;
                while (i != dest.x || j != dest.y) {
                    if (!isBoardEmpty(state, i, j)) {
                        return 0;
                    }
                    i += inc;
                    j += inc;
                }
                if (isSquareOccupiedByOpponent(state, dest.x, dest.y, opponent)) {
                    return 1;
                }
            }
            break;
        case 'n':
            if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
                if (!isSquareOccupiedByFriendly(state, dest.x, dest.y, color)) {
                    return 1;
                }
            }
            break;
        case 'b':
            if (abs(dx) == abs(dy)) {
                int inc_x = dx / abs(dx);
                int inc_y = dy / abs(dy);
                int i = source.x + inc_x, j = source.y + inc_y;
                while (i != dest.x || j != dest.y) {
                    if (!isBoardEmpty(state, i, j)) {
                        return 0;
                    }
                    i += inc_x;
                    j += inc_y;
                }
                if (isSquareOccupiedByOpponent(state, dest.x, dest.y, opponent)) {
                    return 1;
                }
            }
            break;
        case 'q':
            if (abs(dx) == abs(dy) || dx == 0 || dy ==0) {
                int inc_x = dx > 0 ? 1 : (dx < 0 ? -1 : 0);
                int inc_y = dy > 0 ? 1 : (dy < 0 ? -1 : 0);
                int i = source.x + inc_x, j = source.y + inc_y;
                while (i != dest.x || j != dest.y) {
                    if (!isBoardEmpty(state, i, j)) {
                        return 0;
                    }
                    i += inc_x;
                    j += inc_y;
                }
                if (isSquareOccupiedByOpponent(state, dest.x, dest.y, opponent)) {
                    return 1;
                }
            }
            break;
        case 'k':
            if (abs(dx) <= 1 && abs(dy) <= 1) {
                if (!isSquareOccupiedByFriendly(state, dest.x, dest.y, color)) {
                    return 1;
                }
            }
            break;
    }

    return 0;
}

int isKingInCheck(GameState *state, char color) {
    Coords kingCoords;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] != NULL && state->board[i][j]->value == 'k' && state->board[i][j]->color == color) {
                kingCoords.x = i;
                kingCoords.y = j;
            }
        }
    }

    char opponent = getOpponent(color);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] != NULL && state->board[i][j]->color == opponent) {
                if (canMove(state, opponent, (Coords) {.x = i, .y = j}, kingCoords)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int movePiece(GameState *state, Coords source, Coords dest) {
    if (state->board[source.x][source.y] == NULL) {
        return -1;
    }

    if (!canMove(state, state->turn, source, dest)) {
        return -2;
    }

    Piece *piece = state->board[source.x][source.y];
    state->board[dest.x][dest.y] = piece;
    state->board[source.x][source.y] = NULL;

    if (isKingInCheck(state, getOpponent(state->turn))) {
        state->board[source.x][source.y] = piece;
        state->board[dest.x][dest.y] = NULL;
        return -3;
    }

    state->turn = getOpponent(state->turn);
    return 1;
}

int main() {
    GameState state;

    initGame(&state);
    renderBoard(&state);

    while(1) {
        char input[256];
        printf("%c> ", state.turn);
        fgets(input, sizeof(input), stdin);
        if (strlen(input) >= 3 && input[2] == ' ') {
            Coords source = parseCoords(input);
            Coords dest = parseCoords(input + 3);
            int result = movePiece(&state, source, dest);
            if (result == 1) {
                renderBoard(&state);
            }
            else {
                switch (result) {
                    case -1: printf("Invalid move: source square is empty.\n"); break;
                    case -2: printf("Invalid move: piece cannot move to destination square.\n"); break;
                    case -3: printf("Invalid move: your king is in check.\n"); break;
                }
            }
        }
        else {
            printf("Invalid input.\n");
        }
    }

    destroyGame(&state);
    return 0;
}