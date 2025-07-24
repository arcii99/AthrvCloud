//FormAI DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum length of the file name
#define MAX_FILENAME_LENGTH 100

// Define the maximum size of the image
#define MAX_IMAGE_SIZE 2000

// Define the maximum line length
#define MAX_LINE_LENGTH 200

// Define the structure for a pixel
typedef struct {
    unsigned char red, green, blue;
} Pixel;

// Define the structure for an image
typedef struct {
    int width, height;
    Pixel pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

// Function to read an image from a file
void read_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("Could not open file %s.\n", filename);
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    if(strcmp(line, "P3\n") != 0) {
        printf("Invalid file format.\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, file);
    while(line[0] == '#') {
        fgets(line, MAX_LINE_LENGTH, file);
    }
    sscanf(line, "%d %d", &image->width, &image->height);
    fgets(line, MAX_LINE_LENGTH, file);
    int max_color;
    sscanf(line, "%d", &max_color);
    if(max_color > 255) {
        printf("Invalid file format.\n");
        exit(1);
    }
    int x, y;
    for(y = 0; y < image->height; y++) {
        for(x = 0; x < image->width; x++) {
            int red, green, blue;
            fscanf(file, "%d %d %d", &red, &green, &blue);
            if(red > max_color || green > max_color || blue > max_color) {
                printf("Invalid file format.\n");
                exit(1);
            }
            image->pixels[x][y].red = (unsigned char)red;
            image->pixels[x][y].green = (unsigned char)green;
            image->pixels[x][y].blue = (unsigned char)blue;
        }
    }
    fclose(file);
}

// Function to write an image to a file
void write_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    if(!file) {
        printf("Could not open file %s.\n", filename);
        exit(1);
    }
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");
    int x, y;
    for(y = 0; y < image->height; y++) {
        for(x = 0; x < image->width; x++) {
            fprintf(file, "%d %d %d ", image->pixels[x][y].red, image->pixels[x][y].green, image->pixels[x][y].blue);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    int x, y;
    for(y = 0; y < image->height; y++) {
        for(x = 0; x < image->width / 2; x++) {
            Pixel temp = image->pixels[x][y];
            image->pixels[x][y] = image->pixels[image->width - x - 1][y];
            image->pixels[image->width - x - 1][y] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(Image *image) {
    int x, y;
    for(y = 0; y < image->height / 2; y++) {
        for(x = 0; x < image->width; x++) {
            Pixel temp = image->pixels[x][y];
            image->pixels[x][y] = image->pixels[x][image->height - y - 1];
            image->pixels[x][image->height - y - 1] = temp;
        }
    }
}

// Function to increase the brightness of an image by a percentage
void increase_brightness(Image *image, int percent) {
    int x, y;
    for(y = 0; y < image->height; y++) {
        for(x = 0; x < image->width; x++) {
            image->pixels[x][y].red = (unsigned char) (image->pixels[x][y].red * (100 + percent) / 100);
            image->pixels[x][y].green = (unsigned char) (image->pixels[x][y].green * (100 + percent) / 100);
            image->pixels[x][y].blue = (unsigned char) (image->pixels[x][y].blue * (100 + percent) / 100);
        }
    }
}

// Function to decrease the brightness of an image by a percentage
void decrease_brightness(Image *image, int percent) {
    int x, y;
    for(y = 0; y < image->height; y++) {
        for(x = 0; x < image->width; x++) {
            image->pixels[x][y].red = (unsigned char) (image->pixels[x][y].red * (100 - percent) / 100);
            image->pixels[x][y].green = (unsigned char) (image->pixels[x][y].green * (100 - percent) / 100);
            image->pixels[x][y].blue = (unsigned char) (image->pixels[x][y].blue * (100 - percent) / 100);
        }
    }
}

// Function to apply a grayscale filter to an image
void grayscale(Image *image) {
    int x, y;
    for(y = 0; y < image->height; y++) {
        for(x = 0; x < image->width; x++) {
            unsigned char gray = (unsigned char) (0.2126 * image->pixels[x][y].red + 0.7152 * image->pixels[x][y].green + 0.0722 * image->pixels[x][y].blue);
            image->pixels[x][y].red = gray;
            image->pixels[x][y].green = gray;
            image->pixels[x][y].blue = gray;
        }
    }
}

int main() {
    // Prompt the user for the file name
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\r\n")] = 0;
    // Read the image from the file
    Image image;
    read_image(&image, filename);
    // Prompt the user for the operation
    int operation;
    printf("Enter the operation to perform:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Flip the image vertically\n");
    printf("3. Increase the brightness of the image\n");
    printf("4. Decrease the brightness of the image\n");
    printf("5. Apply a grayscale filter to the image\n");
    printf("Enter the operation number: ");
    scanf("%d", &operation);
    // Perform the operation
    switch(operation) {
        case 1:
            flip_horizontal(&image);
            break;
        case 2:
            flip_vertical(&image);
            break;
        case 3:
            printf("Enter the percentage to increase the brightness by: ");
            int percent_increase;
            scanf("%d", &percent_increase);
            increase_brightness(&image, percent_increase);
            break;
        case 4:
            printf("Enter the percentage to decrease the brightness by: ");
            int percent_decrease;
            scanf("%d", &percent_decrease);
            decrease_brightness(&image, percent_decrease);
            break;
        case 5:
            grayscale(&image);
            break;
        default:
            printf("Invalid operation number.\n");
            exit(1);
    }
    // Write the modified image to a file
    write_image(&image, "output.ppm");
    printf("Output written to output.ppm.\n");
    return 0;
}