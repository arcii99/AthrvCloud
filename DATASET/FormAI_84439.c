//FormAI DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// function prototypes
void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
int is_game_over(int revealed[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0}; // all elements set to 0
    srand(time(NULL));
    
    initialize_board(board);
    
    while (!is_game_over(revealed))
    {
        print_board(board, revealed);
        int choice1_row, choice1_col;
        int choice2_row, choice2_col;
        do 
        {
            printf("Choose the first card (row col): ");
            scanf("%d %d", &choice1_row, &choice1_col);
        } while (revealed[choice1_row][choice1_col]);
        revealed[choice1_row][choice1_col] = 1; // reveal first choice
        print_board(board, revealed);
        
        do 
        {
            printf("Choose the second card (row col): ");
            scanf("%d %d", &choice2_row, &choice2_col);
        } while (revealed[choice2_row][choice2_col]);
        revealed[choice2_row][choice2_col] = 1; // reveal second choice
        print_board(board, revealed);
        
        if (board[choice1_row][choice1_col] != board[choice2_row][choice2_col])
        {
            printf("Not a match!\n");
            revealed[choice1_row][choice1_col] = 0; // hide first choice
            revealed[choice2_row][choice2_col] = 0; // hide second choice
        }
        else
        {
            printf("Match!\n");
        }
    }
    
    printf("Game over!\n");
    
    return 0;
}

void initialize_board(int board[ROWS][COLS])
{
    int vals[ROWS*COLS/2];
    for (int i = 0; i < ROWS*COLS/2; i++)
    {
        vals[i] = i+1;
    }
    
    // shuffle the values
    for (int i = 0; i < ROWS*COLS/2; i++)
    {
        int j = rand() % (ROWS*COLS/2);
        int temp = vals[i];
        vals[i] = vals[j];
        vals[j] = temp;
    }
    
    // assign the values to the board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = vals[i*COLS/2 + j/2];
        }
    }
}

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (revealed[i][j])
            {
                printf("%2d", board[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int is_game_over(int revealed[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (!revealed[i][j])
            {
                return 0; // game still in progress
            }
        }
    }
    return 1; // all cards have been revealed
}