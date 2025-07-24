//FormAI DATASET v1.0 Category: Game of Life ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

void print_board(int board[][COL])
{
    printf("\n    ");
    for(int i = 0; i < COL; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n   ");
    for(int i = 0; i < COL; i++)
    {
        printf("--");
    }
    for(int i = 0; i < ROW; i++)
    {
        printf("\n %c |", i+65);

        for(int j = 0; j < COL; j++)
        {
            if(board[i][j] == 1)
            {
                printf("O ");
            }
            else
            {
                printf("  ");
            }
        }
    }

    printf("\n   ");
    for(int i = 0; i < COL; i++)
    {
        printf("--");
    }
}

void update_board(int board[][COL], int new_board[][COL])
{
    int neighbours = 0;

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            neighbours = 0;

            // check upper neighbour
            if(i > 0 && board[i-1][j] == 1)
            {
                neighbours++;
            }

            // check lower neighbour
            if(i < ROW-1 && board[i+1][j] == 1)
            {
                neighbours++;
            }

            // check left neighbour
            if(j > 0 && board[i][j-1] == 1)
            {
                neighbours++;
            }

            // check right neighbour
            if(j < COL-1 && board[i][j+1] == 1)
            {
                neighbours++;
            }

            // check upper left neighbour
            if(i > 0 && j > 0 && board[i-1][j-1] == 1)
            {
                neighbours++;
            }

            // check upper right neighbour
            if(i > 0 && j < COL-1 && board[i-1][j+1] == 1)
            {
                neighbours++;
            }

            // check lower left neighbour
            if(i < ROW-1 && j > 0 && board[i+1][j-1] == 1)
            {
                neighbours++;
            }

            // check lower right neighbour
            if(i < ROW-1 && j < COL-1 && board[i+1][j+1] == 1)
            {
                neighbours++;
            }

            // apply the rules of the game
            if(board[i][j] == 1)
            {
                if(neighbours < 2 || neighbours > 3)
                {
                    new_board[i][j] = 0; // death by loneliness or overcrowding
                }
                else if (neighbours == 2 || neighbours == 3)
                {
                    new_board[i][j] = 1; // survival!
                }
            }
            else
            {
                if(neighbours == 3)
                {
                    new_board[i][j] = 1; // birth by reproduction
                }
            }
        }
    }

    // copy the new board into the old board
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

int main()
{
    // initialize the board with random values
    int board[ROW][COL];
    srand(time(NULL));
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    printf("Welcome to the Game of Life - A Romantic Edition!\n");
    printf("-------------------------------------------------\n");
    printf("This is a simulation of a romantic garden of life where the flowers and bees constantly flourish!\n");
    printf("In this garden, O represents a blooming flower and 1 represents a buzzing bee looking for love!\n");
    printf("-------------------------------------------------\n");

    print_board(board);

    char c;
    while(1)
    {
        printf("\n\nPress ENTER to simulate another cycle of life or any other key to end it all: ");
        c = getchar();
        if(c != '\n')
        {
            break;
        }

        // create a new board to update the old board
        int new_board[ROW][COL] = {0};
        update_board(board, new_board);
        print_board(board);
    }

    printf("\n-------------------------------------------------\n");
    printf("And so the story of love ends here. Thank you for watching the garden of life!");
    
    return 0;
}