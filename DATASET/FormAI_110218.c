//FormAI DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(char board[][BOARD_SIZE]);

void initialize_board(char board[][BOARD_SIZE], char symbols[]);

void shuffle_symbols(char symbols[]);

int is_valid_selection(int selection, char board[][BOARD_SIZE]);

int is_game_over(char board[][BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int card1_row, card1_col, card2_row, card2_col;
    int num_turns = 0;
    
    srand(time(NULL));
    
    initialize_board(board, symbols);
    
    while (!is_game_over(board))
    {
        print_board(board);
        
        printf("Enter the row and column numbers of the first card: ");
        scanf("%d %d", &card1_row, &card1_col);
        
        while (!is_valid_selection(card1_row * 10 + card1_col, board))
        {
            printf("\nInvalid selection.\n");
            printf("\nEnter the row and column numbers of the first card: ");
            scanf("%d %d", &card1_row, &card1_col);
        }
        
        board[card1_row][card1_col] = symbols[card1_row * BOARD_SIZE + card1_col];
        print_board(board);
        
        printf("Enter the row and column numbers of the second card: ");
        scanf("%d %d", &card2_row, &card2_col);
        
        while (!is_valid_selection(card2_row * 10 + card2_col, board))
        {
            printf("\nInvalid selection.\n");
            printf("\nEnter the row and column numbers of the second card: ");
            scanf("%d %d", &card2_row, &card2_col);
        }
        
        board[card2_row][card2_col] = symbols[card2_row * BOARD_SIZE + card2_col];
        print_board(board);
        
        if (board[card1_row][card1_col] != board[card2_row][card2_col])
        {
            printf("\nSorry, the cards do not match. Try again.\n");
            board[card1_row][card1_col] = 'X';
            board[card2_row][card2_col] = 'X';
        }
        else
        {
            printf("\nYou found a match!\n");
        }
        
        num_turns++;
    }
    
    printf("\nCongratulations, you have completed the game in %d turns!\n", num_turns);
    
    return 0;
}

void print_board(char board[][BOARD_SIZE])
{
    int i, j;
    printf("\n   ");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("- ");
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d |", i);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[][BOARD_SIZE], char symbols[])
{
    int i, j, k;
    char temp;
    
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        board[i / BOARD_SIZE][i % BOARD_SIZE] = 'X';
    }
    
    shuffle_symbols(symbols);
    
    k = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = symbols[k];
            k++;
        }
    }
}

void shuffle_symbols(char symbols[])
{
    int i, j;
    char temp;
    
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        j = rand() % (BOARD_SIZE * BOARD_SIZE);
        temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

int is_valid_selection(int selection, char board[][BOARD_SIZE])
{
    int row = selection / 10;
    int col = selection % 10;
    
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        return 0;
    }
    
    if (board[row][col] != 'X')
    {
        return 0;
    }
    
    return 1;
}

int is_game_over(char board[][BOARD_SIZE])
{
    int i, j;
    
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'X')
            {
                return 0;
            }
        }
    }
    return 1;
}