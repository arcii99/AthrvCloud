//FormAI DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>

char board[8][8] = {{'w',' ','w',' ','w',' ','w',' '},
                    {' ','w',' ','w',' ','w',' ','w'},
                    {'w',' ','w',' ','w',' ','w',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ','b',' ','b',' ','b',' ','b'},
                    {'b',' ','b',' ','b',' ','b',' '},
                    {' ','b',' ','b',' ','b',' ','b'}};

void print_board()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    print_board();
}