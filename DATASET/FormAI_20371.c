//FormAI DATASET v1.0 Category: Image Editor ; Style: cheerful
// Welcome to the Happy C Image Editor!
// This program lets you edit your images with cheerful effects and colors!

#include<stdio.h>
#include<string.h>

// Define image dimensions
#define IMG_WIDTH  800
#define IMG_HEIGHT 600

// Define color structure
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

// Define image buffer
RGB image[IMG_WIDTH][IMG_HEIGHT];

// Declare function to set particular RGB value at pixel coordinates (x, y)
void setPixelRGB(int x, int y, RGB color) {
    image[x][y] = color;
}

// Declare function to get particular RGB value at pixel coordinates (x, y)
RGB getPixelRGB(int x, int y) {
    return image[x][y];
}

// Declare function to load image from file
void loadImage(char* filename) {
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    fseek(file, 54, SEEK_SET);
    
    int x, y;
    
    for (y = IMG_HEIGHT - 1; y >= 0; y--) {
        for (x = 0; x < IMG_WIDTH; x++) {
            RGB color;
            fread(&color.blue, 1, 1, file);
            fread(&color.green, 1, 1, file);
            fread(&color.red, 1, 1, file);
            setPixelRGB(x, y, color);
        }
    }
    
    fclose(file);
}

// Declare function to save image to file
void saveImage(char* filename) {
    FILE* file = fopen(filename, "wb");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    // Write header
    unsigned char header[54] = {
        0x42, 0x4D, 0x36, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x20, 0x03, 0x00, 0x00, 0xD0, 0x02, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x10, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00,
        0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    
    fwrite(header, 1, 54, file);
    
    int x, y;
    
    for (y = IMG_HEIGHT - 1; y >= 0; y--) {
        for (x = 0; x < IMG_WIDTH; x++) {
            RGB color = getPixelRGB(x, y);
            fwrite(&color.blue, 1, 1, file);
            fwrite(&color.green, 1, 1, file);
            fwrite(&color.red, 1, 1, file);
        }
    }
    
    fclose(file);
}

// Declare function to apply cheerful effect to image
void applyCheerfulEffect() {
    int x, y;
    
    for (y = IMG_HEIGHT - 1; y >= 0; y--) {
        for (x = 0; x < IMG_WIDTH; x++) {
            RGB color = getPixelRGB(x, y);
            color.red = color.red + 50;
            color.green = color.green + 100;
            color.blue = color.blue + 150;
            setPixelRGB(x, y, color);
        }
    }
}

int main() {
    // Load image from file
    char* filename = "image.bmp";
    loadImage(filename);
    
    // Apply cheerful effect
    applyCheerfulEffect();
    
    // Save image to file
    char* output_filename = "output.bmp";
    saveImage(output_filename);
    
    printf("Cheerful image saved to %s!\n", output_filename);
    
    return 0;
}