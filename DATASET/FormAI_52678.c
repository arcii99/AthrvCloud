//FormAI DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

typedef struct {
    unsigned char r, g, b;
} pixel;

int sqr(int x) {
    return x * x;
}

void blur(pixel img[WIDTH][HEIGHT], int radius) {
    int i, j, k, l, count;
    float r_avg, g_avg, b_avg, weight, total_weight;
    pixel new_img[WIDTH][HEIGHT];
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            r_avg = g_avg = b_avg = total_weight = 0;
            count = 0;
            for(k = i - radius; k <= i + radius; k++) {
                for(l = j - radius; l <= j + radius; l++) {
                    if(k >= 0 && k < WIDTH && l >= 0 && l < HEIGHT) {
                        weight = exp(-(sqr(i - k) + sqr(j - l)) / (2 * sqr(radius)));
                        r_avg += img[k][l].r * weight;
                        g_avg += img[k][l].g * weight;
                        b_avg += img[k][l].b * weight;
                        total_weight += weight;
                        count++;
                    }
                }
            }
            if(count > 0) {
                r_avg /= total_weight;
                g_avg /= total_weight;
                b_avg /= total_weight;
            }
            new_img[i][j].r = r_avg;
            new_img[i][j].g = g_avg;
            new_img[i][j].b = b_avg;
        }
    }
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            img[i][j] = new_img[i][j];
        }
    }
}

void invert(pixel img[WIDTH][HEIGHT]) {
    int i, j;
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            img[i][j].r = 255 - img[i][j].r;
            img[i][j].g = 255 - img[i][j].g;
            img[i][j].b = 255 - img[i][j].b;
        }
    }
}

void psychedelic(pixel img[WIDTH][HEIGHT]) {
    int i, j;
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            img[i][j].r = rand() % 256;
            img[i][j].g = rand() % 256;
            img[i][j].b = rand() % 256;
        }
    }
}

void render(pixel img[WIDTH][HEIGHT]) {
    FILE *fp;
    int i, j;
    fp = fopen("output.ppm", "w+");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            fwrite(&img[i][j], 1, 3, fp);
        }
    }
    fclose(fp);
}

int main() {
    int i, j;
    pixel img[WIDTH][HEIGHT];
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            img[i][j].r = 255;
            img[i][j].g = 255;
            img[i][j].b = 255;
        }
    }
    blur(img, 10);
    invert(img);
    psychedelic(img);
    render(img);
    return 0;
}