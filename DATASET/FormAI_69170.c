//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));   // seed the random number generator

    char pixelArt[8][8];  // create a 2D array for pixel art

    // generate random happy pixel art
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int randomNum = rand() % 2;   // generate random 0 or 1
            pixelArt[i][j] = (randomNum == 0) ? ':' : ')';  // set pixel to ':' or ')'
        }
    }

    // print the pixel art
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}