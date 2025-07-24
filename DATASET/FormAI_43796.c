//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_MOVES 30

void print_board(int board[], int hidden[]);
void initialize_board(int board[], int hidden[], int size);
int get_move(int board[], int hidden[], int moves[]);
int check_move(int board[], int hidden[], int moves[], int move);
void reveal(int board[], int hidden[], int move);
void hide(int board[], int hidden[], int move);
int has_won(int hidden[]);

int main()
{
    int board[BOARD_SIZE];
    int hidden[BOARD_SIZE];
    int moves[MAX_MOVES];
    int num_moves = 0;
    int winner = 0;

    printf("Welcome to Retro Memory Game!\n");

    initialize_board(board, hidden, BOARD_SIZE);
    printf("Let's start the game!\n");
    print_board(board, hidden);

    while (num_moves < MAX_MOVES && !winner)
    {
        int move = get_move(board, hidden, moves);
        int valid_move = check_move(board, hidden, moves, move);

        if (valid_move)
        {
            reveal(board, hidden, move);
            print_board(board, hidden);

            if (has_won(hidden))
            {
                printf("Congratulations, you won!\n");
                winner = 1;
            }

            num_moves++;
        }
        else
        {
            printf("Invalid move, try again.\n");
        }
    }

    if (!winner)
    {
        printf("Sorry, you lost. Try again!\n");
    }

    return 0;
}

void initialize_board(int board[], int hidden[], int size)
{
    int i, j;
    int num_pairs = size / 2;
    int pairs[num_pairs];

    srand(time(NULL));

    // Generate random pairs
    for (i = 0; i < num_pairs; i++)
    {
        int pair;
        do
        {
            pair = rand() % 9 + 1;
        } while (pairs_contains(pairs, num_pairs, pair));
        pairs[i] = pair;
    }

    // Copy pairs to the board
    for (i = 0; i < num_pairs; i++)
    {
        for (j = 0; j < 2; j++)
        {
            int index;
            do
            {
                index = rand() % size;
            } while (board[index] != 0);
            board[index] = pairs[i];
        }
    }

    // Initialize hidden board
    for (i = 0; i < size; i++)
    {
        hidden[i] = 1;
    }
}

int pairs_contains(int pairs[], int size, int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (pairs[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

void print_board(int board[], int hidden[])
{
    int i;

    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        if (hidden[i])
        {
            printf("* ");
        }
        else
        {
            printf("%d ", board[i]);
        }
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int get_move(int board[], int hidden[], int moves[])
{
    int move;
    printf("Enter a move (1-%d): ", BOARD_SIZE);
    scanf("%d", &move);
    moves[move - 1] = move;
    return move - 1;
}

int check_move(int board[], int hidden[], int moves[], int move)
{
    if (move < 0 || move >= BOARD_SIZE)
    {
        return 0;
    }
    if (!hidden[move])
    {
        return 0;
    }
    if (moves[move] != 0)
    {
        return 0;
    }
    return 1;
}

void reveal(int board[], int hidden[], int move)
{
    hidden[move] = 0;
}

void hide(int board[], int hidden[], int move)
{
    hidden[move] = 1;
}

int has_won(int hidden[])
{
    int i;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        if (hidden[i])
        {
            return 0;
        }
    }
    return 1;
}