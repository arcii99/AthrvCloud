//FormAI DATASET v1.0 Category: Checkers Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define BLANK '-'
#define SIZE 8

char board[SIZE][SIZE]; // 8x8 checkers board

void initialize_board()
{
    int i, j;
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (i < 3)
                    board[i][j] = 'O';
                else if (i > 4)
                    board[i][j] = 'X';
                else
                    board[i][j] = BLANK;
            }
            else
                board[i][j] = BLANK;
        }
    }
}

void print_board()
{
    int i, j;
    
    printf("  0 1 2 3 4 5 6 7\n");
    
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for (j = 0; j < SIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int is_valid_move(int from_row, int from_col, int to_row, int to_col, char player)
{
    if (from_row < 0 || from_row >= SIZE || from_col < 0 || from_col >= SIZE || to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE)
        return 0;
    
    if (board[to_row][to_col] != BLANK)
        return 0;
    
    if (player == 'X')
    {
        if (to_row < from_row)
            return 0;
        
        if (to_row - from_row == 1 && abs(to_col - from_col) == 1)
            return 1;
        
        if (to_row - from_row == 2 && abs(to_col - from_col) == 2)
        {
            int middle_row = (to_row + from_row) / 2;
            int middle_col = (to_col + from_col) / 2;
            
            if (board[middle_row][middle_col] == 'O')
                return 1;
        }
    }
    else if (player == 'O')
    {
        if (to_row > from_row)
            return 0;
        
        if (from_row - to_row == 1 && abs(to_col - from_col) == 1)
            return 1;
        
        if (from_row - to_row == 2 && abs(to_col - from_col) == 2)
        {
            int middle_row = (to_row + from_row) / 2;
            int middle_col = (to_col + from_col) / 2;
            
            if (board[middle_row][middle_col] == 'X')
                return 1;
        }
    }
    
    return 0;
}

int apply_move(int from_row, int from_col, int to_row, int to_col, char player)
{
    board[to_row][to_col] = player;
    board[from_row][from_col] = BLANK;
    
    if (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2)
    {
        int middle_row = (to_row + from_row) / 2;
        int middle_col = (to_col + from_col) / 2;
        board[middle_row][middle_col] = BLANK;
        return 1;
    }
    
    return 0;
}

int is_game_over()
{
    int i, j;
    int count_X = 0, count_O = 0;
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'x')
                count_X++;
            
            if (board[i][j] == 'O' || board[i][j] == 'o')
                count_O++;
        }
    }
    
    if (count_X == 0 || count_O == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char player = 'X';
    int from_row, from_col, to_row, to_col;
    int valid_move, capture;
    
    printf("Welcome to the Checkers Game!\n");
    printf("==============================================\n\n");
    
    initialize_board();
    
    while (!is_game_over())
    {
        printf("%c's turn to move\n", player);
        print_board();
        
        capture = 0;
        do
        {
            valid_move = 0;
            printf("Enter the row and column of the checker to move\n");
            scanf("%d %d", &from_row, &from_col);
            
            if (board[from_row][from_col] == player || board[from_row][from_col] == toupper(player))
            {
                printf("Enter the row and column of the destination\n");
                scanf("%d %d", &to_row, &to_col);
                
                valid_move = is_valid_move(from_row, from_col, to_row, to_col, player);
                
                if (valid_move)
                    capture = apply_move(from_row, from_col, to_row, to_col, player);
            }
            
            if (!valid_move)
                printf("Invalid move, please try again\n");
            
        } while (valid_move && capture);
        
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
    
    printf("%c wins!\n", player);
    
    return 0;
}