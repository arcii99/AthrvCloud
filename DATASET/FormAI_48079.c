//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define HEADER_SIZE 54 // BMP header size

/* Function to read BMP file */
unsigned char **read_image(char *filename, int *height, int *width) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, f);

    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    int padding = 0;
    while ((*width * 3 + padding) % 4 != 0) {
        padding++;
    }

    unsigned char **image = (unsigned char **)malloc(sizeof(unsigned char *) * *height);
    for (int i = 0; i < *height; i++) {
        image[i] = (unsigned char *)malloc(sizeof(unsigned char) * (*width) * 3 + padding);
        fread(image[i], sizeof(unsigned char), (*width) * 3 + padding, f);
    }

    fclose(f);
    return image;
}

/* Function to write BMP file */
void write_image(char *filename, unsigned char **image, int height, int width) {
    int padding = 0;
    while ( (width * 3 + padding) % 4 != 0 ) {
        padding++;
    }

    unsigned char header[HEADER_SIZE] = {
        'B', 'M', // magic number
        0,0,0,0, // size of BMP file
        0,0,0,0, // unused
        HEADER_SIZE,0,0,0, // offset of pixel array
        40,0,0,0, // size of info header
        0,0,0,0, // image width
        0,0,0,0, // image height
        1,0,24,0, // color depth (24 bits)
        0,0,0,0, // compression method
        0,0,0,0, // size of raw image data
        0,0,0,0, // horizontal resolution (pixels per meter)
        0,0,0,0, // vertical resolution (pixels per meter)
        0,0,0,0, // colors in color palette
        0,0,0,0 // important colors
    };

    *(int *)&header[2] = (width * 3 + padding) * height + HEADER_SIZE; // size of BMP file
    *(int *)&header[18] = width; // image width
    *(int *)&header[22] = height; // image height
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, f);

    for (int i = height - 1; i >= 0; i--) {
        fwrite(image[i], sizeof(unsigned char), 3 * width + padding, f);
    }

    fclose(f);
}

/* Function to invert pixel colors */
void invert_colors(unsigned char **image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][3 * j] = 255 - image[i][3 * j];
            image[i][3 * j + 1] = 255 - image[i][3 * j + 1];
            image[i][3 * j + 2] = 255 - image[i][3 * j + 2];
        }
    }
}

/* Function to adjust brightness */
void adjust_brightness(unsigned char **image, float factor, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][3 * j] = fminf(255.0, image[i][3 * j] * factor);
            image[i][3 * j + 1] = fminf(255.0, image[i][3 * j + 1] * factor);
            image[i][3 * j + 2] = fminf(255.0, image[i][3 * j + 2] * factor);
        }
    }
}

/* Function to apply sepia tone */
void apply_sepia(unsigned char **image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][3 * j];
            int g = image[i][3 * j + 1];
            int b = image[i][3 * j + 2];

            int tr = fmaxf(0.0, fminf(255.0, 0.393 * r + 0.769 * g + 0.189 * b));
            int tg = fmaxf(0.0, fminf(255.0, 0.349 * r + 0.686 * g + 0.168 * b));
            int tb = fmaxf(0.0, fminf(255.0, 0.272 * r + 0.534 * g + 0.131 * b));

            image[i][3 * j] = tr;
            image[i][3 * j + 1] = tg;
            image[i][3 * j + 2] = tb;
        }
    }
}

/* Function to apply grayscale */
void apply_grayscale(unsigned char **image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][3 * j];
            int g = image[i][3 * j + 1];
            int b = image[i][3 * j + 2];

            int gray = (int)(0.2989 * r + 0.5870 * g + 0.1140 * b);

            image[i][3 * j] = gray;
            image[i][3 * j + 1] = gray;
            image[i][3 * j + 2] = gray;
        }
    }
}

int main() {
    int height, width;
    char filename[100];

    printf("Enter filename with .bmp extension: ");
    scanf("%s", filename);

    unsigned char **image = read_image(filename, &height, &width);

    printf("\n1. Invert Colors\n2. Adjust Brightness\n3. Apply Sepia Tone\n4. Apply Grayscale\n5. Exit\n");

    while (1) {
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert_colors(image, height, width);
                printf("\nColors inverted successfully!\n");
                break;
            case 2:
                float factor;
                printf("Enter brightness factor (0.1 to 10.0): ");
                scanf("%f", &factor);
                adjust_brightness(image, factor, height, width);
                printf("\nBrightness adjusted successfully!\n");
                break;
            case 3:
                apply_sepia(image, height, width);
                printf("\nSepia tone applied successfully!\n");
                break;
            case 4:
                apply_grayscale(image, height, width);
                printf("\nGrayscale applied successfully!\n");
                break;
            case 5:
                printf("\nExiting...\n");
                goto exit_program;
            default:
                printf("\nInvalid choice!\n");
                break;
        }

        // write the modified image to file
        write_image(filename, image, height, width);
    }

    exit_program:
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}