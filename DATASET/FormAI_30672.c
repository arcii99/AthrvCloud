//FormAI DATASET v1.0 Category: Chess engine ; Style: invasive
#include <stdio.h>

int main()
{
    printf("Welcome to Invasive Chess Engine!\n");
    printf("Let's begin!\n\n");

    // Random move generator
    srand(time(NULL));

    // Setting up the board
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    // Printing the initial board
    printf("Initial Board:\n\n");

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Invasive move algorithm
    printf("Invasive Algorithm Active!\n");

    while(1)
    {
        int random_i = rand() % 8;
        int random_j = rand() % 8;
        if(board[random_i][random_j] != ' ')
        {
            char original_piece = board[random_i][random_j];
            int new_i = rand() % 8;
            int new_j = rand() % 8;

            // Moving the piece to the new location
            board[new_i][new_j] = original_piece;
            board[random_i][random_j] = ' ';

            printf("%c from (%d, %d) moved to (%d, %d)!\n", original_piece, random_i, random_j, new_i, new_j);

            // Printing the new board
            printf("\nNew Board:\n\n");

            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    printf("%c ", board[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            // Sleeping for 2 seconds before next move
            sleep(2);
        }
    }

    return 0;
}