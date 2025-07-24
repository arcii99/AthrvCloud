//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
// This program generates a mesmerizing spiral using geometric algorithms
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {

    int width = 40;
    int height = 20;
    int centerX = width / 2;
    int centerY = height / 2;
    int x, y;
    int n = 0;
    int radius = 10;
    double angle = 0;

    char canvas[height][width];

    // Fill canvas with blanks
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            canvas[y][x] = ' ';
        }
    }

    while (1) {

        // Calculate new point using polar coordinates
        double radians = angle * (PI / 180.0);
        double xCoord = centerX + radius * cos(radians);
        double yCoord = centerY + radius * sin(radians);

        // Convert to integer coordinates
        int newX = (int)round(xCoord);
        int newY = (int)round(yCoord);

        // Draw point on canvas
        canvas[newY][newX] = '#';

        // Print canvas
        for (y = 0; y < height; ++y) {
            for (x = 0; x < width; ++x) {
                printf("%c", canvas[y][x]);
            }
            printf("\n");
        }

        // Update angle and radius
        angle += 3.0;
        radius += 1;

        // Check for termination condition
        if (radius >= 15) {
            break;
        }

        // Clear canvas
        for (y = 0; y < height; ++y) {
            for (x = 0; x < width; ++x) {
                canvas[y][x] = ' ';
            }
        }
    }

    return 0;
}