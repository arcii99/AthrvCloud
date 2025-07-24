//FormAI DATASET v1.0 Category: Chess AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void makeMove(char board[][8], char *move);
int minimax(char board[][8], int depth, int alpha, int beta, int maximizingPlayer);
int evaluateBoard(char board[][8]);

int main()
{
    char board[8][8] = {{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
                        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
                        { '\0', '.', '\0', '.', '\0', '.', '\0', '.' },
                        { '.', '\0', '.', '\0', '.', '\0', '.', '\0' },
                        { '\0', '.', '\0', '.', '\0', '.', '\0', '.' },
                        { '.', '\0', '.', '\0', '.', '\0', '.', '\0' },
                        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
                        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }};

    char move[5];
    makeMove(board, move);
    printf("Chosen move: %s\n", move);

    return 0;
}

// function to make the best move using minimax algorithm
void makeMove(char board[][8], char *move)
{
    int bestValue = -10000;
    char start[3], end[3];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] > '\0' && board[i][j] < 'Z') { // white piece
                switch (board[i][j]) {
                    case 'K':
                        strcpy(start, "e1");
                        break;
                    case 'Q':
                        strcpy(start, "d1");
                        break;
                    case 'R':
                        if (j == 0 || (j > 0 && board[i][j-1] != '.')) {
                            strcpy(start, "a1");
                        } else {
                            strcpy(start, "h1");
                        }
                        break;
                    case 'B':
                        if ((i == 0 && j == 1) || (i == 0 && j == 6) || (i == 7 && j == 1) || (i == 7 && j == 6)) {
                            strcpy(start, "c1");
                        } else {
                            strcpy(start, "f1");
                        }
                        break;
                    case 'N':
                        if (j == 1 || j == 6) {
                            strcpy(start, "b1");
                        } else {
                            strcpy(start, "g1");
                        }
                        break;
                    case 'P':
                        sprintf(start, "%c%d", j + 'a', i + 2);
                        break;
                }
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (board[x][y] == '.') { // empty square
                            sprintf(end, "%c%d", y + 'a', x + 1);
                            char temp = board[x][y];
                            board[x][y] = board[i][j];
                            board[i][j] = '.';
                            int value = minimax(board, 3, -10000, 10000, 0);
                            if (value > bestValue) {
                                bestValue = value;
                                sprintf(move, "%s-%s", start, end);
                            }
                            board[i][j] = board[x][y];
                            board[x][y] = temp;
                        }
                    }
                }
            }
        }
    }
}

// minimax function with alpha-beta pruning
int minimax(char board[][8], int depth, int alpha, int beta, int maximizingPlayer)
{
    if (depth == 0) {
        return evaluateBoard(board);
    }
    if (maximizingPlayer) {
        int max = -10000;
        char start[3], end[3];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] > '\0' && board[i][j] < 'Z') { // white piece
                    switch (board[i][j]) {
                        case 'K':
                            strcpy(start, "e1");
                            break;
                        case 'Q':
                            strcpy(start, "d1");
                            break;
                        case 'R':
                            if (j == 0 || (j > 0 && board[i][j-1] != '.')) {
                                strcpy(start, "a1");
                            } else {
                                strcpy(start, "h1");
                            }
                            break;
                        case 'B':
                            if ((i == 0 && j == 1) || (i == 0 && j == 6) || (i == 7 && j == 1) || (i == 7 && j == 6)) {
                                strcpy(start, "c1");
                            } else {
                                strcpy(start, "f1");
                            }
                            break;
                        case 'N':
                            if (j == 1 || j == 6) {
                                strcpy(start, "b1");
                            } else {
                                strcpy(start, "g1");
                            }
                            break;
                        case 'P':
                            sprintf(start, "%c%d", j + 'a', i + 2);
                            break;
                    }
                    for (int x = 0; x < 8; x++) {
                        for (int y = 0; y < 8; y++) {
                            if (board[x][y] == '.') { // empty square
                                sprintf(end, "%c%d", y + 'a', x + 1);
                                char temp = board[x][y];
                                board[x][y] = board[i][j];
                                board[i][j] = '.';
                                int value = minimax(board, depth - 1, alpha, beta, 0);
                                if (value > max) {
                                    max = value;
                                }
                                if (max > alpha) {
                                    alpha = max;
                                }
                                board[i][j] = board[x][y];
                                board[x][y] = temp;
                                if (alpha >= beta) {
                                    return max;
                                }
                            }
                        }
                    }
                }
            }
        }
        return max;
    } else {
        int min = 10000;
        char start[3], end[3];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] > 'a' && board[i][j] < 'z') { // black piece
                    switch (board[i][j]) {
                        case 'k':
                            strcpy(start, "e8");
                            break;
                        case 'q':
                            strcpy(start, "d8");
                            break;
                        case 'r':
                            if (j == 0 || (j > 0 && board[i][j-1] != '.')) {
                                strcpy(start, "a8");
                            } else {
                                strcpy(start, "h8");
                            }
                            break;
                        case 'b':
                            if ((i == 0 && j == 1) || (i == 0 && j == 6) || (i == 7 && j == 1) || (i == 7 && j == 6)) {
                                strcpy(start, "c8");
                            } else {
                                strcpy(start, "f8");
                            }
                            break;
                        case 'n':
                            if (j == 1 || j == 6) {
                                strcpy(start, "b8");
                            } else {
                                strcpy(start, "g8");
                            }
                            break;
                        case 'p':
                            sprintf(start, "%c%d", j + 'a', i + 2);
                            break;
                    }
                    for (int x = 0; x < 8; x++) {
                        for (int y = 0; y < 8; y++) {
                            if (board[x][y] == '.') { // empty square
                                sprintf(end, "%c%d", y + 'a', x + 1);
                                char temp = board[x][y];
                                board[x][y] = board[i][j];
                                board[i][j] = '.';
                                int value = minimax(board, depth - 1, alpha, beta, 1);
                                if (value < min) {
                                    min = value;
                                }
                                if (min < beta) {
                                    beta = min;
                                }
                                board[i][j] = board[x][y];
                                board[x][y] = temp;
                                if (alpha >= beta) {
                                    return min;
                                }
                            }
                        }
                    }
                }
            }
        }
        return min;
    }
}

// function to evaluate the board for the minimax algorithm
int evaluateBoard(char board[][8])
{
    int value = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (board[i][j]) {
                case 'K':
                    value += 1000;
                    break;
                case 'k':
                    value -= 1000;
                    break;
                case 'Q':
                    value += 9;
                    break;
                case 'q':
                    value -= 9;
                    break;
                case 'R':
                    value += 5;
                    break;
                case 'r':
                    value -= 5;
                    break;
                case 'B':
                    value += 3;
                    break;
                case 'b':
                    value -= 3;
                    break;
                case 'N':
                    value += 3;
                    break;
                case 'n':
                    value -= 3;
                    break;
                case 'P':
                    value += 1;
                    break;
                case 'p':
                    value -= 1;
                    break;
            }
        }
    }
    return value;
}