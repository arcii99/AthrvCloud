//FormAI DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function to shuffle the elements of an array
void shuffle(int arr[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        
        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print the game board
void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    
    // Populate the board with numbers
    int numbers[BOARD_SIZE*BOARD_SIZE/2];
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++)
    {
        numbers[i] = i+1;
    }
    shuffle(numbers, BOARD_SIZE*BOARD_SIZE/2);
    
    // Place numbers on the board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (index >= BOARD_SIZE*BOARD_SIZE/2)
            {
                break;
            }
            board[i][j] = numbers[index];
            board[BOARD_SIZE-i-1][BOARD_SIZE-j-1] = numbers[index];
            index++;
        }
        if (index >= BOARD_SIZE*BOARD_SIZE/2)
        {
            break;
        }
    }
    
    // Print the initial board
    print_board(board);
    
    // Main loop of the game
    int row1, col1, row2, col2;
    int remaining_pairs = BOARD_SIZE*BOARD_SIZE/2;
    while (remaining_pairs > 0)
    {
        // Get user input for the first card
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        while (board[row1][col1] == -1)
        {
            printf("That card has already been matched or is invalid, please choose another: ");
            scanf("%d %d", &row1, &col1);
        }
        printf("The first card is %d\n", board[row1][col1]);
        board[row1][col1] = -1;
        print_board(board);
        
        // Get user input for the second card
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
        while (board[row2][col2] == -1 || (row1 == row2 && col1 == col2))
        {
            printf("That card has already been matched or is invalid, please choose another: ");
            scanf("%d %d", &row2, &col2);
        }
        printf("The second card is %d\n", board[row2][col2]);
        if (board[row1][col1] == board[row2][col2])
        {
            printf("Pair matched!\n");
            board[row2][col2] = -1;
            remaining_pairs--;
        }
        else
        {
            board[row1][col1] = board[row2][col2] = 0;
        }
        print_board(board);
    }
    
    printf("Congratulations, you have found all the pairs!\n");
    return 0;
}