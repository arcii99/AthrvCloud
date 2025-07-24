//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    unsigned char* data;
} image_t;

typedef struct {
    int start;
    int end;
    image_t* image;
} thread_data_t;

int clamp(int value) {
    return value > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : value < 0 ? 0 : value;
}

void* brightness_contrast_thread(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    image_t* image = data->image;
    int start = data->start;
    int end = data->end;

    int brightness = 50;
    int contrast = 50;

    int magnitude = ((((contrast + 100) * (contrast + 100)) / 10000.0) - 1) * MAX_PIXEL_VALUE;
    int shift = brightness - ((magnitude * MAX_PIXEL_VALUE) / 2);

    for (int i = start; i <= end; i++) {
        int pixel = image->data[i];
        pixel = ((pixel * magnitude) / MAX_PIXEL_VALUE) + shift;
        image->data[i] = clamp(pixel);
    }

    return NULL;
}

void* flip_thread(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    image_t* image = data->image;
    int start = data->start;
    int end = data->end;

    for (int i = start; i < end; i++) {
        int x = i % image->width;
        int y = i / image->width;
        int index1 = (y * image->width + x) * sizeof(unsigned char);
        int index2 = ((y + 1) * image->width - x - 1) * sizeof(unsigned char);

        unsigned char temp = image->data[index1];
        image->data[index1] = image->data[index2];
        image->data[index2] = temp;
    }

    return NULL;
}

void flip_image(image_t* image) {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];

    int height = image->height;
    int thread_count = height / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        int start = i * thread_count * image->width;
        int end = (i == MAX_THREADS - 1) ? (height * image->width) : (start + thread_count * image->width - 1);

        thread_data[i].start = start;
        thread_data[i].end = end;
        thread_data[i].image = image;

        pthread_create(&threads[i], NULL, flip_thread, &thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

void brightness_contrast_image(image_t* image) {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];

    int size = image->width * image->height;
    int thread_count = size / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        int start = i * thread_count;
        int end = (i == MAX_THREADS - 1) ? size - 1 : (start + thread_count - 1);

        thread_data[i].start = start;
        thread_data[i].end = end;
        thread_data[i].image = image;

        pthread_create(&threads[i], NULL, brightness_contrast_thread, &thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    image_t image;
    unsigned char pixel_data[] = {
        255, 0, 0, 255, 0, 255, 255, 255,
        255, 255, 0, 255, 255, 0, 255, 255,
        255, 255, 255, 255, 255, 255, 255, 255,
        255, 255, 255, 255, 255, 255, 255, 255,
        255, 255, 255, 255, 255, 255, 255, 255,
        255, 255, 0, 255, 255, 0, 255, 255,
        255, 0, 0, 255, 0, 255, 255, 255,
        0, 255, 255, 255, 255, 255, 0, 0
    };
    image.width = 8;
    image.height = 8;
    image.data = pixel_data;

    printf("Original Image:\n");
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            printf("%d ", image.data[i * image.width + j]);
        }
        printf("\n");
    }

    flip_image(&image);
    printf("Flipped Image:\n");
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            printf("%d ", image.data[i * image.width + j]);
        }
        printf("\n");
    }

    brightness_contrast_image(&image);
    printf("Brightness and Contrast Adjusted Image:\n");
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            printf("%d ", image.data[i * image.width + j]);
        }
        printf("\n");
    }

    return 0;
}