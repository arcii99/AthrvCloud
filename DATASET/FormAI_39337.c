//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 500
#define HEIGHT 500

int main()
{
    // create the image array
    char image[WIDTH][HEIGHT];

    // initialize the image to white spaces
    for(int i=0; i<WIDTH; i++)
        for(int j=0; j<HEIGHT; j++)
            image[i][j] = ' ';

    // draw a castle
    for(int i=0; i<WIDTH; i++)
    {
        if(i>=50 && i<=100)
        {
            for(int j=200; j<HEIGHT; j++)
                image[i][j] = '|';
        }
        if(i>=130 && i<=180)
        {
            for(int j=180; j<HEIGHT-20; j++)
                image[i][j] = '|';
        }
        if(i>=160 && i<=220)
        {
            for(int j=200; j<HEIGHT-50; j++)
                image[i][j] = '-';
        }
        if(i>=190 && i<=210)
        {
            for(int j=230; j<HEIGHT-70; j++)
                image[i][j] = '-';
        }
    }

    // add some text
    char text[] = "MEDIEVAL EDITOR";
    int len = sizeof(text)/sizeof(text[0]);
    for(int i=0; i<len; i++)
        image[350][i+200] = text[i];

    // print the final image
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
            printf("%c", image[i][j]);
        printf("\n");
    }

    return 0;
}