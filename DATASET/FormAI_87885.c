//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_BOMBS 10

// function to display the game board with hidden and revealed cells
void display_board(int board[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE])
{
    printf("   ");
    for (int col = 0; col < GRID_SIZE; col++)
    {
        printf("%d ", col);
    }
    printf("\n");

    printf("   ");
    for (int col = 0; col < GRID_SIZE; col++)
    {
        printf("- ");
    }
    printf("\n");

    for (int row = 0; row < GRID_SIZE; row++)
    {
        printf("%d| ", row);
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (revealed[row][col])
            {
                printf("%d ", board[row][col]);
            }
            else
            {
                printf("? ");
            }
        }
        printf("\n");
    }
}

// function to count the number of bombs in the neighbouring cells
int count_bombs(int board[GRID_SIZE][GRID_SIZE], int row, int col)
{
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE)
            {
                if (board[i][j] == -1)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    int board[GRID_SIZE][GRID_SIZE];
    int revealed[GRID_SIZE][GRID_SIZE];
    int num_bombs = 0;

    // initialize random number generator
    srand(time(NULL));

    // place bombs randomly on the board
    while (num_bombs < NUM_BOMBS)
    {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        if (board[row][col] != -1)
        {
            board[row][col] = -1;
            num_bombs++;
        }
    }

    // fill in the rest of the cells with counts of neighbouring bombs
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] != -1)
            {
                board[row][col] = count_bombs(board, row, col);
            }
        }
    }

    // initialize revealed cells to false
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            revealed[row][col] = 0;
        }
    }

    // game loop
    int game_over = 0;
    while (!game_over)
    {
        display_board(board, revealed);

        // get user input for the next move
        int row, col;
        printf("Enter row and column (separated by space): ");
        scanf("%d %d", &row, &col);

        // check if the move is valid
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        {
            printf("Invalid move! Please enter row and column within the bounds of the board.\n");
            continue;
        }

        // check if the cell has already been revealed
        if (revealed[row][col])
        {
            printf("Invalid move! This cell has already been revealed.\n");
            continue;
        }

        // reveal the cell and check for game over
        revealed[row][col] = 1;

        if (board[row][col] == -1)
        {
            printf("Game over! You hit a bomb.\n");
            game_over = 1;
        }
        else if (board[row][col] == 0)
        {
            // reveal neighbouring cells if the current cell has no neighbouring bombs
            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {
                    if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE)
                    {
                        if (!revealed[i][j])
                        {
                            revealed[i][j] = 1;
                        }
                    }
                }
            }
        }

        // check for win condition
        int num_revealed = 0;
        for (int row = 0; row < GRID_SIZE; row++)
        {
            for (int col = 0; col < GRID_SIZE; col++)
            {
                if (revealed[row][col])
                {
                    num_revealed++;
                }
            }
        }

        if (num_revealed == GRID_SIZE * GRID_SIZE - NUM_BOMBS)
        {
            printf("Congratulations! You won the game.\n");
            game_over = 1;
        }
    }

    return 0;
}