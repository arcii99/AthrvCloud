//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 10

int board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    printf("\n\n");
    printf("\t\tA B C D E F G H I J\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("\t\t");
        for(int j=0; j<BOARD_SIZE; j++) {
            if(j==0) {
                printf("%d", i+1);
            }
            if(board[i][j] == 0) {
                printf(" ~");
            }
            else if(board[i][j] == 1) {
                printf(" X");
            }
            else if(board[i][j] == 2) {
                printf(" O");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int isValid(int x, int y) {
    if(x < 0 || x > BOARD_SIZE-1 || y < 0 || y > BOARD_SIZE-1) {
        return 0;
    }
    return 1;
}

void playerMove(int *x, int *y) {
    printf("\nEnter your move (row[1-10] column[A-J]): ");
    char col;
    scanf("%d %c", x, &col);
    *x = *x - 1;
    *y = col - 'A';
    while(!isValid(*x, *y) || board[*x][*y] != 0) {
        printf("\nInvalid move. Please enter a valid move: ");
        scanf("%d %c", x, &col);
        *x = *x - 1;
        *y = col - 'A';
    }
}

void computerMove(int *x, int *y) {
    srand(time(0));
    *x = rand() % BOARD_SIZE;
    *y = rand() % BOARD_SIZE;
    while(board[*x][*y] != 0) {
        *x = rand() % BOARD_SIZE;
        *y = rand() % BOARD_SIZE;
    }
}

int isGameOver() {
    int xCount = 0, oCount = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 1) {
                xCount++;
            }
            else if(board[i][j] == 2) {
                oCount++;
            }
        }
    }
    if(xCount == BOARD_SIZE*BOARD_SIZE || oCount == BOARD_SIZE*BOARD_SIZE) {
        return 1;
    }
    return 0;
}

int isWinner(int player) {
    int count;
    //check rows
    for(int i=0; i<BOARD_SIZE; i++) {
        count = 0;
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }
    //check columns
    for(int i=0; i<BOARD_SIZE; i++) {
        count = 0;
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[j][i] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }
    //check diagonal from top left to bottom right
    count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][i] == player) {
            count++;
        }
    }
    if(count == BOARD_SIZE) {
        return 1;
    }
    //check diagonal from top right to bottom left
    count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][BOARD_SIZE-1-i] == player) {
            count++;
        }
    }
    if(count == BOARD_SIZE) {
        return 1;
    }
    return 0;
}

int main() {
    initializeBoard();
    int playerX = 0, playerY = 0, computerX = 0, computerY = 0;
    int currentPlayer = 1;
    while(!isGameOver()) {
        printBoard();
        if(currentPlayer == 1) {
            playerMove(&playerX, &playerY);
            board[playerX][playerY] = 1;
            if(isWinner(1)) {
                printf("\nYou win!\n");
                return 0;
            }
            currentPlayer = 2;
        }
        else {
            computerMove(&computerX, &computerY);
            board[computerX][computerY] = 2;
            if(isWinner(2)) {
                printf("\nYou lose!\n");
                return 0;
            }
            currentPlayer = 1;
        }
    }
    printBoard();
    printf("\nTie game!\n");
    return 0;
}