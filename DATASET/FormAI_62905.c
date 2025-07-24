//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

int main() {
    //initialize the window
    int x, y, z, i;
    int width = WIDTH;
    int height = HEIGHT;
    unsigned char buffer[WIDTH][HEIGHT][3];

    //initialize the coordinates and divergence flag
    double x0, y0, z0;
    double x1, y1, z1;
    double x2, y2, z2;
    double xtemp, ytemp, ztemp;
    bool diverge;

    //initialize matrix T
    double T[3][3];
    T[0][0] = 0.5;
    T[0][1] = 0.0;
    T[0][2] = 0.0;
    T[1][0] = 0.5;
    T[1][1] = 0.5;
    T[1][2] = 0.0;
    T[2][0] = 0.5;
    T[2][1] = 0.5;
    T[2][2] = 0.5;

    //generate the fractal
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            x0 = (double)x / width;
            y0 = (double)y / height;
            z0 = 0.0;

            //initialize divergence flag
            diverge = false;
            for (i = 0; i < MAX_ITER; i++) {
                //apply matrix transformation
                x1 = T[0][0] * x0 + T[0][1] * y0 + T[0][2] * z0;
                y1 = T[1][0] * x0 + T[1][1] * y0 + T[1][2] * z0;
                z1 = T[2][0] * x0 + T[2][1] * y0 + T[2][2] * z0;

                //apply function transformation
                xtemp = x1 * x1 - y1 * y1 - z1 * z1;
                ytemp = 2 * x1 * y1;
                ztemp = 2 * x1 * z1;

                x2 = xtemp * xtemp - ytemp * ytemp - ztemp * ztemp + 0.187;
                y2 = 2 * xtemp * ytemp;
                z2 = 2 * xtemp * ztemp;

                //check if diverge
                if (x2 * x2 + y2 * y2 + z2 * z2 > 100) {
                    diverge = true;
                    break;
                }

                //update coordinates
                x0 = x2;
                y0 = y2;
                z0 = z2;
            }

            //color the pixel according to divergence flag
            if (diverge) {
                buffer[x][y][0] = 255 - i;
                buffer[x][y][1] = 255 - i;
                buffer[x][y][2] = 255 - i;
            }
            else {
                buffer[x][y][0] = 0;
                buffer[x][y][1] = 0;
                buffer[x][y][2] = 0;
            }
        }
    }

    //write the image file
    FILE *fptr;
    fptr = fopen("fractal.ppm", "wb");
    fprintf(fptr, "P6\n%d %d\n%d\n", width, height, 255);
    fwrite(buffer, sizeof(unsigned char), width * height * 3, fptr);
    fclose(fptr);

    //exit program
    printf("Fractal generated.\n");
    return 0;
}