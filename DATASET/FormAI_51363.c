//FormAI DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 4
#define MAX_MOVES BOARD_SIZE*BOARD_SIZE*2

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int* arr, int n)
{
    srand(time(NULL));
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n---------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("| %2d ", board[i][j]);
        }
        printf("|\n---------------------\n");
    }
}

int check_win_condition(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != (i*BOARD_SIZE) + (j+1))
            {
                return 0;
            }
        }
    }
    return 1;
}

int make_move(int board[BOARD_SIZE][BOARD_SIZE], char move)
{
    int empty_row, empty_col, move_row, move_col, temp;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
    }

    switch(move)
    {
        case 'U':
            move_row = empty_row+1;
            move_col = empty_col;
            break;
        case 'D':
            move_row = empty_row-1;
            move_col = empty_col;
            break;
        case 'L':
            move_row = empty_row;
            move_col = empty_col+1;
            break;
        case 'R':
            move_row = empty_row;
            move_col = empty_col-1;
            break;
        default:
            return 0;
    }
    
    if (move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE)
    {
        return 0;
    }

    temp = board[move_row][move_col];
    board[move_row][move_col] = board[empty_row][empty_col];
    board[empty_row][empty_col] = temp;

    return 1;
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    char moves[MAX_MOVES];
    int num_moves = 0;
    int input, game_over = 0;

    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = (i*BOARD_SIZE) + (j+1);
        }
    }
    board[BOARD_SIZE-1][BOARD_SIZE-1] = 0;

    shuffle((int*)board, BOARD_SIZE*BOARD_SIZE);

    printf("Welcome to the Memory Game!\n\n");
    printf("Use the following keys to make your moves:\n");
    printf("U (up), D (down), L (left), R (right)\n\n");
    printf("Press 1 to start game: ");

    scanf("%d", &input);

    if (input == 1)
    {
        while (!game_over)
        {
            system("clear");
            print_board(board);

            if (check_win_condition(board))
            {
                printf("\nCONGRATULATIONS! YOU WIN!\n");
                printf("NUMBER OF MOVES: %d\n\n", num_moves);
                game_over = 1;
                break;
            }

            printf("\nEnter move (U/D/L/R): ");
            scanf(" %c", &moves[num_moves]);

            if (make_move(board, moves[num_moves]))
            {
                num_moves++;
            }
            else
            {
                printf("\nINVALID MOVE!\n");
            }
        }
    }
    else
    {
        printf("Invalid input. Quitting game.\n");
    }

    return 0;
}