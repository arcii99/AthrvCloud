//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 10

void print_board(int board[][BOARD_SIZE], int show_mines);
void initialize_board(int board[][BOARD_SIZE], int num_mines);
void process_turn(int board[][BOARD_SIZE], int *num_unopened);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int num_unopened = BOARD_SIZE * BOARD_SIZE;
    int game_over = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the board and print it
    initialize_board(board, NUM_MINES);
    print_board(board, 0);

    // Loop until the game is over
    while (!game_over)
    {
        process_turn(board, &num_unopened);
        if (num_unopened == NUM_MINES)
        {
            printf("Congratulations, you have found all the mines!\n");
            game_over = 1;
        }
    }

    return 0;
}

// Initialize the board with mines in random positions
void initialize_board(int board[][BOARD_SIZE], int num_mines)
{
    int i, j, k;

    // Set all cells to 0
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place the mines randomly
    for (k = 0; k < num_mines; k++)
    {
        do {
            i = rand() % BOARD_SIZE;
            j = rand() % BOARD_SIZE;
        } while (board[i][j] == -1);

        board[i][j] = -1;

        // Increment the count of adjacent cells
        if (i > 0 && j > 0 && board[i - 1][j - 1] != -1) board[i - 1][j - 1]++;
        if (i > 0 && board[i - 1][j] != -1) board[i - 1][j]++;
        if (i > 0 && j < BOARD_SIZE - 1 && board[i - 1][j + 1] != -1) board[i - 1][j + 1]++;
        if (j > 0 && board[i][j - 1] != -1) board[i][j - 1]++;
        if (j < BOARD_SIZE - 1 && board[i][j + 1] != -1) board[i][j + 1]++;
        if (i < BOARD_SIZE - 1 && j > 0 && board[i + 1][j - 1] != -1) board[i + 1][j - 1]++;
        if (i < BOARD_SIZE - 1 && board[i + 1][j] != -1) board[i + 1][j]++;
        if (i < BOARD_SIZE - 1 && j < BOARD_SIZE - 1 && board[i + 1][j + 1] != -1) board[i + 1][j + 1]++;
    }
}

// Process the player's turn
void process_turn(int board[][BOARD_SIZE], int *num_unopened)
{
    int i, j;
    int row, col;
    char action[10];

    printf("Enter row and column (e.g. '4 5') or 'f row col' to flag a mine: ");

    // Read the user's input
    scanf("%s", action);
    if (action[0] == 'f')
    {
        scanf("%d %d", &row, &col);
        if (board[row][col] == -1)
        {
            board[row][col] = -2; // Flagged as mine
            (*num_unopened)--;
        }
        else
        {
            printf("That is not a mine!\n");
        }
    }
    else
    {
        sscanf(action, "%d", &row);
        scanf("%d", &col);
        if (board[row][col] == -1)
        {
            printf("BOOM! You hit a mine and lost the game.\n");
            print_board(board, 1);
            exit(0);
        }
        else if (board[row][col] == -2)
        {
            printf("That cell is flagged as a mine!\n");
        }
        else if (board[row][col] == 0)
        {
            int stack[BOARD_SIZE * BOARD_SIZE][2], top = 0;

            // Flood-fill algorithm to open all the empty cells
            stack[top][0] = row;
            stack[top][1] = col;
            top++;

            while (top > 0)
            {
                top--;
                row = stack[top][0];
                col = stack[top][1];
                if (board[row][col] == 0)
                {
                    board[row][col] = -3; // Opened empty cell
                    (*num_unopened)--;
                    if (row > 0 && col > 0 && board[row - 1][col - 1] >= 0 && board[row - 1][col - 1] <= 8)
                    {
                        stack[top][0] = row - 1;
                        stack[top][1] = col - 1;
                        top++;
                    }
                    if (row > 0 && board[row - 1][col] >= 0 && board[row - 1][col] <= 8)
                    {
                        stack[top][0] = row - 1;
                        stack[top][1] = col;
                        top++;
                    }
                    if (row > 0 && col < BOARD_SIZE - 1 && board[row - 1][col + 1] >= 0 && board[row - 1][col + 1] <= 8)
                    {
                        stack[top][0] = row - 1;
                        stack[top][1] = col + 1;
                        top++;
                    }
                    if (col > 0 && board[row][col - 1] >= 0 && board[row][col - 1] <= 8)
                    {
                        stack[top][0] = row;
                        stack[top][1] = col - 1;
                        top++;
                    }
                    if (col < BOARD_SIZE - 1 && board[row][col + 1] >= 0 && board[row][col + 1] <= 8)
                    {
                        stack[top][0] = row;
                        stack[top][1] = col + 1;
                        top++;
                    }
                    if (row < BOARD_SIZE - 1 && col > 0 && board[row + 1][col - 1] >= 0 && board[row + 1][col - 1] <= 8)
                    {
                        stack[top][0] = row + 1;
                        stack[top][1] = col - 1;
                        top++;
                    }
                    if (row < BOARD_SIZE - 1 && board[row + 1][col] >= 0 && board[row + 1][col] <= 8)
                    {
                        stack[top][0] = row + 1;
                        stack[top][1] = col;
                        top++;
                    }
                    if (row < BOARD_SIZE - 1 && col < BOARD_SIZE - 1 && board[row + 1][col + 1] >= 0 && board[row + 1][col + 1] <= 8)
                    {
                        stack[top][0] = row + 1;
                        stack[top][1] = col + 1;
                        top++;
                    }
                }
                else if (board[row][col] >= 1 && board[row][col] <= 8)
                {
                    board[row][col] += 10; // Opened numbered cell
                    (*num_unopened)--;
                }
            }
        }
        else // board[row][col] >= 1 && board[row][col] <= 8
        {
            board[row][col] += 10; // Opened numbered cell
            (*num_unopened)--;
        }
    }

    printf("\n");
    print_board(board, 0);
}

// Print the board
void print_board(int board[][BOARD_SIZE], int show_mines)
{
    int i, j;

    printf("  ");
    for (j = 0; j < BOARD_SIZE; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] >= 10)
            {
                if (board[i][j] == -3)
                {
                    printf(". ");
                }
                else
                {
                    printf("%d ", board[i][j] - 10);
                }
            }
            else if (board[i][j] == -2 && show_mines)
            {
                printf("* ");
            }
            else if (board[i][j] == 0 || board[i][j] == -3)
            {
                printf(". ");
            }
            else
            {
                printf("? ");
            }
        }
        printf("\n");
    }
}