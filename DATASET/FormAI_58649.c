//FormAI DATASET v1.0 Category: Image Editor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_IMAGE_SIZE 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    char filename[MAX_FILENAME_LEN];
    int width;
    int height;
    Pixel pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void load_image(Image *image) {
    printf("Enter the name of the image file: ");
    scanf("%s", image->filename);
    FILE *file = fopen(image->filename, "rb");
    if (!file) {
        printf("Error: could not open file '%s'\n", image->filename);
        exit(-1);
    }
    char magic_number[3];
    fread(&magic_number, sizeof(char), 2, file);
    if (strcmp(magic_number, "P6") != 0) {
        printf("Error: invalid file format\n");
        exit(-1);
    }
    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);
    while (buffer[0] == '#') {
        fgets(buffer, sizeof(buffer), file);
    }
    sscanf(buffer, "%d %d", &image->width, &image->height);
    fgets(buffer, sizeof(buffer), file);
    int max_color;
    sscanf(buffer, "%d", &max_color);
    if (max_color != 255) {
        printf("Error: unsupported maximum color value\n");
        exit(-1);
    }
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void save_image(const Image *image) {
    char filename[MAX_FILENAME_LEN + 5];
    strcpy(filename, image->filename);
    strcat(filename, ".new");
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        exit(-1);
    }
    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    printf("Image saved as '%s'\n", filename);
}

void filter_image(Image *image) {
    printf("Select a filter (1 = invert, 2 = grayscale): ");
    int filter;
    scanf("%d", &filter);
    if (filter == 1) {
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                image->pixels[i][j].red = 255 - image->pixels[i][j].red;
                image->pixels[i][j].green = 255 - image->pixels[i][j].green;
                image->pixels[i][j].blue = 255 - image->pixels[i][j].blue;
            }
        }
        printf("Invert filter applied\n");
    }
    else if (filter == 2) {
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                Pixel *p = &image->pixels[i][j];
                unsigned int gray = p->red * 0.299 + p->green * 0.587 + p->blue * 0.114;
                p->red = gray;
                p->green = gray;
                p->blue = gray;
            }
        }
        printf("Grayscale filter applied\n");
    }
    else {
        printf("Error: invalid filter\n");
        exit(-1);
    }
}

int main() {
    printf("Welcome to the Happy C Image Editor!\n");
    printf("Let's load an image...\n");
    Image image;
    load_image(&image);
    printf("Image loaded successfully!\n");
    filter_image(&image);
    save_image(&image);
    printf("Bye bye!\n");
    return 0;
}