//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#define SIZE 8
#define RED 'R'
#define BLACK 'B'
#define EMPTY '-'

void initializeBoard(char board[][SIZE]);
void displayBoard(char board[][SIZE]);
int checkMoveValidity(char board[][SIZE], int startX, int startY, int endX, int endY, char playerPiece);
int checkEndGame(char board[][SIZE]);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    displayBoard(board);
    int startX, startY, endX, endY, moveValidity;
    char playerPiece = RED;
    while(1) {
        printf("It's %c Player's Turn!\n", playerPiece);
        printf("Enter the starting position (x,y): ");
        scanf("%d,%d", &startX, &startY);
        printf("Enter the ending position (x,y): ");
        scanf("%d,%d", &endX, &endY);
        moveValidity = checkMoveValidity(board, startX, startY, endX, endY, playerPiece);
        if(moveValidity) {
            board[startX][startY] = EMPTY;
            board[endX][endY] = playerPiece;
            displayBoard(board);
            if(checkEndGame(board)) {
                printf("Congratulations %c Player, You Won!\n", playerPiece);
                break;
            }
            if(playerPiece == RED)
                playerPiece = BLACK;
            else
                playerPiece = RED;
        }
        else {
            printf("Invalid Move, Please Try Again!\n");
        }
    }
    return 0;
}

void initializeBoard(char board[][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(i < 3 && (i+j)%2 == 0)
                board[i][j] = BLACK;
            else if(i > 4 && (i+j)%2 == 0)
                board[i][j] = RED;
            else
                board[i][j] = EMPTY;
        }
    }
}

void displayBoard(char board[][SIZE]) {
    int i, j;
    printf("\n   0 1 2 3 4 5 6 7\n\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d  ", i);
        for(j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkMoveValidity(char board[][SIZE], int startX, int startY, int endX, int endY, char playerPiece) {
    if(board[startX][startY] != playerPiece || board[endX][endY] != EMPTY)
        return 0;
    if(playerPiece == RED && endX >= startX)
        return 0;
    if(playerPiece == BLACK && endX <= startX)
        return 0;
    int dx = endX - startX > 0 ? 1 : -1;
    int dy = endY - startY > 0 ? 1 : -1;
    int numSteps = abs(endX - startX);
    if(abs(endX - startX) != abs(endY - startY))
        return 0;
    if(numSteps == 1 && abs(endY - startY) == 1)
        return 1;
    int i;
    for(i = 1; i < numSteps; i++) {
        if(board[startX + i*dx][startY + i*dy] != EMPTY)
            return 0;
    }
    if(numSteps > 2) {
        int midX = (startX + endX)/2;
        int midY = (startY + endY)/2;
        if(board[midX][midY] != (playerPiece == RED ? BLACK : RED))
            return 0;
    }
    return 1;
}

int checkEndGame(char board[][SIZE]) {
    int i, j, redCount = 0, blackCount = 0;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[i][j] == RED)
                redCount++;
            else if(board[i][j] == BLACK)
                blackCount++;
        }
    }
    if(redCount == 0 || blackCount == 0)
        return 1;
    return 0;
}