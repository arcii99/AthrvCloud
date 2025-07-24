//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 3

int board[SIZE][SIZE];
int ai = 1, human = -1;

void display_board()
{
    printf("-------------\n");
    for (int i=0; i<SIZE; i++)
    {
        printf("|");
        for (int j=0; j<SIZE; j++)
        {
            if (board[i][j] == ai)
                printf(" O |");
            else if (board[i][j] == human)
                printf(" X |");
            else
                printf("   |");
        }
        printf("\n-------------\n");
    }
}

bool is_move_valid(int x, int y)
{
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        return false;
    if (board[x][y] != 0)
        return false;
    return true;
}

bool game_over()
{
    for (int i=0; i<SIZE; i++)
    {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[2][0] != 0 && board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return true;

    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }

    return true;
}

int minmax(bool is_ai, int depth, int alpha, int beta)
{
    if (game_over())
        return ai*(10-depth);

    if (is_ai)
    {
        int max_score = -1000;
        for (int i=0; i<SIZE; i++)
        {
            for (int j=0; j<SIZE; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = ai;
                    int score = minmax(false, depth+1, alpha, beta);
                    board[i][j] = 0;
                    if (score > max_score)
                    {
                        max_score = score;
                        if (depth == 0)
                            printf("AI placed O at (%d,%d)\n", i, j);
                    }
                    if (score > alpha)
                        alpha = score;
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return max_score;
    }
    else
    {
        int min_score = 1000;
        for (int i=0; i<SIZE; i++)
        {
            for (int j=0; j<SIZE; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = human;
                    int score = minmax(true, depth+1, alpha, beta);
                    board[i][j] = 0;
                    if (score < min_score)
                        min_score = score;
                    if (score < beta)
                        beta = score;
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return min_score;
    }
}

void ai_move()
{
    int max_score = -1000;
    int best_i = -1, best_j = -1;

    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = ai;
                int score = minmax(false, 0, -1000, 1000);
                board[i][j] = 0;
                if (score > max_score)
                {
                    max_score = score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    board[best_i][best_j] = ai;
    display_board();
}

int main()
{
    srand(time(NULL));
    int turn = rand() % 2;
    printf("AI is O and you are X.\n");
    if (turn == 0)
        printf("AI goes first.\n\n");
    else
        printf("You go first.\n\n");

    while(!game_over())
    {
        if (turn == 0)
            ai_move();
        else
        {
            int x, y;
            printf("Enter x-coordinate (0-2): ");
            scanf("%d", &x);
            printf("Enter y-coordinate (0-2): ");
            scanf("%d", &y);
            while (!is_move_valid(x, y))
            {
                printf("Invalid move. Try again.\n");
                printf("Enter x-coordinate (0-2): ");
                scanf("%d", &x);
                printf("Enter y-coordinate (0-2): ");
                scanf("%d", &y);
            }
            board[x][y] = human;
            display_board();
        }
        turn = !turn;
    }

    if (game_over())
    {
        printf("Game over!\n");
        if (minmax(false, 0, -1000, 1000) == ai*10)
            printf("AI wins!\n");
        else if (minmax(false, 0, -1000, 1000) == human*10)
            printf("You win!\n");
        else
            printf("It's a tie!\n");
    }
    return 0;
}