//FormAI DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 1000

// Function to load an image from file
char** load_image(char* filename, int* width, int* height) {
    char** image = NULL;
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char buffer[MAX_FILENAME_LEN];
        fgets(buffer, MAX_FILENAME_LEN, file);
        sscanf(buffer, "%d %d\n", width, height);
        image = (char**)malloc(sizeof(char*) * (*height));
        for (int i = 0; i < *height; i++) {
            image[i] = (char*)malloc(sizeof(char) * (*width));
            fgets(image[i], (*width) + 1, file);
        }
        fclose(file);
    } else {
        printf("ERROR: File not found.\n");
    }
    return image;
}

// Function to save image to file
void save_image(char* filename, char** image, int width, int height) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%d %d\n", width, height);
        for (int i = 0; i < height; i++) {
            fputs(image[i], file);
            fputs("\n", file);
        }
        fclose(file);
    } else {
        printf("ERROR: Cannot save file.\n");
    }
}

// Function to flip image horizontally
void flip_horizontal(char** image, int width, int height, int row) {
    if (row >= height / 2) {
        return;
    }
    for (int i = 0; i < width / 2; i++) {
        char temp = image[row][i];
        image[row][i] = image[row][width - i - 1];
        image[row][width - i - 1] = temp;
    }
    flip_horizontal(image, width, height, row + 1);
}

// Function to flip image vertically
void flip_vertical(char** image, int width, int height, int col) {
    if (col >= width / 2) {
        return;
    }
    for (int i = 0; i < height / 2; i++) {
        char temp = image[i][col];
        image[i][col] = image[height - i - 1][col];
        image[height - i - 1][col] = temp;
    }
    flip_vertical(image, width, height, col + 1);
}

// Function to rotate image 90 degrees clockwise
char** rotate_clockwise(char** image, int width, int height) {
    char** rotated = (char**)malloc(sizeof(char*) * width);
    for (int i = 0; i < width; i++) {
        rotated[i] = (char*)malloc(sizeof(char) * height);
        for (int j = 0; j < height; j++) {
            rotated[i][j] = image[height - j - 1][i];
        }
    }
    return rotated;
}

// Main program
int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0;
    int width, height;
    char** image = load_image(filename, &width, &height);
    if (image != NULL) {
        int choice = -1;
        while (choice != 0) {
            printf("1. Flip horizontally\n");
            printf("2. Flip vertically\n");
            printf("3. Rotate 90 degrees clockwise\n");
            printf("4. Save changes\n");
            printf("5. Cancel changes\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            getchar();
            switch (choice) {
                case 1: flip_horizontal(image, width, height, 0); break;
                case 2: flip_vertical(image, width, height, 0); break;
                case 3:
                    char** rotated = rotate_clockwise(image, width, height);
                    for (int i = 0; i < height; i++) {
                        free(image[i]);
                    }
                    free(image);
                    image = rotated;
                    int temp = width;
                    width = height;
                    height = temp;
                    break;
                case 4:
                    save_image(filename, image, width, height);
                    printf("Changes saved.\n");
                    choice = 0;
                    break;
                case 5:
                    printf("Changes cancelled.\n");
                    choice = 0;
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
        }
    }
    return 0;
}