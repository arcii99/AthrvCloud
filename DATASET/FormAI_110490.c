//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>

// Define ASCII characters to use in the conversion.
char shade[] = {' ', '.', '-', '=', '+', '*', '#', '%', '@'};

int main() {
    // Declare variables to hold image properties and pixel data.
    int width, height;
    unsigned char pixels[100][100];

    // Get input from the user for the image width and height.
    printf("Enter the image width: ");
    scanf("%d", &width);
    printf("Enter the image height: ");
    scanf("%d", &height);

    // Get input from the user for the pixel data.
    printf("Enter the pixel data:\n");
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            scanf("%hhu", &pixels[row][col]);
        }
    }

    // Convert the pixel data to ASCII art and print it to the console.
    printf("\nASCII art:\n");
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int index = pixels[row][col] * 9 / 255;
            printf("%c", shade[index]);
        }
        printf("\n");
    }

    return 0;
}