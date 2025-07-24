//FormAI DATASET v1.0 Category: Image Classification system ; Style: peaceful
#include <stdio.h>

// Function to classify images based on their type
void classify_image(int image_id) {
    // Read the image data from a file
    FILE *image_file = fopen("image_data.txt", "r");
    int image_data[100]; // Assume image data can be stored in an array of size 100
    for (int i = 0; i < 100; i++) {
        fscanf(image_file, "%d", &image_data[i]);
    }
    fclose(image_file);
    
    // Analyze the image data to determine its type
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += image_data[i];
    }
    double average = sum / 100.0;
    if (average < 50) {
        printf("Image %d is a dark image.\n", image_id);
    } else if (average >= 50 && average < 100) {
        printf("Image %d is a medium-brightness image.\n", image_id);
    } else {
        printf("Image %d is a bright image.\n", image_id);
    }
}

int main() {
    // Assume we have 3 images to classify
    int image_ids[3] = {1, 2, 3};
    
    // Loop over each image and classify it
    for (int i = 0; i < 3; i++) {
        classify_image(image_ids[i]);
    }
    
    return 0;
}