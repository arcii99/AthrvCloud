//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int gen[8][8]; // generate a 2D array to store pixel art

    // loop through the entire 2D array and randomly assign 0 or 1 to each element
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            gen[i][j] = rand() % 2;
        }
    }

    // loop through the entire 2D array and display the pixel art
    printf("\n Here is your pixel art: \n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gen[i][j] == 0)
            {
                printf("  "); // print two spaces to represent a black pixel
            }
            else
            {
                printf("██"); // print two full block characters to represent a white pixel
            }
        }
        printf("\n");
    }
    return 0;
}