//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 25

int bingo[ROWS][COLS];
int numbers_left = TOTAL_NUMBERS;
int winner_flag = 0;

void *generate_numbers(void *arg);
void *play_bingo(void *arg);

int main()
{
    srand(time(0));
    pthread_t tid1, tid2;

    // Initialize bingo card
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(i==2 && j==2)
            {
                bingo[i][j] = -1; // Free Space
                continue;
            }
            bingo[i][j] = (10*i) + rand() % 10;
        }
    }

    // Print bingo card
    printf("\nBingo Card:\n");
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d\t", bingo[i][j]);
        }
        printf("\n");
    }

    // Create threads for generating numbers and playing bingo
    pthread_create(&tid1, NULL, &generate_numbers, NULL);
    pthread_create(&tid2, NULL, &play_bingo, NULL);

    // Wait for threads to complete
    pthread_join(tid1, NULL); 
    pthread_join(tid2, NULL);

    return 0;
}

void *generate_numbers(void *arg)
{
    while(numbers_left > 0)
    {
        int number = rand() % TOTAL_NUMBERS + 1;
        printf("Number generated: %d\n", number);
        numbers_left--;
        sleep(1);
    }
}

void *play_bingo(void *arg)
{
    int numbers_called[TOTAL_NUMBERS];
    int index = 0;

    while(!winner_flag)
    {
        int number = rand() % TOTAL_NUMBERS + 1;
        numbers_called[index++] = number;

        for(int i=0; i<ROWS; i++)
        {
            for(int j=0; j<COLS; j++)
            {
                if(bingo[i][j] == number)
                {
                    bingo[i][j] = -1;  // Mark as called
                }
            }
        }

        // Print out called numbers
        printf("\nNumbers Called:\n");
        for(int i=0; i<index; i++)
        {
            printf("%d ", numbers_called[i]);
        }

        // Check for bingo
        for(int i=0; i<ROWS; i++)
        {
            int sum = 0;
            for(int j=0; j<COLS; j++)
            {
                sum += bingo[i][j];
            }
            if(sum == -5) // All values have been called on row i
            {
                printf("\nBingo! Row %d\n", i+1);
                winner_flag = 1;
            }
        }

        for(int j=0; j<COLS; j++)
        {
            int sum = 0;
            for(int i=0; i<ROWS; i++)
            {
                sum += bingo[i][j];
            }
            if(sum == -5) // All values have been called on column j
            {
                printf("\nBingo! Column %d\n", j+1);
                winner_flag = 1;
            }
        }

        int diagonal1_sum = bingo[0][0] + bingo[1][1] + bingo[3][3] + bingo[4][4];
        int diagonal2_sum = bingo[0][4] + bingo[1][3] + bingo[3][1] + bingo[4][0];
        if(diagonal1_sum == -4 || diagonal2_sum == -4) // All values have been called on a diagonal
        {
            printf("\nBingo! Diagonal\n");
            winner_flag = 1;
        }

        sleep(1);
    }
}