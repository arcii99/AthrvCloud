//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void draw_board(char TicTacToeBoard[]);
int check_game_over(char TicTacToeBoard[], char player);
int check_win(char TicTacToeBoard[], char player);
int get_best_move(char TicTacToeBoard[], char player);
void print_message();
 
int main(void) 
{
    char TicTacToeBoard[] = {'1','2','3','4','5','6','7','8','9'};
    int game_over=0;
    int num_of_moves=0;
    char player='X';
   
    print_message();
    draw_board(TicTacToeBoard);
 
    while(!game_over && num_of_moves<9)
    {  
      if(player=='X')
        {
            printf("Player 1 turn: ");
            scanf(" %c", &player);
        }
        else
        {
            player='O';
            if(num_of_moves!=0)     
            {
                player=get_best_move(TicTacToeBoard, player);
            }
            printf("Computer's turn: %c\n", player);
        }
       
        int idx=0;
        while(idx<9 && TicTacToeBoard[idx]!=player)
        {
            idx++;
        }
        TicTacToeBoard[idx]=player;
        draw_board(TicTacToeBoard);
        game_over=check_game_over(TicTacToeBoard, player);
        num_of_moves++;
 
        if(player=='O')
            player='X';
        else
            player='O'; 
    }
   
    if(num_of_moves==9 && !game_over)
    {
        printf("The game is a tie!\n");
    }  
                      
    return 0;
}
 
void draw_board(char TicTacToeBoard[])
{
    printf("\n");
    printf("%c | %c | %c\n", TicTacToeBoard[0], TicTacToeBoard[1], TicTacToeBoard[2]);
    printf("--|---|--\n");
    printf("%c | %c | %c\n", TicTacToeBoard[3], TicTacToeBoard[4], TicTacToeBoard[5]);
    printf("--|---|--\n");
    printf("%c | %c | %c\n", TicTacToeBoard[6], TicTacToeBoard[7], TicTacToeBoard[8]);
    printf("\n");
}
 
int check_game_over(char TicTacToeBoard[], char player)
{
    if(check_win(TicTacToeBoard, player))
    {
        printf("%c wins!\n", player);
        return 1; 
    }
    else
        return 0;
}
 
int check_win(char TicTacToeBoard[], char player)
{
    if(TicTacToeBoard[0] == player && TicTacToeBoard[1] == player && TicTacToeBoard[2] == player)
        return 1;
    else if(TicTacToeBoard[3] == player && TicTacToeBoard[4] == player && TicTacToeBoard[5] == player)
        return 1;
    else if(TicTacToeBoard[6] == player && TicTacToeBoard[7] == player && TicTacToeBoard[8] == player)
        return 1;
    else if(TicTacToeBoard[0] == player && TicTacToeBoard[3] == player && TicTacToeBoard[6] == player)
        return 1;
    else if(TicTacToeBoard[1] == player && TicTacToeBoard[4] == player && TicTacToeBoard[7] == player)
        return 1;
    else if(TicTacToeBoard[2] == player && TicTacToeBoard[5] == player && TicTacToeBoard[8] == player)
        return 1;
    else if(TicTacToeBoard[0] == player && TicTacToeBoard[4] == player && TicTacToeBoard[8] == player)
        return 1;
    else if(TicTacToeBoard[2] == player && TicTacToeBoard[4] == player && TicTacToeBoard[6] == player)
        return 1;
    else
        return 0;
}
 
int get_best_move(char TicTacToeBoard[], char player)
{
    int best_move=-1;
    int i;
    srand(time(NULL));
 
    while(best_move == -1)
    {
        i = rand() % 9;
        if(TicTacToeBoard[i] != 'X' && TicTacToeBoard[i] != 'O')
            best_move=i;  
    }
    return(TicTacToeBoard[best_move] = player);
}
 
void print_message()
{
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is X and the Computer is O.\n");
    printf("Enter a number from 1 to 9 to mark your position on the board.\n");
    printf("Let's begin!\n");
}