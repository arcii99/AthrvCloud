//FormAI DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>

#define NUM_CLASSES 5
#define IMAGE_HEIGHT 480
#define IMAGE_WIDTH 640
#define NUM_PIXELS (IMAGE_HEIGHT * IMAGE_WIDTH)

float weights[NUM_PIXELS * NUM_CLASSES];
float biases[NUM_CLASSES];

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

int argmax(float *arr, int size) {
    int idx = 0;
    float max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    // Load image data into img array
    float img[NUM_PIXELS];
    // ...

    // Compute logits
    float logits[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_PIXELS; j++) {
            sum += img[j] * weights[NUM_PIXELS * i + j];
        }
        logits[i] = sum + biases[i];
    }

    // Apply sigmoid activation function
    float predictions[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        predictions[i] = sigmoid(logits[i]);
    }

    // Make prediction
    int prediction = argmax(predictions, NUM_CLASSES);

    printf("Predicted class: %d\n", prediction);

    return 0;
}