//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 255

int main()
{
    FILE *inFile, *outFile;
    char inFileName[50], outFileName[50];
    char option;
    int numRows, numCols, maxVal, pixel, row, col, newPixel, i, j;

    printf("Enter the name of the input file: ");
    scanf("%s", inFileName);

    inFile = fopen(inFileName, "r");

    if (inFile == NULL)
    {
        printf("Cannot open file.\n");
        exit(0);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", outFileName);

    printf("Choose an option:\n");
    printf("f - flip image horizontally\n");
    printf("v - flip image vertically\n");
    printf("b - adjust brightness\n");
    printf("c - adjust contrast\n");
    scanf(" %c", &option);

    fscanf(inFile, "%d %d %d", &numRows, &numCols, &maxVal);

    int image[numRows][numCols];

    for (row = 0; row < numRows; row++)
    {
        for (col = 0; col < numCols; col++)
        {
            fscanf(inFile, "%d", &pixel);
            image[row][col] = pixel;
        }
    }

    outFile = fopen(outFileName, "w");

    if (outFile == NULL)
    {
        printf("Cannot create file.\n");
        exit(0);
    }

    switch (option)
    {
        case 'f':
            for (i = 0; i < numRows; i++)
            {
                for (j = numCols - 1; j >= 0; j--)
                {
                    fprintf(outFile, "%d ", image[i][j]);
                }
                fprintf(outFile, "\n");
            }
            printf("Image flipped horizontally and saved to file.\n");
            break;
        case 'v':
            for (i = numRows - 1; i >= 0; i--)
            {
                for(j = 0; j < numCols; j++)
                {
                    fprintf(outFile, "%d ", image[i][j]);
                }
                fprintf(outFile, "\n");
            }
            printf("Image flipped vertically and saved to file.\n");
            break;
        case 'b':
            int brightness;
            printf("Enter the brightness adjustment (-%d to +%d): ", MAX, MAX);
            scanf("%d", &brightness);
            for (i = 0; i < numRows; i++)
            {
                for(j = 0; j < numCols; j++)
                {
                    newPixel = image[i][j] + brightness;
                    if (newPixel > MAX)
                        newPixel = MAX;
                    if (newPixel < 0)
                        newPixel = 0;
                    fprintf(outFile, "%d ", newPixel);
                }
                fprintf(outFile, "\n");
            }
            printf("Brightness adjusted and saved to file.\n");
            break;
        case 'c':
            float contrast;
            printf("Enter the contrast adjustment (1 to 10): ");
            scanf("%f", &contrast);
            contrast /= 10;
            for (i = 0; i < numRows; i++)
            {
                for(j = 0; j < numCols; j++)
                {
                    newPixel = contrast * (image[i][j] - (MAX / 2)) + (MAX / 2);
                    if (newPixel > MAX)
                        newPixel = MAX;
                    if (newPixel < 0)
                        newPixel = 0;
                    fprintf(outFile, "%d ", newPixel);
                }
                fprintf(outFile, "\n");
            }
            printf("Contrast adjusted and saved to file.\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}