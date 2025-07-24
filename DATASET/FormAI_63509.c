//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define WATERMARK "MyDigitalWatermark"

// function to embed the digital watermark on an image
void embedWatermark(char img[ROWS][COLS], char watermark[])
{
    // calculate the length of the watermark
    int watermarkLen = strlen(watermark);

    // iterate over the rows and columns of the image
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            // if the current pixel is black, embed the watermark character
            if (img[row][col] == 'X')
            {
                int index = (row * COLS + col) % watermarkLen;
                img[row][col] = watermark[index];
            }
        }
    }
}

// function to extract the digital watermark from an image
void extractWatermark(char img[ROWS][COLS], char watermark[], int watermarkLen)
{
    // iterate over the rows and columns of the image
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            // if the current pixel is black, add the character to the watermark
            if (img[row][col] == 'X')
            {
                int index = (row * COLS + col) % watermarkLen;
                watermark[index] = img[row][col];
            }
        }
    }
}

int main()
{
    char img[ROWS][COLS] = {
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X'},
        {'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O'},
        {'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O'},
        {'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},
        {'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O'},
        {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O'}
    };

    char watermark[] = WATERMARK;
    int watermarkLen = strlen(watermark);

    // output original image
    printf("Original Image:\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%c ", img[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // embed the digital watermark
    embedWatermark(img, watermark);

    // output image with digital watermark embedded
    printf("Image with Digital Watermark Embedded:\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%c ", img[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // extract the digital watermark
    extractWatermark(img, watermark, watermarkLen);

    // output extracted digital watermark
    printf("Extracted Digital Watermark: %s\n", watermark);

    return 0;
}