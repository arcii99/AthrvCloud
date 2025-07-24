//FormAI DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function declarations
void print_board(int board[4][4]);
bool place_random(int board[4][4]);
void move(int board[4][4], char direction);
bool check_game_over(int board[4][4]);
bool has_won(int board[4][4]);

int main()
{
    // initialize the board to all zeroes
    int board[4][4] = {0};

    // place two random numbers on the board to start
    bool success = place_random(board);
    if (!success)
    {
        printf("Error initializing game.\n");
        return 1;
    }
    success = place_random(board);
    if (!success)
    {
        printf("Error initializing game.\n");
        return 1;
    }

    // print the starting board
    print_board(board);

    // game loop
    while (true)
    {
        // get player input
        char direction;
        printf("Enter a direction (w = up, a = left, s = down, d = right): ");
        scanf("%c", &direction);

        // clear the input buffer
        while (getchar() != '\n');

        // move the tiles
        move(board, direction);

        // check if the game is over
        if (check_game_over(board))
        {
            printf("Game over!\n");
            break;
        }

        // check if the player has won
        if (has_won(board))
        {
            printf("Congratulations, you have won!\n");
            break;
        }

        // place a new number on the board
        success = place_random(board);
        if (!success)
        {
            printf("Error placing new number.\n");
            return 1;
        }

        // print the updated board
        print_board(board);
    }

    return 0;
}

// function definitions

void print_board(int board[4][4])
{
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool place_random(int board[4][4])
{
    // search for an empty cell
    int empty_cells[16][2];
    int num_empty = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                empty_cells[num_empty][0] = i;
                empty_cells[num_empty][1] = j;
                num_empty++;
            }
        }
    }

    // if there are no empty cells, return false
    if (num_empty == 0)
    {
        return false;
    }

    // choose a random empty cell and place a 2 or 4 at random
    srand(time(NULL));
    int index = rand() % num_empty;
    int i = empty_cells[index][0];
    int j = empty_cells[index][1];
    int value = (rand() % 2 + 1) * 2;
    board[i][j] = value;

    return true;
}

void move(int board[4][4], char direction)
{
    switch (direction)
    {
        case 'w': // up
            for (int j = 0; j < 4; j++)
            {
                int last_merged = -1;
                for (int i = 1; i < 4; i++)
                {
                    if (board[i][j] == 0) continue;
                    int k = i;
                    while (k > 0 && (board[k-1][j] == 0 || board[k-1][j] == board[i][j]))
                    {
                        if (board[k-1][j] == board[i][j] && k-1 != last_merged)
                        {
                            board[k-1][j] *= 2;
                            board[i][j] = 0;
                            last_merged = k-1;
                            break;
                        }
                        if (board[k-1][j] == 0)
                        {
                            board[k-1][j] = board[i][j];
                            board[i][j] = 0;
                            k--;
                        }
                        if (k == 1) break;
                        k--;
                    }
                }
            }
            break;
        case 'a': // left
            for (int i = 0; i < 4; i++)
            {
                int last_merged = -1;
                for (int j = 1; j < 4; j++)
                {
                    if (board[i][j] == 0) continue;
                    int k = j;
                    while (k > 0 && (board[i][k-1] == 0 || board[i][k-1] == board[i][j]))
                    {
                        if (board[i][k-1] == board[i][j] && k-1 != last_merged)
                        {
                            board[i][k-1] *= 2;
                            board[i][j] = 0;
                            last_merged = k-1;
                            break;
                        }
                        if (board[i][k-1] == 0)
                        {
                            board[i][k-1] = board[i][j];
                            board[i][j] = 0;
                            k--;
                        }
                        if (k == 1) break;
                        k--;
                    }
                }
            }
            break;
        case 's': // down
            for (int j = 0; j < 4; j++)
            {
                int last_merged = -1;
                for (int i = 2; i >= 0; i--)
                {
                    if (board[i][j] == 0) continue;
                    int k = i;
                    while (k < 3 && (board[k+1][j] == 0 || board[k+1][j] == board[i][j]))
                    {
                        if (board[k+1][j] == board[i][j] && k+1 != last_merged)
                        {
                            board[k+1][j] *= 2;
                            board[i][j] = 0;
                            last_merged = k+1;
                            break;
                        }
                        if (board[k+1][j] == 0)
                        {
                            board[k+1][j] = board[i][j];
                            board[i][j] = 0;
                            k++;
                        }
                        if (k == 3) break;
                        k++;
                    }
                }
            }
            break;
        case 'd': // right
            for (int i = 0; i < 4; i++)
            {
                int last_merged = -1;
                for (int j = 2; j >= 0; j--)
                {
                    if (board[i][j] == 0) continue;
                    int k = j;
                    while (k < 3 && (board[i][k+1] == 0 || board[i][k+1] == board[i][j]))
                    {
                        if (board[i][k+1] == board[i][j] && k+1 != last_merged)
                        {
                            board[i][k+1] *= 2;
                            board[i][j] = 0;
                            last_merged = k+1;
                            break;
                        }
                        if (board[i][k+1] == 0)
                        {
                            board[i][k+1] = board[i][j];
                            board[i][j] = 0;
                            k++;
                        }
                        if (k == 3) break;
                        k++;
                    }
                }
            }
            break;
    }
}

bool check_game_over(int board[4][4])
{
    // check if the board is full
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                return false;
            }
        }
    }

    // check if any adjacent tiles are the same
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i < 3 && board[i][j] == board[i+1][j])
            {
                return false;
            }
            if (j < 3 && board[i][j] == board[i][j+1])
            {
                return false;
            }
        }
    }

    return true;
}

bool has_won(int board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                return true;
            }
        }
    }

    return false;
}