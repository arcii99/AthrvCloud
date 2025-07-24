//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Initialize the game
void init(char board[][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}

// Display the board
void display(char board[][3]){
    int i;
    printf("   1 2 3\n");
    for(i=0;i<3;i++){
        printf("%d  ",i+1);
        printf("%c|%c|%c\n", board[i][0], board[i][1], board[i][2]);
        if(i<2){
            printf("  -----\n");
        }
    }
}

// Get the player's move
void player_move(char board[][3]){
    int row, col;
    printf("Enter the row number (1-3) where you want to place your mark: ");
    scanf("%d",&row);
    printf("Enter the column number (1-3) where you want to place your mark: ");
    scanf("%d",&col);
    if(board[row-1][col-1] == ' '){
        board[row-1][col-1] = 'X';
    }
    else{
        printf("Invalid move!\n");
        player_move(board);
    }
}

// Get the computer's move
void computer_move(char board[][3]){
    int row, col;
    srand(time(NULL));
    row = rand()%3;
    col = rand()%3;
    if(board[row][col] == ' '){
        board[row][col] = 'O';
    }
    else{
        computer_move(board);
    }
}

// Check if there is a winner
char check_winner(char board[][3]){
    int i;
    for(i=0;i<3;i++){
        if(board[i][0]!= ' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return board[i][0];
        }
        if(board[0][i]!= ' ' && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return board[0][i];
        }
    }
    if(board[0][0]!= ' ' && board[0][0]==board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2]!= ' ' && board[0][2]==board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }
    return ' ';
}

// Main function
int main(){
    char board[3][3];
    char winner = ' ';
    printf("*** Welcome to Tic Tac Toe ***\n");
    printf("You are playing against the computer.\n");
    printf("Player = X, Computer = O\n");
    init(board);
    display(board);
    while(winner == ' '){
        player_move(board);
        display(board);
        winner = check_winner(board);
        if(winner != ' '){
            break;
        }
        printf("Computer's move:\n");
        computer_move(board);
        display(board);
        winner = check_winner(board);
    }
    if(winner == 'X'){
        printf("You win!\n");
    }
    else if(winner == 'O'){
        printf("Computer wins!\n");
    }
    else{
        printf("Draw!\n");
    }
    return 0;
}