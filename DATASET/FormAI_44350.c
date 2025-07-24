//FormAI DATASET v1.0 Category: Image Classification system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Image
typedef struct {
    int width;
    int height;
} Image;

// Function to classify the Image
void classifyImage(Image img) {
    if (img.width == 640 && img.height == 480) {
        printf("The image is of type Standard Definition.\n");
    } else if (img.width == 1920 && img.height == 1080) {
        printf("The image is of type Full High Definition.\n");
    } else if (img.width == 3840 && img.height == 2160) {
        printf("The image is of type Ultra High Definition.\n");
    } else {
        printf("The image is of an unknown type.\n");
    }
}

// Main function to test the Image Classification system
int main() {
    Image img1 = {640, 480};
    Image img2 = {1920, 1080};
    Image img3 = {3840, 2160};
    Image img4 = {1000, 800};

    // Classify the Images
    classifyImage(img1);
    classifyImage(img2);
    classifyImage(img3);
    classifyImage(img4);

    return 0;
}