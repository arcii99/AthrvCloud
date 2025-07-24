//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j;
    int width = 20;
    int height = 20;
    int pixels[20][20];

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if((i==1 && j>=6 && j<=13) || (i==4 && j>=5 && j<=14) || (j==4 && i>=6 && i<=8) || (j==15 && i>=6 && i<=8) || (i==9 && j>=6 && j<=13) )
                pixels[i][j] = 1;
            else
                pixels[i][j] = 0;
        }
    }

    // Print the generated pixel art
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(pixels[i][j] == 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}