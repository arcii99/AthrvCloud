//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>

// Function to print the ASCII art of the given image
void printASCII(char *img[], int rows, int cols)
{
    // ASCII characters in increasing order of density
    char ascii[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    // Scale of the image (ratio of ASCII character to pixel width)
    float scale = 0.1;

    // Loop through the rows of the image
    for (int i = 0; i < rows; i++)
    {
        // Loop through the columns of the image
        for (int j = 0; j < cols; j++)
        {
            // Calculate the average intensity of the current pixel
            int r = (img[i][j] & 0xff0000) >> 16;
            int g = (img[i][j] & 0x00ff00) >> 8;
            int b = img[i][j] & 0x0000ff;
            float intensity = (r + g + b) / 3.0 / 255;

            // Calculate the equivalent ASCII character for this intensity
            int index = (int)(intensity / scale);
            if (index > 9)
                index = 9;

            // Output the ASCII character
            printf("%c", ascii[index]);
        }

        // Move to the next line
        printf("\n");
    }
}

int main()
{
    // Example image as a 3x5 array
    char *img[] = {
        "\xff\xff\xff\x00\x00", "\xff\x7f\x00\xff\x00", "\xff\xff\x7f\x7f\x7f"};
    int rows = 3;
    int cols = 5;

    // Print the ASCII art of the image
    printASCII(img, rows, cols);

    return 0;
}