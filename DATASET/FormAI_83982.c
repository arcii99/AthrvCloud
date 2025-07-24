//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

enum Player {X, O, NONE};
enum Player game_board[3][3];
int num_moves = 0, curr_player = X, winner = NONE, x_wins = 0, o_wins = 0;

// Check if there is a winner
void check_win(){
    for(int i = 0; i < 3; i++){
        if((game_board[i][0] == game_board[i][1]) && (game_board[i][1] == game_board[i][2]))
            winner = game_board[i][0];
        if((game_board[0][i] == game_board[1][i]) && (game_board[1][i] == game_board[2][i]))
            winner = game_board[0][i];
    }
    if((game_board[0][0] == game_board[1][1]) && (game_board[1][1] == game_board[2][2]))
        winner = game_board[0][0];
    else if((game_board[0][2] == game_board[1][1]) && (game_board[1][1] == game_board[2][0]))
        winner = game_board[0][2];
    if(winner == X){
        x_wins++;
        printf("X wins!");
    }
    else if(winner == O){
        o_wins++;
        printf("O wins!");
    }
}

// Return whether the game is over
int is_game_over(){
    if(winner != NONE)
        return 1;
    if(num_moves == 9){
        printf("Draw!");
        return 1;
    }
    return 0;
}

// Write the current state of the game board
void print_board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", game_board[i][j] == NONE ? '_' : (game_board[i][j] == X ? 'X' : 'O'));
        }
        printf("\n");
    }
}

// Handle a move sent by a client
void handle_move(int row, int col){
    if(game_board[row][col] != NONE){
        printf("Invalid Move!\n");
    }
    else{
        game_board[row][col] = curr_player;
        num_moves++;
        print_board();
        check_win();
        curr_player = curr_player == X ? O : X;
    }
}

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            game_board[i][j] = NONE;
        }
    }
    while(!is_game_over()){
        // Listen for moves from connected clients and handle them
    }
}