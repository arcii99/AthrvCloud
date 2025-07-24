//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS])
{
    printf("\n\n");

    printf(" _ _ _ _ _\n");
    for(int i=0; i<ROWS; i++)
    {
        printf("|");
        for(int j=0; j<COLS; j++)
        {
            if(board[i][j] == -1)
            {
                printf("X|");
            }
            else
            {
                printf("%d|", board[i][j]);
            }
        }
        printf("\n");
    }
    printf(" ‾ ‾ ‾ ‾ ‾\n");

    printf("\n\n");
}

int main()
{
    srand(time(NULL));
    int board[ROWS][COLS];
    int chosen_numbers[25] = {0};

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = -1;
        }
    }

    int num_count = 0;
    while(num_count < 25)
    {
        int num = rand()%75 + 1;
        int flag = 0;

        for(int i=0; i<num_count; i++)
        {
            if(chosen_numbers[i] == num)
            {
                flag = 1;   //number already chosen
                break;
            }
        }

        if(flag == 0)
        {
            int row = num/15;
            if(num%15 == 0)
            {
                row -= 1;
            }
            int col = -1;

            for(int j=0; j<COLS; j++)
            {
                if(board[row][j] == num)
                {
                    flag = 1;   //number already on board
                    break;
                }
                else if(board[row][j] == -1)
                {
                    col = j;
                }
            }

            if(flag == 0 && col != -1)
            {
                board[row][col] = num;
                chosen_numbers[num_count] = num;
                num_count++;
            }
        }
    }

    print_board(board);

    int count = 0;
    int numbers_left = 25;
    int winner_flag = 0;

    printf("LET THE BINGO GAME BEGIN!!!\n\n");

    while(!winner_flag)
    {
        if(numbers_left == 0)
        {
            printf("DRAW!\n");
            break;
        }

        printf("ENTER THE NEXT NUMBER: ");
        int num = 0;
        scanf("%d", &num);

        //check if number already called
        int flag = 0;
        for(int i=0; i<count; i++)
        {
            if(chosen_numbers[i] == num)
            {
                flag = 1;   //number already called
                break;
            }
        }

        if(flag)
        {
            printf("NUMBER ALREADY CALLED! TRY AGAIN.\n");
            continue;
        }

        int row = num/15;
        if(num%15 == 0)
        {
            row -= 1;
        }

        flag = 0;
        for(int j=0; j<COLS; j++)
        {
            if(board[row][j] == num)    //number on board
            {
                board[row][j] = -1;     //set as called
                chosen_numbers[count] = num;
                count++;
                numbers_left--;

                printf("CORRECT! %d LEFT TO GO.\n", numbers_left);

                print_board(board);

                //check rows for bingo
                flag = 1;
                for(int k=0; k<ROWS; k++)
                {
                    int full_row = 1;
                    for(int l=0; l<COLS; l++)
                    {
                        if(board[k][l] != -1)
                        {
                            full_row = 0;
                            break;
                        }
                    }
                    if(full_row)
                    {
                        printf("BINGO! ROW %d\n", k+1);
                        winner_flag = 1;
                        break;
                    }
                }
                if(winner_flag)
                {
                    break;
                }

                //check columns for bingo
                for(int k=0; k<COLS; k++)
                {
                    int full_col = 1;
                    for(int l=0; l<ROWS; l++)
                    {
                        if(board[l][k] != -1)
                        {
                            full_col = 0;
                            break;
                        }
                    }
                    if(full_col)
                    {
                        printf("BINGO! COLUMN %d\n", k+1);
                        winner_flag = 1;
                        break;
                    }
                }
                if(winner_flag)
                {
                    break;
                }

                //check diagonals for bingo
                int full_diag = 1;
                for(int k=0; k<ROWS; k++)
                {
                    if(board[k][k] != -1)
                    {
                        full_diag = 0;
                        break;
                    }
                }
                if(full_diag)
                {
                    printf("BINGO! DIAGONAL\n");
                    winner_flag = 1;
                    break;
                }

                full_diag = 1;
                for(int k=0; k<ROWS; k++)
                {
                    if(board[ROWS-1-k][k] != -1)
                    {
                        full_diag = 0;
                        break;
                    }
                }
                if(full_diag)
                {
                    printf("BINGO! DIAGONAL\n");
                    winner_flag = 1;
                    break;
                }
            }
        }

        if(!flag)
        {
            printf("WRONG NUMBER! TRY AGAIN.\n");
        }
    }

    return 0;
}