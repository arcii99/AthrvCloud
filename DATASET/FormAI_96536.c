//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Touring
#include <stdio.h>

char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
char mark = 'X';

void draw_board()
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

void player_turn()
{
    int choice;
    printf("Player %c, please enter a number corresponding to the board (1-9): ", mark);
    scanf("%d", &choice);

    if(choice == 1 && board[0][0] == '1')
        board[0][0] = mark;
    else if(choice == 2 && board[0][1] == '2')
        board[0][1] = mark;
    else if(choice == 3 && board[0][2] == '3')
        board[0][2] = mark;
    else if(choice == 4 && board[1][0] == '4')
        board[1][0] = mark;
    else if(choice == 5 && board[1][1] == '5')
        board[1][1] = mark;
    else if(choice == 6 && board[1][2] == '6')
        board[1][2] = mark;
    else if(choice == 7 && board[2][0] == '7')
        board[2][0] = mark;
    else if(choice == 8 && board[2][1] == '8')
        board[2][1] = mark;
    else if(choice == 9 && board[2][2] == '9')
        board[2][2] = mark;
    else
    {
        printf("Invalid move, please try again.\n");
        player_turn();
    }
}

int check_for_win()
{
    if(board[0][0] == board[0][1] && board[0][0] == board[0][2]) return 1;
    else if(board[1][0] == board[1][1] && board[1][0] == board[1][2]) return 1;
    else if(board[2][0] == board[2][1] && board[2][0] == board[2][2]) return 1;
    else if(board[0][0] == board[1][0] && board[0][0] == board[2][0]) return 1;
    else if(board[0][1] == board[1][1] && board[0][1] == board[2][1]) return 1;
    else if(board[0][2] == board[1][2] && board[0][2] == board[2][2]) return 1;
    else if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) return 1;
    else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) return 1;
    else if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' 
                    && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' 
                  && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
    {
        return -1;
    }
    else
    {
        return 0;   
    }
}

void switch_players()
{
    if(mark == 'X')
        mark = 'O';
    else 
        mark = 'X';
}

int main()
{
    int status;
    do
    {
        draw_board();
        player_turn();
        switch_players();
        status = check_for_win();
    }while(status == 0);

    if(status == 1)
        printf("Game over, Player %c wins!\n", mark);
    else
        printf("Game over, it was a draw!\n");

    return 0;
}