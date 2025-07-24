//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>

// Function to convert RGB to grayscale
int getGrayscale(int red, int green, int blue) {
    return 0.21*red + 0.72*green + 0.07*blue;
}

// Function to map grayscale value to ASCII character
char getSymbol(int grayscale) {
    const char symbols[] = "@#%xo;:. ";
    int index = (int)(grayscale / 25.5);
    return symbols[index];
}

int main() {
    // Open image file
    FILE *fp = fopen("image.jpg", "rb");
    if (!fp) {
        printf("Error opening image file.");
        return 1;
    }

    // Skip header information
    fseek(fp, 54, SEEK_SET);

    // Get image dimensions
    int width = 0, height = 0;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Calculate padding for each row
    int padding = 4 - (width * sizeof(int)) % 4;
    if (padding == 4) padding = 0;

    // Loop through each pixel in the image
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            // Read RGB values for this pixel
            int red = 0, green = 0, blue = 0;
            fread(&blue, sizeof(char), 1, fp);
            fread(&green, sizeof(char), 1, fp);
            fread(&red, sizeof(char), 1, fp);

            // Convert RGB to grayscale and get corresponding ASCII symbol
            int grayscale = getGrayscale(red, green, blue);
            char symbol = getSymbol(grayscale);

            // Print symbol to the screen
            printf("%c", symbol);
        }

        // Skip padding at the end of each row
        fseek(fp, padding, SEEK_CUR);

        // Print new line at the end of each row
        printf("\n");
    }

    // Close image file
    fclose(fp);

    return 0;
}