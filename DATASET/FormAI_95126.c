//FormAI DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>

void generateFractal(int x, int y, int width, int height, int depth) {
    if (depth == 0) {
        // Base case: print the color of the pixel
        printf("#");
    } else {
        // Recursive case: split into 4 quadrants and call recursively
        int splitWidth = width / 2;
        int splitHeight = height / 2;
        generateFractal(x, y, splitWidth, splitHeight, depth - 1);
        generateFractal(x + splitWidth, y, splitWidth, splitHeight, depth - 1);
        generateFractal(x, y + splitHeight, splitWidth, splitHeight, depth - 1);
        generateFractal(x + splitWidth, y + splitHeight, splitWidth, splitHeight, depth - 1);
    }
}

int main() {
    int width, height, depth;
    printf("Enter width, height, and depth: ");
    scanf("%d %d %d", &width, &height, &depth);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            generateFractal(x, y, width, height, depth);
        }
        printf("\n");
    }
    return 0;
}