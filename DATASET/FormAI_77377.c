//FormAI DATASET v1.0 Category: Chess AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX 8
 
int chessBoard[MAX][MAX];
 
struct move {
    int x, y;
};
 
int isSafe(int row, int col) {
    int i, j;
    for(i=0; i<row; i++)
        if(chessBoard[i][col])
            return 0;
 
    for(i=row, j=col; i>=0 && j>=0; i--, j--)
        if(chessBoard[i][j])
            return 0;
 
    for(i=row, j=col; i>=0 && j<MAX; i--, j++)
        if(chessBoard[i][j])
            return 0;
 
    return 1;
}
 
void printBoard() {
    int i, j;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++)
            printf("%d ", chessBoard[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
int solve(int row) {
    if(row == MAX) {
        printBoard();
        return 1;
    }
 
    int i;
    int result = 0;
    for(i=0; i<MAX; i++) {
        if(isSafe(row, i)) {
            chessBoard[row][i] = 1;
            result = solve(row+1) || result;
            chessBoard[row][i] = 0;
        }
    }
 
    return result;
}
 
int main() {
    srand(time(NULL));
    int i, j, queenCount = 0;
 
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            int r = rand() % 100;
            if(r < 25 && queenCount < 8) {
                chessBoard[i][j] = 1;
                queenCount++;
            }
        }
    }
 
    printf("The Initial chess board is:\n");
    printBoard();
 
    if(!solve(0))
        printf("Solution does not exist!\n");
 
    return 0;
}