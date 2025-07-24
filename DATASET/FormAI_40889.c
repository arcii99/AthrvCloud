//FormAI DATASET v1.0 Category: Checkers Game ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'

char board[8][8] = { 
    { '-', 'W', '-', 'W', '-', 'W', '-', 'W' },
    { 'W', '-', 'W', '-', 'W', '-', 'W', '-' },
    { '-', 'W', '-', 'W', '-', 'W', '-', 'W' },
    { EMPTY, '-', EMPTY, '-', EMPTY, '-', EMPTY, '-' },
    { '-', EMPTY, '-', EMPTY, '-', EMPTY, '-', EMPTY },
    { 'B', '-', 'B', '-', 'B', '-', 'B', '-' },
    { '-', 'B', '-', 'B', '-', 'B', '-', 'B' },
    { 'B', '-', 'B', '-', 'B', '-', 'B', '-' }
};

int gameOver() {
    int i, j, whiteCount = 0, blackCount = 0;
    for(i=0;i<8;++i) {
        for(j=0;j<8;++j) {
            if(board[i][j] == WHITE) whiteCount++;
            else if(board[i][j] == BLACK) blackCount++;
        }
    }
    return (whiteCount == 0 || blackCount == 0);
}

void render() {
    int i, j;
    printf("  |A|B|C|D|E|F|G|H|\n");
    printf("  -----------------\n");
    for(i=0;i<8;++i) {
        printf("%d ", i+1);
        printf("|");
        for(j=0;j<8;++j) {
            printf("%c|", board[i][j]);
        }
        printf("%d", i+1);
        printf("\n");
    }
    printf("  -----------------\n");
    printf("  |A|B|C|D|E|F|G|H|\n");
}

int isLegalMove(int startX, int startY, int desX, int desY, char player) {
    if(board[desY][desX] != EMPTY) {
        return 0;
    }
    if(player == BLACK) { // black player moves upside
        if(startX == desX+2 && startY == desY+2) { // capturing move left going upwards
            if(board[startY-1][startX-1] == WHITE) {
                return 1;
            }
        }
        if(startX == desX-2 && startY == desY+2) { // capturing move right going upwards
            if(board[startY-1][startX+1] == WHITE) {
                return 1;
            }
        }
        if(startX == desX+2 && startY == desY-2) { // non-capturing move left going upwards
            return 1;
        }
        if(startX == desX-2 && startY == desY-2) { // non-capturing move right going upwards
            return 1;
        }
    } else { // white player moves downwards
        if(startX == desX+2 && startY == desY-2) { // capturing move left going downwards
            if(board[startY+1][startX-1] == BLACK) {
                return 1;
            }
        }
        if(startX == desX-2 && startY == desY-2) { // capturing move right going downwards
            if(board[startY+1][startX+1] == BLACK) {
                return 1;
            }
        }
        if(startX == desX+2 && startY == desY+2) { // non-capturing move left going downwards
            return 1;
        }
        if(startX == desX-2 && startY == desY+2) { // non-capturing move right going downwards
            return 1; 
        }
    }
    return 0;
}

void movePiece(int startX, int startY, int desX, int desY) {
    char temp = board[startY][startX];
    board[startY][startX] = EMPTY;
    board[desY][desX] = temp;
    if(startX == desX+2 || startX == desX-2) { // capturing move
        int midX = (startX+desX)/2, midY = (startY+desY)/2;
        board[midY][midX] = EMPTY;
    }
}

int takeTurn(char player) {
    printf("Player: %c\n", player);
    int startX, startY, desX, desY;
    printf("Enter current position (ex: A3): ");
    scanf("%d", &startY);
    startX = getchar() - 'A';
    printf("Enter destination position (ex: B4): ");
    scanf("%d", &desY);
    desX = getchar() - 'A';
    if(startX>=0&&startX<=7&&startY>=0&&startY<=7&&desX>=0&&desX<=7&&desY>=0&&desY<=7) {
        if(isLegalMove(startX, startY, desX, desY, player)) {
            movePiece(startX, startY, desX, desY);
            return 1;
        } else {
            printf("Illegal move.\n");
            return 0;
        }
    } else {
        printf("Invalid input.\n");
        return 0;
    }
}

int main() {
    printf("Welcome to C Checkers Game\n");
    int turnCount = 0;
    render();
    char currentPlayer = BLACK;
    while(!gameOver()) {
        printf("\nTurn %d\n", ++turnCount);
        render();
        if(!takeTurn(currentPlayer)) continue;
        if(currentPlayer == BLACK) currentPlayer = WHITE;
        else currentPlayer = BLACK;
    }
    render();
    printf("Game Over. %c player wins!\n", currentPlayer);
    return 0;
}