//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>

char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Tic Tac Toe Board

void display_board() // Function to Display Game Board
{
    printf("\nTIC TAC TOE GAME\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

int check_win() // Function to Check if Game is Won
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;

    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;

    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3'
          && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6'
          && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return 0;

    else
        return -1;
}

int get_best_move(char player)
{
    int best_score = (player == 'X') ? -1000 : 1000;
    int score = 0;
    int i,j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;

                if (player == 'X')
                {
                    score = get_best_move('O');
                    if (score > best_score)
                        best_score = score;
                }
                else if (player == 'O')
                {
                    score = get_best_move('X');
                    if (score < best_score)
                        best_score = score;
                }

                board[i][j] = ' ';
            }
        }
    }

    return best_score;
}

void ai_move() // AI Move Function
{
    int best_score, i, j;
    best_score = -1000;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';

                int move_score = get_best_move('X');

                if (move_score > best_score)
                {
                    best_score = move_score;
                }
                board[i][j] = ' ';
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int move_score = get_best_move('X');

                if (move_score == best_score)
                {
                    return;
                }

                board[i][j] = ' ';
            }
        }
    }
}

int main() // Main Function
{
    int player = 0, i, choice;

    char mark;
    while (player != -1)
    {
        display_board(); // Display the Game Board
 
        player = check_win(); // Check if Game is Won

        if (player != -1)
            break;
        else
        {
            ai_move();

            display_board();

            player = check_win();

            if (player != -1)
                break;


            printf("Your turn: ");
            scanf("%d", &choice);

            mark = (player % 2 == 0) ? 'X' : 'O';

            if (choice == 1 && board[0][0] == '1')
                board[0][0] = mark;

            else if (choice == 2 && board[0][1] == '2')
                board[0][1] = mark;

            else if (choice == 3 && board[0][2] == '3')
                board[0][2] = mark;

            else if (choice == 4 && board[1][0] == '4')
                board[1][0] = mark;

            else if (choice == 5 && board[1][1] == '5')
                board[1][1] = mark;

            else if (choice == 6 && board[1][2] == '6')
                board[1][2] = mark;

            else if (choice == 7 && board[2][0] == '7')
                board[2][0] = mark;

            else if (choice == 8 && board[2][1] == '8')
                board[2][1] = mark;

            else if (choice == 9 && board[2][2] == '9')
                board[2][2] = mark;

            else
            {
                printf("Invalid Move, Try Again!\n");
                player--;
            }
        }
        player++;
    }
    if(player == 1 || player == 3)
        printf("Congratulations!!! You Win!!\n");
    else
        printf("Sorry, You Lost! Better Luck Next Time!!\n");

    printf("Thank you for playing!!\n");

    return 0;
}