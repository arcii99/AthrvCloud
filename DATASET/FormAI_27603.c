//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 10
#define NUM_SHIPS 3
#define SHIP_SIZE 3

void clear_board(int board[][BOARD_SIZE]);
void show_board(int board[][BOARD_SIZE], int show_all);
int get_random(int limit);
int place_ship(int board[][BOARD_SIZE], int row, int col, int direction);
int check_win(int board[][BOARD_SIZE]);
int check_hit(int board[][BOARD_SIZE], int row, int col);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int player_1_board[BOARD_SIZE][BOARD_SIZE];
    int player_2_board[BOARD_SIZE][BOARD_SIZE];
    int player_1_hits[BOARD_SIZE][BOARD_SIZE];
    int player_2_hits[BOARD_SIZE][BOARD_SIZE];
    int player_turn = 1;
    int i, j;
    int row, col;
    int valid_input = 0;
    int hit_result;

    srand((unsigned) time(NULL));
    clear_board(board);
    clear_board(player_1_board);
    clear_board(player_2_board);
    clear_board(player_1_hits);
    clear_board(player_2_hits);

    printf("Welcome to the Battleship Game!\n\n");

    /* place random ships for player 1 */
    for (i = 0; i < NUM_SHIPS; i++)
    {
        do{
            row = get_random(BOARD_SIZE);
            col = get_random(BOARD_SIZE);
        } while(!place_ship(player_1_board, row, col, get_random(2)));
    }

    /* place random ships for player 2 */
    for (i = 0; i < NUM_SHIPS; i++)
    {
        do {
            row = get_random(BOARD_SIZE);
            col = get_random(BOARD_SIZE);
        } while(!place_ship(player_2_board, row, col, get_random(2)));
    }

    do
    {
        /* print current player's board */
        if(player_turn == 1)
        {
            show_board(player_1_board, 1);
            printf("Player 1's turn.\n");
        }
        else
        {
            show_board(player_2_board, 1);
            printf("Player 2's turn.\n");
        }

        /* get row and column input */
        valid_input = 0;
        while (!valid_input)
        {
            printf("Enter a row (0 to %d) and column (0 to %d): ", BOARD_SIZE - 1, BOARD_SIZE - 1);
            scanf("%d %d", &row, &col);
            getchar(); /* consume newline character */
            valid_input = ((row >= 0) && (row < BOARD_SIZE) && (col >= 0) && (col < BOARD_SIZE));
            if (!valid_input)
            {
                printf("Invalid input. ");
            }
        }

        /* check for hit or miss */
        if (player_turn == 1)
        {
            hit_result = check_hit(player_2_board, row, col);
            if (hit_result)
            {
                printf("Hit!\n");
                player_1_hits[row][col] = 1;
            }
            else
            {
                printf("Miss!\n");
            }
            if(check_win(player_2_board))
            {
                printf("Player 1 wins!\n");
                break;
            }
        }
        else
        {
            hit_result = check_hit(player_1_board, row, col);
            if (hit_result)
            {
                printf("Hit!\n");
                player_2_hits[row][col] = 1;
            }
            else
            {
                printf("Miss!\n");
            }
            if(check_win(player_1_board))
            {
                printf("Player 2 wins!\n");
                break;
            }
        }

        /* switch turn */
        if(hit_result == 0)
        {
            player_turn = (player_turn == 1) ? 2 : 1;
        }
    } while(1);

    return 0;
}

void clear_board(int board[][BOARD_SIZE])
{
    int i, j;

    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}

void show_board(int board[][BOARD_SIZE], int show_all)
{
    int i, j;

    printf("    ");
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d |", i);
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == 1 || show_all == 1)
            {
                printf("* ");
            }
            else if(board[i][j] == 2)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int get_random(int limit)
{
    return rand() % limit;
}

int place_ship(int board[][BOARD_SIZE], int row, int col, int direction)
{
    int i, j;

    if(direction == 0)
    {
        /* horizontal */
        if ((col + SHIP_SIZE) > BOARD_SIZE)
        {
            return 0;
        }
        for (i = col; i < (col + SHIP_SIZE); i++)
        {
            if (board[row][i] == 1)
            {
                return 0;
            }
        }
        for (i = col; i < (col + SHIP_SIZE); i++)
        {
            board[row][i] = 1;
        }
    }
    else
    {
        /* vertical */
        if ((row + SHIP_SIZE) > BOARD_SIZE)
        {
            return 0;
        }
        for (i = row; i < (row + SHIP_SIZE); i++)
        {
            if (board[i][col] == 1)
            {
                return 0;
            }
        }
        for (i = row; i < (row + SHIP_SIZE); i++)
        {
            board[i][col] = 1;
        }
    }

    return 1;
}

int check_win(int board[][BOARD_SIZE])
{
    int i, j;
    int hit_count = 0;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 1)
            {
                return 0;
            }
        }
    }

    return 1;
}

int check_hit(int board[][BOARD_SIZE], int row, int col)
{
    if (board[row][col] == 1)
    {
        board[row][col] = 2;
        return 1;
    }
    else
    {
        return 0;
    }
}