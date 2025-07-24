//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateImage(int width, int height, int pixelSize);

int main() {
    int width = 20;
    int height = 10;
    int pixelSize = 7;
    generateImage(width, height, pixelSize);
    return 0;
}

void generateImage(int width, int height, int pixelSize) {
    srand(time(NULL));
    printf("P3 %d %d 255\n", width * pixelSize, height * pixelSize);
    
    for (int y = 0; y < height; y++) {
        for (int pointY = 0; pointY < pixelSize; pointY++) {
            for (int x = 0; x < width; x++) {
                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;
                
                for (int pointX = 0; pointX < pixelSize; pointX++) {
                    printf("%d %d %d ", r, g, b);
                }
            }
            printf("\n");
        }
    }
}