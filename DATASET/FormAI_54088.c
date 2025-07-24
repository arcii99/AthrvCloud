//FormAI DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>

//Function to print the checkerboard
void print_board(int board[8][8])
{
    printf("  1 2 3 4 5 6 7 8\n");
    printf("------------------\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d|", i + 1);
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 0)
            {
                printf("  ");
            }
            else if (board[i][j] == 1)
            {
                printf("x ");
            }
            else if (board[i][j] == 2)
            {
                printf("o ");
            }
        }
        printf("|%d\n", i + 1);
    }
    printf("------------------\n");
    printf("  1 2 3 4 5 6 7 8\n");
}

//Function to check if a move is valid
int is_valid_move(int board[8][8], int current_player, int row1, int col1, int row2, int col2)
{
    if (row2 < 0 || row2 > 7 || col2 < 0 || col2 > 7)
    {
        return 0;
    }
    if (board[row2][col2] != 0)
    {
        return 0;
    }
    if (current_player == 1)
    {
        if (row2 != row1 - 1 || (col2 != col1 - 1 && col2 != col1 + 1))
        {
            if (row1-row2 == 2 && (col1-col2 == 2 || col2-col1 == 2)) {
                if (board[row1-1][(col1+col2)/2] == 2) {
                    board[row1-1][(col1+col2)/2] = 0;
                    return 1;
                }
                return 0;
            }
            return 0;
        }
    }
    else
    {
        if (row2 != row1 + 1 || (col2 != col1 - 1 && col2 != col1 + 1))
        {
            if (row2-row1 == 2 && (col1-col2 == 2 || col2-col1 == 2)) {
                if (board[row1+1][(col1+col2)/2] == 1) {
                    board[row1+1][(col1+col2)/2] = 0;
                    return 1;
                }
                return 0;
            }
            return 0;
        }
    }
    return 1;
}

//Function to check if the game is over
int is_game_over(int board[8][8])
{
    int x_count = 0, o_count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 1)
            {
                x_count++;
            }
            else if (board[i][j] == 2)
            {
                o_count++;
            }
        }
    }
    if (x_count == 0 || o_count == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    //Initialize the board
    int board[8][8] = {{0, 2, 0, 2, 0, 2, 0, 2},
                       {2, 0, 2, 0, 2, 0, 2, 0},
                       {0, 2, 0, 2, 0, 2, 0, 2},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {1, 0, 1, 0, 1, 0, 1, 0},
                       {0, 1, 0, 1, 0, 1, 0, 1},
                       {1, 0, 1, 0, 1, 0, 1, 0}};

    int current_player = 1;
    int game_over = 0;
    int row1, col1, row2, col2;

    printf("Welcome to Checkers!\n\n");

    while (!game_over)
    {
        printf("Player %d's Turn:\n", current_player);

        print_board(board);

        printf("Enter the row and column of the checker you want to move: ");
        scanf("%d %d", &row1, &col1);

        printf("Enter the row and column of the location you want to move the checker to: ");
        scanf("%d %d", &row2, &col2);

        if (is_valid_move(board, current_player, row1 - 1, col1 - 1, row2 - 1, col2 - 1))
        {
            board[row2 - 1][col2 - 1] = board[row1 - 1][col1 - 1];
            board[row1 - 1][col1 - 1] = 0;
            if (current_player == 1 && row2 == 1 || current_player == 2 && row2 == 8) {
                board[row2 - 1][col2 - 1] = current_player + 2;
            }
            if (!is_game_over(board)) {
                current_player = (current_player == 1) ? 2 : 1;
            }
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }

        game_over = is_game_over(board);
    }

    print_board(board);

    if (current_player == 1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }

    return 0;
}