//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 256
#define WIDTH 256

void invert(unsigned char input[], unsigned char output[])
{
    for (int i = 0; i < HEIGHT * WIDTH; i++)
        output[i] = 255 - input[i];
}

void grayscale(unsigned char input[], unsigned char output[])
{
    for (int i = 0; i < HEIGHT * WIDTH; i++)
    {
        int r = input[i] >> 2;
        int g = input[i+1] >> 2;
        int b = input[i+2] >> 2;
        output[i] = (r + g + b) / 3;
        output[i+1] = (r + g + b) / 3;
        output[i+2] = (r + g + b) / 3;
    }
}

void blur(unsigned char input[], unsigned char output[])
{
    for (int i = 0; i < HEIGHT * WIDTH; i++)
    {
        int sum = input[i] + input[i+1] + input[i+2]
                + input[i+WIDTH] + input[i+WIDTH+1] + input[i+WIDTH+2]
                + input[i-WIDTH] + input[i-WIDTH+1] + input[i-WIDTH+2];
        output[i] = sum / 9;
        output[i+1] = sum / 9;
        output[i+2] = sum / 9;
    }
}

int main()
{
    unsigned char input[HEIGHT * WIDTH * 3];
    unsigned char output[HEIGHT * WIDTH * 3];

    // read input image
    FILE* f = fopen("input.rgb", "rb");
    fread(input, 1, HEIGHT * WIDTH * 3, f);
    fclose(f);

    // invert color image
    invert(input, output);

    // save output image
    FILE* f1 = fopen("output-inverted.rgb", "wb");
    fwrite(output, 1, HEIGHT * WIDTH * 3, f1);
    fclose(f1);

    // grayscale color image
    grayscale(input, output);

    // save output image
    FILE* f2 = fopen("output-grayscale.rgb", "wb");
    fwrite(output, 1, HEIGHT * WIDTH * 3, f2);
    fclose(f2);

    // blur color image
    blur(input, output);

    // save output image
    FILE* f3 = fopen("output-blurred.rgb", "wb");
    fwrite(output, 1, HEIGHT * WIDTH * 3, f3);
    fclose(f3);

    return 0;
}