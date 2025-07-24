//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_board(int board[], int size, int score);
void generate_new_tile(int board[], int size);
void shift_up(int board[], int size, int *score_ptr);
void shift_down(int board[], int size, int *score_ptr);
void shift_left(int board[], int size, int *score_ptr);
void shift_right(int board[], int size, int *score_ptr);
int check_win(int board[], int size);

int main()
{
    int board[16] = {0};
    int size = 4;
    int score = 0;
    char direction;

    // Initialize random number generator
    srand(time(NULL));

    // Print instructions
    printf("*** Welcome to 2048! ***\n");
    printf("Use W(up), A(left), S(down), D(right) to shift the board.\n");
    printf("Join the numbers and get to the 2048 tile!\n");

    // Generate first two tiles
    generate_new_tile(board, size);
    generate_new_tile(board, size);

    // Start game loop
    while (1)
    {
        // Print the board
        print_board(board, size, score);

        // Check if user has won
        if (check_win(board, size))
        {
            printf("Congratulations, you won!\n");
            break;
        }

        // Get user input
        printf("Enter direction: ");
        scanf(" %c", &direction);

        // Shift board based on user input
        switch (direction)
        {
        case 'W':
            shift_up(board, size, &score);
            break;
        case 'S':
            shift_down(board, size, &score);
            break;
        case 'A':
            shift_left(board, size, &score);
            break;
        case 'D':
            shift_right(board, size, &score);
            break;
        default:
            printf("Invalid direction.\n");
            break;
        }

        // Generate a new tile
        generate_new_tile(board, size);
    }

    return 0;
}

// Prints the board and current score
void print_board(int board[], int size, int score)
{
    system("clear"); // Clears the console
    printf("Score: %d\n", score);
    printf("+------------------------+\n");

    for (int i = 0; i < size; i++)
    {
        printf("|");

        for (int j = 0; j < size; j++)
        {
            if (board[i * size + j] != 0)
            {
                printf("%4d    ", board[i * size + j]);
            }
            else
            {
                printf("         ");
            }
        }

        printf("|\n");
    }

    printf("+------------------------+\n");
}

// Generates a new tile at a random location
void generate_new_tile(int board[], int size)
{
    int rand_row, rand_col, rand_val;

    // Generate random row and column
    do
    {
        rand_row = rand() % size;
        rand_col = rand() % size;
    } while (board[rand_row * size + rand_col] != 0);

    // Generate random value (2 or 4)
    rand_val = (rand() % 2 + 1) * 2;

    // Update board
    board[rand_row * size + rand_col] = rand_val;
}

// Shifts the board up
void shift_up(int board[], int size, int *score_ptr)
{
    int i, j, k;
    int score = *score_ptr;

    // Shift each row upwards
    for (j = 0; j < size; j++)
    {
        for (i = 1; i < size; i++)
        {
            if (board[i * size + j] != 0)
            {
                k = i;

                while (k > 0 && board[(k - 1) * size + j] == 0)
                {
                    board[(k - 1) * size + j] = board[k * size + j];
                    board[k * size + j] = 0;
                    k--;
                }

                if (k > 0 && board[(k - 1) * size + j] == board[k * size + j])
                {
                    board[(k - 1) * size + j] += board[k * size + j];
                    board[k * size + j] = 0;
                    score += board[(k - 1) * size + j];
                }
            }
        }
    }

    *score_ptr = score;
}

// Shifts the board down
void shift_down(int board[], int size, int *score_ptr)
{
    int i, j, k;
    int score = *score_ptr;

    // Shift each row downwards
    for (j = 0; j < size; j++)
    {
        for (i = size - 2; i >= 0; i--)
        {
            if (board[i * size + j] != 0)
            {
                k = i;

                while (k < size - 1 && board[(k + 1) * size + j] == 0)
                {
                    board[(k + 1) * size + j] = board[k * size + j];
                    board[k * size + j] = 0;
                    k++;
                }

                if (k < size - 1 && board[(k + 1) * size + j] == board[k * size + j])
                {
                    board[(k + 1) * size + j] += board[k * size + j];
                    board[k * size + j] = 0;
                    score += board[(k + 1) * size + j];
                }
            }
        }
    }

    *score_ptr = score;
}

// Shifts the board left
void shift_left(int board[], int size, int *score_ptr)
{
    int i, j, k;
    int score = *score_ptr;

    // Shift each column left
    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size; j++)
        {
            if (board[i * size + j] != 0)
            {
                k = j;

                while (k > 0 && board[i * size + k - 1] == 0)
                {
                    board[i * size + k - 1] = board[i * size + k];
                    board[i * size + k] = 0;
                    k--;
                }

                if (k > 0 && board[i * size + k - 1] == board[i * size + k])
                {
                    board[i * size + k - 1] += board[i * size + k];
                    board[i * size + k] = 0;
                    score += board[i * size + k - 1];
                }
            }
        }
    }

    *score_ptr = score;
}

// Shifts the board right
void shift_right(int board[], int size, int *score_ptr)
{
    int i, j, k;
    int score = *score_ptr;

    // Shift each column right
    for (i = 0; i < size; i++)
    {
        for (j = size - 2; j >= 0; j--)
        {
            if (board[i * size + j] != 0)
            {
                k = j;

                while (k < size - 1 && board[i * size + k + 1] == 0)
                {
                    board[i * size + k + 1] = board[i * size + k];
                    board[i * size + k] = 0;
                    k++;
                }

                if (k < size - 1 && board[i * size + k + 1] == board[i * size + k])
                {
                    board[i * size + k + 1] += board[i * size + k];
                    board[i * size + k] = 0;
                    score += board[i * size + k + 1];
                }
            }
        }
    }

    *score_ptr = score;
}

// Checks if player has won
int check_win(int board[], int size)
{
    for (int i = 0; i < size * size; i++)
    {
        if (board[i] == 2048)
        {
            return 1;
        }
    }

    return 0;
}