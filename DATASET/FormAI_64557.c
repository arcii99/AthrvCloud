//FormAI DATASET v1.0 Category: Image Classification system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to initialize weights
void initialize_weights(float weights[][3], int num_classes) {
    for(int i=0; i<num_classes; i++) {
        for(int j=0; j<3; j++) {
            weights[i][j] = (float)rand()/(float)(RAND_MAX/2) - 1; // random weight initialization between -1 and 1
        }
    }
}

// Function to calculate dot product of two vectors
float dot_product(float x[], float y[], int len) {
    float result = 0.0;
    for(int i=0; i<len; i++) {
        result += x[i] * y[i];
    }
    return result;
}

// Function to predict class based on input
int predict_class(float weights[][3], float input[], int num_classes) {
    int predicted_class = 0;
    float max_dot = -999999; // initializing max dot product to a very low value
    for(int i=0; i<num_classes; i++) {
        float dot = dot_product(weights[i], input, 3);
        if(dot > max_dot) {
            predicted_class = i;
            max_dot = dot;
        }
    }
    return predicted_class;
}

// Main function
int main() {
    // Initialize weights
    int num_classes = 3;
    float weights[num_classes][3];
    initialize_weights(weights, num_classes);

    // Fake input images
    float input_1[] = {0.5, 0.2, 0.8};
    float input_2[] = {0.9, 0.1, 0.7};
    float input_3[] = {0.3, 0.8, 0.6};

    // Predict classes for inputs
    int predicted_class_1 = predict_class(weights, input_1, num_classes);
    int predicted_class_2 = predict_class(weights, input_2, num_classes);
    int predicted_class_3 = predict_class(weights, input_3, num_classes);

    // Print predictions
    printf("Predicted class for input 1: %d\n", predicted_class_1);
    printf("Predicted class for input 2: %d\n", predicted_class_2);
    printf("Predicted class for input 3: %d\n", predicted_class_3);

    return 0;
}