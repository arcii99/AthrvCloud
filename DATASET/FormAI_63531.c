//FormAI DATASET v1.0 Category: Chess engine ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BoardSize 8    // Board size constant

int chessboard[BoardSize][BoardSize] = {0};
int knightMoves[8][2] = {{-1,-2}, {-2,-1}, {1,-2}, {2,-1}, {1,2}, {2,1}, {-1,2}, {-2,1}};   // Knight's possible moves
int knightCount = 0;    // Count of squares visited
int movesWithoutCapture = 0;    // Count of consecutive moves without a capture

// Function to print the chessboard
void printBoard(){
    for(int i=0;i<BoardSize;i++){
        for(int j=0;j<BoardSize;j++){
            printf("%d ",chessboard[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int isValid(int x, int y){
    if(x>=0 && x<BoardSize && y>=0 && y<BoardSize && chessboard[x][y] == 0)
        return 1;
    return 0;
}

// Function to check if there are no moves left
int noMovesLeft(int x, int y){
    for(int i=0;i<8;i++){
        int xNew = x + knightMoves[i][0];
        int yNew = y + knightMoves[i][1];
        if(isValid(xNew, yNew))
            return 0;
    }
    return 1;
}

// Function to simulate the knight's tour
void knightTour(int x, int y){
    chessboard[x][y] = ++knightCount;
    if(noMovesLeft(x, y))
        return;
    int nextIndex = -1;
    int minMoves = BoardSize;   // Initializing to an upper bound
    for(int i=0;i<8;i++){
        int xNew = x + knightMoves[i][0];
        int yNew = y + knightMoves[i][1];
        if(isValid(xNew, yNew)){
            int moves = 0;
            for(int j=0;j<8;j++){
                int xNext = xNew + knightMoves[j][0];
                int yNext = yNew + knightMoves[j][1];
                if(isValid(xNext, yNext))
                    moves++;
            }
            if(moves<minMoves){
                minMoves = moves;
                nextIndex = i;
            }
        }
    }
    int xNext = x + knightMoves[nextIndex][0];
    int yNext = y + knightMoves[nextIndex][1];
    knightTour(xNext, yNext);
}

int main(){
    srand(time(NULL));
    int x = rand()%BoardSize;
    int y = rand()%BoardSize;
    printf("Starting position: (%d,%d)\n",x,y);
    knightTour(x,y);
    printf("\nFinal board:\n");
    printBoard();
    printf("\nSquares visited: %d\n",knightCount);
    return 0;
}