//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>

// Define a struct to represent a pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Define a union to manipulate an int as both a whole and by individual bytes
typedef union {
    int value;
    unsigned char bytes[4];
} IntConverter;

int main() {
    // Create a test pixel
    Pixel testPixel = {255, 0, 127};
    // Convert the pixel's values to binary and print them
    printf("Pixel values in binary: %d%d%d %d%d%d %d%d%d\n",
           (testPixel.red >> 7) & 1, (testPixel.red >> 6) & 1, (testPixel.red >> 5) & 1,
           (testPixel.green >> 7) & 1, (testPixel.green >> 6) & 1, (testPixel.green >> 5) & 1,
           (testPixel.blue >> 7) & 1, (testPixel.blue >> 6) & 1, (testPixel.blue >> 5) & 1);
    // Use bitwise OR to combine the red and blue values
    unsigned char purple = testPixel.red | testPixel.blue;
    printf("Purple value in binary: %d%d%d\n",
           (purple >> 2) & 1, (purple >> 1) & 1, purple & 1);
    // Use bitwise AND to clear the 2 least significant bits of the green value
    testPixel.green &= 0xFC;
    printf("Green value in binary (with 2 least significant bits cleared): %d%d%d\n",
           (testPixel.green >> 5) & 1, (testPixel.green >> 4) & 1, (testPixel.green >> 3) & 1);
    // Use the int converter union to manipulate an int as individual bytes
    IntConverter converter;
    converter.value = 0;
    // Set the most significant byte to 0xAB and the least significant byte to 0xCD
    converter.bytes[3] = 0xAB;
    converter.bytes[0] = 0xCD;
    printf("Converted int value: %08X\n", converter.value);
    return 0;
}