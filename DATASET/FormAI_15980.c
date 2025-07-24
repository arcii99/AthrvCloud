//FormAI DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 100
#define IMAGE_HEIGHT 100

typedef unsigned char byte;

byte img[IMAGE_HEIGHT][IMAGE_WIDTH][3];

int main()
{
    int i, j;
    char filename[100];
    FILE *fout;

    // Initialize the image to black
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            img[i][j][0] = img[i][j][1] = img[i][j][2] = 0;
        }
    }

    // Draw a red diagonal line from top-left to bottom-right
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            if (i == j) {
                img[i][j][0] = 255;  // red channel
                img[i][j][1] = img[i][j][2] = 0;  // green and blue channels
            }
        }
    }

    // Draw a blue horizontal line near the bottom
    for (i = 90; i < 95; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            img[i][j][2] = 255;  // blue channel
            img[i][j][0] = img[i][j][1] = 0;  // red and green channels
        }
    }

    // Draw a green vertical line near the right edge
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 90; j < 95; j++) {
            img[i][j][1] = 255;  // green channel
            img[i][j][0] = img[i][j][2] = 0;  // red and blue channels
        }
    }

    // Save the image to a PPM file
    printf("Enter filename (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".ppm");
    fout = fopen(filename, "wb");
    fprintf(fout, "P6\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fwrite(img, sizeof(byte), IMAGE_WIDTH * IMAGE_HEIGHT * 3, fout);
    fclose(fout);

    printf("Image saved to %s!\n", filename);

    return 0;
}