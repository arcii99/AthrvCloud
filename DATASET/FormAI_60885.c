//FormAI DATASET v1.0 Category: Image compression ; Style: funny
#include <stdio.h>

/* Function to determine the binary representation of a given decimal number */
int *decimalToBinary(int decimalNumber) {
    static int binaryNumber[8];
    int i = 0;
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }
    return binaryNumber;
}

/* Main function to compress an image */
int main() {
    int pixels[8][8] = {
        {234, 215, 180, 149, 135, 174, 222, 229},
        {231, 190, 131, 102, 121, 160, 203, 215},
        {214, 144, 67, 33, 66, 107, 156, 175},
        {157, 76, 14, 0, 25, 68, 121, 138},
        {121, 41, 0, 11, 42, 86, 133, 147},
        {167, 62, 5, 4, 37, 76, 118, 131},
        {223, 109, 55, 29, 70, 120, 149, 160},
        {234, 201, 173, 132, 118, 158, 209, 223},
    };
    
    printf("Original Image:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d\t", pixels[i][j]);
        }
        printf("\n");
    }
    
    printf("Compressed Image:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int *binaryPixels = decimalToBinary(pixels[i][j]);
            for (int k = 0; k < 8; k += 2) {
                int b1 = binaryPixels[k];
                int b2 = binaryPixels[k+1];
                int compressedPixel = (b1 * 2) + b2;
                printf("%d\t", compressedPixel);
            }
        }
        printf("\n");
    }
    
    return 0;
}