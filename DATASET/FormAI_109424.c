//FormAI DATASET v1.0 Category: Image Classification system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Image Classification System!\n\n");

    // Open the file containing image data
    FILE* image_file = fopen("image_data.txt", "r");
    if (image_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Determine the size of the image data array
    int num_images = 0;
    char line[256];
    while (fgets(line, sizeof(line), image_file)) {
        if (line[0] == '\n') {
            num_images++;
        }
    }
    rewind(image_file);

    // Allocate memory for the image data array
    float** image_data = (float**)malloc(num_images * sizeof(float*));
    if (image_data == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }
    for (int i = 0; i < num_images; i++) {
        image_data[i] = (float*)malloc(784 * sizeof(float));
        if (image_data[i] == NULL) {
            printf("Error allocating memory!\n");
            return 1;
        }
    }

    // Read the image data from the file
    int image_index = 0;
    while (fgets(line, sizeof(line), image_file)) {
        if (line[0] == '\n') {
            image_index++;
        } else {
            char* tok = strtok(line, ",");
            int pixel_index = 0;
            while (tok != NULL) {
                image_data[image_index][pixel_index] = atof(tok);
                pixel_index++;
                tok = strtok(NULL, ",");
            }
        }
    }
    fclose(image_file);

    // Determine the class labels for each image
    int* class_labels = (int*)malloc(num_images * sizeof(int));
    if (class_labels == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }
    for (int i = 0; i < num_images; i++) {
        class_labels[i] = i % 10;
    }

    // Train the classifier using the image data and class labels
    float** classifier = (float**)malloc(10 * sizeof(float*));
    if (classifier == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        classifier[i] = (float*)malloc(784 * sizeof(float));
        if (classifier[i] == NULL) {
            printf("Error allocating memory!\n");
            return 1;
        }
        for (int j = 0; j < 784; j++) {
            classifier[i][j] = 0.0;
            for (int k = 0; k < num_images; k++) {
                if (class_labels[k] == i) {
                    classifier[i][j] += image_data[k][j];
                }
            }
            classifier[i][j] /= num_images;
        }
    }

    // Classify a test image
    float test_image[784];
    printf("Enter the pixel values for a test image:\n");
    for (int i = 0; i < 784; i++) {
        scanf("%f", &test_image[i]);
    }
    int prediction = -1;
    float max_score = -1;
    for (int i = 0; i < 10; i++) {
        float score = 0;
        for (int j = 0; j < 784; j++) {
            score += classifier[i][j] * test_image[j];
        }
        if (score > max_score) {
            max_score = score;
            prediction = i;
        }
    }
    printf("The test image is classified as class %d.\n", prediction);

    // Free allocated memory
    for (int i = 0; i < num_images; i++) {
        free(image_data[i]);
    }
    free(image_data);
    free(class_labels);
    for (int i = 0; i < 10; i++) {
        free(classifier[i]);
    }
    free(classifier);

    return 0;
}