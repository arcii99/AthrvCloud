//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* function to initialize the game board */
void init_game_board(char* board){
    for(int i=0;i<16;i++){
        board[i] = '+';
    }
}

/* function to print the game board */
void print_game_board(char* board){
    printf("  1 2 3 4\n");
    for(int i=0;i<4;i++){
        printf("%d ",i+1);
        for(int j=0;j<4;j++){
            printf("%c ",board[i*4+j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* function to shuffle the game board */
void shuffle_game_board(char* board){
    srand(time(0));
    int a,b;
    char temp;
    for(int i=0;i<50;i++){
        a = rand()%16;
        b = rand()%16;
        temp = board[a];
        board[a] = board[b];
        board[b] = temp;
    }
}

/* function to check if the game is over */
int is_game_over(char* board){
    for(int i=0;i<16;i++){
        if(board[i] == '+')
            return 0;
    }
    return 1;
}

/* function to get input from user */
void get_input(int* a, int* b){
    printf("Enter two positions to flip: ");
    scanf("%d %d",a,b);
    getchar();
    printf("\n");
}

/* function to flip the selected positions */
void flip_positions(char* board, int a, int b){
    char temp;
    a -= 1;
    b -= 1;
    temp = board[a*4+b];
    board[a*4+b] = board[b*4+a];
    board[b*4+a] = temp;
}

/* main function */
int main(){
    char game_board[16];
    int user_input1, user_input2, moves = 0, game_over = 0;
    init_game_board(game_board);
    shuffle_game_board(game_board);
    printf("Welcome to Memory Game!\n");
    printf("You have to flip the positions to make all the squares same.\n");
    while(!game_over){
        print_game_board(game_board);
        get_input(&user_input1,&user_input2);
        flip_positions(game_board,user_input1,user_input2);
        moves++;
        if(is_game_over(game_board)){
            game_over = 1;
        }
    }
    print_game_board(game_board);
    printf("You won the game in %d moves!\n",moves);
    return 0;
}