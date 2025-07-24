//FormAI DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>

#define SIZE 8

int board[SIZE][SIZE];

void initBoard();
void printBoard();
int makeMove(int player, int x1, int y1, int x2, int y2);
int isPiece(int x, int y);
int isLegal(int player, int x1, int y1, int x2, int y2);
int isJump(int player, int x1, int y1, int x2, int y2);
int numPieces(int player);
int canMove(int player);

int main() {
    int player = 1; // player 1 starts
    initBoard();
    printBoard();
    while(1) {
        int x1, y1, x2, y2;
        printf("Player %d\n", player);
        printf("Enter piece position x y: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter destination position x y: ");
        scanf("%d %d", &x2, &y2);
        if(!makeMove(player, x1, y1, x2, y2)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        printf("-----------------------------\n");
        printBoard();
        if(numPieces(player) == 0) {
            printf("Player %d wins!\n", player == 1 ? 2 : 1);
            break;
        }
        if(!canMove(player)) {
            printf("Player %d cannot move. Player %d wins!\n", player, player == 1 ? 2 : 1);
            break;
        }
        if(isJump(player, x2, y2, x2+2, y2+2)) {
            printf("Jump possible. ");
            while(isJump(player, x2, y2, x2+2, y2+2)) {
                printf("Enter jump position: ");
                scanf("%d %d", &x1, &y1);
                x2 = x2+2;
                y2 = y2+2;
            }
        }
        player = player == 1 ? 2 : 1; // switch players
    }
    return 0;
}

void initBoard() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if((i+j) % 2 == 0 && i < 3) {
                board[i][j] = 1;
            }
            else if((i+j) % 2 == 0 && i > 4) {
                board[i][j] = 2;
            }
            else {
                board[i][j] = 0;
            }
        }
    }
}

void printBoard() {
    printf("   ");
    for(int i=1; i<=SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  +");
    for(int i=0; i<SIZE; i++) {
        printf("-+");
    }
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d |", i+1);
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == 1) {
                printf("O|");
            }
            else if(board[i][j] == 2) {
                printf("X|");
            }
            else {
                printf(" |");
            }
        }
        printf("\n");
        printf("  +");
        for(int i=0; i<SIZE; i++) {
            printf("-+");
        }
        printf("\n");
    }
}

int makeMove(int player, int x1, int y1, int x2, int y2) {
    if(!isLegal(player, x1-1, y1-1, x2-1, y2-1)) {
        return 0;
    }
    board[x2-1][y2-1] = board[x1-1][y1-1];
    board[x1-1][y1-1] = 0;
    if(isJump(player, x2-1, y2-1, x2+2-1, y2+2-1)) { // additional jump possible
        board[x2+1-1][y2+1-1] = 0;
    }
    return 1;
}

int isPiece(int x, int y) {
    return board[x][y] != 0;
}

int isLegal(int player, int x1, int y1, int x2, int y2) {
    if(x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || isPiece(x2, y2)) {
        return 0;
    }
    if(board[x1][y1] != player && board[x1][y1] != player + 2) {
        return 0;
    }
    if(abs(x2 - x1) == 1) { // regular move
        if(player == 1 && board[x1][y1] == 1 && x2 < x1) {
            return 0;
        }
        if(player == 2 && board[x1][y1] == 2 && x2 > x1) {
            return 0;
        }
        return 1;
    }
    else if(abs(x2 - x1) == 2) { // jump move
        if(player == 1 && board[x1][y1] == 1 && x2 < x1) {
            return 0;
        }
        if(player == 2 && board[x1][y1] == 2 && x2 > x1) {
            return 0;
        }
        int jumpX = (x1 + x2) / 2;
        int jumpY = (y1 + y2) / 2;
        if(board[jumpX][jumpY] != (player == 1 ? 2 : 1) && board[jumpX][jumpY] != (player == 1 ? 4 : 3)) {
            return 0;
        }
        return 1;
    }
    else {
        return 0;
    }
}

int isJump(int player, int x1, int y1, int x2, int y2) {
    if(!isLegal(player, x1, y1, x2, y2)) {
        return 0;
    }
    if(abs(x2 - x1) == 2) {
        return 1;
    }
    if(isJump(player, x1, y1, x2+1, y2+1) || isJump(player, x1, y1, x2+1, y2-1) || isJump(player, x1, y1, x2-1, y2-1) || isJump(player, x1, y1, x2-1, y2+1)) {
        return 1;
    }
    return 0;
}

int numPieces(int player) {
    int num = 0;
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == player || board[i][j] == player + 2) {
                num++;
            }
        }
    }
    return num;
}

int canMove(int player) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == player || board[i][j] == player + 2) {
                if(isJump(player, i, j, i+2, j+2) || isJump(player, i, j, i+2, j-2) || isJump(player, i, j, i-2, j+2) || isJump(player, i, j, i-2, j-2)) {
                    return 1;
                }
                else if(isLegal(player, i, j, i+1, j+1) || isLegal(player, i, j, i+1, j-1) || isLegal(player, i, j, i-1, j+1) || isLegal(player, i, j, i-1, j-1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}