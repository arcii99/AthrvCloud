//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET_SIZE 10

char characters[CHAR_SET_SIZE] = {'@', '#', '&', '%', '$', '*', '+', '-', '/', '='};

void convertToASCII(char image[MAX_HEIGHT][MAX_WIDTH], int height, int width);

int main()
{
    FILE *imageFile;
    char fileName[20];
    int height, width, maxVal;
    char image[MAX_HEIGHT][MAX_WIDTH];

    printf("Enter file name: ");
    scanf("%s", fileName);

    imageFile = fopen(fileName, "r");
    if(imageFile == NULL)
    {
        printf("Error reading file!\n");
        exit(1);
    }

    // read header
    char type[3];
    fscanf(imageFile, "%s\n",type);
    if(strcmp(type,"P2")) 
    { 
        printf("Image type not supported!");
        exit(1);
    }
  
    fscanf(imageFile, "%d %d\n", &width, &height);
    fscanf(imageFile, "%d\n", &maxVal);

    if(width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        printf("Image dimensions too large!");
        exit(1);
    }

    // read image data
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            fscanf(imageFile, "%hhu", &image[i][j]);
        }
    }

    fclose(imageFile);

    // convert image to ASCII art
    convertToASCII(image, height, width);

    return 0;
}

void convertToASCII(char image[MAX_HEIGHT][MAX_WIDTH], int height, int width)
{
    float scale = (float)CHAR_SET_SIZE / 256;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int index = (int)(image[i][j] * scale);
            printf("%c", characters[index]);
        }
        printf("\n");
    }
}