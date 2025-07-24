//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r;
    int g;
    int b;
} RGB;

RGB** readImage(FILE *file, int *width, int *height);
void writeImage(FILE *file, RGB **image, int width, int height);
RGB** grayscale(RGB **image, int width, int height);
RGB** invert(RGB **image, int width, int height);
RGB** horizontalFlip(RGB **image, int width, int height);
RGB** verticalFlip(RGB **image, int width, int height);
RGB** blur(RGB **image, int width, int height);

int main(void) {
    FILE *inputFile = fopen("input.ppm", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.");
        return 1;
    }

    int width, height;
    RGB **image = readImage(inputFile, &width, &height);

    fclose(inputFile);

    int choice;
    do {
        printf("Choose an operation:\n");
        printf("1. Convert to grayscale\n");
        printf("2. Invert colors\n");
        printf("3. Horizontal flip\n");
        printf("4. Vertical flip\n");
        printf("5. Blur\n");
        printf("6. Save to file and exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                image = grayscale(image, width, height);
                break;
            case 2:
                image = invert(image, width, height);
                break;
            case 3:
                image = horizontalFlip(image, width, height);
                break;
            case 4:
                image = verticalFlip(image, width, height);
                break;
            case 5:
                image = blur(image, width, height);
                break;
            case 6:
                FILE *outputFile = fopen("output.ppm", "w");
                if (outputFile == NULL) {
                    printf("Error opening output file.");
                    return 1;
                }

                writeImage(outputFile, image, width, height);

                fclose(outputFile);

                printf("Successfully saved to output.ppm.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

RGB** readImage(FILE *file, int *width, int *height) {
    char type[3];
    fscanf(file, "%s", type);

    if (strcmp(type, "P3") != 0) {
        printf("Invalid file format.");
        exit(1);
    }

    fscanf(file, "%d %d", width, height);

    int max_val;
    fscanf(file, "%d", &max_val);

    if (max_val != 255) {
        printf("Invalid file format.");
        exit(1);
    }

    RGB **image = (RGB **) malloc(*height * sizeof(RGB *));
    for (int i = 0; i < *height; i++) {
        image[i] = (RGB *) malloc(*width * sizeof(RGB));
        for (int j = 0; j < *width; j++) {
            int r, g, b;
            fscanf(file, "%d %d %d", &r, &g, &b);

            image[i][j].r = r;
            image[i][j].g = g;
            image[i][j].b = b;
        }
    }

    return image;
}

void writeImage(FILE *file, RGB **image, int width, int height) {
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d %d %d\n", image[i][j].r, image[i][j].g, image[i][j].b);
        }
    }
}

RGB** grayscale(RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;

            image[i][j].r = average;
            image[i][j].g = average;
            image[i][j].b = average;
        }
    }

    printf("Image converted to grayscale.\n");

    return image;
}

RGB** invert(RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].r = 255 - image[i][j].r;
            image[i][j].g = 255 - image[i][j].g;
            image[i][j].b = 255 - image[i][j].b;
        }
    }

    printf("Image colors inverted.\n");

    return image;
}

RGB** horizontalFlip(RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGB tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }

    printf("Image flipped horizontally.\n");

    return image;
}

RGB** verticalFlip(RGB **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            RGB tmp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = tmp;
        }
    }

    printf("Image flipped vertically.\n");

    return image;
}

RGB** blur(RGB **image, int width, int height) {
    RGB **new_image = (RGB **) malloc(height * sizeof(RGB *));
    for (int i = 0; i < height; i++) {
        new_image[i] = (RGB *) malloc(width * sizeof(RGB));
        for (int j = 0; j < width; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width) {
                        continue;
                    }

                    sum_r += image[i + k][j + l].r;
                    sum_g += image[i + k][j + l].g;
                    sum_b += image[i + k][j + l].b;
                    count++;
                }
            }

            new_image[i][j].r = sum_r / count;
            new_image[i][j].g = sum_g / count;
            new_image[i][j].b = sum_b / count;
        }
    }

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    printf("Image blurred.\n");

    return new_image;
}