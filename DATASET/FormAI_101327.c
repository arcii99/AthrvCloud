//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 50
#define MAX_COMMAND_LENGTH 20
#define MAX_PIXEL_VALUE 255

// Define image struct
typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

// Function to print the image
void print_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }
}

// Function to load image from file
Image* load_image(char *filename) {
    FILE *file;
    char command[MAX_COMMAND_LENGTH];
    Image *img = malloc(sizeof(Image));

    if (!img) {
        printf("Error: Could not allocate memory for image.\n");
        return NULL;
    }

    file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s.\n", filename);
        free(img);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);

    img->pixels = malloc(img->height * sizeof(int *));
    if (!img->pixels) {
        printf("Error: Could not allocate memory for pixels.\n");
        free(img);
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = malloc(img->width * sizeof(int));
        if (!img->pixels[i]) {
            printf("Error: Could not allocate memory for pixels.\n");
            free_image(img);
            fclose(file);
            return NULL;
        }
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(file, "%d", &img->pixels[i][j]);
        }
    }

    fclose(file);
    return img;
}

// Function to save image to file
void save_image(Image *img, char *filename) {
    FILE *file;

    file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not create file %s.\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(file, "%d ", img->pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to free image memory
void free_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

// Function to invert the colors of an image
void invert_colors(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = MAX_PIXEL_VALUE - img->pixels[i][j];
        }
    }
}

// Function to rotate an image 90 degrees clockwise
void rotate_clockwise(Image *img) {
    int **new_pixels = malloc(img->width * sizeof(int *));
    for (int i = 0; i < img->width; i++) {
        new_pixels[i] = malloc(img->height * sizeof(int));
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            new_pixels[j][img->height - 1 - i] = img->pixels[i][j];
        }
    }

    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);

    img->pixels = new_pixels;
    int temp = img->width;
    img->width = img->height;
    img->height = temp;
}

int main() {
    char filename[MAX_FILENAME];
    printf("Enter image filename: ");
    scanf("%s", filename);

    Image *img = load_image(filename);

    if (!img) {
        return EXIT_FAILURE;
    }

    char command[MAX_COMMAND_LENGTH];
    do {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "print") == 0) {
            print_image(img);
        } else if (strcmp(command, "invert") == 0) {
            invert_colors(img);
        } else if (strcmp(command, "rotate") == 0) {
            rotate_clockwise(img);
        } else if (strcmp(command, "save") == 0) {
            char save_filename[MAX_FILENAME];
            printf("Enter filename to save: ");
            scanf("%s", save_filename);
            save_image(img, save_filename);
        }

    } while (strcmp(command, "quit") != 0);

    free_image(img);
    return EXIT_SUCCESS;
}