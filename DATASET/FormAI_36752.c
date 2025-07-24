//FormAI DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_COMMAND_LENGTH 50
#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 100
#define MAX_PIXEL_VALUE 255

typedef struct Pixel {
    unsigned char r, g, b; // red, green, blue values
} Pixel;

typedef struct Image {
    int width, height, max_color_value;
    Pixel **pixels;
} Image;

/**
 * @brief Reads the PPM file header and returns an Image struct
 * 
 * @param input_file Pointer to input file
 * @return Image* Pointer to Image struct
 */
Image* read_image_header(FILE *input_file) {
    Image *img = (Image *) malloc(sizeof(Image));

    // Read magic number
    char magic_number[3];
    fscanf(input_file, "%2s\n", magic_number);
    if (strcmp(magic_number, "P3") != 0) {
        fprintf(stderr, "Error: Invalid magic number\n");
        free(img);
        return NULL;
    }

    // Read dimensions
    fscanf(input_file, "%d %d\n", &(img->width), &(img->height));

    // Read max color value
    fscanf(input_file, "%d\n", &(img->max_color_value));
    if (img->max_color_value != MAX_PIXEL_VALUE) {
        fprintf(stderr, "Warning: Max color value not 255\n");
    }

    // Allocate memory for pixels
    img->pixels = (Pixel **) malloc(sizeof(Pixel *) * img->height);
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = (Pixel *) malloc(sizeof(Pixel) * img->width);
    }

    return img;
}

/**
 * @brief Reads the pixel data from an input file and stores it in an Image struct
 * 
 * @param img Pointer to Image struct
 * @param input_file Pointer to input file
 */
void read_pixels(Image *img, FILE *input_file) {
    // Read pixel values
    int r, g, b;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(input_file, "%d %d %d", &r, &g, &b);
            img->pixels[i][j].r = (unsigned char) r;
            img->pixels[i][j].g = (unsigned char) g;
            img->pixels[i][j].b = (unsigned char) b;
        }
    }
}

/**
 * @brief Writes an Image struct to an output file
 * 
 * @param img Pointer to Image struct
 * @param output_file Pointer to output file
 */
void write_image(Image *img, FILE *output_file) {
    // Write PPM header
    fprintf(output_file, "P3\n");
    fprintf(output_file, "%d %d\n", img->width, img->height);
    fprintf(output_file, "%d\n", img->max_color_value);

    // Write pixel values
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(output_file, "%d %d %d ", (int) img->pixels[i][j].r, (int) img->pixels[i][j].g, (int) img->pixels[i][j].b);
        }
        fprintf(output_file, "\n");
    }
}

/**
 * @brief Inverts all the pixels in an Image
 * 
 * @param img Pointer to Image struct
 */
void invert_pixels(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j].r = MAX_PIXEL_VALUE - img->pixels[i][j].r;
            img->pixels[i][j].g = MAX_PIXEL_VALUE - img->pixels[i][j].g;
            img->pixels[i][j].b = MAX_PIXEL_VALUE - img->pixels[i][j].b;
        }
    }
}

/**
 * @brief Adds noise to an Image
 * 
 * @param img Pointer to Image struct
 * @param intensity Intensity of noise
 */
void add_noise(Image *img, int intensity) {
    int range = 2 * intensity;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j].r = img->pixels[i][j].r + rand() % range - intensity;
            img->pixels[i][j].g = img->pixels[i][j].g + rand() % range - intensity;
            img->pixels[i][j].b = img->pixels[i][j].b + rand() % range - intensity;
            if (img->pixels[i][j].r < 0) img->pixels[i][j].r = 0;
            if (img->pixels[i][j].g < 0) img->pixels[i][j].g = 0;
            if (img->pixels[i][j].b < 0) img->pixels[i][j].b = 0;
            if (img->pixels[i][j].r > MAX_PIXEL_VALUE) img->pixels[i][j].r = MAX_PIXEL_VALUE;
            if (img->pixels[i][j].g > MAX_PIXEL_VALUE) img->pixels[i][j].g = MAX_PIXEL_VALUE;
            if (img->pixels[i][j].b > MAX_PIXEL_VALUE) img->pixels[i][j].b = MAX_PIXEL_VALUE;
        }
    }
}

int main() {
    printf("Welcome to the C Image Editor.\n");
    printf("Enter the name of the input file: ");

    // Get input file name
    char input_filename[MAX_FILENAME_LENGTH];
    fgets(input_filename, MAX_FILENAME_LENGTH, stdin);
    input_filename[strcspn(input_filename, "\n")] = 0; // remove newline character

    // Check if input file exists
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        return 1;
    }

    // Read image header
    Image *img = read_image_header(input_file);
    if (img == NULL) {
        fclose(input_file);
        return 1;
    }

    // Read pixel data
    read_pixels(img, input_file);
    fclose(input_file);

    // Menu loop
    char command[MAX_COMMAND_LENGTH];
    while (true) {
        printf("\nWhat would you like to do with the image? (Type 'help' for a list of commands)\n");
        printf(">");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character

        if (strcmp(command, "help") == 0) {
            printf("Commands:\n");
            printf("invert - Invert all pixels\n");
            printf("noise <intensity> - Add random noise to each pixel\n");
            printf("save <filename> - Save the edited image to a file\n");
        } else if (strcmp(command, "invert") == 0) {
            invert_pixels(img);
            printf("Pixels inverted.\n");
        } else if (strstr(command, "noise") != NULL) {
            int intensity;
            sscanf(command, "noise %d", &intensity);
            add_noise(img, intensity);
            printf("Noise added.\n");
        } else if (strstr(command, "save") != NULL) {
            char output_filename[MAX_FILENAME_LENGTH];
            sscanf(command, "save %99s", output_filename);

            FILE *output_file = fopen(output_filename, "w");
            if (output_file == NULL) {
                fprintf(stderr, "Error: Could not create output file\n");
                continue;
            }

            write_image(img, output_file);
            fclose(output_file);
            printf("Image saved as %s.\n", output_filename);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Command not recognized. Type 'help' for a list of commands.\n");
        }
    }

    // Free memory allocated for pixels
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);

    printf("Goodbye!\n");
    return 0;
}