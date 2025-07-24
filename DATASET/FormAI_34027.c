//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int row, column, n, i, j;
    char pixelColorChar[7] = {'#', 'R', 'G', 'B', 'Y', 'C', 'M'};
    srand(time(NULL));
    printf("Enter the number of rows and columns separated by a space: ");
    scanf("%d %d", &row, &column);
    printf("Enter the number of unique colors (from 1 to 6): ");
    scanf("%d", &n);
    char pixel[row][column];

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < column; j++)
        {
            int randomColor = rand() % n + 1;
            pixel[i][j] = pixelColorChar[randomColor];
            printf("%c", pixel[i][j]);
        }
        printf("\n");
    }

    return 0;
}