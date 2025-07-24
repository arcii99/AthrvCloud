//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void generate_card(int card[][COLS]);
void print_card(int card[][COLS]);
void generate_numbers(int numbers[]);
int check_card(int card[][COLS], int num);
int check_bingo(int card[][COLS]);

int main()
{
    int card[ROWS][COLS];
    int numbers[MAX_NUM];
    int num_drawn, row, col, num_bingo;
    char play_again = 'y';

    // Set random seed
    srand(time(NULL));

    printf("Welcome to the Bingo Simulator!\n");

    while (play_again == 'y')
    {
        // Generate a new card
        generate_card(card);
        
        // Reset all numbers drawn
        for (int i = 0; i < MAX_NUM; i++)
        {
            numbers[i] = 0;
        }

        num_bingo = 0;

        // Main game loop
        while (num_bingo == 0)
        {
            // Generate a new random number
            generate_numbers(numbers);
            num_drawn = numbers[rand() % MAX_NUM];

            // Check if number is in card
            if (check_card(card, num_drawn))
            {
                printf("Number drawn: %d\n", num_drawn);

                // Mark the number in the card
                for (row = 0; row < ROWS; row++)
                {
                    for (col = 0; col < COLS; col++)
                    {
                        if (card[row][col] == num_drawn)
                        {
                            card[row][col] = -1;
                        }
                    }
                }

                // Print updated card
                print_card(card);

                // Check for bingo
                num_bingo = check_bingo(card);

                if (num_bingo > 0)
                {
                    printf("Bingo! You won with %d numbers drawn!\n", MAX_NUM - num_bingo);
                }
            }
        }

        // Ask if user wants to play again
        printf("Would you like to play again? (y/n): ");
        fflush(stdin);
        scanf("%c", &play_again);
    }

    printf("Thank you for playing the Bingo Simulator!\n");

    return 0;
}

void generate_card(int card[][COLS])
{
    int i, j;
    int row_nums[ROWS][COLS] = {0};
    int col_nums[ROWS][COLS] = {0};

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            card[i][j] = 0;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (j == 2 && i == 2)
            {
                card[i][j] = -1;
            }
            else
            {
                int num = rand() % 15 + (j * 15) + 1;
    
                while (row_nums[i][num / 15] == 1 || col_nums[j][num / 15] == 1)
                {
                    num = rand() % 15 + (j * 15) + 1;
                }
        
                card[i][j] = num;
                row_nums[i][num / 15] = 1;
                col_nums[j][num / 15] = 1;
            }
        }
    }
}

void print_card(int card[][COLS])
{
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                printf("[X]");
            }
            else
            {
                printf("[%02d]", card[i][j]);
            }
        }
        
        printf("\n");
    }

    printf("\n");
}

void generate_numbers(int numbers[])
{
    int i, num;

    do
    {
        num = rand() % MAX_NUM + 1;
    } while (numbers[num - 1] == 1);

    numbers[num - 1] = 1;
}

int check_card(int card[][COLS], int num)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if(card[i][j] == num)
            {
                return 1;
            }
        }
    }

    return 0;
}

int check_bingo(int card[][COLS])
{
    int i, j, count;

    // Check rows
    for (i = 0; i < ROWS; i++)
    {
        count = 0;

        for (j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                count++;
            }
        }

        if (count == COLS)
        {
            return (ROWS - i) * COLS; // Return number of numbers drawn
        }
    }

    // Check columns
    for (j = 0; j < COLS; j++)
    {
        count = 0;

        for (i = 0; i < ROWS; i++)
        {
            if (card[i][j] == -1)
            {
                count++;
            }
        }

        if (count == ROWS)
        {
            return (ROWS * COLS) - ((COLS - j) * ROWS); // Return number of numbers drawn
        }
    }

    // Check diagonals
    count = 0;

    for (i = 0; i < ROWS; i++)
    {
        if (card[i][i] == -1)
        {
            count++;
        }
    }

    if (count == ROWS)
    {
        return (ROWS * COLS) - (2 * ROWS); // Return number of numbers drawn
    }

    count = 0;

    for (i = 0; i < ROWS; i++)
    {
        if (card[i][COLS - 1 - i] == -1)
        {
            count++;
        }
    }

    if (count == ROWS)
    {
        return (ROWS * COLS) - (2 * ROWS); // Return number of numbers drawn
    }

    return 0;
}