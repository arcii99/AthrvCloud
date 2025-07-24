//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void flip(char *filename, int width, int height, char *newFilename);
void adjustBrightness(char *filename, int width, int height, int brightness, char *newFilename);
void adjustContrast(char *filename, int width, int height, int contrast, char *newFilename);

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    int width, height, choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter width: ");
    scanf("%d", &width);

    printf("Enter height: ");
    scanf("%d", &height);

    printf("What do you want to do?\n");
    printf("1. Flip image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    scanf("%d", &choice);

    char newFilename[MAX_FILENAME_LENGTH];
    switch (choice)
    {
    case 1:
        flip(filename, width, height, newFilename);
        break;
    case 2:
        int brightness;
        printf("Enter brightness adjustment value: ");
        scanf("%d", &brightness);
        adjustBrightness(filename, width, height, brightness, newFilename);
        break;
    case 3:
        int contrast;
        printf("Enter contrast adjustment value: ");
        scanf("%d", &contrast);
        adjustContrast(filename, width, height, contrast, newFilename);
        break;
    default:
        printf("Invalid choice");
        return 1;
    }

    printf("New image saved as %s\n", newFilename);

    return 0;
}

void flip(char *filename, int width, int height, char *newFilename)
{
    unsigned char image[height][width][3];

    FILE *fp = fopen(filename, "rb");
    fread(image, sizeof(unsigned char), height * width * 3, fp);
    fclose(fp);

    unsigned char newImage[height][width][3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j][0] = image[i][width-j-1][0];
            newImage[i][j][1] = image[i][width-j-1][1];
            newImage[i][j][2] = image[i][width-j-1][2];
        }
    }

    strcpy(newFilename, "flipped-");
    strcat(newFilename, filename);

    FILE *fp2 = fopen(newFilename, "wb");
    fwrite(newImage, sizeof(unsigned char), height * width * 3, fp2);
    fclose(fp2);
}

void adjustBrightness(char *filename, int width, int height, int brightness, char *newFilename)
{
    unsigned char image[height][width][3];

    FILE *fp = fopen(filename, "rb");
    fread(image, sizeof(unsigned char), height * width * 3, fp);
    fclose(fp);

    unsigned char newImage[height][width][3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j][0] = image[i][j][0] + brightness;
            newImage[i][j][1] = image[i][j][1] + brightness;
            newImage[i][j][2] = image[i][j][2] + brightness;

            if (newImage[i][j][0] > 255)
                newImage[i][j][0] = 255;
            if (newImage[i][j][1] > 255)
                newImage[i][j][1] = 255;
            if (newImage[i][j][2] > 255)
                newImage[i][j][2] = 255;
        }
    }

    strcpy(newFilename, "bright-");
    strcat(newFilename, filename);

    FILE *fp2 = fopen(newFilename, "wb");
    fwrite(newImage, sizeof(unsigned char), height * width * 3, fp2);
    fclose(fp2);
}

void adjustContrast(char *filename, int width, int height, int contrast, char *newFilename)
{
    unsigned char image[height][width][3];

    FILE *fp = fopen(filename, "rb");
    fread(image, sizeof(unsigned char), height * width * 3, fp);
    fclose(fp);

    unsigned char newImage[height][width][3];

    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j][0] = (unsigned char)(factor * (image[i][j][0] - 128) + 128);
            newImage[i][j][1] = (unsigned char)(factor * (image[i][j][1] - 128) + 128);
            newImage[i][j][2] = (unsigned char)(factor * (image[i][j][2] - 128) + 128);

            if (newImage[i][j][0] > 255)
                newImage[i][j][0] = 255;
            if (newImage[i][j][1] > 255)
                newImage[i][j][1] = 255;
            if (newImage[i][j][2] > 255)
                newImage[i][j][2] = 255;
        }
    }

    strcpy(newFilename, "contrast-");
    strcat(newFilename, filename);

    FILE *fp2 = fopen(newFilename, "wb");
    fwrite(newImage, sizeof(unsigned char), height * width * 3, fp2);
    fclose(fp2);
}