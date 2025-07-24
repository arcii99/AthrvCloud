//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char pixelArt[8][8];  //define 8x8 pixel art
    int i, j;

    //initialize pixel art with random values
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            int num = rand() % 2;  //random 0 or 1
            if(num == 0){   //if 0, pixel is white
                pixelArt[i][j] = '-';
            }
            else{   //if 1, pixel is black
                pixelArt[i][j] = '*';
            }
        }
    }

    //printing pixel art
    printf("Here is your Sherlock Holmes inspired pixel art:\n");
    printf("---------------------------------------------\n");
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");

    return 0;
}