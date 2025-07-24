//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: romantic
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 20

void printArray(int arr[][HEIGHT])
{
    for(int y=0; y < HEIGHT; y++)
    {
        for(int x=0; x < WIDTH; x++)
        {
            printf("%d ", arr[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Define color values
    int colors[] = {0xFFC0CB, 0xFFB6C1, 0xFF69B4, 0xFF1493};

    // Define the color values for the heart shape
    int heartColors[WIDTH][HEIGHT] = {0};
    heartColors[9][0] = colors[0];
    heartColors[8][1] = colors[0];
    heartColors[7][2] = colors[0];
    heartColors[6][3] = colors[0];
    heartColors[5][4] = colors[0];
    heartColors[4][5] = colors[0];
    heartColors[3][6] = colors[0];
    heartColors[2][7] = colors[0];
    heartColors[1][8] = colors[0];
    heartColors[0][9] = colors[0];
    heartColors[1][9] = colors[0];
    heartColors[2][9] = colors[0];
    heartColors[3][9] = colors[0];
    heartColors[4][9] = colors[0];
    heartColors[5][9] = colors[0];
    heartColors[6][9] = colors[0];
    heartColors[7][9] = colors[0];
    heartColors[8][9] = colors[0];
    heartColors[9][9] = colors[0];
    heartColors[10][8] = colors[0];
    heartColors[11][7] = colors[0];
    heartColors[12][6] = colors[0];
    heartColors[13][5] = colors[0];
    heartColors[14][4] = colors[0];
    heartColors[15][3] = colors[0];
    heartColors[16][2] = colors[0];
    heartColors[17][1] = colors[0];

    // Fill the rest of the pixel array with random colors
    int pixelArray[WIDTH][HEIGHT] = {0};
    for(int y=0; y < HEIGHT; y++)
    {
        for(int x=0; x < WIDTH; x++)
        {
            if(heartColors[x][y] == 0)
            {
                pixelArray[x][y] = colors[rand() % 4];
            }
            else
            {
                pixelArray[x][y] = heartColors[x][y];
            }
        }
    }

    // Print the pixel array
    printArray(pixelArray);

    return 0;
}