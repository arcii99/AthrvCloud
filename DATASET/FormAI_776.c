//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Function prototypes
void shuffle(int *arr, int n);
void print_board(int board[][COLS], int revealed[][COLS]);
void reveal_card(int row, int col, int board[][COLS], int revealed[][COLS]);
int check_endgame(int revealed[][COLS]);

int main()
{
    int board[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int revealed[ROWS][COLS] = {0};

    int card1_row, card1_col, card2_row, card2_col;

    int num_revealed = 0;

    shuffle((int *)board, ROWS*COLS);

    while (check_endgame(revealed) == 0)
    {
        print_board(board, revealed);

        printf("Enter row and column of card 1: ");
        scanf("%d %d", &card1_row, &card1_col);

        reveal_card(card1_row, card1_col, board, revealed);
        print_board(board, revealed);

        printf("Enter row and column of card 2: ");
        scanf("%d %d", &card2_row, &card2_col);

        reveal_card(card2_row, card2_col, board, revealed);
        print_board(board, revealed);

        if (board[card1_row][card1_col] != board[card2_row][card2_col])
        {
            printf("Sorry, they don't match\n");
            revealed[card1_row][card1_col] = revealed[card2_row][card2_col] = 0;
        }
        else
        {
            printf("Yay, you found a match!\n");
            num_revealed += 2;
        }
    }

    printf("Congratulations! You won in %d tries\n", num_revealed/2);

    return 0;
}

void shuffle(int *arr, int n)
{
    srand(time(0));
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        int temp = *(arr+i);
        *(arr+i) = *(arr+j);
        *(arr+j) = temp;
    }
}

void print_board(int board[][COLS], int revealed[][COLS])
{
    printf("\n\n\n\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (revealed[i][j] == 1)
            {
                printf("%2d ", board[i][j]);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void reveal_card(int row, int col, int board[][COLS], int revealed[][COLS])
{
    revealed[row][col] = 1;
}

int check_endgame(int revealed[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (revealed[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}