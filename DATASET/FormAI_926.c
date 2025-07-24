//FormAI DATASET v1.0 Category: Image Classification system ; Style: modular
#include <stdio.h>

// Function to get the maximum value of pixel intensity in a given image data
int getMaxPixelValue(int *imageData, int numPixels) {
    int maxPixelValue = 0;
    for(int i = 0; i < numPixels; i++) {
        if(imageData[i] > maxPixelValue) {
            maxPixelValue = imageData[i];
        }
    }
    return maxPixelValue;
}

// Function to normalize the pixel intensity values to range of 0-255
void normalizePixelValues(int *imageData, int numPixels) {
    int maxPixelValue = getMaxPixelValue(imageData, numPixels);

    for(int i = 0; i < numPixels; i++) {
        imageData[i] = (int)( ((float)imageData[i] / (float)maxPixelValue) * 255.0 );
    }
}

// Function to classify the given image data as cat or not cat
int classifyImage(int *imageData, int numPixels) {
    // Implement your logic for image classification here
    int sumOfPixelValues = 0;
    for(int i = 0; i < numPixels; i++) {
        sumOfPixelValues += imageData[i];
    }
    int averagePixelValue = (int)( ((float)sumOfPixelValues / (float)numPixels) + 0.5 );
    if(averagePixelValue >= 128) {
        return 1; // image is classified as cat
    } else {
        return 0; // image is classified as not cat
    }
}

// Main function to load image data and classify the image
int main() {
    // Load image data from file or input stream
    int imageData[] = {50, 70, 80, 120, 130, 140, 150, 160, 170, 200, 220, 240};
    int numPixels = sizeof(imageData) / sizeof(int);

    // Normalize the pixel intensity values of the image
    normalizePixelValues(imageData, numPixels);

    // Classify the image as cat or not cat
    int result = classifyImage(imageData, numPixels);

    if(result == 1) {
        printf("Given image is classified as CAT\n");
    } else {
        printf("Given image is classified as NOT CAT\n");
    }

    return 0;
}