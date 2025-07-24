//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define GENERATIONS 1000

void initialize_board(int board[HEIGHT][WIDTH]);
void print_board(int board[HEIGHT][WIDTH]);
void update_board(int board[HEIGHT][WIDTH]);

int main()
{
    int board[HEIGHT][WIDTH];

    // initialize board with random values
    initialize_board(board);

    // print initial board
    print_board(board);

    // iterate through generations
    for (int i = 0; i < GENERATIONS; i++)
    {
        // update board with new generation
        update_board(board);

        // print updated board
        print_board(board);
    }

    return 0;
}

void initialize_board(int board[HEIGHT][WIDTH])
{
    // seed random function with current time
    srand(time(NULL));

    // loop through each element of the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // generate random value (0 or 1)
            int value = rand() % 2;

            // set board element to random value
            board[i][j] = value;
        }
    }
}

void print_board(int board[HEIGHT][WIDTH])
{
    // clear screen
    system("clear");

    // loop through each element of the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // check value of board element
            if (board[i][j] == 0)
            {
                // print empty space
                printf(" ");
            }
            else
            {
                // print full square
                printf("█");
            }
        }

        // print newline to move to next row
        printf("\n");
    }

    // pause program for 100 milliseconds
    usleep(100000);
}

void update_board(int board[HEIGHT][WIDTH])
{
    // create copy of board
    int temp_board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            temp_board[i][j] = board[i][j];
        }
    }

    // iterate through each element of the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // count number of live neighbors
            int live_neighbors = 0;

            // check top neighbor
            if (i > 0 && board[i-1][j] == 1) live_neighbors++;

            // check bottom neighbor
            if (i < HEIGHT-1 && board[i+1][j] == 1) live_neighbors++;

            // check left neighbor
            if (j > 0 && board[i][j-1] == 1) live_neighbors++;

            // check right neighbor
            if (j < WIDTH-1 && board[i][j+1] == 1) live_neighbors++;

            // check top-left neighbor
            if (i > 0 && j > 0 && board[i-1][j-1] == 1) live_neighbors++;

            // check top-right neighbor
            if (i > 0 && j < WIDTH-1 && board[i-1][j+1] == 1) live_neighbors++;

            // check bottom-left neighbor
            if (i < HEIGHT-1 && j > 0 && board[i+1][j-1] == 1) live_neighbors++;

            // check bottom-right neighbor
            if (i < HEIGHT-1 && j < WIDTH-1 && board[i+1][j+1] == 1) live_neighbors++;

            // apply rules of Game of Life to determine new value
            if (board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3))
            {
                temp_board[i][j] = 0;
            }
            else if (board[i][j] == 0 && live_neighbors == 3)
            {
                temp_board[i][j] = 1;
            }
        }
    }

    // copy updated board back to original board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = temp_board[i][j];
        }
    }
}