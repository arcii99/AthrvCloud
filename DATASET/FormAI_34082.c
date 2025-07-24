//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void printBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("| %c |",board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char symbol){
    if(board[0][0]==symbol && board[0][1]==symbol && board[0][2]==symbol)
        return 1;
    if(board[1][0]==symbol && board[1][1]==symbol && board[1][2]==symbol)
        return 1;
    if(board[2][0]==symbol && board[2][1]==symbol && board[2][2]==symbol)
        return 1;
    if(board[0][0]==symbol && board[1][0]==symbol && board[2][0]==symbol)
        return 1;
    if(board[0][1]==symbol && board[1][1]==symbol && board[2][1]==symbol)
        return 1;
    if(board[0][2]==symbol && board[1][2]==symbol && board[2][2]==symbol)
        return 1;
    if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol)
        return 1;
    if(board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol)
        return 1;
    return 0;
}

int getScore(char symbol){
    if(checkWin(symbol))
        return 10;
    else if(checkWin(symbol=='X' ? 'O' : 'X'))
        return -10;
    else
        return 0;
}

int minimax(int depth, int isMax, char symbol){
    int score = getScore(symbol);
    if(score==10)
        return score-depth;
    if(score==-10)
        return score+depth;
    if(depth==9)
        return 0;

    if(isMax){
        int bestScore = -1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j] = symbol;
                    int sc = minimax(depth+1,!isMax,symbol=='X' ? 'O' : 'X');
                    board[i][j] = ' ';
                    if(sc>bestScore)
                        bestScore = sc;
                }
            }
        }
        return bestScore;
    }
    else{
        int bestScore = 1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j] = symbol;
                    int sc = minimax(depth+1,!isMax,symbol=='X' ? 'O' : 'X');
                    board[i][j] = ' ';
                    if(sc<bestScore)
                        bestScore = sc;
                }
            }
        }
        return bestScore;
    }
}

int* getBestMove(char symbol){
    int row = -1,col = -1;
    int bestScore = -1000;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j] = symbol;
                int score = minimax(0,0,symbol=='X' ? 'O' : 'X');
                board[i][j] = ' ';
                if(score>bestScore){
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    int mv[2] = {row,col};
    return mv;
}

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }

    srand(time(NULL));
    int first = rand()%2;

    printf("You are X\n");
    printf("Computer is O\n");

    if(first==1){
        int r = rand()%3,c = rand()%3;
        board[r][c] = 'O';
    }

    printBoard();

    while(1){
        int r,c;
        printf("Enter row and column(separator space): ");
        scanf("%d %d",&r,&c);
        if(board[r-1][c-1]!=' '){
            printf("Invalid move\n");
            continue;
        }
        board[r-1][c-1] = 'X';
        if(checkWin('X')){
            printf("You win!\n");
            printBoard();
            break;
        }
        int* mv = getBestMove('O');
        board[mv[0]][mv[1]] = 'O';
        if(checkWin('O')){
            printf("Computer wins!\n");
            printBoard();
            break;
        }
        printBoard();
    }

    return 0;
}