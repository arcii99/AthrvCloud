//FormAI DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <math.h>

#define WIDTH 800 // define image width
#define HEIGHT 600 // define image height
#define MAX_ITER 256 // define maximum iterations

typedef unsigned char byte; // define byte type

byte color(double x) // function to calculate the color
{
    return (byte)(pow(log(x), 2) / log(MAX_ITER) * 255); 
}

int main()
{
    byte image[HEIGHT][WIDTH][3]; // array to store the image

    double x_min = -2.0, x_max = 1.0; // define x range
    double y_min = -1.5, y_max = 1.5; // define y range

    double dx = (x_max - x_min) / WIDTH; // calculate x step
    double dy = (y_max - y_min) / HEIGHT; // calculate y step

    // loop through the image pixels and calculate the fractal
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            double x0 = x_min + j * dx;
            double y0 = y_min + i * dy;

            double x = 0, y = 0;

            int iter = 0;
            while (x*x + y*y <= 4 && iter < MAX_ITER)
            {
                double xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;

                iter++;
            }

            byte c = color(iter);
            image[i][j][0] = c;
            image[i][j][1] = c;
            image[i][j][2] = c;
        }
    }

    // save the image as PPM format
    FILE* file = fopen("fractal.ppm", "wb");
    fprintf(file, "P6 %d %d 255\n", WIDTH, HEIGHT);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            fwrite(image[i][j], 1, 3, file);
        }
    }

    fclose(file);

    return 0;
}