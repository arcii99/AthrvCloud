//FormAI DATASET v1.0 Category: Chess AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
 
// function to print the board
void print_board(char chessboard[8][8]){
    int i, j;
    for(i = 0; i < 8; i++){
        printf("\n");
        for(j = 0; j < 8; j++){
            printf("%c ", chessboard[i][j]);
        }
    }
    printf("\n");
}
 
// function to initialize the board
void initialize_board(char chessboard[8][8]){
    int i, j;
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i == 0){
                chessboard[i][j] = pieces[j];
            }
            else if(i == 1){
                chessboard[i][j] = 'P';
            }
            else if(i == 6){
                chessboard[i][j] = 'p';
            }
            else if(i == 7){
                chessboard[i][j] = pieces[j] + 32;
            }
            else{
                chessboard[i][j] = '-';
            }
        }
    }
}
 
// function to make a move
void make_move(char chessboard[8][8], int init_x, int init_y, int final_x, int final_y){
    chessboard[final_x][final_y] = chessboard[init_x][init_y];
    chessboard[init_x][init_y] = '-';
}
 
// function to check if a move is valid
int is_valid_move(char chessboard[8][8], int init_x, int init_y, int final_x, int final_y){
    if(init_x == final_x && init_y == final_y){
        return 0;
    }
    if(chessboard[init_x][init_y] == '-'){
        return 0;
    }
    char piece = chessboard[init_x][init_y];
    if(piece == 'P'){
        if(init_x == 6){
            if(init_y == final_y && init_x - final_x == 1 && chessboard[final_x][final_y] == '-'){
                return 1;
            }
            else if(init_y == final_y && init_x - final_x == 2 && chessboard[final_x][final_y] == '-'
            && chessboard[final_x + 1][final_y] == '-'){
                return 1;
            }
            else if(abs(init_y - final_y) == 1 && init_x - final_x == 1 && 
            (chessboard[final_x][final_y] != '-' && chessboard[final_x][final_y] < 'a')){
                return 1;
            }
        }
        else{
            if(init_y == final_y && init_x - final_x == 1 && chessboard[final_x][final_y] == '-'){
                return 1;
            }
            else if(abs(init_y - final_y) == 1 && init_x - final_x == 1 && 
            (chessboard[final_x][final_y] != '-' && chessboard[final_x][final_y] < 'a')){
                return 1;
            }
        }
    }
    if(piece == 'p'){
        if(init_x == 1){
            if(init_y == final_y && final_x - init_x == 1 && chessboard[final_x][final_y] == '-'){
                return 1;
            }
            else if(init_y == final_y && final_x - init_x == 2 && chessboard[final_x][final_y] == '-'
            && chessboard[final_x - 1][final_y] == '-'){
                return 1;
            }
            else if(abs(init_y - final_y) == 1 && final_x - init_x == 1 && 
            (chessboard[final_x][final_y] != '-' && chessboard[final_x][final_y] >= 'a')){
                return 1;
            }
        }
        else{
            if(init_y == final_y && final_x - init_x == 1 && chessboard[final_x][final_y] == '-'){
                return 1;
            }
            else if(abs(init_y - final_y) == 1 && final_x - init_x == 1 && 
            (chessboard[final_x][final_y] != '-' && chessboard[final_x][final_y] >= 'a')){
                return 1;
            }
        }
    }
    return 0;
}
 
// function to check if the game is over
int is_game_over(char chessboard[8][8]){
    // check if any king is killed
    int i, j;
    int white_king_dead = 1;
    int black_king_dead = 1;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(chessboard[i][j] == 'K'){
                white_king_dead = 0;
            }
            if(chessboard[i][j] == 'k'){
                black_king_dead = 0;
            }
        }
    }
    if(white_king_dead == 1){
        return 1;
    }
    if(black_king_dead == 1){
        return 2;
    }
    return 0;
}
 
// main function
int main(){
    char chessboard[8][8];
    initialize_board(chessboard);
    int game_over = 0;
    int turn = 1; // 1: white, 2: black
    int init_x, init_y, final_x, final_y;
    char input[5];
    while(game_over == 0){
        printf("\n\n");
        if(turn == 1){
            printf("White's turn:\n");
        }
        else{
            printf("Black's turn:\n");
        }
        print_board(chessboard);
        printf("Enter move (e.g. 'e2e4'): ");
        scanf("%s", input);
        init_y = input[0] - 'a';
        init_x = abs(input[1] - '0' - 8);
        final_y = input[2] - 'a';
        final_x = abs(input[3] - '0' - 8);
        if(is_valid_move(chessboard, init_x, init_y, final_x, final_y)){
            make_move(chessboard, init_x, init_y, final_x, final_y);
            game_over = is_game_over(chessboard);
            if(game_over == 1){
                printf("\nWhite wins!\n");
                print_board(chessboard);
            }
            else if(game_over == 2){
                printf("\nBlack wins!\n");
                print_board(chessboard);
            }
            else{
                turn = turn == 1 ? 2 : 1;
            }
        }
        else{
            printf("\nInvalid move! Try again.\n");
        }
    }
    return 0;
}