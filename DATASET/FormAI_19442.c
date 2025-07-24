//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define constants for image width and height
#define WIDTH 640
#define HEIGHT 480

// Define image struct
typedef struct {
    int width, height;
    unsigned char *data;
} Image;

// Define filter function prototype
typedef void (*FilterFunction)(Image*);

// Define filter struct
typedef struct {
    char *name;
    FilterFunction function;
} Filter;

// Define filter functions
void grayscale_filter(Image *image) {
    int i, j;
    unsigned char r, g, b, gray;
    unsigned char *data = image->data;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            r = data[(i * image->width + j) * 3];
            g = data[(i * image->width + j) * 3 + 1];
            b = data[(i * image->width + j) * 3 + 2];
            gray = (unsigned char)(0.2126 * r + 0.7152 * g + 0.0722 * b);
            data[(i * image->width + j) * 3] = gray;
            data[(i * image->width + j) * 3 + 1] = gray;
            data[(i * image->width + j) * 3 + 2] = gray;
        }
    }
}

void sepia_filter(Image *image) {
    int i, j;
    unsigned char r, g, b;
    unsigned char *data = image->data;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            r = data[(i * image->width + j) * 3];
            g = data[(i * image->width + j) * 3 + 1];
            b = data[(i * image->width + j) * 3 + 2];
            data[(i * image->width + j) * 3] = (unsigned char)(0.393 * r + 0.769 * g + 0.189 * b);
            data[(i * image->width + j) * 3 + 1] = (unsigned char)(0.349 * r + 0.686 * g + 0.168 * b);
            data[(i * image->width + j) * 3 + 2] = (unsigned char)(0.272 * r + 0.534 * g + 0.131 * b);
        }
    }
}

// Define function to load image from file
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: File not found.\n");
        return NULL;
    }
    unsigned char header[54];
    if (fread(header, 1, 54, file) != 54 || header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid file format.\n");
        fclose(file);
        return NULL;
    }
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    if (width != WIDTH || height != HEIGHT) {
        printf("Error: Unsupported image size.\n");
        fclose(file);
        return NULL;
    }
    int data_size = *(int*)&header[34];
    if (data_size != width * height * 3) {
        printf("Error: Incorrect data size.\n");
        fclose(file);
        return NULL;
    }
    unsigned char *data = (unsigned char*)malloc(data_size);
    if (!data) {
        printf("Error: Out of memory.\n");
        fclose(file);
        return NULL;
    }
    fread(data, 1, data_size, file);
    fclose(file);
    Image *image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;
    return image;
}

// Define function to save image to file
void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Failed to create file.\n");
        return;
    }
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    *(int*)&header[34] = image->width * image->height * 3;
    fwrite(header, 1, 54, file);
    fwrite(image->data, 1, image->width * image->height * 3, file);
    fclose(file);
}

// Define thread function for applying filters asynchronously
void *apply_filter_async(void *args) {
    Image *image = (Image*)args;
    Filter *filter = (Filter*)args + sizeof(Image);
    filter->function(image);
    printf("Filter \"%s\" applied asynchronously.\n", filter->name);
    return NULL;
}

int main() {
    // Load image from file
    Image *image = load_image("input.bmp");
    if (!image) {
        return 1;
    }

    // Define filters
    Filter filters[] = {
        {"Grayscale", grayscale_filter},
        {"Sepia", sepia_filter}
    };
    int num_filters = sizeof(filters) / sizeof(Filter);

    // Apply filters asynchronously
    pthread_t threads[num_filters];
    int i;
    for (i = 0; i < num_filters; i++) {
        pthread_create(&threads[i], NULL, apply_filter_async, (void*)filters[i].name);
    }
    for (i = 0; i < num_filters; i++) {
        pthread_join(threads[i], NULL);
    }

    // Save image to file
    save_image(image, "output.bmp");
    printf("Output saved to \"output.bmp\".\n");

    // Free memory
    free(image->data);
    free(image);

    return 0;
}