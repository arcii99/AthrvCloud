//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256
#define BPP 1

unsigned char image[WIDTH][HEIGHT];
unsigned char new_image[WIDTH][HEIGHT];

void flip_image()
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            new_image[y][x] = image[y][WIDTH - 1 - x];
        }
    }

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            image[y][x] = new_image[y][x];
        }
    }
}

void adjust_contrast(int amount)
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            int value = (int)image[y][x] + (amount * 10);

            if (value < 0)
            {
                value = 0;
            }

            if (value > 255)
            {
                value = 255;
            }

            new_image[y][x] = (unsigned char)value;
        }
    }

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            image[y][x] = new_image[y][x];
        }
    }
}

void adjust_brightness(int amount)
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            int value = (int)image[y][x] + amount;

            if (value < 0)
            {
                value = 0;
            }

            if (value > 255)
            {
                value = 255;
            }

            new_image[y][x] = (unsigned char)value;
        }
    }

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            image[y][x] = new_image[y][x];
        }
    }
}

int main()
{
    FILE* file;
    unsigned char* buffer;

    file = fopen("image.raw", "rb");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    buffer = (unsigned char*)malloc(WIDTH * HEIGHT * BPP);

    if (buffer == NULL)
    {
        fclose(file);
        printf("Error allocating memory\n");
        return 1;
    }

    fread(buffer, BPP, WIDTH * HEIGHT, file);

    fclose(file);

    int x, y, i;

    for (y = 0, i = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++, i++)
        {
            image[y][x] = buffer[i];
        }
    }

    free(buffer);

    // Flip image horizontally
    flip_image();

    // Adjust brightness by 50
    adjust_brightness(50);

    // Adjust contrast by -20
    adjust_contrast(-20);

    // Save modified image
    file = fopen("modified_image.raw", "wb");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    for (y = 0, i = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++, i++)
        {
            buffer[i] = image[y][x];
        }
    }

    fwrite(buffer, BPP, WIDTH * HEIGHT, file);

    fclose(file);

    free(buffer);

    return 0;
}