//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void display_board(int board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]);
int match_found(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);
void wait_for_enter();

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = { 0 };
    int row1, col1, row2, col2;
    int num_attempts = 0;
    int num_matches = 0;

    printf("*** Memory Game ***\n\n");

    srand(time(NULL));
    initialize_board(board);

    while (num_matches < BOARD_SIZE * BOARD_SIZE / 2)
    {
        display_board(board, revealed);

        printf("Enter row and column of first card: ");
        scanf("%d %d", &row1, &col1);
        printf("\n");

        if (row1 < 1 || row1 > BOARD_SIZE || col1 < 1 || col1 > BOARD_SIZE)
        {
            printf("Invalid row/column. Try again.\n");
            wait_for_enter();
            continue;
        }

        printf("Enter row and column of second card: ");
        scanf("%d %d", &row2, &col2);
        printf("\n");

        if (row2 < 1 || row2 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE)
        {
            printf("Invalid row/column. Try again.\n");
            wait_for_enter();
            continue;
        }

        if (row1 == row2 && col1 == col2)
        {
            printf("Cannot select same card twice. Try again.\n");
            wait_for_enter();
            continue;
        }

        if (revealed[row1 - 1][col1 - 1] || revealed[row2 - 1][col2 - 1])
        {
            printf("Card already revealed. Try again.\n");
            wait_for_enter();
            continue;
        }

        if (match_found(board, row1 - 1, col1 - 1, row2 - 1, col2 - 1))
        {
            printf("Match found!\n");
            revealed[row1 - 1][col1 - 1] = 1;
            revealed[row2 - 1][col2 - 1] = 1;
            num_attempts++;
            num_matches++;
        }
        else
        {
            printf("No match. Try again.\n");
            revealed[row1 - 1][col1 - 1] = 1;
            revealed[row2 - 1][col2 - 1] = 1;
            num_attempts++;
        }

        wait_for_enter();
    }

    display_board(board, revealed);
    printf("Congratulations! You found all %d matches in %d attempts.\n", BOARD_SIZE * BOARD_SIZE / 2, num_attempts);

    return 0;
}

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    int nums[BOARD_SIZE * BOARD_SIZE / 2];
    int i, j;
    int count = 0;

    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++)
    {
        nums[i] = count;
        count++;
    }

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = -1;
        }
    }

    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++)
    {
        int rand1, rand2;

        do
        {
            rand1 = rand() % BOARD_SIZE;
            rand2 = rand() % BOARD_SIZE;
        } while (board[rand1][rand2] != -1);

        board[rand1][rand2] = nums[i];
        do
        {
            rand1 = rand() % BOARD_SIZE;
            rand2 = rand() % BOARD_SIZE;
        } while (board[rand1][rand2] != -1);

        board[rand1][rand2] = nums[i];
    }
}

void display_board(int board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    printf("    ");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d  ", i + 1);
    }
    printf("\n");

    printf("  +");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("---+");
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d|", i + 1);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (revealed[i][j])
            {
                printf(" %2d|", board[i][j] + 1);
            }
            else
            {
                printf("   |");
            }
        }
        printf("\n");

        printf("  +");
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("---+");
        }
        printf("\n");
    }
}

int match_found(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void wait_for_enter()
{
    while (getchar() != '\n')
    {
        // Wait for enter
    }

    printf("Press enter to continue.\n");
    getchar();
}