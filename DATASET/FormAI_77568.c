//FormAI DATASET v1.0 Category: Image Classification system ; Style: random
#include <stdio.h>

// Function to load image data
void load_image_data(char* filename, int* img_data) {
    FILE* fp;
    fp = fopen(filename, "rb");
    if (fp) {
        fread(img_data, sizeof(int), 784, fp);
        fclose(fp);
    }
}

// Function to normalize image data
void normalize_image_data(int* img_data) {
    for (int i = 0; i < 784; i++) {
        img_data[i] = img_data[i]/255;
    }
}

// Function to classify image
int classify_image(int* img_data) {
    float weights[784] = {0.0}; // Initialize weights with zero
    int classes[10] = {0}; // Initialize classes with zero
    int max_class = -1;
    float max_prob = -1.0;

    // Load weights from a trained model
    FILE* fp;
    fp = fopen("model.bin", "rb");
    if (fp) {
        fread(weights, sizeof(float), 784, fp);
        fclose(fp);
    }

    // Calculate probability for each class
    for (int i = 0; i < 10; i++) {
        float prob = 0.0;
        for (int j = 0; j < 784; j++) {
            prob += weights[j]*img_data[j];
        }
        classes[i] = prob;
        if (prob > max_prob) {
            max_prob = prob;
            max_class = i;
        }
    }

    return max_class;
}

int main() {
    // Load image data
    int img_data[784] = {0};
    load_image_data("test_image.bin", img_data);

    // Normalize image data
    normalize_image_data(img_data);

    // Classify image
    int class = classify_image(img_data);

    // Print result
    printf("The image belongs to class %d\n", class);

    return 0;
}