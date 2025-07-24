//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50], option;
    int width, height, maxVal, i, j, k;

    printf("Enter the file name of the input image: ");
    scanf("%s", inputFileName);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL)
    {
        printf("Could not open file %s\n", inputFileName);
        return 1;
    }

    // Read the image dimensions and max pixel value
    fscanf(inputFile, "P3\n%d %d\n%d\n", &width, &height, &maxVal);

    // Allocate memory for the input and output images
    int **inputImage = (int **)malloc(height * sizeof(int *));
    int **outputImage = (int **)malloc(height * sizeof(int *));
    for (i=0; i<height; i++)
    {
        inputImage[i] = (int *)malloc(width * sizeof(int));
        outputImage[i] = (int *)malloc(width * sizeof(int));
    }

    // Read the input image pixels
    for (i=0; i<height; i++)
    {
        for (j=0; j<width; j++)
        {
            fscanf(inputFile, "%d %d %d", &inputImage[i][j], &inputImage[i][j+1], &inputImage[i][j+2]);
        }
    }

    // Close the input file
    fclose(inputFile);

    printf("Enter an option:\n");
    printf("'f' to flip the image\n");
    printf("'b' to change the brightness\n");
    printf("'c' to change the contrast\n");
    scanf("%c", &option);

    switch (option)
    {
        case 'f':
            // Flip the image vertically
            for (i=0; i<height; i++)
            {
                for (j=0, k=width-1; j<width; j++, k--)
                {
                    outputImage[i][j] = inputImage[i][k];
                }
            }
            break;

        case 'b':
            // Change the brightness
            int brightness;
            printf("Enter a brightness value (between -255 and 255): ");
            scanf("%d", &brightness);

            if (brightness < -255 || brightness > 255)
            {
                printf("Invalid brightness value\n");
                return 1;
            }

            for (i=0; i<height; i++)
            {
                for (j=0; j<width; j++)
                {
                    outputImage[i][j] = inputImage[i][j] + brightness;
                    if (outputImage[i][j] > maxVal) outputImage[i][j] = maxVal;
                    if (outputImage[i][j] < 0) outputImage[i][j] = 0;
                }
            }
            break;

        case 'c':
            // Change the contrast
            int contrast;
            printf("Enter a contrast value (between -100 and 100): ");
            scanf("%d", &contrast);

            if (contrast < -100 || contrast > 100)
            {
                printf("Invalid contrast value\n");
                return 1;
            }

            float factor = (259*(contrast + 255))/(255*(259 - contrast));
            for (i=0; i<height; i++)
            {
                for (j=0; j<width; j++)
                {
                    outputImage[i][j] = factor*(inputImage[i][j] - 128) + 128;
                    if (outputImage[i][j] > maxVal) outputImage[i][j] = maxVal;
                    if (outputImage[i][j] < 0) outputImage[i][j] = 0;
                }
            }
            break;

        default:
            printf("Invalid option\n");
            return 1;
    }

    printf("Enter the file name of the output image: ");
    scanf("%s", outputFileName);

    // Open the output file for writing
    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL)
    {
        printf("Could not open file %s\n", outputFileName);
        return 1;
    }

    // Write the output image in P3 format
    fprintf(outputFile, "P3\n%d %d\n%d\n", width, height, maxVal);
    for (i=0; i<height; i++)
    {
        for (j=0; j<width; j++)
        {
            fprintf(outputFile, "%d %d %d ", outputImage[i][j], outputImage[i][j], outputImage[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    // Close the output file
    fclose(outputFile);

    // Deallocate memory for the input and output images
    for (i=0; i<height; i++)
    {
        free(inputImage[i]);
        free(outputImage[i]);
    }
    free(inputImage);
    free(outputImage);

    printf("Done\n");

    return 0;
}