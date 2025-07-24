//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#define BOARD_SIZE 8

void printBoard(char board[][BOARD_SIZE]) {
    // Prints the current state of the board
    printf("   ");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j=0; j<BOARD_SIZE; j++) {
            printf("| %c", board[i][j]);
        }
        printf("|\n");
    }
}

int isvalid(int x, int y) {
    // Determines if a move is valid
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return 0;
    }
    if (x % 2 == y % 2) {
        return 0;
    }
    return 1;
}

int canCapture(char board[][BOARD_SIZE], int x, int y) {
    // Determines if a piece can capture an opponent's piece
    if (board[x][y] == 'X' || board[x][y] == 'x') {
        if (isvalid(x-2, y-2) && (board[x-1][y-1] == 'O' || board[x-1][y-1] == 'o') && board[x-2][y-2] == ' ') {
            return 1;
        }
        if (isvalid(x-2, y+2) && (board[x-1][y+1] == 'O' || board[x-1][y+1] == 'o') && board[x-2][y+2] == ' ') {
            return 1;
        }
    } else {
        if (isvalid(x+2, y-2) && (board[x+1][y-1] == 'X' || board[x+1][y-1] == 'x') && board[x+2][y-2] == ' ') {
            return 1;
        }
        if (isvalid(x+2, y+2) && (board[x+1][y+1] == 'X' || board[x+1][y+1] == 'x') && board[x+2][y+2] == ' ') {
            return 1;
        }
    }
    return 0;
}

int canMove(char board[][BOARD_SIZE], int x, int y) {
    // Determines if a piece can move to an empty space
    if (board[x][y] == 'X' || board[x][y] == 'x') {
        if (isvalid(x-1, y-1) && board[x-1][y-1] == ' ') {
            return 1;
        }
        if (isvalid(x-1, y+1) && board[x-1][y+1] == ' ') {
            return 1;
        }
    } else {
        if (isvalid(x+1, y-1) && board[x+1][y-1] == ' ') {
            return 1;
        }
        if (isvalid(x+1, y+1) && board[x+1][y+1] == ' ') {
            return 1;
        }
    }
    return 0;
}

void capture(char board[][BOARD_SIZE], int x, int y) {
    // Removes an opponent's piece from the board after being captured
    if (board[x][y] == 'X' || board[x][y] == 'x') {
        if (board[x-1][y-1] == 'O' || board[x-1][y-1] == 'o') {
            board[x-1][y-1] = ' ';
        } else {
            board[x-1][y+1] = ' ';
        }
    } else {
        if (board[x+1][y-1] == 'X' || board[x+1][y-1] == 'x') {
            board[x+1][y-1] = ' ';
        } else {
            board[x+1][y+1] = ' ';
        }
    }
}

void makeMove(char board[][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    // Updates the board after a move has been made
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
    if (x2 == 0 || x2 == BOARD_SIZE-1) {
        board[x2][y2] = (board[x2][y2] == 'x' || board[x2][y2] == 'X') ? 'X' : 'O';
    }
    if (abs(x2-x1) == 2) {
        capture(board, (x1+x2)/2, (y1+y2)/2);
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
        {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
        {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
        {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '}
    };
    int player = 1;
    int x1, y1, x2, y2;
    while (1) {
        printBoard(board);
        printf("\n");
        if (player == 1) {
            printf("Player 1 (X) move: ");
        } else {
            printf("Player 2 (O) move: ");
        }
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (!isvalid(x1, y1) || !isvalid(x2, y2)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (player == 1 && (board[x1][y1] == 'O' || board[x1][y1] == 'o')) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (player == 2 && (board[x1][y1] == 'X' || board[x1][y1] == 'x')) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (board[x2][y2] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (abs(x2-x1) == 1 && !canMove(board, x1, y1)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (abs(x2-x1) == 2 && !canCapture(board, x1, y1)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        makeMove(board, x1, y1, x2, y2);
        player = (player == 1) ? 2 : 1;
    }
    return 0;
}