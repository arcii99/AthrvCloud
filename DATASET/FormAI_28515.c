//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hey there! Let me show you a unique C pattern :)\n\n");

    int col, row, height;
    height = 10; //changing the value of height can alter the height of the pattern

    for(row=1; row<=height; row++)
    {
        for(col=1; col<=height; col++)
        {
            if(row == 1 || row == height || col == 1 || col == height) //checks if it's the first or last row or column
            {
                printf("C ");
            }
            else if(row == (height/2)+1 && col > 2 && col < height-1)
            {
                printf("C ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\nYay! You just printed a cheerful C pattern! :D\n");

    return 0;
}