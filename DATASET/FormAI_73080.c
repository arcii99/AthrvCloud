//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void display_board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |     |     \n\n");
}

bool is_win()
{
    if (board[1] == board[2] && board[2] == board[3])
        return true;
    else if (board[4] == board[5] && board[5] == board[6])
        return true;
    else if (board[7] == board[8] && board[8] == board[9])
        return true;
    else if (board[1] == board[4] && board[4] == board[7])
        return true;
    else if (board[2] == board[5] && board[5] == board[8])
        return true;
    else if (board[3] == board[6] && board[6] == board[9])
        return true;
    else if (board[1] == board[5] && board[5] == board[9])
        return true;
    else if (board[3] == board[5] && board[5] == board[7])
        return true;
    else
        return false;
}

int make_move(int player)
{
    int position;
    if(player == 1)
    {
        printf("Player 1 enter your move: ");
        scanf("%d", &position);
        if(position < 1 || position > 9 || board[position] == 'X' || board[position] == 'O')
        {
            printf("Error: Invalid move\n");
            return make_move(player);
        }
        else
            board[position] = 'X';
    }
    else
    {
        printf("Player 2 enter your move: ");
        scanf("%d", &position);
        if(position < 1 || position > 9 || board[position] == 'X' || board[position] == 'O')
        {
            printf("Error: Invalid move\n");
            return make_move(player);
        }
        else
            board[position] = 'O';
    }
    return 0;
}

int main()
{
    int player = 1;
    int choice;

    do
    {
        display_board();
        player = player % 2 == 1 ? 1 : 2;
        make_move(player);
        choice = is_win();
        player++;

    }while(choice == false);

    display_board();

    if (choice == true && --player % 2 == 1)
        printf("\n==>\aPlayer 1 wins!\n");
    else
        printf("\n==>\aPlayer 2 wins!\n");

    return 0;
}