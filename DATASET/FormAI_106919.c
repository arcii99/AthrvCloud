//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char pixelArt[20][20];
    int i, j;

    //Fill array with empty space character
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            pixelArt[i][j] = ' ';
        }
    }

    //Draw castle walls
    for(i=0; i<20; i++)
    {
        pixelArt[0][i] = '|';
        pixelArt[19][i] = '|';
    }
    for(i=1; i<19; i++)
    {
        pixelArt[i][0] = '-';
        pixelArt[i][19] = '-';
    }

    //Draw towers
    for(i=3; i<8; i++)
    {
        pixelArt[i][3] = '*';
        pixelArt[i][16] = '*';
    }
    for(i=4; i<7; i++)
    {
        pixelArt[2][i] = '*';
        pixelArt[17][i] = '*';
    }
    for(i=13; i<17; i++)
    {
        pixelArt[2][i] = '*';
        pixelArt[17][i] = '*';
    }
    for(i=4; i<7; i++)
    {
        pixelArt[i][2] = '*';
        pixelArt[i][17] = '*';
    }
    for(i=13; i<17; i++)
    {
        pixelArt[i][2] = '*';
        pixelArt[i][17] = '*';
    }

    //Draw door
    for(i=9; i<12; i++)
    {
        pixelArt[i][0] = ' ';
        pixelArt[i][1] = ' ';
    }
    pixelArt[11][0] = '|';

    //Draw windows
    for(i=4; i<7; i++)
    {
        pixelArt[6][i] = '#';
        pixelArt[13][i] = '#';
    }

    //Draw flags
    for(i=0; i<20; i++)
    {
        if(rand() % 2 == 0)
        {
            pixelArt[0][i] = 'F';
        }
        if(rand() % 2 == 0)
        {
            pixelArt[19][i] = 'F';
        }
    }

    //Print pixel art
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}