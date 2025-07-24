//FormAI DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to calculate the color of each pixel */
int coloring(double x, double y)
{
    double a = 0.0, b = 0.0, temp;
    int i, color = 0;

    /* Iterate until the absolute value of a and b exceeds 2 */
    for (i = 0; i < 500; i++) {
        temp = a * a - b * b + x;
        b = 2 * a * b + y;
        a = temp;

        if (sqrt(a * a + b * b) > 2) {
            color = i;
            break;
        }
    }

    /* Return the color based on the number of iterations */
    if (color % 2 == 0) {
        return (color / 16) % 15;
    } else {
        return (color / 32) % 15;
    }
}

int main()
{
    int width = 800, height = 600, max_color = 255, color;
    double x, y, x_min = -2.0, x_max = 1.0, y_min = -1.5, y_max = 1.5;
    FILE *fp;
    char filename[] = "fractal.ppm";

    /* Open the output file */
    fp = fopen(filename, "wb");
    fprintf(fp, "P3\n%d %d\n%d\n", width, height, max_color);

    /* Loop through each pixel and calculate its color */
    for (y = y_min; y < y_max; y += (y_max - y_min) / height) {
        for (x = x_min; x < x_max; x += (x_max - x_min) / width) {
            color = coloring(x, y);
            fprintf(fp, "%d %d %d ", color * 16, color * 16, color * 16);
        }
        fprintf(fp, "\n");
    }

    /* Close the output file */
    fclose(fp);
    printf("Fractal generation complete!\n");

    return 0;
}