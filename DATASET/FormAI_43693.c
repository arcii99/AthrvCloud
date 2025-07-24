//FormAI DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COLOR 255

typedef struct {
    unsigned char red, green, blue;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

void printMenu() {
    printf("Image Editor Menu\n");
    printf("---------------\n");
    printf("1. Load Image\n");
    printf("2. Save Image\n");
    printf("3. Convert to Grayscale\n");
    printf("4. Flip Image\n");
    printf("5. Rotate 90 degrees\n");
    printf("6. Add Border\n");
    printf("7. Invert Color\n");
    printf("8. Brightness Adjustment\n");
    printf("9. Contrast Adjustment\n");
    printf("10. Gaussian Blur\n");
    printf("11. Quit\n");
}

void loadImage(image *img, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fscanf(fp, "P3\n");

    // Get dimensions
    fscanf(fp, "%d %d\n", &img->width, &img->height);

    // Allocate memory for data
    img->data = (pixel*) malloc(img->width * img->height * sizeof(pixel));

    // Get max color value
    int max_color;
    fscanf(fp, "%d\n", &max_color);

    // Read in pixel data
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        fscanf(fp, "%hhu %hhu %hhu ", &img->data[i].red, &img->data[i].green, &img->data[i].blue);
    }
    fclose(fp);
}

void saveImage(image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        exit(1);
    }
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", MAX_COLOR);

    int i;
    for (i = 0; i < img->width * img->height; i++) {
        pixel p = img->data[i];
        fprintf(fp, "%hhu %hhu %hhu ", p.red, p.green, p.blue);
    }
    fclose(fp);
}

void grayscale(image *img) {
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        pixel p = img->data[i];
        unsigned char gray = (unsigned char) round(0.2989 * p.red + 0.5870 * p.green + 0.1141 * p.blue);
        img->data[i] = (pixel) {gray, gray, gray};
    }
}

void flip(image *img) {
    int i;
    for (i = 0; i < img->height; i++) {
        int j;
        for (j = 0; j < img->width / 2; j++) {
            pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + (img->width - j - 1)];
            img->data[i * img->width + (img->width - j - 1)] = temp;
        }
    }
}

void rotate(image *img) {
    pixel *new_data = (pixel*) malloc(img->width * img->height * sizeof(pixel));
    int i;
    for (i = 0; i < img->height; i++) {
        int j;
        for (j = 0; j < img->width; j++) {
            int new_i = j;
            int new_j = img->height - i - 1;
            new_data[new_i * img->height + new_j] = img->data[i * img->width + j];
        }
    }
    free(img->data);
    img->data = new_data;
    int temp = img->width;
    img->width = img->height;
    img->height = temp;
}

void addBorder(image *img, int size, pixel color) {
    int new_width = img->width + 2 * size;
    int new_height = img->height + 2 * size;
    pixel *new_data = (pixel*) malloc(new_width * new_height * sizeof(pixel));

    int i;
    for (i = 0; i < new_width * new_height; i++) {
        new_data[i] = color;
    }

    for (i = 0; i < img->height; i++) {
        int j;
        for (j = 0; j < img->width; j++) {
            new_data[(i+size) * new_width + j + size] = img->data[i * img->width + j];
        }
    }

    free(img->data);
    img->data = new_data;
    img->width = new_width;
    img->height = new_height;
}

void invertColor(image *img) {
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        pixel p = img->data[i];
        img->data[i] = (pixel) {MAX_COLOR - p.red, MAX_COLOR - p.green, MAX_COLOR - p.blue};
    }
}

void adjustBrightness(image *img, int level) {
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        pixel p = img->data[i];
        int new_red = p.red + level;
        int new_green = p.green + level;
        int new_blue = p.blue + level;
        new_red = (new_red < 0 ? 0 : (new_red > MAX_COLOR ? MAX_COLOR : new_red));
        new_green = (new_green < 0 ? 0 : (new_green > MAX_COLOR ? MAX_COLOR : new_green));
        new_blue = (new_blue < 0 ? 0 : (new_blue > MAX_COLOR ? MAX_COLOR : new_blue));
        img->data[i] = (pixel) {new_red, new_green, new_blue};
    }
}

