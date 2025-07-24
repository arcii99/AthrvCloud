//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define MAX_ITERATIONS 1000
#define SCALE 2

typedef struct {
    double x, y;
} complex;

int main() {
    unsigned char colors[WIDTH][HEIGHT][3];
    int i, j, k;

    complex c, z, z_temp;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            c.x = (i - WIDTH / 2.0) * SCALE / WIDTH;
            c.y = (j - HEIGHT / 2.0) * SCALE / HEIGHT;
            z = c;

            for (k = 0; k < MAX_ITERATIONS; k++) {
                z_temp.x = (z.x * z.x) - (z.y * z.y) + c.x;
                z_temp.y = (2 * z.x * z.y) + c.y;

                if (sqrt(z_temp.x * z_temp.x + z_temp.y * z_temp.y) > 2) {
                    colors[i][j][0] = k % 256; // Red component
                    colors[i][j][1] = ((2 * k) % 256); // Green component
                    colors[i][j][2] = ((3 * k) % 256); // Blue component
                    break;
                }
                z = z_temp;
            }
        }
    }
    FILE *fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(colors, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    return 0;
}