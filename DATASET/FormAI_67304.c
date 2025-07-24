//FormAI DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(char board[][BOARD_SIZE])
{
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void shuffle(char *arr, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

int main()
{
    srand(time(NULL));
    
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'1', '2', '3', '4'},
        {'5', '6', '7', '8'},
        {'9', 'A', 'B', 'C'},
        {'D', 'E', 'F', 'G'}
    };
    
    int size = BOARD_SIZE*BOARD_SIZE;
    char arr[size];
    int idx = 0;
    
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            arr[idx++] = board[i][j];
        }
    }
    
    shuffle(arr, size);
    
    idx = 0;
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            board[i][j] = arr[idx++];
        }
    }
    
    print_board(board);
    
    return 0;
}