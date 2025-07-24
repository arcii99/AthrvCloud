//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define WIDTH 640
#define HEIGHT 480

#define MAX_ITER 1000

typedef struct {
    int xstart;
    int xend;
    int ystart;
    int yend;
} block;

typedef struct {
    unsigned char r, g, b;
} color;

color palette[MAX_ITER];

unsigned char image[HEIGHT][WIDTH][3];

void set_palette(void)
{
    int i, j;

    for (i = 0; i < MAX_ITER; i++) {
        j = (i * 255 / MAX_ITER);
        palette[i].r = j;
        palette[i].g = j;
        palette[i].b = j;
    }
}

void draw_block(block *b, int x_offset, int y_offset)
{
    int x, y, i, k;
    float cx, cy, zx, zy, tmpx;

    for (y = b->ystart; y < b->yend; y++) {
        for (x = b->xstart; x < b->xend; x++) {
            cx = (((float) x + x_offset) - WIDTH / 2) / (float) (WIDTH / 4);
            cy = (((float) y + y_offset) - HEIGHT / 2) / (float) (HEIGHT / 4);
            zx = 0.0;
            zy = 0.0;
            k = 0;
            while ((zx * zx + zy * zy < 4.0) && (k < MAX_ITER)) {
                tmpx = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = tmpx;
                k++;
            }
            image[y][x][0] = palette[k].r;
            image[y][x][1] = palette[k].g;
            image[y][x][2] = palette[k].b;
        }
    }
}

void *worker(void *arg)
{
    block *b = (block *) arg;
    draw_block(b, 0, 0);
    return NULL;
}

void fractal_async(void)
{
    int i, j;
    block b[4];
    pthread_t tid[4];
    int xwidth = WIDTH / 2;
    int yheight = HEIGHT / 2;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            b[i * 2 + j].xstart = j * xwidth;
            b[i * 2 + j].xend = (j + 1) * xwidth;
            b[i * 2 + j].ystart = i * yheight;
            b[i * 2 + j].yend = (i + 1) * yheight;
            pthread_create(&tid[i * 2 + j], NULL, worker, (void *) &b[i * 2 + j]);
        }
    }

    for (i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }
}

int main(void)
{
    clock_t start, stop;
    double time;

    set_palette();

    start = clock();    
    fractal_async();
    stop = clock();
    
    time = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("Time taken = %f seconds\n", time);

    FILE *fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(image), 1, fp);
    fclose(fp);

    return 0;
}