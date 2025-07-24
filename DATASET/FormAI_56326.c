//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

char ascii[MAX_HEIGHT][MAX_WIDTH + 1];

void resize(int *width, int *height, int *scale) {
    int new_width = 0, new_height = 0, new_scale = 1;
    printf("Enter new scaling factor (1-10): ");
    scanf("%d", &new_scale);
    new_scale = (new_scale < 1) ? 1 : (new_scale > 10) ? 10 : new_scale;
    new_width = (*width % new_scale) ? (*width / new_scale) + 1 : (*width / new_scale);
    new_height = (*height % new_scale) ? (*height / new_scale) + 1 : (*height / new_scale);
    *width = new_width;
    *height = new_height;
    *scale = new_scale;
}

char get_ascii_char(int luminosity) {
    const char *ascii_chars = " .,:;irsXA253hMHGS#9B&@";
    const int total_chars = strlen(ascii_chars);
    int index = ((float) luminosity / 255) * total_chars;
    return ascii_chars[index];
}

void convert(char *filename, int width, int height, int scale) {
    FILE *image_file;
    image_file = fopen(filename, "rb");
    if (!image_file) {
        printf("Error: Failed to open file %s", filename);
        exit(1);
    }

    unsigned char buffer[height][width][3];

    // Read image data
    fread(buffer, sizeof(buffer), 1, image_file);

    // Convert image to ascii
    for (int y = 0, k = 0; y < height; y += scale) {
        for (int x = 0; x < width; x += scale, k++) {
            int red = buffer[y][x][0];
            int green = buffer[y][x][1];
            int blue = buffer[y][x][2];
            int luminosity = (0.2126 * red) + (0.7152 * green) + (0.0722 * blue);
            ascii[y / scale][k] = get_ascii_char(luminosity);
        }
    }

    // Print ascii art
    for (int y = 0; y < height / scale; y++) {
        ascii[y][width / scale] = '\0';
        printf("%s\n", ascii[y]);
    }

    fclose(image_file);
}

int main() {
    printf("Welcome to Image to ASCII Converter!\n");
    
    char filename[100];
    int width = 0;
    int height = 0;
    int scale = 1;

    printf("Enter name of image file: ");
    scanf("%s", filename);

    printf("Enter width of output in characters: ");
    scanf("%d", &width);
    width = (width > MAX_WIDTH) ? MAX_WIDTH : width;

    printf("Enter height of output in characters: ");
    scanf("%d", &height);
    height = (height > MAX_HEIGHT) ? MAX_HEIGHT : height;

    convert(filename, width, height, scale);

    int choice = 0;
    while (1) {
        printf("Do you want to resize? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        resize(&width, &height, &scale);
        convert(filename, width, height, scale);
    }

    printf("Thanks for using this program. Goodbye!\n");
    return 0;
}