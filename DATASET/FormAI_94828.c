//FormAI DATASET v1.0 Category: Image Classification system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 16
#define IMAGE_HEIGHT 16

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct Image {
    int width;
    int height;
    struct Pixel pixels[IMAGE_WIDTH * IMAGE_HEIGHT];
};

struct Classifier {
    struct Image classes[10];
};

int classify(struct Image image, struct Classifier classifier) {
    int classification = -1;
    int min_error = 9999999;
    for (int c = 0; c < 10; c++) {
        int error = 0;
        for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
            error += abs(image.pixels[i].red - classifier.classes[c].pixels[i].red) +
                     abs(image.pixels[i].green - classifier.classes[c].pixels[i].green) +
                     abs(image.pixels[i].blue - classifier.classes[c].pixels[i].blue);
        }
        if (error < min_error) {
            classification = c;
            min_error = error;
        }
    }
    return classification;
}

int main() {
    struct Classifier classifier;
    for (int c = 0; c < 10; c++) {
        char filename[100];
        sprintf(filename, "class%d.raw", c);
        FILE* file = fopen(filename, "rb");
        if (!file) {
            printf("Could not open file %s\n", filename);
            return 1;
        }
        struct Image image;
        image.width = IMAGE_WIDTH;
        image.height = IMAGE_HEIGHT;
        fread(image.pixels, sizeof(struct Pixel), IMAGE_WIDTH * IMAGE_HEIGHT, file);
        classifier.classes[c] = image;
        fclose(file);
    }
    struct Image image;
    char filename[100];
    printf("Enter filename of image to classify: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    image.width = IMAGE_WIDTH;
    image.height = IMAGE_HEIGHT;
    fread(image.pixels, sizeof(struct Pixel), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fclose(file);
    int classification = classify(image, classifier);
    printf("Image is classified as digit %d\n", classification);
    return 0;
}