//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include<stdio.h>
#define ROWS 5
#define COLS 5

int main()
{
    char c[ROWS][COLS]={{' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' '},
                       {' ',' ','O',' ',' '},
                       {' ','|',' ','|',' '},
                       {'/',' ',' ',' ','\\'}};

    int i,j;

    printf("\nASCII Art Generator\n");

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}