void adjustContrast(image *img, float level) {
    float factor = (259 * (level + 255)) / (255 * (259 - level));
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        pixel p = img->data[i];
        int new_red = factor * (p.red - 128) + 128;
        int new_green = factor * (p.green - 128) + 128;
        int new_blue = factor * (p.blue - 128) + 128;
        new_red = (new_red < 0 ? 0 : (new_red > MAX_COLOR ? MAX_COLOR : new_red));
        new_green = (new_green < 0 ? 0 : (new_green > MAX_COLOR ? MAX_COLOR : new_green));
        new_blue = (new_blue < 0 ? 0 : (new_blue > MAX_COLOR ? MAX_COLOR : new_blue));
        img->data[i] = (pixel) {new_red, new_green, new_blue};
    }
}

void applyGaussianBlur(image *img, float sigma) {
    int size = (int) ceil(3 * sigma);
    int kernel_size = 2 * size + 1;
    float *kernel = (float*) malloc(kernel_size * kernel_size * sizeof(float));
    float sum = 0;

    // Generate kernel
    int i, j;
    for (i = -size; i <= size; i++) {
        for (j = -size; j <= size; j++) {
            kernel[(i+size) * kernel_size + (j+size)] = exp(-(i*i + j*j) / (2 * sigma*sigma));
            sum += kernel[(i+size) * kernel_size + (j+size)];
        }
    }

    // Normalize kernel
    for (i = 0; i < kernel_size * kernel_size; i++) {
        kernel[i] /= sum;
    }

    // Apply kernel
    pixel *new_data = (pixel*) malloc(img->width * img->height * sizeof(pixel));
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            float r = 0, g = 0, b = 0;
            int k_i, k_j;
            for (k_i = -size; k_i <= size; k_i++) {
                for (k_j = -size; k_j <= size; k_j++) {
                    if (i + k_i >= 0 && i + k_i < img->height && j + k_j >= 0 && j + k_j < img->width) {
                        pixel p = img->data[(i+k_i) * img->width + (j+k_j)];
                        float kernel_value = kernel[(k_i+size) * kernel_size + (k_j+size)];
                        r += kernel_value * p.red;
                        g += kernel_value * p.green;
                        b += kernel_value * p.blue;
                    }
                }
            }
            new_data[i * img->width + j] = (pixel) {round(r), round(g), round(b)};
        }
    }
    free(img->data);
    img->data = new_data;
    free(kernel);
}

int main() {
    image img;
    int running = 1;
    while (running) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                char filename[100];
                printf("Enter filename: ");
                scanf("%s", filename);
                loadImage(&img, filename);
                printf("Loaded image with dimensions %d x %d.\n", img.width, img.height);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                saveImage(&img, filename);
                printf("Image saved to file.\n");
                break;
            case 3:
                grayscale(&img);
                printf("Converted to grayscale.\n");
                break;
            case 4:
                flip(&img);
                printf("Flipped image.\n");
                break;
            case 5:
                rotate(&img);
                printf("Rotated image.\n");
                break;
            case 6:
                printf("Enter border size: ");
                int size;
                scanf("%d", &size);
                printf("Enter border color (red green blue): ");
                pixel color;
                scanf("%hhu %hhu %hhu", &color.red, &color.green, &color.blue);
                addBorder(&img, size, color);
                printf("Added border.\n");
                break;
            case 7:
                invertColor(&img);
                printf("Inverted color.\n");
                break;
            case 8:
                printf("Enter brightness level: ");
                int level;
                scanf("%d", &level);
                adjustBrightness(&img, level);
                printf("Adjusted brightness.\n");
                break;
            case 9:
                printf("Enter contrast level: ");
                float contrast_level;
                scanf("%f", &contrast_level);
                adjustContrast(&img, contrast_level);
                printf("Adjusted contrast.\n");
                break;
            case 10:
                printf("Enter sigma for gaussian blur: ");
                float sigma;
                scanf("%f", &sigma);
                applyGaussianBlur(&img, sigma);
                printf("Applied gaussian blur.\n");
                break;
            case 11:
                running = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    free(img.data);
    return 0;
}