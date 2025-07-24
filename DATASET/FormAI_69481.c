//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display_board(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[3][3], char player){
    //checking rows
    for(int i=0;i<3;i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return 1;
        }
    }
    //checking columns
    for(int j=0;j<3;j++){
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player){
            return 1;
        }
    }
    //checking diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return 1;
    }
    return 0;
}

int mini_max(char board[3][3], int depth, int is_maximizing){
    if(check_win(board, 'O')){
        return 1;
    }
    if(check_win(board, 'X')){
        return -1;
    }
    if(depth == 0){
        return 0;
    }

    if(is_maximizing){
        int best_score = -1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'O';
                    int score = mini_max(board, depth-1, 0);
                    board[i][j] = '_';
                    if(score > best_score){
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
    else{
        int best_score = 1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'X';
                    int score = mini_max(board, depth-1, 1);
                    board[i][j] = '_';
                    if(score < best_score){
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

void computer_move(char board[3][3]){
    int best_score = -1000;
    int best_i,best_j;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == '_'){
                board[i][j] = 'O';
                int score = mini_max(board, 4, 0);
                board[i][j] = '_';
                if(score > best_score){
                    best_score = score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }
    board[best_i][best_j] = 'O';
}

int main(){
    char board[3][3] = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
    int turn = 0;

    printf("Dear Player, \n\n");
    printf("You have been on my mind for a while,\nAnd I thought we could spend some time and play Tic Tac Toe,\nJust you and me 🥰\n");
    printf("To begin, the empty board looks like:\n\n");
    display_board(board);
    printf("\n");

    while(1){
        if(turn%2 == 0){
            printf("It's your turn. Please enter row number (0-2) and column number (0-2) separated by a space:\n");
            int row,col;
            scanf("%d %d", &row, &col);
            if(board[row][col] != '_'){
                printf("Invalid move. That position is already taken. Please try again.\n");
                continue;
            }
            board[row][col] = 'X';
        }
        else{
            printf("My turn, I'll think...\n");
            computer_move(board);
        }

        printf("\nAfter this move, the board looks like:\n\n");
        display_board(board);
        printf("\n");

        if(check_win(board, 'X')){
            printf("You won! It was a pleasure playing with you <3\n");
            break;
        }
        if(check_win(board, 'O')){
            printf("I won! This was so much fun, we have to play again! 😘\n");
            break;
        }
        if(turn == 8){
            printf("The game is a tie, congrats on playing me to a draw!\n");
            break;
        }

        turn++;
    }

    return 0;
}