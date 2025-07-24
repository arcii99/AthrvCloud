//FormAI DATASET v1.0 Category: Checkers Game ; Style: distributed
#include <stdio.h>

// initialize the board with starting positions
void initializeBoard(int board[8][8]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i < 3 && (i+j)%2 == 0) board[i][j] = 1;
            else if(i > 4 && (i+j)%2 == 0) board[i][j] = -1;
            else board[i][j] = 0;
        }
    }
}

// print the current state of the board
void printBoard(int board[8][8]) {
    printf("    0 1 2 3 4 5 6 7\n");
    printf("   ---------------\n");
    for(int i = 0; i < 8; i++) {
        printf("%d | ", i);
        for(int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("| %d\n", i);
    }
    printf("   ---------------\n");
    printf("    0 1 2 3 4 5 6 7\n");
}

// check if a move is valid
int isValidMove(int player, int board[8][8], int startX, int startY, int endX, int endY) {
    if(player == board[startX][startY]) {
        if(board[endX][endY] == 0) {
            if(player == 1) {
                if(startX-1 == endX && (startY-1 == endY || startY+1 == endY)) return 1;
                if(startX-2 == endX && startY-2 == endY && board[startX-1][startY-1] == -1) return 1;
                if(startX-2 == endX && startY+2 == endY && board[startX-1][startY+1] == -1) return 1;
            } else {
                if(startX+1 == endX && (startY-1 == endY || startY+1 == endY)) return 1;
                if(startX+2 == endX && startY-2 == endY && board[startX+1][startY-1] == 1) return 1;
                if(startX+2 == endX && startY+2 == endY && board[startX+1][startY+1] == 1) return 1;
            }
        }
    }
    return 0;
}

// make the move on the board
void makeMove(int board[8][8], int startX, int startY, int endX, int endY) {
    int player = board[startX][startY];
    board[startX][startY] = 0;
    if(player == 1 && endX == 0) board[endX][endY] = 2;
    else if(player == -1 && endX == 7) board[endX][endY] = -2;
    else board[endX][endY] = player;
    if(abs(endX-startX) == 2 && abs(endY-startY) == 2) {
        board[startX + (endX-startX)/2][startY + (endY-startY)/2] = 0;
    }
}

int main() {
    int board[8][8];
    initializeBoard(board);
    printBoard(board);
    int player = 1;
    while(1) {
        int startX, startY, endX, endY, valid;
        printf("Player %d's turn\n", player);
        do {
            printf("Enter starting position (x,y): ");
            scanf("%d,%d", &startX, &startY);
            printf("Enter ending position (x,y): ");
            scanf("%d,%d", &endX, &endY);
            valid = isValidMove(player, board, startX, startY, endX, endY);
            if(!valid) printf("Invalid move!\n");
        } while(!valid);
        makeMove(board, startX, startY, endX, endY);
        printf("\n");
        printBoard(board);
        if(player == 1) player = -1;
        else player = 1;
    }
    return 0;
}