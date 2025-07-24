//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef enum { BLACK, WHITE } Player;

typedef struct {
    int x;
    int y;
} Move;

typedef struct {
    Player player;
    int king;
} Piece;

#define BOARD_SIZE 8

Piece board[BOARD_SIZE][BOARD_SIZE];
Player currentPlayer = BLACK;

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j].player = BLACK;
                    board[i][j].king = 0;
                } else if (i > 4) {
                    board[i][j].player = WHITE;
                    board[i][j].king = 0;
                }
            }
        }
    }
}

void printBoard() {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                char symbol = ' ';
                if (board[i][j].player == BLACK) {
                    symbol = board[i][j].king ? 'B' : 'b';
                } else if (board[i][j].player == WHITE) {
                    symbol = board[i][j].king ? 'W' : 'w';
                }
                printf("%c ", symbol);
            } else {
                printf("  ");
            }
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n\n");
}

int isMoveValid(Player player, Move move) {
    if (move.x < 0 || move.x > 7 || move.y < 0 || move.y > 7) {
        return 0;
    }
    if ((move.y + move.x) % 2 != 0) {
        return 0;
    }
    if (board[move.y][move.x].player != -1) {
        return 0;
    }
    int dx = move.x - player;
    int dy = move.y - player;
    if (abs(dx) == 1 && dy == player) {
        return 1;
    }
    if (abs(dx) == 2 && dy == player * 2) {
        int jumpX = (player + move.x) / 2;
        int jumpY = (player + move.y) / 2;
        if (board[jumpY][jumpX].player != -1 && board[jumpY][jumpX].player != player) {
            return 1;
        }
    }
    return 0;
}

int canPlayerJump(Player player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].player == player) {
                Move move1 = {j + 2, i + player * 2};
                if (isMoveValid(player, move1)) {
                    return 1;
                }
                Move move2 = {j - 2, i + player * 2};
                if (isMoveValid(player, move2)) {
                    return 1;
                }
                if (board[i][j].king) {
                    Move move3 = {j + 2, i - player * 2};
                    if (isMoveValid(player, move3)) {
                        return 1;
                    }
                    Move move4 = {j - 2, i - player * 2};
                    if (isMoveValid(player, move4)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void makeMove(Move move) {
    Piece piece = board[currentPlayer][move.x];
    board[currentPlayer][move.x].player = -1;
    board[currentPlayer][move.x].king = 0;
    board[currentPlayer][move.y] = piece;
    if (currentPlayer == BLACK && move.y == 0) {
        board[currentPlayer][move.y].king = 1;
    }
    if (currentPlayer == WHITE && move.y == 7) {
        board[currentPlayer][move.y].king = 1;
    }
    if (abs(move.x - move.y) == 2) {
        int jumpX = (move.x + move.y) / 2;
        int jumpY = (currentPlayer == BLACK ? 0 : BOARD_SIZE - 1) - (abs(move.x - jumpX) - 1) / 2;
        board[jumpY][jumpX].player = -1;
        board[jumpY][jumpX].king = 0;
        if (!canPlayerJump(currentPlayer)) {
            currentPlayer = (currentPlayer == BLACK ? WHITE : BLACK);
        }
    } else {
        currentPlayer = (currentPlayer == BLACK ? WHITE : BLACK);
    }
}

int isGameFinished() {
    int blackPieces = 0;
    int whitePieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (board[i][j].player == BLACK) {
                    blackPieces++;
                } else if (board[i][j].player == WHITE) {
                    whitePieces++;
                }
            }
        }
    }
    return (blackPieces == 0 || whitePieces == 0);
}

int getWinner() {
    int blackPieces = 0;
    int whitePieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (board[i][j].player == BLACK) {
                    blackPieces++;
                } else if (board[i][j].player == WHITE) {
                    whitePieces++;
                }
            }
        }
    }
    if (blackPieces > whitePieces) {
        return BLACK;
    } else if (whitePieces > blackPieces) {
        return WHITE;
    } else {
        return -1;
    }
}

void play() {
    initBoard();
    while (!isGameFinished()) {
        printBoard();
        printf("%s player's turn.\n", (currentPlayer == BLACK ? "Black" : "White"));
        Move move;
        printf("Enter origin column and row:\n");
        scanf("%d %d", &move.x, &move.y);
        printf("Enter destination column and row:\n");
        scanf("%d %d", &move.x, &move.y);
        if (isMoveValid(currentPlayer, move) || canPlayerJump(currentPlayer)) {
            makeMove(move);
        } else {
            printf("Invalid move!\n");
        }
    }
    printBoard();
    int winner = getWinner();
    if (winner == -1) {
        printf("It's a tie!");
    } else {
        printf("%s player wins!", (winner == BLACK ? "Black" : "White"));
    }
}

int main() {
    play();
    return 0;
}