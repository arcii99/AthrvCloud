//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to flip image horizontally
void flipHorizontally(int rows, int columns, int image[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][columns - j - 1];
            image[i][columns - j - 1] = temp;
        }
    }
}

// Function to change brightness by a certain factor
void changeBrightness(int rows, int columns, int image[rows][columns], float factor) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int newValue = image[i][j] * factor;
            if (newValue > 255) {
                image[i][j] = 255;
            } else {
                image[i][j] = newValue;
            }
        }
    }
}

// Function to change contrast by a certain factor
void changeContrast(int rows, int columns, int image[rows][columns], float factor) {
    float scale = (259 * (factor + 255)) / (255 * (259 - factor));
    int shift = 128 * (1 - scale);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int newValue = scale * (image[i][j] - 128) + 128 + shift;
            if (newValue < 0) {
                image[i][j] = 0;
            } else if (newValue > 255) {
                image[i][j] = 255;
            } else {
                image[i][j] = newValue;
            }
        }
    }
}

int main() {
    int rows, columns, choice;
    printf("Enter rows and columns of the image: ");
    scanf("%d %d", &rows, &columns);

    int img[rows][columns];
    printf("Enter the pixel values of the image:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &img[i][j]);
        }
    }

    printf("Choose an operation:\n");
    printf("1. Flip horizontally\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flipHorizontally(rows, columns, img);
            printf("Image flipped horizontally.\n");
            break;
        case 2:
            float brightFactor;
            printf("Enter brightness factor (between 0 and 2): ");
            scanf("%f", &brightFactor);
            changeBrightness(rows, columns, img, brightFactor);
            printf("Brightness changed.\n");
            break;
        case 3:
            float contrastFactor;
            printf("Enter contrast factor (between 0 and 255): ");
            scanf("%f", &contrastFactor);
            changeContrast(rows, columns, img, contrastFactor);
            printf("Contrast changed.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("Modified image:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}