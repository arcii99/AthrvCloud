//FormAI DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLENGTH 1000

typedef struct Image {
    char type[3];
    int width;
    int height;
    int max_color_value;
    int **pixels;
} Image;

Image *create_image(char type[], int width, int height, int max_color_value) {
    Image *new_image = malloc(sizeof(Image));
    strcpy(new_image->type, type);
    new_image->width = width;
    new_image->height = height;
    new_image->max_color_value = max_color_value;
    new_image->pixels = malloc(sizeof(int*) * height);
    for(int i = 0; i < height; i++) {
        new_image->pixels[i] = malloc(sizeof(int) * width);
    }
    return new_image;
}

Image *read_image_from_file(char filename[]) {
    FILE *image_file = fopen(filename, "r");
    char header[3];
    fscanf(image_file, "%s", header);
    int width, height, max_color_value;
    fscanf(image_file, "%d %d %d", &width, &height, &max_color_value);
    Image *new_image = create_image(header, width, height, max_color_value);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fscanf(image_file, "%d", &new_image->pixels[i][j]);
        }
    }
    fclose(image_file);
    return new_image;
}

void write_image_to_file(Image *image, char filename[]) {
    FILE *image_file = fopen(filename, "w");
    fprintf(image_file, "%s\n%d %d\n%d\n", image->type, image->width, image->height, image->max_color_value);
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            fprintf(image_file, "%d ", image->pixels[i][j]);
        }
        fprintf(image_file, "\n");
    }
    fclose(image_file);
}

Image *copy_image(Image *image) {
    Image *new_image = create_image(image->type, image->width, image->height, image->max_color_value);
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            new_image->pixels[i][j] = image->pixels[i][j];
        }
    }
    return new_image;
}

void limit_pixels(Image *image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            if(image->pixels[i][j] > image->max_color_value) {
                image->pixels[i][j] = image->max_color_value;
            } else if(image->pixels[i][j] < 0) {
                image->pixels[i][j] = 0;
            }
        }
    }
}

int find_max(int arr[], int n) { 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] > max) {
            max = arr[i]; 
        }
    } 
    return max; 
}

int find_min(int arr[], int n) { 
    int min = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] < min) {
            min = arr[i]; 
        }
    } 
    return min; 
}

Image *apply_brightness(Image *image, int brightness_value) {
    Image *new_image = copy_image(image);
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            new_image->pixels[i][j] += brightness_value;
        }
    }
    limit_pixels(new_image);
    return new_image;
}

Image *apply_blur(Image *image) {
    Image *new_image = copy_image(image);
    int blur_kernel[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    for(int i = 1; i < image->height - 1; i++) {
        for(int j = 1; j < image->width - 1; j++) {
            int sum = 0;
            for(int k = -1; k <= 1; k++) {
                for(int l = -1; l <= 1; l++) {
                    sum += blur_kernel[k + 1][l + 1] * image->pixels[i + k][j + l];
                }
            }
            new_image->pixels[i][j] = sum / 9;
        }
    }
    limit_pixels(new_image);
    return new_image;
}

Image *apply_edge_detection(Image *image) {
    Image *new_image = copy_image(image);
    int G_x_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int G_y_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for(int i = 1; i < image->height - 1; i++) {
        for(int j = 1; j < image->width - 1; j++) {
            int G_x = 0, G_y = 0;
            for(int k = -1; k <= 1; k++) {
                for(int l = -1; l <= 1; l++) {
                    G_x += G_x_kernel[k + 1][l + 1] * image->pixels[i + k][j + l];
                    G_y += G_y_kernel[k + 1][l + 1] * image->pixels[i + k][j + l];
                }
            }
            new_image->pixels[i][j] = (int)sqrt(G_x * G_x + G_y * G_y);
        }
    }
    limit_pixels(new_image);
    return new_image;
}

void free_image(Image *image) {
    for(int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

int main() {
    char filename[MAXLENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    Image *image = read_image_from_file(filename);
    printf("Image type: %s\n", image->type);
    printf("Image dimensions: %d x %d\n", image->width, image->height);

    int choice, brightness_value;
    do {
        printf("\nSelect an option:\n");
        printf("1. Save the current image\n");
        printf("2. Apply brightness\n");
        printf("3. Apply blur\n");
        printf("4. Apply edge detection\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the filename to save the image to: ");
                scanf("%s", filename);
                write_image_to_file(image, filename);
                break;
            case 2:
                printf("Enter the brightness value: ");
                scanf("%d", &brightness_value);
                image = apply_brightness(image, brightness_value);
                printf("Brightness applied successfully.\n");
                break;
            case 3:
                image = apply_blur(image);
                printf("Blur applied successfully.\n");
                break;
            case 4:
                image = apply_edge_detection(image);
                printf("Edge detection applied successfully.\n");
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        if(choice != 5) {
            printf("Max pixel value: %d\n", find_max(*image->pixels, image->width * image->height));
            printf("Min pixel value: %d\n", find_min(*image->pixels, image->width * image->height));
        }
    } while(choice != 5);

    free_image(image);
    return 0;
}