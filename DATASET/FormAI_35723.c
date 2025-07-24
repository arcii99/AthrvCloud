//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include<stdio.h>

//Function to check if anyone wins the game
int checkWin(char board[3][3]){
    //Checking rows
    for(int i=0;i<3;i++){
        if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X')
            return 1;
        if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')
            return 2;
    }
    //Checking columns
    for(int i=0;i<3;i++){
        if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')
            return 1;
        if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')
            return 2;
    }
    //Checking diagonals
    if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
        return 1;
    if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')
        return 2;
    if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
        return 1;
    if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
        return 2;
    //If no one wins yet
    return 0;
}

//Function to display the current state of board
void displayBoard(char board[3][3]){
    printf("\n");
    for(int i=0;i<3;i++){
        printf("\t\t\t\t");
        for(int j=0;j<3;j++){
            printf("%c",board[i][j]);
            if(j!=2)
                printf(" | ");
        }
        printf("\n");
        if(i!=2)
            printf("\t\t\t\t---------\n");
    }
    printf("\n");
}

//Function to get computer's next move
void computerMove(char board[3][3]){
    //Easy level AI - random move
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j]='O';
                displayBoard(board);
                return;
            }
        }
    }
}

//Function to get user's next move
void userMove(char board[3][3]){
    int row,column;
    printf("\nEnter the row and column number to put your 'X' (row column): ");
    scanf("%d %d",&row,&column);
    //Checking if the row and column inputs are within 1-3 range
    if(row<1 || row>3 || column<1 || column>3){
        printf("Invalid row or column, please enter again.\n");
        userMove(board);
        return;
    }
    //Checking if the spot is already occupied
    if(board[row-1][column-1]!=' '){
        printf("Spot already occupied, please enter again.\n");
        userMove(board);
        return;
    }
    board[row-1][column-1]='X';
    displayBoard(board);
}

int main(){
    //Initializing board
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int result=0;
    printf("\n\n\t\t\tWelcome to Tic Tac Toe Game!\n\n");
    printf("\t\t\t     1   2   3\n");
    printf("\t\t\t   -------------\n");
    for(int i=0;i<3;i++){
        printf("\t\t\t%d  ",i+1);
        for(int j=0;j<3;j++){
            printf("| %c ",board[i][j]);
        }
        printf("|\n");
        printf("\t\t\t   -------------\n");
    }
    printf("\n");
    //Starting game
    while(result==0){
        printf("Computer's turn (O):\n");
        computerMove(board);
        result=checkWin(board);
        if(result!=0)
            break;
        printf("Your turn (X):\n");
        userMove(board);
        result=checkWin(board);
    }
    //Displaying winner
    printf("\n\n");
    if(result==1)
        printf("\t\t\tYou Lost! Better luck next time.\n\n");
    else
        printf("\t\t\tCongratulations! You Won!\n\n");

    return 0;
}