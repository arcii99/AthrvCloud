//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>

#define PLAYER_X 1
#define PLAYER_O 2
#define EMPTY 0

int board[3][3];

void printBoard() {
    printf("\n-------------\n");
    for(int i = 0; i < 3; i++) {
        printf("| ");
        for(int j = 0; j < 3; j++) {
            printf("%c | ",board[i][j]==EMPTY ? ' ' : board[i][j]==PLAYER_X ? 'X' : 'O');
        }
        printf("\n-------------\n");
    }
}

int checkWinner() {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return board[i][0];
        }
    }
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return board[0][i];
        }
    }
    // Check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return board[0][0];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return board[0][2];
    }
    // Check for tie
    int count = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j]!=EMPTY){
                count++;
            }
        }
    }
    if(count==9){
        return -1;
    }
    return 0;
}

int getAIMove() {
    // Check for winning move
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j]==EMPTY) {
                board[i][j] = PLAYER_O;
                if(checkWinner()==PLAYER_O){
                    board[i][j] = EMPTY;
                    return i*3+j;
                }
                board[i][j] = EMPTY;
            }
        }
    }
    // Check for blocking move
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j]==EMPTY) {
                board[i][j] = PLAYER_X;
                if(checkWinner()==PLAYER_X){
                    board[i][j] = EMPTY;
                    return i*3+j;
                }
                board[i][j] = EMPTY;
            }
        }
    }
    // Pick any available spot
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j]==EMPTY) {
                return i*3+j;
            }
        }
    }
    return -1;
}

int main() {
    printf("\nWelcome to AI Tic Tac Toe!\n\n");
    printf("The board is numbered as follows:\n");
    printf(" 1 | 2 | 3 \n");
    printf("-----------\n");
    printf(" 4 | 5 | 6 \n");
    printf("-----------\n");
    printf(" 7 | 8 | 9 \n\n");
    printf("You are X and AI is O\n\n");
    int turn = PLAYER_X;
    int winner = 0;
    while(winner==0) {
        if(turn==PLAYER_X) {
            int move = -1;
            while(move<0 || move>8 || board[move/3][move%3]!=EMPTY) {
                printf("Enter move (1-9): ");
                scanf("%d",&move);
                move--;
            }
            board[move/3][move%3] = PLAYER_X;
        } else {
            printf("AI is thinking...\n");
            int move = getAIMove();
            board[move/3][move%3] = PLAYER_O;
        }
        printBoard();
        winner = checkWinner();
        turn = (turn==PLAYER_X ? PLAYER_O : PLAYER_X);
    }
    if(winner==-1) {
        printf("\nGame over. It's a tie!\n");
    } else {
        printf("\nGame over. %c wins!\n",(winner==PLAYER_X ? 'X' : 'O'));
    }
    return 0;
}