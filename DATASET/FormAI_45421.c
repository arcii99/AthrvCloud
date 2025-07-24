//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH  512
#define HEIGHT 512

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return -1;
    }

    char *input_image = argv[1];
    char *output_image = argv[2];

    // Load input image
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT);
    FILE *fp = fopen(input_image, "rb");
    fread(image, 1, WIDTH * HEIGHT, fp);
    fclose(fp);

    // Embed watermark pattern
    char *pattern = "UNIQUEWATERMARK";
    int len = strlen(pattern);
    for (int i = 0; i < len; i++)
    {
        int x = i % WIDTH;
        int y = i / WIDTH;
        int index = y * WIDTH + x;
        image[index] = ((int)image[index] & 0xF0) | ((pattern[i] >> 4) & 0x0F);
        image[index + 1] = ((int)image[index + 1] & 0x0F) | ((pattern[i] << 4) & 0xF0);
    }

    // Save output image
    fp = fopen(output_image, "wb");
    fwrite(image, 1, WIDTH * HEIGHT, fp);
    fclose(fp);

    free(image);

    return 0;
}