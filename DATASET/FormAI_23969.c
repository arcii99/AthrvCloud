//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
int player_turn;

void init_board()
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board()
{
    printf("\n\n");
    printf("  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---------\n");
    printf("  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---------\n");
    printf("  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

int get_winner()
{
    int i;
    // check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'X')
                return 1;
            else if (board[i][0] == 'O')
                return 2;
            else
                continue;
        }
    }

    // check columns
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 'X')
                return 1;
            else if (board[0][i] == 'O')
                return 2;
            else
                continue;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 'X')
            return 1;
        else if (board[0][0] == 'O')
            return 2;
        else
            return 0;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 'X')
            return 1;
        else if (board[0][2] == 'O')
            return 2;
        else
            return 0;
    }

    // check if board is full
    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;

    return 3;
}

void play_ai()
{
    int i, j;
    int best_score = -1000, score;
    // loop through every possible move
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O'; 
                score = negamax(1);
                if (score > best_score)
                     best_score = score;
                board[i][j] = ' ';
            }
        }
    // now make the best move
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O'; 
                score = negamax(1);
                if (score == best_score)
                     return;
                board[i][j] = ' ';
            }
        }
}

int negamax(int depth)
{
    int winner = get_winner();
    if (winner == 2) return 100 - depth;
    if (winner == 1 || winner == 3) return depth - 100;

    int i, j, score;
    int best_score = -1000;

    // loop through every possible move
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = (player_turn % 2 == 0) ? 'O' : 'X';
                player_turn++;
                score = -negamax(depth + 1);
                player_turn--;
                board[i][j] = ' ';

                if (score > best_score)
                {
                    best_score = score;
                }
            }
        }
    return best_score;
}

int main()
{
    init_board();
    print_board();

    while (get_winner() == 0)
    {
        if (player_turn % 2 == 0)
        {
            printf("AI's turn\n");
            play_ai();
        }
        else
        {
            printf("Your turn\n");
            int x, y;
            printf("Enter row and column: ");
            scanf("%d %d", &x, &y);
            while (board[x - 1][y - 1] != ' ')
            {
                printf("That position is already filled. Enter another row and column: ");
                scanf("%d %d", &x, &y);
            }
            board[x - 1][y - 1] = 'X';
        }
        player_turn++;
        print_board();
    }

    int winner = get_winner();
    if (winner == 1)
        printf("AI wins!");
    else if (winner == 2)
        printf("You win!");
    else
        printf("It's a tie!");

    return 0;
}