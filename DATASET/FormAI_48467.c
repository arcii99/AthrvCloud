//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void initialize_board(int board[][BOARD_SIZE], int count)
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = (count / 2) > i * BOARD_SIZE + j ? count / 2 - i * BOARD_SIZE - j : count - 1 - (i * BOARD_SIZE + j - count / 2);
        }
    }
}

void randomize_board(int board[][BOARD_SIZE], int count)
{
    srand(time(NULL));
    for(int i = 0; i < count * 2; i++)
    {
        int x1 = rand() % BOARD_SIZE;
        int y1 = rand() % BOARD_SIZE;
        int x2 = rand() % BOARD_SIZE;
        int y2 = rand() % BOARD_SIZE;
        
        int temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }
}

void print_board(int board[][BOARD_SIZE])
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_board(int board[][BOARD_SIZE], int x1, int y1, int x2, int y2)
{
    if(board[x1][y1] != board[x2][y2])
    {
        return 0;
    }
    board[x1][y1] = -1;
    board[x2][y2] = -1;
    return 1;
}

int check_win(int board[][BOARD_SIZE])
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] != -1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int count = BOARD_SIZE * BOARD_SIZE;
    
    initialize_board(board, count);
    randomize_board(board, count);
    
    while(1)
    {
        print_board(board);
        
        printf("Enter coordinates of two cards (x1 y1 x2 y2): ");
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        
        if(x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
        {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        if(board[x1][y1] == -1 || board[x2][y2] == -1)
        {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        
        if(check_board(board, x1, y1, x2, y2))
        {
            printf("You found a match!\n");
            if(check_win(board))
            {
                printf("Congratulations, you won!\n");
                break;
            }
        }
        else
        {
            printf("Sorry, try again.\n");
        }
    }
    
    return 0;
}