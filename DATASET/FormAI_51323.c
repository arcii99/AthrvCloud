//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>

#define MAX_SIZE 100000

int main()
{
    // Declare Variables
    char ascii[MAX_SIZE];
    int width, height, i, j;
    char * img_name = "input.png";
    
    // Open image file
    FILE *img_file = fopen(img_name, "rb");
    
    if (!img_file) {
        printf("Unable to open image file %s!\n", img_name);
        return 1;
    }
    
    // Get dimensions of image
    fseek(img_file, 18, SEEK_SET);
    fread(&width, sizeof(width), 1, img_file);
    fread(&height, sizeof(height), 1, img_file);
    fseek(img_file, 54, SEEK_SET);
    
    // Convert image pixel values to ASCII characters
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            char r, g, b;
            fread(&b, 1, 1, img_file);
            fread(&g, 1, 1, img_file);
            fread(&r, 1, 1, img_file);
            float gray = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            if (gray >= 230) {
                ascii[i * width + j] = ' ';
            } else if (gray >= 200) {
                ascii[i * width + j] = '-';
            } else if (gray >= 180) {
                ascii[i * width + j] = '/';
            } else if (gray >= 160) {
                ascii[i * width + j] = '\'';
            } else if (gray >= 130) {
                ascii[i * width + j] = ':';
            } else if (gray >= 100) {
                ascii[i * width + j] = '*';
            } else if (gray >=70) {
                ascii[i * width + j] = '=';
            } else if (gray >= 50) {
                ascii[i * width + j] = '!';
            } else {
                ascii[i * width + j] = '+';
            }
        }
    }
    
    // Print ASCII image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii[i * width + j]);
        }
        printf("\n");
    }
    
    // Close image file and free memory used
    fclose(img_file);
    
    return 0;
}