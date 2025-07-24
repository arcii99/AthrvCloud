//FormAI DATASET v1.0 Category: Memory Game ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 4
#define MAX_INDEX 15

void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
void swap(int *a, int *b);

int main()
{
    srand(time(NULL));
    int row, col, temp;
    int board[BOARD_SIZE][BOARD_SIZE];
    int indexes[MAX_INDEX];
    
    // Initialize indexes array
    for(int i=0; i<MAX_INDEX; i++)
    {
        indexes[i] = i;
    }
    
    // Shuffle indexes array
    for(int i=0; i<MAX_INDEX; i++)
    {
        int random_idx = rand() % MAX_INDEX;
        swap(&indexes[i], &indexes[random_idx]);
    }
    
    // Assign shuffled indexes to board
    for(int i=0; i<MAX_INDEX; i++)
    {
        row = i / BOARD_SIZE;
        col = i % BOARD_SIZE;
        board[row][col] = indexes[i] + 1;
    }
    
    // Place the empty cell at bottom right corner
    board[BOARD_SIZE-1][BOARD_SIZE-1] = 0;
    
    // Play game
    printf("Welcome to the medieval memory game!\n");
    printf("The numbers represent different weapons in a medieval arsenal.\n");
    printf("The goal is to match them by swapping the cells.\n");
    printf("Enter the row and column of the cell you'd like to swap.\n");
    printf("Enter 0 in both fields to quit the game.\n\n");
    
    int user_row, user_col;
    do{
        print_board(board);
        printf("Enter row: ");
        scanf("%d", &user_row);
        printf("Enter col: ");
        scanf("%d", &user_col);
        
        // Check for invalid input
        if(user_row < 0 || user_row >= BOARD_SIZE || 
           user_col < 0 || user_col >= BOARD_SIZE)
        {
            printf("Invalid input! Please enter valid row and column values.\n");
            continue;
        }
        
        // Check for user quitting the game
        if(user_row == 0 && user_col == 0)
        {
            printf("Thanks for playing! Goodbye.\n");
            return 0;
        }
        
        // Swap cells
        row = user_row - 1;
        col = user_col - 1;
        if(row < BOARD_SIZE-1 && board[row+1][col] == 0) // Check below
        {
            swap(&board[row][col], &board[row+1][col]);
        }
        else if(col < BOARD_SIZE-1 && board[row][col+1] == 0) // Check right
        {
            swap(&board[row][col], &board[row][col+1]);
        }
        else if(row > 0 && board[row-1][col] == 0) // Check above
        {
            swap(&board[row][col], &board[row-1][col]);
        }
        else if(col > 0 && board[row][col-1] == 0) // Check left
        {
            swap(&board[row][col], &board[row][col-1]);
        }
        else // No valid swap found
        {
            printf("Invalid move! Please choose a cell next to the empty cell.\n");
        }
                
    }while(board[BOARD_SIZE-1][BOARD_SIZE-1] != MAX_INDEX);
    
    // Game won!
    print_board(board);
    printf("Congratulations! You matched all the weapons.\n");
    
    return 0;
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            if(board[i][j] == 0) // Empty cell
            {
                printf("     ");
            }
            else
            {
                printf("%-5d", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}