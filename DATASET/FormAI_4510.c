//FormAI DATASET v1.0 Category: Image Classification system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the happy image classification program!\n\n");
    
    // create an array of image file paths
    char imagePaths[5][20] = {"image1.jpg", "image2.png", "image3.bmp", "image4.tif", "image5.gif"};
    
    for (int i = 0; i < 5; i++) {
        printf("Processing image: %s...\n", imagePaths[i]);
        
        // simulate image classification
        int classification = rand() % 4; // generate a random number between 0 and 3
        char* label;
        switch (classification) {
            case 0:
                label = "cat";
                break;
            case 1:
                label = "dog";
                break;
            case 2:
                label = "bird";
                break;
            case 3:
                label = "fish";
                break;
            default:
                label = "unknown";
                break;
        }
        printf("%s classified as: %s\n\n", imagePaths[i], label);
    }
    
    printf("All images have been classified. Thank you for using our program!\n");
    return 0;
}