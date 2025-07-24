//FormAI DATASET v1.0 Category: Image Editor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input image
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Define struct for the image matrix
typedef struct {
    int width;
    int height;
    int matrix[MAX_WIDTH][MAX_HEIGHT];
} image;

// Initialize an image with all pixels set to zero
void init_image(image* img) {
    img->width = 0;
    img->height = 0;
    for (int x = 0; x < MAX_WIDTH; x++) {
        for (int y = 0; y < MAX_HEIGHT; y++) {
            img->matrix[x][y] = 0;
        }
    }
}

// Load an image from a file
int load_image(image* img, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }
    char line[10000];
    fgets(line, sizeof(line), fp);
    int width, height;
    sscanf(line, "%d %d", &width, &height);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image too large\n");
        return -1;
    }
    img->width = width;
    img->height = height;
    for (int y = 0; y < height; y++) {
        fgets(line, sizeof(line), fp);
        char* tok = strtok(line, " ");
        for (int x = 0; x < width; x++) {
            img->matrix[x][y] = atoi(tok);
            tok = strtok(NULL, " ");
        }
    }
    fclose(fp);
    return 0;
}

// Save an image to a file
int save_image(image* img, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return -1;
    }
    fprintf(fp, "%d %d\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            fprintf(fp, "%d ", img->matrix[x][y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}

// Invert the colors of an image
void invert_colors(image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->matrix[x][y] = 255 - img->matrix[x][y];
        }
    }
}

// Adjust the brightness of an image
void adjust_brightness(image* img, int brightness) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->matrix[x][y] += brightness;
            if (img->matrix[x][y] < 0) {
                img->matrix[x][y] = 0;
            }
            if (img->matrix[x][y] > 255) {
                img->matrix[x][y] = 255;
            }
        }
    }
}

// Main function
int main() {
    image img;
    init_image(&img);

    int option = 0;
    while (option != 4) {
        printf("1. Load image\n");
        printf("2. Invert colors\n");
        printf("3. Adjust brightness\n");
        printf("4. Save and exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter filename: ");
                char filename[100];
                scanf("%s", filename);
                if (load_image(&img, filename) == -1) {
                    printf("Error loading image\n");
                }
                break;

            case 2:
                invert_colors(&img);
                printf("Colors inverted\n");
                break;

            case 3:
                printf("Enter brightness adjustment (-255 to 255): ");
                int brightness;
                scanf("%d", &brightness);
                adjust_brightness(&img, brightness);
                printf("Brightness adjusted by %d\n", brightness);
                break;

            case 4:
                printf("Enter filename to save: ");
                char save_filename[100];
                scanf("%s", save_filename);
                if (save_image(&img, save_filename) == -1) {
                    printf("Error saving image\n");
                }
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}