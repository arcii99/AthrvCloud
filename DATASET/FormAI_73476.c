//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    int numbers[75];
    int count = 0;
    int selected[75] = {0};

    // generate an array of unique random numbers between 1 and 75
    for(int i=1; i<=75; i++)
        numbers[i-1] = i;
    for(int i=0; i<75; i++)
    {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    printf("\n********* BINGO SIMULATOR *********\n");

    // keep playing until all the numbers are selected
    while(count < 75)
    {
        printf("\nPress ENTER to get a new number or type 'exit' to quit.");

        // check for user input
        char input[10];
        scanf("%s", input);

        if(strcmp(input, "exit") == 0)
        {
            printf("\nThanks for playing! Bye.\n");
            return 0;
        }
        else
        {
            // get a unique random number and mark it as selected
            int num;
            do {
                num = numbers[rand() % 75];
            } while(selected[num-1] != 0);
            selected[num-1] = 1;
            count++;

            // display the selected number
            printf("\nThe next number is: %d\n", num);

            // check for a bingo
            if(count >= 5)
            {
                int row_flag[5] = {0};
                int col_flag[5] = {0};
                int diag_flag1 = 0;
                int diag_flag2 = 0;

                // check rows and columns
                for(int i=0; i<5; i++)
                {
                    for(int j=0; j<5; j++)
                    {
                        if(selected[i*5+j] == 0)
                            break;
                        if(j == 4)
                            row_flag[i] = 1;
                        if(selected[j*5+i] == 0)
                            break;
                        if(j == 4)
                            col_flag[i] = 1;
                    }
                }

                // check diagonals
                for(int i=0; i<5; i++)
                {
                    if(selected[i*6] == 0)
                        break;
                    if(i == 4)
                        diag_flag1 = 1;
                    if(selected[4+i*4] == 0)
                        break;
                    if(i == 4)
                        diag_flag2 = 1;
                }

                // check if there is a bingo
                if(row_flag[0] || row_flag[1] || row_flag[2] || row_flag[3] || row_flag[4] ||
                   col_flag[0] || col_flag[1] || col_flag[2] || col_flag[3] || col_flag[4] ||
                   diag_flag1 || diag_flag2)
                {
                    printf("\nBINGO!!! You won!\n");
                    return 0;
                }
            }
        }
    }

    // all the numbers are selected and nobody has won
    printf("\nNo more numbers left. It's a tie!\n");
    return 0;
}