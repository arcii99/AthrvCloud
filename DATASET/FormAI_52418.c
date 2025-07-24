//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 100
#define MAX_COL_SIZE 100

// Function definition to convert image to grayscale
void to_grayscale(unsigned char img[MAX_ROW_SIZE][MAX_COL_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            unsigned char r = img[i][j] >> 16;
            unsigned char g = img[i][j] >> 8;
            unsigned char b = img[i][j];
            img[i][j] = 0.21 * r + 0.72 * g + 0.07 * b;
        }
    }
}

// Function definition to convert pixel values to ASCII characters
void to_ascii(unsigned char img[MAX_ROW_SIZE][MAX_COL_SIZE], int rows, int cols)
{
    char ascii_map[11] = " .,:;ox%#@";
    float steps = 255 / strlen(ascii_map);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int index = img[i][j] / steps;
            if (index >= strlen(ascii_map))
            {
                index = strlen(ascii_map) - 1;
            }
            printf("%c", ascii_map[index]);
        }
        printf("\n");
    }
}

int main()
{
    // Load image data
    unsigned char img[MAX_ROW_SIZE][MAX_COL_SIZE] = {{0}};
    FILE *in_file = fopen("image.bin", "rb");
    if (in_file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    int rows = 0, cols = 0;
    fread(&rows, sizeof(int), 1, in_file);
    fread(&cols, sizeof(int), 1, in_file);
    fread(img, sizeof(unsigned char), rows * cols, in_file);
    fclose(in_file);

    // Convert image to grayscale
    to_grayscale(img, rows, cols);

    // Convert pixel values to ASCII characters
    to_ascii(img, rows, cols);

    return 0;
}