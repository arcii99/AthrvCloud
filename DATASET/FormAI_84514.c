//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75
#define MAX_DRAW 75

/* Function prototypes */
void generate_card(int card[ROWS][COLS]);
int draw_number(int drawn_numbers[MAX_DRAW], int num_drawn);
int check_win(int card[ROWS][COLS], int drawn_numbers[MAX_DRAW], int num_drawn);

/* Main function */
int main(void)
{
    int card[ROWS][COLS];
    int drawn_numbers[MAX_DRAW];
    int num_drawn = 0;
    int winner;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate the Bingo card */
    generate_card(card);

    /* Main game loop */
    while (num_drawn < MAX_DRAW)
    {
        /* Draw a number */
        int num = draw_number(drawn_numbers, num_drawn);
        num_drawn++;

        /* Display the drawn number */
        printf("Number Drawn: %d\n", num);

        /* Check for winners */
        winner = check_win(card, drawn_numbers, num_drawn);
        if (winner)
        {
            printf("\nBINGO! Winning pattern found...\n");
            break;
        }
    }

    /* Display the final Bingo card */
    printf("\nFinal Bingo Card:\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%2d ", card[row][col]);
        }
        printf("\n");
    }

    return 0;
}

/* Function to generate a random Bingo card */
void generate_card(int card[ROWS][COLS])
{
    int nums[MAX_NUM];
    int num_count = 0;

    /* Initialize array with all possible numbers */
    for (int num = 1; num <= MAX_NUM; num++)
    {
        nums[num_count] = num;
        num_count++;
    }

    /* Shuffle numbers array */
    for (int i = 0; i < num_count; i++)
    {
        int temp = nums[i];
        int rand_idx = rand() % num_count;
        nums[i] = nums[rand_idx];
        nums[rand_idx] = temp;
    }

    /* Populate Bingo card */
    num_count = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            card[row][col] = nums[num_count];
            num_count++;
        }
    }

    /* Place a free space in the center */
    card[ROWS/2][COLS/2] = 0;
}

/* Function to draw a random number that hasn't been drawn before */
int draw_number(int drawn_numbers[MAX_DRAW], int num_drawn)
{
    int num;

    do {
        num = rand() % MAX_NUM + 1;
    } while (contains(drawn_numbers, num_drawn, num));

    drawn_numbers[num_drawn] = num;

    return num;
}

/* Function to check for Bingo-winning patterns */
int check_win(int card[ROWS][COLS], int drawn_numbers[MAX_DRAW], int num_drawn)
{
    int row, col;
    int diag1 = 0;
    int diag2 = 0;

    /* Check rows */
    for (row = 0; row < ROWS; row++)
    {
        int pattern = 1;
        for (col = 0; col < COLS; col++)
        {
            if (card[row][col] == 0 || contains(drawn_numbers, num_drawn, card[row][col]))
            {
                pattern = 0;
                break;
            }
        }
        if (pattern) return 1;
    }

    /* Check columns */
    for (col = 0; col < COLS; col++)
    {
        int pattern = 1;
        for (row = 0; row < ROWS; row++)
        {
            if (card[row][col] == 0 || contains(drawn_numbers, num_drawn, card[row][col]))
            {
                pattern = 0;
                break;
            }
        }
        if (pattern) return 1;
    }

    /* Check diagonal 1 */
    for (row = 0; row < ROWS; row++)
    {
        if (card[row][row] == 0 || contains(drawn_numbers, num_drawn, card[row][row]))
        {
            diag1 = 0;
            break;
        }
        diag1 = 1;
    }
    if (diag1) return 1;

    /* Check diagonal 2 */
    for (row = 0; row < ROWS; row++)
    {
        col = ROWS - row - 1;
        if (card[row][col] == 0 || contains(drawn_numbers, num_drawn, card[row][col]))
        {
            diag2 = 0;
            break;
        }
        diag2 = 1;
    }
    if (diag2) return 1;

    /* No winner */
    return 0;
}

/* Helper function to check if a number is in an array */
int contains(int arr[], int arr_len, int num)
{
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}