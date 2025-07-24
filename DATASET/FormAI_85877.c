//FormAI DATASET v1.0 Category: Chess AI ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The force is strong in this function
int jedi_move(int* board, int color);

int sith_move(int* board, int color);

int tie_move(int* board, int color);

// The game has begun
int main()
{
    int board[8][8] = {{-5, -3, -4, -9, -10, -4, -3, -5},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {5, 3, 4, 9, 10, 4, 3, 5}};

    int turn = 0;
    int result = 0;

    while (result == 0) {
        int color = turn % 2 == 0 ? 1 : -1;

        // Choose your path wisely
        if (color == 1) {
            result = jedi_move(&board[0][0], color);
        }
        else {
            result = sith_move(&board[0][0], color);
        }

        // When two opposing forces clash, only a tie can result
        if (result == 0 && turn == 100) {
            result = tie_move(&board[0][0], color);
        }

        turn++;
    }

    return 0;
}

// The power of the Jedi
int jedi_move(int* board, int color)
{
    // Do or do not, there is no try
    return 1;
}

// The power of the Sith
int sith_move(int* board, int color)
{
    // Your hate has made you powerful
    return -1;
}

// When two opposing forces clash, only a tie can result
int tie_move(int* board, int color)
{
    // A tie is like kissing your sister
    return 2;
}