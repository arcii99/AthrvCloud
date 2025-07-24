//FormAI DATASET v1.0 Category: Image Classification system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initialize_weights(float *weights, int rows, int cols) {
    for(int i = 0; i < rows * cols; i++) {
        *(weights + i) = (float) rand() / RAND_MAX * 2 - 1;
    }
}

void softmax(float *output, float *input, int n_classes) {
    float maxVal = -INFINITY;
    for(int i = 0; i < n_classes; i++) {
        maxVal = fmax(maxVal, *(input + i));
    }

    float denominator = 0.0;
    for(int i = 0; i < n_classes; i++) {
        denominator += exp(*(input + i) - maxVal);
    }

    for(int i = 0; i < n_classes; i++) {
        *(output + i) = exp(*(input + i) - maxVal) / denominator;
    }
}

void dense(float *output, float *input, float *weights, int n_classes, int input_dim) {
    for(int i = 0; i < n_classes; i++) {
        *(output + i) = 0.0;
        for(int j = 0; j < input_dim; j++) {
            *(output + i) += *(input + j) * *(weights + j * n_classes + i);
        }
    }
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // input data
    float input[784]; // 28x28 image (flattened)
    for(int i = 0; i < 784; i++) {
        *(input + i) = (float) rand() / RAND_MAX;
    }

    // weights
    int n_layers = 2;
    int n_classes = 10;
    int layer_dims[2] = {64, n_classes};
    float *weights[n_layers];
    for(int i = 0; i < n_layers; i++) {
        int rows = i == 0 ? 784 : layer_dims[i - 1];
        int cols = layer_dims[i];
        weights[i] = (float *) malloc(rows * cols * sizeof(float));
        initialize_weights(weights[i], rows, cols);
    }

    // forward pass
    float output[n_classes];
    float *prev_output;
    for(int i = 0; i < n_layers; i++) {
        prev_output = i == 0 ? input : output;
        dense(output, prev_output, weights[i], layer_dims[i], i == 0 ? 784 : layer_dims[i - 1]);
        if(i == n_layers - 1) {
            softmax(output, output, n_classes);
        }
    }

    // print output probabilities
    printf("Output probabilities:\n");
    for(int i = 0; i < n_classes; i++) {
        printf("%.2f%%\n", *(output + i) * 100);
    }

    // free memory
    for(int i = 0; i < n_layers; i++) {
        free(weights[i]);
    }

    return 0;
}