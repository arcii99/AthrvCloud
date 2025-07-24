//FormAI DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct Image {
    int width;
    int height;
    Pixel* pixels;
} Image;

void printMenu() {
    printf("Choose an operation:\n");
    printf("1. Load image\n");
    printf("2. Save image\n");
    printf("3. Invert colors\n");
    printf("4. Flip horizontally\n");
    printf("5. Flip vertically\n");
    printf("6. Quit\n");
}

Image* loadImage(char* filePath) {
    FILE* imageFile = fopen(filePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file!\n");
        return NULL;
    }

    // Read the image header
    char format[3];
    int width, height, maxVal;
    fscanf(imageFile, "%s\n%d %d\n%d\n", format, &width, &height, &maxVal);
    if (strcmp(format, "P6") != 0) {
        printf("Error: Invalid image format!\n");
        fclose(imageFile);
        return NULL;
    }

    // Allocate memory for the image pixels
    Pixel* pixels = (Pixel*) malloc(sizeof(Pixel) * width * height);

    // Read the image pixels
    fread(pixels, sizeof(Pixel), width * height, imageFile);

    // Close the image file
    fclose(imageFile);

    // Create an Image object and return it
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;
    return image;
}

void saveImage(Image* image, char* filePath) {
    FILE* imageFile = fopen(filePath, "wb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file!\n");
        return;
    }

    // Write the image header
    fprintf(imageFile, "P6\n%d %d\n%d\n", image->width, image->height, 255);

    // Write the image pixels
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, imageFile);

    // Close the image file
    fclose(imageFile);

    printf("Image saved successfully!\n");
}

void invertColors(Image* image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].red = 255 - image->pixels[i].red;
        image->pixels[i].green = 255 - image->pixels[i].green;
        image->pixels[i].blue = 255 - image->pixels[i].blue;
    }

    printf("Colors inverted successfully!\n");
}

void flipHorizontally(Image* image) {
    Pixel temp;
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width / 2; col++) {
            temp = image->pixels[row * image->width + col];
            image->pixels[row * image->width + col] = image->pixels[row * image->width + image->width - col - 1];
            image->pixels[row * image->width + image->width - col - 1] = temp;
        }
    }

    printf("Image flipped horizontally successfully!\n");
}

void flipVertically(Image* image) {
    Pixel temp;
    for (int col = 0; col < image->width; col++) {
        for (int row = 0; row < image->height / 2; row++) {
            temp = image->pixels[row * image->width + col];
            image->pixels[row * image->width + col] = image->pixels[(image->height - row - 1) * image->width + col];
            image->pixels[(image->height - row - 1) * image->width + col] = temp;
        }
    }

    printf("Image flipped vertically successfully!\n");
}

int main() {
    Image* image = NULL;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char filePath[100];
                printf("Enter the path to the image file:\n");
                scanf("%s", filePath);
                printf("Loading image...\n");
                image = loadImage(filePath);
                if (image == NULL) {
                    printf("Failed to load image!\n");
                } else {
                    printf("Image loaded successfully!\n");
                }
                break;
            case 2:
                if (image == NULL) {
                    printf("Error: No image loaded!\n");
                } else {
                    char filePath[100];
                    printf("Enter the path to save the image file:\n");
                    scanf("%s", filePath);
                    saveImage(image, filePath);
                }
                break;
            case 3:
                if (image == NULL) {
                    printf("Error: No image loaded!\n");
                } else {
                    invertColors(image);
                }
                break;
            case 4:
                if (image == NULL) {
                    printf("Error: No image loaded!\n");
                } else {
                    flipHorizontally(image);
                }
                break;
            case 5:
                if (image == NULL) {
                    printf("Error: No image loaded!\n");
                } else {
                    flipVertically(image);
                }
                break;
            case 6:
                break;
            default:
                printf("Error: Invalid choice!\n");
                break;
        }

    } while (choice != 6);
    
    if (image != NULL) {
        free(image->pixels);
        free(image);
    }

    return 0;
}