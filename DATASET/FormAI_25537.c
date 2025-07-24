//FormAI DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void shuffle(int *arr, int size); // Function to shuffle the cards
void print_board(int board[][BOARD_SIZE], int hidden); // Function to print the game board
void get_move(int *row, int *col); // Function to get user's move
int check_move(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2); // Function to check if a move is valid
void update_board(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2); // Function to update the game board
int check_win(int board[][BOARD_SIZE]); // Function to check if the player has won

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize game board
    int board[BOARD_SIZE][BOARD_SIZE] = {{1, 1, 2, 2},
                                          {3, 3, 4, 4},
                                          {5, 5, 6, 6},
                                          {7, 7, 8, 8}};
    shuffle((int *)board, BOARD_SIZE * BOARD_SIZE); // Shuffle the cards

    int moves = 0;
    int row1, col1, row2, col2;
    int hidden_board[BOARD_SIZE][BOARD_SIZE] = {{0}}; // Initialize hidden board
    int game_over = 0; // Flag to check if game is over

    printf("Welcome to Memory Game!\n");
    printf("To play, enter the row and column numbers of the two cards you want to flip.\n");
    printf("The game ends when all the cards have been correctly matched.\n\n");

    // Game loop
    while (!game_over)
    {
        print_board(board, 0); // Print game board (hide cards)

        get_move(&row1, &col1); // Get user's move

        // Make sure move is valid
        while (hidden_board[row1][col1] || row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE)
        {
            printf("Invalid move. Please enter a valid row and column.\n");
            get_move(&row1, &col1);
        }

        hidden_board[row1][col1] = board[row1][col1]; // Reveal card at chosen position
        print_board(hidden_board, 1); // Print game board (show revealed cards)

        get_move(&row2, &col2); // Get second move

        // Make sure second move is valid
        while (hidden_board[row2][col2] || row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE)
        {
            printf("Invalid move. Please enter a valid row and column.\n");
            get_move(&row2, &col2);
        }

        // Check if the two moves match
        if (check_move(board, row1, col1, row2, col2))
        {
            hidden_board[row2][col2] = board[row2][col2]; // Reveal second card

            printf("Match found!\n\n");

            // Check if game is over
            if (check_win(hidden_board))
            {
                printf("Congratulations! You won in %d moves!\n", moves);
                game_over = 1;
            }
        }
        else
        {
            printf("No match. Try again.\n\n");
            hidden_board[row1][col1] = 0; // Hide first card
            hidden_board[row2][col2] = 0; // Hide second card
        }

        moves++; // Increment move counter
    }

    return 0;
}

void shuffle(int *arr, int size)
{
    // Shuffle array using Fisher-Yates algorithm
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    }
}

void print_board(int board[][BOARD_SIZE], int hidden)
{
    printf("\n   0  1  2  3\n");
    printf("  ------------\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (hidden && !board[i][j]) // Hide card if requested
            {
                printf(" | ");
            }
            else
            {
                printf("|%2d", board[i][j]);
            }
        }
        printf("|\n");
    }

    printf("  ------------\n\n");
}

void get_move(int *row, int *col)
{
    printf("Enter row and column (e.g. 0 1): ");
    scanf("%d %d", row, col);
}

int check_move(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2)
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

void update_board(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2)
{
    board[row1][col1] = 0;
    board[row2][col2] = 0;
}

int check_win(int board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (!board[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}