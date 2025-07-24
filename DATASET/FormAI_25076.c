//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to check if the input number is valid or not
int isValid(int x, int y, int choice, int n, char arr[]){
    if(x<1 || y<1 || x>n || y>n)
        return 0;
    if(choice==1){
        if(arr[(x-1)*n+y-1] == 'X' || arr[(x-1)*n+y-1] == 'O')
            return 0;
    }
    else if(choice==2){
        if(arr[(x-1)*n+y-1] == 'O')
            return 1;
        else
            return 0;
    }
    return 1;
}

// function to change the turn of the player
void changeTurn(int *turn){
    if(*turn == 1)
        *turn = 2;
    else
        *turn = 1;
}

// function to print the Tic Tac Toe board
void printBoard(int n, char arr[]){
    printf("\n");
    for(int i=1; i<=n*n; i++){
        printf(" %c ", arr[i-1]);
        if(i%n == 0)
            printf("\n\n");
        else
            printf("|");
    }
}

// function to check if there is a winner or the game is drawn
int checkWinner(int n, char arr[]){
    // checking rows
    for(int i=0; i<n*n; i+=n){
        if(arr[i]=='X' && arr[i+1]=='X' && arr[i+2]=='X')
            return 1;
        if(arr[i]=='O' && arr[i+1]=='O' && arr[i+2]=='O')
            return 2;
    }
    // checking columns
    for(int i=0; i<n; i++){
        if(arr[i]=='X' && arr[i+n]=='X' && arr[i+n*2]=='X')
            return 1;
        if(arr[i]=='O' && arr[i+n]=='O' && arr[i+n*2]=='O')
            return 2;
    }
    // checking diagonals
    if(arr[0]=='X' && arr[n+1]=='X' && arr[2*n+2]=='X')
        return 1;
    if(arr[0]=='O' && arr[n+1]=='O' && arr[2*n+2]=='O')
        return 2;
    if(arr[2]=='X' && arr[n+1]=='X' && arr[2*n]=='X')
        return 1;
    if(arr[2]=='O' && arr[n+1]=='O' && arr[2*n]=='O')
        return 2;
    // checking if the board is full
    for(int i=0; i<n*n; i++){
        if(arr[i] != 'X' && arr[i] != 'O')
            return 0;
    }
    return 3; // game is drawn
}

int main(){
    printf("Welcome to the Tic Tac Toe Game! \n\n");
    int n;
    printf("Enter the size of the board (minimum 3): ");
    scanf("%d", &n);
    char arr[n*n];
    for(int i=0; i<n*n; i++)
        arr[i] = '-';
    printBoard(n, arr);
    int turn = 1;
    while(1){
        int x, y;
        printf("Player %d, enter your move (x y): ", turn);
        scanf("%d %d", &x, &y);
        while(!isValid(x, y, 1, n, arr)){
            printf("Invalid move! Enter your move again (x y): ");
            scanf("%d %d", &x, &y);
        }
        if(turn == 1)
            arr[(x-1)*n+y-1] = 'X';
        else
            arr[(x-1)*n+y-1] = 'O';
        printBoard(n, arr);
        int result = checkWinner(n, arr);
        if(result == 1){
            printf("Player 1 has won the game! \n");
            break;
        }
        if(result == 2){
            printf("Player 2 has won the game! \n");
            break;
        }
        if(result == 3){
            printf("The game is drawn! \n");
            break;
        }
        changeTurn(&turn);
    }
    printf("Thank you for playing the Tic Tac Toe Game! \n");
    return 0;
}