//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000 // Maximum size of the image
#define MAX_THREADS 16 // Maximum threads to run

struct image {
    int height;
    int width;
    char pixels[MAX_SIZE][MAX_SIZE];
};

void* convertImageToASCII(void* arg) {
    struct image* im = (struct image*) arg;
    int start = im->height / MAX_THREADS * (int) pthread_self();
    int end = start + im->height / MAX_THREADS;
    if ((im->height % MAX_THREADS != 0) && ((int) pthread_self() == MAX_THREADS - 1)) {
        end = im->height;
    }
    for (int i = start; i < end; i++) {
        for (int j = 0; j < im->width; j++) {
            if (im->pixels[i][j] <= 25) printf("@");
            else if (im->pixels[i][j] <= 50) printf("#");
            else if (im->pixels[i][j] <= 75) printf("&");
            else if (im->pixels[i][j] <= 100) printf("8");
            else if (im->pixels[i][j] <= 125) printf("o");
            else if (im->pixels[i][j] <= 150) printf(":");
            else if (im->pixels[i][j] <= 175) printf("'");
            else if (im->pixels[i][j] <= 200) printf(",");
            else if (im->pixels[i][j] <= 225) printf(".");
            else if (im->pixels[i][j] <= 250) printf(" ");
        }
        printf("\n");
    }
    return NULL;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    struct image im;
    fscanf(fp, "%d %d", &im.height, &im.width);
    for (int i = 0; i < im.height; i++) {
        for (int j = 0; j < im.width; j++) {
            fscanf(fp, "%hhd", &im.pixels[i][j]);
        }
    }
    fclose(fp);

    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, convertImageToASCII, &im);
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}