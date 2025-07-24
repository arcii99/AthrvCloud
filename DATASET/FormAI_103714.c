//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6

void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
void generate_board(char board[BOARD_SIZE][BOARD_SIZE]);
int valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);
int check_empty(char board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int row1, col1, row2, col2;
    int score = 0;
    int move_count = 0;
    int game_over = 0;
    
    // Generate random board
    generate_board(board);
    
    // Main game loop
    while(!game_over)
    {
        // Display current board state
        display_board(board);
        
        // Prompt user for move input
        printf("Enter row and column of first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter row and column of second card: ");
        scanf("%d %d", &row2, &col2);
        
        // Validate move
        if(valid_move(board, row1, col1, row2, col2))
        {
            // Add score and remove cards from board
            score += 10;
            board[row1][col1] = ' ';
            board[row2][col2] = ' ';
            
            // Increment move count
            move_count++;
            
            // Check if game is over
            if(check_empty(board))
            {
                game_over = 1;
            }
        }
        else
        {
            // Penalty for incorrect move
            score -= 2;
        }
        
        // Display current score and move count
        printf("Current score: %d\n", score);
        printf("Moves: %d\n", move_count);
    }
    
    printf("Game over. Final score: %d\n", score);
    
    return 0;
}

// Function to display board
void display_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    
    printf("\n\n******** Memory Game ********\n\n");
    
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            printf("[%c]", board[i][j]);
        }
        
        printf("\n");
    }
}

// Function to generate random board
void generate_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    int num_pairs = BOARD_SIZE * BOARD_SIZE / 2;
    char pairs[num_pairs];
    int count = 0;
    
    // Generate pairs
    for(i = 0; i < num_pairs; i++)
    {
        pairs[i] = 'A' + i;
    }
    
    // Shuffle pairs
    srand(time(NULL));
    for(i = num_pairs - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }
    
    // Populate board with pairs
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = pairs[count];
            count++;
        }
    }
}

// Function to check if move is valid
int valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2)
{
    // Check if cards are the same
    if(board[row1][col1] == board[row2][col2])
    {
        // Check if cards are not already removed
        if(board[row1][col1] != ' ')
        {
            return 1;
        }
    }
    
    return 0;
}

// Function to check if board is empty
int check_empty(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] != ' ')
            {
                return 0;
            }
        }
    }
    
    return 1;
}