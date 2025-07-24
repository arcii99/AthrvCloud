//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 80
#define HEIGHT 40

char chars[] = {'@', '#', '%', '*', '+', '=', '-', ':', '.', ' '};
int charlen = sizeof(chars) / sizeof(char);

struct thread_args {
    int start;
    int end;
    int (*image)[WIDTH];
    char (*ascii)[WIDTH+1];
};

void *image_to_ascii(void *args) {
    struct thread_args *targs = args;
    int start = targs->start;
    int end = targs->end;
    int (*image)[WIDTH] = targs->image;
    char (*ascii)[WIDTH+1] = targs->ascii;

    for (int y = start; y < end; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color = image[y][x];
            int index = (charlen - 1) - color * charlen / 256;
            ascii[y][x] = chars[index];
        }
        ascii[y][WIDTH] = '\0';
    }

    return NULL;
}

int main() {
    int image[HEIGHT][WIDTH];
    char ascii[HEIGHT][WIDTH+1];
    pthread_t threads[4];
    int num_threads = sizeof(threads) / sizeof(pthread_t);

    // Generate random image
    srand(123);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x] = rand() % 256;
        }
    }

    // Create threads to convert image to ASCII
    for (int i = 0; i < num_threads; i++) {
        int start = HEIGHT * i / num_threads;
        int end = HEIGHT * (i+1) / num_threads;
        struct thread_args *args = malloc(sizeof(struct thread_args));
        args->start = start;
        args->end = end;
        args->image = image;
        args->ascii = ascii;
        pthread_create(&threads[i], NULL, image_to_ascii, args);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", ascii[y]);
    }

    return 0;
}