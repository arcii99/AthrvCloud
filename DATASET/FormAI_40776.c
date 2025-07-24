//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int SIZE = 3;

void display_board(char board[SIZE][SIZE]){
    printf("\n");
    for(int i=0;i<SIZE;i++){
        printf("\t\t");
        for(int j=0;j<SIZE;j++){
            printf(" %c ", board[i][j]);
            if(j<SIZE-1)
                printf("|");
        }
        printf("\n");
        if(i<SIZE-1){
            printf("\t\t---------\n");
        }
    }
    printf("\n");
}

bool is_valid_move(char board[SIZE][SIZE], int row, int col){
    if(row>=0 && row<SIZE && col>=0 && col<SIZE){
        if(board[row][col] == '-'){
            return true;
        }
    }
    return false;
}

bool is_game_over(char board[SIZE][SIZE], char player){
    //check rows
    for(int i=0;i<SIZE;i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
    }
    
    //check columns
    for(int i=0;i<SIZE;i++){
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
    
    //check diagonal
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    
    //check if board is full
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j] == '-'){
                return false;
            }
        }
    }
    return true;
}

int minimax(char board[SIZE][SIZE], bool is_max, int depth, char player, char ai_player, char human_player){
    if(is_game_over(board, ai_player)){
        return 10;
    }
    
    if(is_game_over(board, human_player)){
        return -10;
    }
    
    if(depth == 0){
        return 0;
    }
    
    int best_score, current_score;
    
    if(is_max){
        best_score = -1000;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(board[i][j] == '-'){
                    board[i][j] = ai_player;
                    current_score = minimax(board, !is_max, depth-1, player, ai_player, human_player);
                    if(current_score > best_score){
                        best_score = current_score;
                    }
                    board[i][j] = '-';
                }
            }
        }
    }
    else{
        best_score = 1000;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(board[i][j] == '-'){
                    board[i][j] = human_player;
                    current_score = minimax(board, !is_max, depth-1, player, ai_player, human_player);
                    if(current_score < best_score){
                        best_score = current_score;
                    }
                    board[i][j] = '-';
                }
            }
        }
    }
    
    return best_score;
}

void ai_move(char board[SIZE][SIZE], char ai_player, char human_player){
    int best_score = -1000;
    int row, col;
    
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j] == '-'){
                board[i][j] = ai_player;
                int current_score = minimax(board, false, SIZE*SIZE, ai_player, ai_player, human_player);
                if(current_score > best_score){
                    best_score = current_score;
                    row = i;
                    col = j;
                }
                board[i][j] = '-';
            }
        }
    }
    
    board[row][col] = ai_player;
    printf("\nAI player (\'%c\') has made a move.\n", ai_player);
    display_board(board);
}

void human_move(char board[SIZE][SIZE], char human_player){
    int row, col;
    
    do{
        printf("\nHuman player (\'%c\') enter row and column number to make a move: ", human_player);
        scanf("%d %d", &row, &col);
        if(!is_valid_move(board,row-1,col-1)){
            printf("\nThe position is already occupied or invalid.\n");
        }
    }while(!is_valid_move(board,row-1,col-1));
    
    board[row-1][col-1] = human_player;
    display_board(board);
}

void play_game(char board[SIZE][SIZE], char player1, char player2){
    display_board(board);
    
    while(!is_game_over(board, player1) && !is_game_over(board, player2)){
        if(player1 == 'X'){
            ai_move(board, player1, player2);
            if(is_game_over(board, player1)){
                printf("\nAI player wins!\n");
                return;
            }
            human_move(board, player2);
            if(is_game_over(board, player2)){
                printf("\nHuman player wins!\n");
                return;
            }
        }
        else{
            human_move(board, player1);
            if(is_game_over(board, player1)){
                printf("\nHuman player wins!\n");
                return;
            }
            ai_move(board, player2, player1);
            if(is_game_over(board, player2)){
                printf("\nAI player wins!\n");
                return;
            }
        }
    }
    printf("\nIt's a tie!\n");
}

int main(){
    char board[SIZE][SIZE];
    char player1, player2;
    srand(time(NULL));
    int random_num = rand()%2;
    
    if(random_num == 0){
        player1 = 'X';
        player2 = 'O';
        printf("\nAI player (\'%c\') goes first.", player1);
    }
    else{
        player1 = 'O';
        player2 = 'X';
        printf("\nHuman player (\'%c\') goes first.", player1);
    }
    
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board[i][j] = '-';
        }
    }
    
    play_game(board, player1, player2);
    
    return 0;
}