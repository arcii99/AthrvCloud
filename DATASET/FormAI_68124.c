//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_FILENAME 20

// Function prototypes
void flipImage(unsigned char *image, int width, int height);
void adjustBrightness(unsigned char *image, int width, int height, int brightness);
void adjustContrast(unsigned char *image, int width, int height, float contrast);
void printImage(unsigned char *image, int width, int height);

int main() {
    int choice, brightness;
    float contrast;
    char filename[MAX_FILENAME];
    unsigned char *image = NULL;
    int width = 0, height = 0;
    int numPlayers = 0, playerIndex = 0;

    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar();

    while (playerIndex < numPlayers) {
        printf("\nPlayer %d, enter the filename of your image: ", playerIndex + 1);
        fgets(filename, MAX_FILENAME, stdin);
        filename[strcspn(filename, "\n")] = '\0';  // Remove '\n' from filename
        FILE *fp = fopen(filename, "rb");
        if (fp == NULL) {
            printf("Error: could not open file %s\n", filename);
            continue;  // Move on to next iteration of loop
        }

        // Read image dimensions from file header
        fseek(fp, 18, SEEK_SET);
        fread(&width, 4, 1, fp);
        fread(&height, 4, 1, fp);

        // Allocate memory for image data
        int imageSize = width * height * 3;
        image = (unsigned char*) malloc(imageSize);
        if (image == NULL) {
            printf("Error: could not allocate memory for image\n");
            return 1;
        }

        // Read image data from file
        fseek(fp, 54, SEEK_SET);
        fread(image, 1, imageSize, fp);
        fclose(fp);

        // Menu of image processing options
        printf("\nPlayer %d, choose a transformation to apply:\n", playerIndex + 1);
        printf("1. Flip image horizontally\n");
        printf("2. Flip image vertically\n");
        printf("3. Adjust brightness\n");
        printf("4. Adjust contrast\n");
        printf("5. Print image\n");
        printf("6. Save image and move to next player\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flipImage(image, width, height);
                printf("Image flipped horizontally\n");
                break;
            case 2:
                // Flip vertically by flipping horizontally and then rotating
                flipImage(image, width, height);
                for (int i = 0; i < height / 2; i++) {
                    for (int j = 0; j < width * 3; j++) {
                        unsigned char temp = image[i * width * 3 + j];
                        image[i * width * 3 + j] = image[(height - i - 1) * width * 3 + j];
                        image[(height - i - 1) * width * 3 + j] = temp;
                    }
                }
                printf("Image flipped vertically\n");
                break;
            case 3:
                printf("Enter brightness value (-255 to 255): ");
                scanf("%d", &brightness);
                adjustBrightness(image, width, height, brightness);
                printf("Brightness adjusted\n");
                break;
            case 4:
                printf("Enter contrast value (0.1 to 10.0): ");
                scanf("%f", &contrast);
                adjustContrast(image, width, height, contrast);
                printf("Contrast adjusted\n");
                break;
            case 5:
                printImage(image, width, height);
                break;
            case 6:
                // Save image to file
                char outputFilename[MAX_FILENAME];
                sprintf(outputFilename, "processed_%s", filename);
                fp = fopen(outputFilename, "wb");
                if (fp == NULL) {
                    printf("Error: could not open file %s for writing\n", outputFilename);
                } else {
                    fwrite(image, 1, imageSize, fp);
                    fclose(fp);
                    free(image);
                    printf("Image saved to file: %s\n", outputFilename);
                    playerIndex++;
                }
                break;
            default:
                printf("Invalid choice\n");
        }
        getchar();  // Clear input buffer
    }

    printf("\nAll players have finished processing their images!\n");

    return 0;
}

// Flip image horizontally
void flipImage(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            for (int k = 0; k < 3; k++) {
                unsigned char temp = image[(i * width + j) * 3 + k];
                image[(i * width + j) * 3 + k] = image[(i * width + width - j - 1) * 3 + k];
                image[(i * width + width - j - 1) * 3 + k] = temp;
            }
        }
    }
}

// Adjust brightness of image
void adjustBrightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                int pixel = image[(i * width + j) * 3 + k] + brightness;
                if (pixel < 0) {
                    pixel = 0;
                } else if (pixel > 255) {
                    pixel = 255;
                }
                image[(i * width + j) * 3 + k] = pixel;
            }
        }
    }
}

// Adjust contrast of image
void adjustContrast(unsigned char *image, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                int pixel = factor * (image[(i * width + j) * 3 + k] - 128) + 128;
                if (pixel < 0) {
                    pixel = 0;
                } else if (pixel > 255) {
                    pixel = 255;
                }
                image[(i * width + j) * 3 + k] = pixel;
            }
        }
    }
}

// Print image to console in ASCII art style
void printImage(unsigned char *image, int width, int height) {
    printf("+");
    for (int i = 0; i < width * 3; i++) {
        printf("-");
    }
    printf("+\n");

    for (int i = 0; i < height; i++) {
        printf("|");
        for (int j = 0; j < width; j++) {
            int average = (image[(i * width + j) * 3] + image[(i * width + j) * 3 + 1] + image[(i * width + j) * 3 + 2]) / 3;
            char symbol;
            if (average < 64) {
                symbol = '@';
            } else if (average < 128) {
                symbol = 'X';
            } else if (average < 192) {
                symbol = '-';
            } else {
                symbol = ' ';
            }
            printf("%c%c%c", symbol, symbol, symbol);
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < width * 3; i++) {
        printf("-");
    }
    printf("+\n");
}