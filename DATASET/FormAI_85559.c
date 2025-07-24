//FormAI DATASET v1.0 Category: Chess engine ; Style: unmistakable
#include <stdio.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board();
void print_board();

int main()
{
    initialize_board();
    print_board();
    return 0;
}

void initialize_board()
{
    // Initialize board with blank spaces
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Initialize pawns
    for(int i=0; i<BOARD_SIZE; i++)
    {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }

    // Initialize rooks
    board[0][0] = 'r';
    board[0][7] = 'r';
    board[7][0] = 'R';
    board[7][7] = 'R';

    // Initialize knights
    board[0][1] = 'n';
    board[0][6] = 'n';
    board[7][1] = 'N';
    board[7][6] = 'N';

    // Initialize bishops
    board[0][2] = 'b';
    board[0][5] = 'b';
    board[7][2] = 'B';
    board[7][5] = 'B';

    // Initialize queens
    board[0][3] = 'q';
    board[7][3] = 'Q';

    // Initialize kings
    board[0][4] = 'k';
    board[7][4] = 'K';
}

void print_board()
{
    printf("  a b c d e f g h\n");
    for(int i=0; i<BOARD_SIZE; i++)
    {
        printf("%d ", BOARD_SIZE-i);
        for(int j=0; j<BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", BOARD_SIZE-i);
    }
    printf("  a b c d e f g h\n");
}