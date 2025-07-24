//FormAI DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS];
int flipped[ROWS][COLS];

int num_pairs, pairs_found;

void init_board();
void print_board();
void flip_card(int row, int col);
int check_card(int row, int col);
void reset_flipped();
int check_win();

int main()
{
    srand(time(NULL));
    init_board();
    print_board();
    
    while (num_pairs > 0)
    {
        int row1, col1, row2, col2;
        
        printf("Enter row and column of first card to flip: ");
        scanf("%d %d", &row1, &col1);
        flip_card(row1, col1);
        print_board();
        
        printf("Enter row and column of second card to flip: ");
        scanf("%d %d", &row2, &col2);
        flip_card(row2, col2);
        print_board();
        
        if (check_card(row1, col1) && check_card(row2, col2))
        {
            printf("Pairs found!\n");
            num_pairs--;
            pairs_found++;
            
            if (pairs_found == ROWS * COLS / 2)
            {
                printf("Congratulations, you won!\n");
                return 0;
            }
        }
        else
        {
            printf("Not a pair!\n");
            reset_flipped();
        }
    }
    
    return 0;
}

void init_board()
{
    int nums[ROWS * COLS / 2];
    int i, j, k;
    num_pairs = ROWS * COLS / 2;
    
    for (i = 0; i < num_pairs; i++)
        nums[i] = i + 1;
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = 0;
            flipped[i][j] = 0;
        }
    }
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS / 2; j++)
        {
            int rand_idx = rand() % num_pairs;
            int num = nums[rand_idx];
            
            board[i][j * 2] = num;
            board[i][j * 2 + 1] = num;
            
            for (k = rand_idx; k < num_pairs - 1; k++)
                nums[k] = nums[k + 1];
            
            num_pairs--;
        }
    }
}

void print_board()
{
    int i, j;
    
    printf("\n  ");
    
    for (i = 0; i < COLS; i++)
        printf("%d ", i + 1);
    
    printf("\n");
    
    for (i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        
        for (j = 0; j < COLS; j++)
        {
            if (flipped[i][j])
                printf("%d ", board[i][j]);
            else
                printf("* ");
        }
        
        printf("\n");
    }
    
    printf("\n");
}

void flip_card(int row, int col)
{
    flipped[row - 1][col - 1] = 1;
}

int check_card(int row, int col)
{
    int num = board[row - 1][col - 1];
    int i, j;
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (flipped[i][j] == 1 && board[i][j] == num && (i != row - 1 || j != col - 1))
            {
                return 1;
            }
        }
    }
    
    return 0;
}

void reset_flipped()
{
    int i, j;
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (flipped[i][j] == 1)
            {
                flipped[i][j] = 0;
            }
        }
    }
}

int check_win()
{
    return pairs_found == ROWS * COLS / 2;
}