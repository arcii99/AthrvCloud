//FormAI DATASET v1.0 Category: Image Classification system ; Style: recursive
#include <stdio.h>

void classifyImage(int image[][3], int row, int col, int count[])
{
    int i, j;
    int blueCount = 0, yellowCount = 0, whiteCount = 0;
    int newrow, newcol;

    if (row >= 0 && col >= 0 && row < 3 && col < 3)
    {
        if (image[row][col] == 1)
        {
            count[0]++;
            image[row][col] = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    newrow = row + i;
                    newcol = col + j;
                    classifyImage(image, newrow, newcol, count);
                }
            }
        }
        else if (image[row][col] == 2)
        {
            count[1]++;
            image[row][col] = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    newrow = row + i;
                    newcol = col + j;
                    classifyImage(image, newrow, newcol, count);
                }
            }
        }
        else if (image[row][col] == 3)
        {
            count[2]++;
            image[row][col] = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    newrow = row + i;
                    newcol = col + j;
                    classifyImage(image, newrow, newcol, count);
                }
            }
        }
    }
}

int main()
{
    int image[3][3] = {{1, 2, 1}, {2, 1, 3}, {3, 3, 2}};
    int count[3] = {0, 0, 0};
    classifyImage(image, 0, 0, count);

    printf("Blue pixels: %d\n", count[0]);
    printf("Yellow pixels: %d\n", count[1]);
    printf("White pixels: %d\n", count[2]);

    return 0;
}