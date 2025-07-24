//FormAI DATASET v1.0 Category: Image Classification system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 3
#define NUM_FEATURES 5
#define NUM_DATA_POINTS 10
#define NUM_TEST_POINTS 2

struct Image {
    float feature_vector[NUM_FEATURES];
    int label;
};

struct Image images[NUM_DATA_POINTS] = {
    {{1.2, 2.5, 0.3, 1.9, 0.8}, 0},
    {{0.8, 1.6, 0.5, 2.2, 0.7}, 0},
    {{3.2, 1.4, 0.2, 0.5, 1.1}, 1},
    {{1.7, 0.7, 2.1, 1.2, 1.8}, 1},
    {{2.8, 3.2, 0.7, 1.5, 1.0}, 0},
    {{1.8, 1.2, 1.1, 2.9, 2.4}, 1},
    {{0.9, 3.1, 0.6, 1.0, 1.6}, 0},
    {{2.3, 2.9, 1.3, 0.5, 0.9}, 1},
    {{0.5, 2.1, 1.9, 0.8, 2.5}, 2},
    {{0.7, 1.1, 3.2, 2.1, 1.4}, 2}
};

struct Image test_images[NUM_TEST_POINTS] = {
    {{2.0, 2.8, 0.4, 1.4, 1.2}},
    {{0.6, 1.5, 2.8, 1.0, 2.0}}
};

float dot_product(float* a, float* b, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int argmax(float* arr, int n) {
    int max_index = 0;
    float max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_index = i;
            max_val = arr[i];
        }
    }
    return max_index;
}

int predict(struct Image img, float weights[NUM_CLASSES][NUM_FEATURES]) {
    float scores[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        scores[i] = dot_product(weights[i], img.feature_vector, NUM_FEATURES);
    }
    return argmax(scores, NUM_CLASSES);
}

void train(float weights[NUM_CLASSES][NUM_FEATURES], float learning_rate, int num_iterations) {
    for (int iteration = 0; iteration < num_iterations; iteration++) {
        for (int i = 0; i < NUM_DATA_POINTS; i++) {
            struct Image img = images[i];
            float* class_weights = weights[img.label];
            float score = dot_product(img.feature_vector, class_weights, NUM_FEATURES);
            for (int j = 0; j < NUM_FEATURES; j++) {
                class_weights[j] += learning_rate * img.feature_vector[j] * (1 - (score - class_weights[j]));
            }
        }
    }
}

int main() {
    float weights[NUM_CLASSES][NUM_FEATURES] = {
        {0.2, 0.3, 0.1, 0.5, 0.4},
        {0.3, 0.2, 0.4, 0.3, 0.5},
        {0.1, 0.4, 0.2, 0.2, 0.1}
    };
    float learning_rate = 0.1;
    int num_iterations = 100;
    train(weights, learning_rate, num_iterations);

    for (int i = 0; i < NUM_TEST_POINTS; i++) {
        struct Image img = test_images[i];
        int predicted_label = predict(img, weights);
        printf("Predicted label for test image %d: %d\n", i+1, predicted_label);
    }

    return 0;
}