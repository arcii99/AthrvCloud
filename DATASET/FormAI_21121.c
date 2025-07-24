//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

// Function to check if all the numbers are visited
int check_visited(int *visited)
{
    for (int i = 0; i < ROW * COL; i++)
    {
        if (!visited[i])
            return 0;
    }
    return 1;
}

// Function to print the Bingo Board
void print_board(int board[ROW][COL], int *visited)
{
    printf("\n\n");

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (visited[i * COL + j])
            {
                if (board[i][j] < 10)
                    printf("  %d ", board[i][j]);
                else
                    printf(" %d ", board[i][j]);
            }
            else
                printf("  X ");
        }
        printf("\n");
    }
}

int main()
{
    int board[ROW][COL];
    int visited[ROW * COL] = {0};

    srand(time(NULL));

    // Fill the array with random numbers
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = rand() % 99 + 1;
        }
    }

    printf("\t\tB\tI\tN\tG\tO\n");
    print_board(board, visited);

    int input;
    int bingo = 0;
    while (!bingo)
    {
        printf("Please enter a number between 1-99: ");
        scanf("%d", &input);

        // check if input matches any numbers on the board
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (board[i][j] == input)
                {
                    visited[i * COL + j] = 1;
                    break;
                }
            }
        }

        // Check if Bingo
        int rows[5] = {0}, cols[5] = {0}, diag[2] = {0};
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                rows[i] += visited[i * COL + j];
                cols[j] += visited[i * COL + j];
                if (i == j)
                    diag[0] += visited[i * COL + j];
                if (i + j == 4)
                    diag[1] += visited[i * COL + j];
            }
        }
        for (int i = 0; i < ROW; i++)
        {
            if (rows[i] == 5 || cols[i] == 5 || diag[0] == 5 || diag[1] == 5)
            {
                printf("BINGO!!\n");
                bingo = 1;
                break;
            }
        }

        print_board(board, visited);

        if (check_visited(visited))
        {
            printf("All numbers have been called. It's a draw!\n");
            break;
        }
    }

    return 0;
}