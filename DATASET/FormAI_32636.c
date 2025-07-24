//FormAI DATASET v1.0 Category: Image Editor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void happyFilter(unsigned char *image, int width, int height) {
    // Apply a filter that increases saturation and brightness
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width * 3; j += 3) {
            int red = image[i * width * 3 + j];
            int green = image[i * width * 3 + j + 1];
            int blue = image[i * width * 3 + j + 2];

            // Convert to HSV color space
            double r = red / 255.0;
            double g = green / 255.0;
            double b = blue / 255.0;
            double max = fmax(fmax(r, g), b);
            double min = fmin(fmin(r, g), b);
            double delta = max - min;

            double hue = 0;
            double saturation = 0;
            double value = max;

            if (delta != 0) {
                if (max == r) {
                    hue = fmod((g - b) / delta, 6);
                } else if (max == g) {
                    hue = (b - r) / delta + 2;
                } else if (max == b) {
                    hue = (r - g) / delta + 4;
                }
                saturation = delta / max;
            }

            // Increase saturation and brightness
            saturation = fmin(1.0, saturation * 1.2);
            value = fmin(1.0, value * 1.2);

            // Convert back to RGB color space
            double chroma = value * saturation;
            double h = hue / 6.0;
            double x = chroma * (1 - fabs(fmod(h, 2) - 1));
            double m = value - chroma;
            double r1, g1, b1;

            if (h < 1) {
                r1 = chroma;
                g1 = x;
                b1 = 0;
            } else if (h < 2) {
                r1 = x;
                g1 = chroma;
                b1 = 0;
            } else if (h < 3) {
                r1 = 0;
                g1 = chroma;
                b1 = x;
            } else if (h < 4) {
                r1 = 0;
                g1 = x;
                b1 = chroma;
            } else if (h < 5) {
                r1 = x;
                g1 = 0;
                b1 = chroma;
            } else {
                r1 = chroma;
                g1 = 0;
                b1 = x;
            }

            red = (r1 + m) * 255;
            green = (g1 + m) * 255;
            blue = (b1 + m) * 255;

            image[i * width * 3 + j] = red;
            image[i * width * 3 + j + 1] = green;
            image[i * width * 3 + j + 2] = blue;
        }
    }
}

int main() {
    // Open image
    FILE *fp = fopen("image.bmp", "rb");
    if (!fp) {
        printf("Error: could not open image\n");
        return 1;
    }

    // Read header
    unsigned char header[54];
    fread(header, 1, 54, fp);
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int size = *(int *)&header[34];
    unsigned char *image = malloc(size);
    fread(image, 1, size, fp);
    fclose(fp);

    // Apply happy filter
    happyFilter(image, width, height);

    // Save new image
    fp = fopen("happy_image.bmp", "wb");
    if (!fp) {
        printf("Error: could not create image\n");
        return 1;
    }
    fwrite(header, 1, 54, fp);
    fwrite(image, 1, size, fp);
    fclose(fp);

    free(image);

    printf("Image edited happily!\n");

    return 0;
}