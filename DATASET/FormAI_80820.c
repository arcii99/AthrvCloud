//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    int x;
    int y;
} Point;

// Initializes the board
void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else if (i < 3) {
                board[i][j] = 'b';
            } else if (i > 4) {
                board[i][j] = 'w';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Outputs the board to the console
void printBoard(char board[SIZE][SIZE]) {
    printf("\n  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d ", i);
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Determines if the move is valid
int isValidMove(char board[SIZE][SIZE], Point start, Point end) {
    if (end.x < 0 || end.x >= SIZE || end.y < 0 || end.y >= SIZE || board[end.x][end.y] != ' ') {
        return 0;
    }

    if (abs(start.x - end.x) == 1 && abs(start.y - end.y) == 1) {
        return 1;
    }

    if (abs(start.x - end.x) == 2 && abs(start.y - end.y) == 2) {
        Point middle = {(start.x + end.x) / 2, (start.y + end.y) / 2};
        if (board[middle.x][middle.y] == (board[start.x][start.y] == 'w' ? 'b' : 'w')) {
            return 1;
        }
    }

    return 0;
}

// Moves a piece on the board
void move(char board[SIZE][SIZE], Point start, Point end) {
    board[end.x][end.y] = board[start.x][start.y];
    board[start.x][start.y] = ' ';
}

// Determines if a player is blocked (unable to make any moves)
int isBlocked(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == player) {
                Point start = {i, j};
                Point end1 = {i - 1, j + 1};
                Point end2 = {i - 1, j - 1};
                Point end3 = {i + 1, j + 1};
                Point end4 = {i + 1, j - 1};
                if (isValidMove(board, start, end1) || isValidMove(board, start, end2) || isValidMove(board, start, end3) || isValidMove(board, start, end4)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Determines if the game has ended
int isGameOver(char board[SIZE][SIZE]) {
    int wCount = 0, bCount = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'w' || board[i][j] == 'W') {
                wCount++;
            } else if (board[i][j] == 'b' || board[i][j] == 'B') {
                bCount++;
            }
        }
    }
    if (wCount == 0 || bCount == 0 || isBlocked(board, 'w') || isBlocked(board, 'b')) {
        return 1;
    }
    return 0;
}

// Promotes a piece to a king when it reaches the end of the board
void promote(char board[SIZE][SIZE], Point p) {
    if (board[p.x][p.y] == 'w' && p.x == 0) {
        board[p.x][p.y] = 'W';
    } else if (board[p.x][p.y] == 'b' && p.x == SIZE - 1) {
        board[p.x][p.y] = 'B';
    }
}

// Gets the human player's move
void getHumanMove(char board[SIZE][SIZE], Point* start, Point* end) {
    char buffer[10];
    do {
        printf("Enter your move (starting point, space, then ending point): ");
        fgets(buffer, 10, stdin);
        sscanf(buffer, "%d %d %d %d", &start->x, &start->y, &end->x, &end->y);
    } while (!isValidMove(board, *start, *end));
}

// Gets the CPU's move (randomly)
void getCPUMove(char board[SIZE][SIZE], Point* start, Point* end) {
    do {
        start->x = rand() % SIZE;
        start->y = rand() % SIZE;
        end->x = rand() % SIZE;
        end->y = rand() % SIZE;
    } while (!isValidMove(board, *start, *end));
}

int main() {
    char board[SIZE][SIZE];
    Point start, end;
    int turn = 0;

    initBoard(board);
    printBoard(board);

    while (!isGameOver(board)) {
        if (turn % 2 == 0) {
            getHumanMove(board, &start, &end);
        } else {
            getCPUMove(board, &start, &end);
        }
        move(board, start, end);
        promote(board, end);
        printBoard(board);
        turn++;
    }

    printf("Game over!\n");
    if (isBlocked(board, 'w') || isBlocked(board, 'W')) {
        printf("Black wins!\n");
    } else if (isBlocked(board, 'b') || isBlocked(board, 'B')) {
        printf("White wins!\n");
    } else if (isGameOver(board)) {
        int wCount = 0, bCount = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 'w' || board[i][j] == 'W') {
                    wCount++;
                } else if (board[i][j] == 'b' || board[i][j] == 'B') {
                    bCount++;
                }
            }
        }
        if (wCount > bCount) {
            printf("White wins!\n");
        } else if (bCount > wCount) {
            printf("Black wins!\n");
        } else {
            printf("It's a tie!\n");
        }
    }

    return 0;
}