//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_fractal(int depth, double x, double y, double size) {
    // base case
    if (depth == 0) {
        return;
    }

    // set color
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    printf("setrgbcolor %d %d %d setrgbcolor\n", r, g, b);

    // draw current shape
    double x1 = x - size / 2;
    double y1 = y - size / 2;
    double x2 = x + size / 2;
    double y2 = y + size / 2;
    printf("%lf %lf moveto\n", x1, y1);
    printf("%lf %lf lineto\n", x1, y2);
    printf("%lf %lf lineto\n", x2, y2);
    printf("%lf %lf lineto\n", x2, y1);
    printf("closepath fill\n");

    // calculate new size and positions
    double new_size = size / 2;
    double new_x1 = x - new_size / 2;
    double new_y1 = y - new_size / 2;
    double new_x2 = x + new_size / 2;
    double new_y2 = y + new_size / 2;

    // draw recursive shapes
    draw_fractal(depth - 1, new_x1, new_y1, new_size);
    draw_fractal(depth - 1, new_x2, new_y1, new_size);
    draw_fractal(depth - 1, new_x1, new_y2, new_size);
    draw_fractal(depth - 1, new_x2, new_y2, new_size);
}

int main() {
    // set up postscript file
    FILE *fp = fopen("fractal.ps", "w");
    fprintf(fp, "%%!PS-Adobe-3.0\n");
    fprintf(fp, "/setrgbcolor { setrgbcolor } bind def\n");

    // recursively draw fractal
    int depth = 5;
    double x = 300;
    double y = 400;
    double size = pow(2, depth);
    draw_fractal(depth, x, y, size);

    // close postscript file
    fprintf(fp, "showpage\n");
    fclose(fp);
    
    return 0;
}