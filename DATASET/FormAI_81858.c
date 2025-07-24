//FormAI DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Initialization
    int image[3][3] = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int kernel[2][2] = {{1, 1}, {1, 1}};
    int result[2][2] = {{0, 0}, {0, 0}};

    // Convolution
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int sum = 0;
            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    sum += image[i+x][j+y] * kernel[x][y];
                }
            }
            result[i][j] = sum; 
        }
    }

    // Print result
    printf("The classified image is: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", (result[i][j] > 2) ? 1 : 0);
        }
        printf("\n");
    }

    return 0;
}