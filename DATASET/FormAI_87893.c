//FormAI DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 784   // 28x28 pixels
#define HIDDEN_LAYER_SIZE 16 
#define OUTPUT_SIZE 10    // 10 possible digits

// Activation function
float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of activation function
float sigmoid_prime(float x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

// Softmax function
void softmax(float *input, int length) {
    float exp_sum = 0.0;
    for (int i = 0; i < length; i++) {
        exp_sum += exp(input[i]);
    }
    for (int i = 0; i < length; i++) {
        input[i] = exp(input[i]) / exp_sum;
    }
}

// Feedforward function
void feedforward(float *input, float *weights1, float *bias1, 
                 float *weights2, float *bias2, float *output) {
    // Hidden layer
    float z1[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        z1[i] = 0.0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            z1[i] += input[j] * weights1[i*INPUT_SIZE+j];
        }
        z1[i] += bias1[i];
        output[i] = sigmoid(z1[i]);
    }

    // Output layer
    float z2[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        z2[i] = 0.0;
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            z2[i] += output[j] * weights2[i*HIDDEN_LAYER_SIZE+j];
        }
        z2[i] += bias2[i];
    }
    softmax(z2, OUTPUT_SIZE);
    memcpy(output+HIDDEN_LAYER_SIZE, z2, OUTPUT_SIZE*sizeof(float));
}

// Backpropagation function
void backpropagation(float *input, float *output, float *target, 
                     float *weights1, float *bias1, float *weights2, 
                     float *bias2, float *d_weights1, float *d_bias1, 
                     float *d_weights2, float *d_bias2) {
    float y[OUTPUT_SIZE];
    memcpy(y, output+HIDDEN_LAYER_SIZE, OUTPUT_SIZE*sizeof(float));

    // Calculate dE/dz2
    float delta2[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        delta2[i] = y[i] - target[i];
    }

    // Calculate dE/dz1
    float delta1[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        delta1[i] = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            delta1[i] += delta2[j] * weights2[j*HIDDEN_LAYER_SIZE+i];
        }
        delta1[i] *= sigmoid_prime(output[i]);
    }

    // Calculate dE/dw2 and dE/db2
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            d_weights2[i*HIDDEN_LAYER_SIZE+j] += delta2[i] * output[j];
        }
        d_bias2[i] += delta2[i];
    }

    // Calculate dE/dw1 and dE/db1
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            d_weights1[i*INPUT_SIZE+j] += delta1[i] * input[j];
        }
        d_bias1[i] += delta1[i];
    }
}

// Update weights and biases
void update(float *weights1, float *bias1, float *d_weights1, float *d_bias1,
            float *weights2, float *bias2, float *d_weights2, float *d_bias2,
            float learning_rate) {
    // Update weights and biases for hidden layer
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            weights1[i*INPUT_SIZE+j] -= learning_rate * d_weights1[i*INPUT_SIZE+j];
        }
        bias1[i] -= learning_rate * d_bias1[i];
    }

    // Update weights and biases for output layer
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            weights2[i*HIDDEN_LAYER_SIZE+j] -= learning_rate * d_weights2[i*HIDDEN_LAYER_SIZE+j];
        }
        bias2[i] -= learning_rate * d_bias2[i];
    }
}

int main() {
    // Load MNIST dataset
    FILE *fp = fopen("train-images-idx3-ubyte", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int magic_number, n_images, rows, cols;
    fread(&magic_number, 4, 1, fp);
    fread(&n_images, 4, 1, fp);
    fread(&rows, 4, 1, fp);
    fread(&cols, 4, 1, fp);
    unsigned char image[INPUT_SIZE];
    float input[INPUT_SIZE];
    
    // Initialize weights and biases
    float weights1[HIDDEN_LAYER_SIZE*INPUT_SIZE];
    float bias1[HIDDEN_LAYER_SIZE];
    float weights2[OUTPUT_SIZE*HIDDEN_LAYER_SIZE];
    float bias2[OUTPUT_SIZE];
    float output[HIDDEN_LAYER_SIZE+OUTPUT_SIZE];
    float target[OUTPUT_SIZE];
    float d_weights1[HIDDEN_LAYER_SIZE*INPUT_SIZE];
    float d_bias1[HIDDEN_LAYER_SIZE];
    float d_weights2[OUTPUT_SIZE*HIDDEN_LAYER_SIZE];
    float d_bias2[OUTPUT_SIZE];

    // Randomly initialize weights and biases
    for (int i = 0; i < HIDDEN_LAYER_SIZE*INPUT_SIZE; i++) {
        weights1[i] = ((float) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        bias1[i] = ((float) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int i = 0; i < OUTPUT_SIZE*HIDDEN_LAYER_SIZE; i++) {
        weights2[i] = ((float) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        bias2[i] = ((float) rand() / RAND_MAX) * 2.0 - 1.0;
    }

    int n_epochs = 10;
    float learning_rate = 0.1;
    for (int epoch = 0; epoch < n_epochs; epoch++) {
        printf("Training epoch %d...\n", epoch+1);
        for (int i = 0; i < HIDDEN_LAYER_SIZE*INPUT_SIZE; i++) {
            d_weights1[i] = 0.0;
        }
        for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
            d_bias1[i] = 0.0;
        }
        for (int i = 0; i < OUTPUT_SIZE*HIDDEN_LAYER_SIZE; i++) {
            d_weights2[i] = 0.0;
        }
        for (int i = 0; i < OUTPUT_SIZE; i++) {
            d_bias2[i] = 0.0;
        }

        for (int idx = 0; idx < n_images; idx++) {
            fread(&image, sizeof(char), INPUT_SIZE, fp);
            for (int i = 0; i < INPUT_SIZE; i++) {
                input[i] = (float) image[i] / 255.0;
            }
            feedforward(input, weights1, bias1, weights2, bias2, output);
        
            // One-hot encode target
            int label;
            fread(&label, sizeof(char), 1, fp);
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                if (i == label) {
                    target[i] = 1.0;
                } else {
                    target[i] = 0.0;
                }
            }

            backpropagation(input, output, target, weights1, bias1, weights2, 
                             bias2, d_weights1, d_bias1, d_weights2, d_bias2);
        }
        update(weights1, bias1, d_weights1, d_bias1, weights2, bias2, d_weights2, 
               d_bias2, learning_rate);
        printf("Training complete\n");
        rewind(fp);
    }
    fclose(fp);
    return 0;
}