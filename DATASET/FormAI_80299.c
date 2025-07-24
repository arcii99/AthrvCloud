//FormAI DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

// function prototypes
void initialize_board(int board[][SIZE]);
void shuffle_board(int board[][SIZE]);
void print_board(int board[][SIZE]);
void play_game(int board[][SIZE]);
int is_board_solved(int board[][SIZE]);

int main()
{
    int board[SIZE][SIZE];
    srand(time(NULL)); // seed random number generator

    // set up and shuffle board
    initialize_board(board);
    shuffle_board(board);

    // play game
    play_game(board);

    return 0;
}

// function to initialize new board to numbered sequence
void initialize_board(int board[][SIZE])
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            board[i][j] = i*SIZE + j + 1;
        }
    }

    board[SIZE-1][SIZE-1] = 0; // set bottom right corner to empty spot
}

// function to randomly shuffle board
void shuffle_board(int board[][SIZE])
{
    int temp, rand_i, rand_j;

    for (int i = 0; i < SIZE*SIZE; i++) 
    {
        // pick random spot on board that is not the empty spot
        do {
            rand_i = rand() % SIZE;
            rand_j = rand() % SIZE;
        } while (board[rand_i][rand_j] == 0);

        // swap values with empty spot
        temp = board[rand_i][rand_j];
        board[rand_i][rand_j] = board[SIZE-1][SIZE-1];
        board[SIZE-1][SIZE-1] = temp;
    }
}

// function to print current status of board
void print_board(int board[][SIZE])
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// main game loop
void play_game(int board[][SIZE])
{
    int input_i, input_j, temp;

    while (!is_board_solved(board))
    {
        print_board(board);

        printf("Enter the row and column number of the piece you want to move: ");
        scanf("%d %d", &input_i, &input_j);

        // check if input is valid, and spot is adjacent to empty spot
        if (input_i < SIZE && input_j < SIZE && board[input_i][input_j] != 0)
        {
            // check if spot is adjacent to empty spot
            if ((input_i == SIZE-1 && input_j == SIZE-2) ||
                (input_i == SIZE-2 && (input_j == SIZE-1 || input_j == SIZE-3)) ||
                (input_i == SIZE-3 && (input_j == SIZE-2 || input_j == SIZE-4)) ||
                (input_i == SIZE-4 && input_j == SIZE-3))
            {
                // swap pieces
                temp = board[input_i][input_j];
                board[input_i][input_j] = board[SIZE-1][SIZE-1];
                board[SIZE-1][SIZE-1] = temp;
            }
            else 
            {
                printf("Error: Piece is not adjacent to empty spot.\n\n");
            }
        }
        else 
        {
            printf("Error: Invalid input.\n\n");
        }
    }

    printf("You have successfully solved the puzzle!\n");
}

// function to check whether board is in solved state
int is_board_solved(int board[][SIZE])
{
    int count = 1;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] != count && !(i == SIZE-1 && j == SIZE-1)) 
            {
                return 0;
            }
            count++;
        }
    }
    return 1;
}