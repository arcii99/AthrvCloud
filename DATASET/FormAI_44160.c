//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fp;
    char fname[100];
    int width, height, maxval;
    unsigned char *image;

    printf("Enter the name of the image file: ");
    scanf("%s", fname);

    fp = fopen(fname, "rb");
    if (fp == NULL)
    {
        printf("Error: can't open the file %s\n", fname);
        exit(1);
    }

    fscanf(fp, "%*s%d%d%d%*c", &width, &height, &maxval);
    image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Task 1: Flipping the image
    unsigned char *flipped_image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    int col, row;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            flipped_image[row*width + col] = image[(height - row - 1)*width + col];
        }
    }

    // Task 2: Adjusting Brightness
    unsigned char *bright_image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    int brightness = 50;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            int val = image[row*width + col] + brightness;
            if (val < 0)
                val = 0;
            else if (val > maxval)
                val = maxval;
            bright_image[row*width + col] = val;
        }
    }

    // Task 3: Adjusting Contrast
    unsigned char *contrast_image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    double contrast_factor = 2.0;
    double delta = maxval / (pow(2, log2(maxval) - 1) + 1);
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            double val = image[row*width + col];
            val = ((val - delta) * contrast_factor) + delta;
            if (val < 0)
                val = 0;
            else if (val > maxval)
                val = maxval;
            contrast_image[row*width + col] = (unsigned char)val;
        }
    }

    // Output the results
    char out_fname[100];
    sprintf(out_fname, "%s_flipped.pgm", fname);
    fp = fopen(out_fname, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, maxval);
    fwrite(flipped_image, sizeof(unsigned char), width * height, fp);
    fclose(fp);
    free(flipped_image);

    sprintf(out_fname, "%s_bright.pgm", fname);
    fp = fopen(out_fname, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, maxval);
    fwrite(bright_image, sizeof(unsigned char), width * height, fp);
    fclose(fp);
    free(bright_image);

    sprintf(out_fname, "%s_contrast.pgm", fname);
    fp = fopen(out_fname, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, maxval);
    fwrite(contrast_image, sizeof(unsigned char), width * height, fp);
    fclose(fp);
    free(contrast_image);

    free(image);

    return 0;
}