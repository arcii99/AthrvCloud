//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: paranoid
#include <stdio.h>

int main()
{
    // Print a paranoid message to scare off anyone trying to hack into our program
    printf("WARNING: Unauthorized access detected. Alerting security... \n\n");

    // Creating a 2D array to simulate an image
    int image[4][4] = {{10, 20, 30, 40},
                       {50, 60, 70, 80},
                       {90, 100, 110, 120},
                       {130, 140, 150, 160}};

    // Flipping the image horizontally
    printf("Flipping the image horizontally... \n");
    int temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][3-j];
            image[i][3-j] = temp;
        }
    }

    // Changing the brightness of the image
    printf("Changing the brightness of the image... \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            image[i][j] += 30;
        }
    }

    // Changing the contrast of the image
    printf("Changing the contrast of the image... \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            image[i][j] = (int)(image[i][j] * 1.2);
        }
    }

    // Printing the final image
    printf("Final image: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Ending with a threatening message for anyone trying to steal our code
    printf("\nWARNING: Attempting to copy or modify this code will result in severe consequences. \n");
    return 0;
}