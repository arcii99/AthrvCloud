//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void display_card(int card[][COLS], int marked[][COLS], int row_lim, int col_lim)
{
    printf("  ");
    for(int i=0; i<col_lim; ++i)
        printf("  %d  ", i+1);
    printf("\n  ");
    for(int i=0; i<col_lim+1; ++i)
        printf("=====");
    printf("\n");

    for(int i=0; i<row_lim; ++i)
    {
        printf("%c ", i+65);
        for(int j=0; j<col_lim; ++j)
        {
            if(marked[i][j])
                printf("| O |");
            else
                printf("| %d |", card[i][j]);
        }
        printf("\n  ");
        for(int i=0; i<col_lim+1; ++i)
            printf("=====");
        printf("\n");
    }
}

void shuffle_card(int card[][COLS], int row_lim, int col_lim)
{
    int temp;
    for(int i=0; i<row_lim; ++i)
    {
        for(int j=0; j<col_lim; ++j)
        {
            int rand_row = rand() % row_lim;
            int rand_col = rand() % col_lim;
            temp = card[i][j];
            card[i][j] = card[rand_row][rand_col];
            card[rand_row][rand_col] = temp;
        }
    }
}

int check_win(int card[][COLS], int marked[][COLS], int row_lim, int col_lim)
{
    for(int i=0; i<row_lim; ++i)
    {
        int row_count = 0;
        for(int j=0; j<col_lim; ++j)
        {
            if(marked[i][j])
                ++row_count;
        }
        if(row_count == col_lim)
            return 1;
    }

    for(int j=0; j<col_lim; ++j)
    {
        int col_count = 0;
        for(int i=0; i<row_lim; ++i)
        {
            if(marked[i][j])
                ++col_count;
        }
        if(col_count == row_lim)
            return 1;
    }

    int diagonal_count1 = 0, diagonal_count2 = 0;
    for(int i=0; i<row_lim; ++i)
    {
        if(marked[i][i])
            ++diagonal_count1;
        if(marked[i][col_lim-i-1])
            ++diagonal_count2;
    }
    if(diagonal_count1 == row_lim || diagonal_count2 == row_lim)
        return 1;

    return 0;
}

int main()
{
    srand(time(NULL));
    int card[ROWS][COLS];
    int marked[ROWS][COLS] = {0};
    char input[5];

    //generating numbers
    for(int i=0; i<ROWS; ++i)
    {
        int start_num = i * 15 + 1;
        int end_num = start_num + 14;
        for(int j=0; j<COLS; ++j)
        {
            card[i][j] = start_num + (rand() % (end_num - start_num + 1));
        }
    }

    shuffle_card(card, ROWS, COLS);
    display_card(card, marked, ROWS, COLS);

    while(1)
    {
        printf("Enter the number (or QUIT to exit): ");
        scanf("%s", input);

        if(input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T')
            break;

        int num = atoi(input);
        int found = 0;
        for(int i=0; i<ROWS; ++i)
        {
            for(int j=0; j<COLS; ++j)
            {
                if(card[i][j] == num)
                {
                    found = 1;
                    marked[i][j] = 1;
                    break;
                }
            }
            if(found)
                break;
        }
        system("clear");
        display_card(card, marked, ROWS, COLS);

        if(check_win(card, marked, ROWS, COLS))
        {
            printf("Congratulations! You have won the game!\n");
            break;
        }
    }

    return 0;
}