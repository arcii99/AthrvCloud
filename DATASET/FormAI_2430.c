//FormAI DATASET v1.0 Category: Fractal Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int width = 640; // Width of the image.
    int height = 480; // Height of the image.
    int max_iter = 256; // Maximum number of iterations per pixel.
    float scale = 1; // Scale of the fractal.
    float offsetX = 0; // X offset of the fractal.
    float offsetY = 0; // Y offset of the fractal.

    // Image buffer.
    unsigned char image[width * height * 3];

    // Initialize the RNG.
    srand(time(0));

    // Create the fractal.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            float zx = ((float)x / width - 0.5) * 3.0 * scale + offsetX;
            float zy = ((float)y / height - 0.5) * 3.0 * scale + offsetY;

            int iter = 0;
            float length = zx * zx + zy * zy;

            while (iter < max_iter && length < 4.0)
            {
                float xtemp = zx * zx - zy * zy + sin(zx + zy);
                zy = 2.0 * zx * zy + cos(zx - zy);
                zx = xtemp;

                iter++;
                length = zx * zx + zy * zy;
            }

            float red = (float)iter / max_iter * 255;
            float green = (float)iter / max_iter * 255;
            float blue = (float)iter / max_iter * 255;

            image[(y * width + x) * 3] = (unsigned char)red;
            image[(y * width + x) * 3 + 1] = (unsigned char)green;
            image[(y * width + x) * 3 + 2] = (unsigned char)blue;
        }
    }

    // Save the image.
    FILE *fp = fopen("fractal.bmp", "wb");
    fprintf(fp, "BM");
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);
    fwrite("\x01\x00\x18\x00", 4, 1, fp);
    int imageSize = width * height * 3;
    fwrite(&imageSize, 4, 1, fp);
    fwrite("\x00\x00\x00\x00\x00\x00\x00\x00"
           "\x00\x00\x00\x00\xff\xff\xff\x00", 16, 1, fp);
    fwrite(image, imageSize, 1, fp);
    fflush(fp);
    fclose(fp);

    return 0;
}