//FormAI DATASET v1.0 Category: Image compression ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Sample 8x8 pixel grayscale image
    int image[8][8] = {{135, 135, 135, 135, 135, 135, 135, 135},
                       {135, 135, 135, 135, 135, 135, 135, 135},
                       {135, 135, 165, 165, 135, 125, 125, 135},
                       {135, 165, 220, 220, 135, 50,  50,  135},
                       {135, 165, 220, 220, 135, 50,  50,  135},
                       {135, 135, 165, 165, 135, 125, 125, 135},
                       {135, 135, 135, 135, 135, 135, 135, 135},
                       {135, 135, 135, 135, 135, 135, 135, 135}};
    int i, j;

    // Print original image
    printf("Original Image:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Compress image using run-length encoding
    int compressed[64];
    int count, k = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            count = 1;
            while (j < 7 && image[i][j] == image[i][j+1]) {
                count++;
                j++;
            }
            compressed[k] = image[i][j];
            compressed[k+1] = count;
            k+=2;
        }
    }

    // Print compressed image
    printf("\nCompressed Image:\n");
    for (i = 0; i < 64; i+=2) {
        printf("%d,%d ", compressed[i], compressed[i+1]);
    }
    printf("\n");

    // Decompress image
    int decompressed[8][8];
    k = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (compressed[k+1] > 0) {
                decompressed[i][j] = compressed[k];
                compressed[k+1]--;
                continue;
            }
            k+=2;
            decompressed[i][j] = compressed[k];
            compressed[k+1]--;
            j--;
        }
    }

    // Print decompressed image
    printf("\nDecompressed Image:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", decompressed[i][j]);
        }
        printf("\n");
    }

    return 0;
}