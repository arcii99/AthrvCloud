//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 784
#define NUM_HIDDEN 512
#define NUM_CLASSES 10
#define LEARNING_RATE 0.001

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

void softmax(float* x, int n) {
    float sum = 0;
    int i;

    for (i = 0; i < n; ++i) {
        sum += exp(x[i]);
    }

    for (i = 0; i < n; ++i) {
        x[i] = exp(x[i]) / sum;
    }
}

int main() {
    /* Initialize neural network */
    float input[INPUT_SIZE];
    float hidden[NUM_HIDDEN];
    float output[NUM_CLASSES];
    float weights_ih[INPUT_SIZE * NUM_HIDDEN];
    float weights_ho[NUM_HIDDEN * NUM_CLASSES];
    int i, j, k;

    /* Randomly initialize weights */
    for (i = 0; i < INPUT_SIZE * NUM_HIDDEN; ++i) {
        weights_ih[i] = ((float) rand() / RAND_MAX) - 0.5;
    }

    for (i = 0; i < NUM_HIDDEN * NUM_CLASSES; ++i) {
        weights_ho[i] = ((float) rand() / RAND_MAX) - 0.5;
    }

    /* Load input */
    FILE* fp = fopen("input.txt", "r");
    for (i = 0; i < INPUT_SIZE; ++i) {
        fscanf(fp, "%f", &input[i]);
    }
    fclose(fp);

    /* Forward pass */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        hidden[i] = 0;
        for (j = 0; j < INPUT_SIZE; ++j) {
            hidden[i] += input[j] * weights_ih[i * INPUT_SIZE + j];
        }
        hidden[i] = sigmoid(hidden[i]);
    }

    for (i = 0; i < NUM_CLASSES; ++i) {
        output[i] = 0;
        for (j = 0; j < NUM_HIDDEN; ++j) {
            output[i] += hidden[j] * weights_ho[j * NUM_CLASSES + i];
        }
    }
    softmax(output, NUM_CLASSES);

    /* Backward pass */
    int label = 7;
    float target[NUM_CLASSES];
    for (i = 0; i < NUM_CLASSES; ++i) {
        if (i == label) {
            target[i] = 1.0;
        } else {
            target[i] = 0.0;
        }
    }

    float d_output[NUM_CLASSES];
    for (i = 0; i < NUM_CLASSES; ++i) {
        d_output[i] = output[i] - target[i];
    }

    float d_hidden[NUM_HIDDEN];
    for (i = 0; i < NUM_HIDDEN; ++i) {
        d_hidden[i] = 0;
        for (j = 0; j < NUM_CLASSES; ++j) {
            d_hidden[i] += d_output[j] * weights_ho[i * NUM_CLASSES + j];
        }
        d_hidden[i] *= hidden[i] * (1 - hidden[i]);
    }

    for (i = 0; i < NUM_HIDDEN; ++i) {
        for (j = 0; j < NUM_CLASSES; ++j) {
            weights_ho[i * NUM_CLASSES + j] -= LEARNING_RATE * d_output[j] * hidden[i];
        }
    }

    for (i = 0; i < INPUT_SIZE; ++i) {
        for (j = 0; j < NUM_HIDDEN; ++j) {
            weights_ih[i * NUM_HIDDEN + j] -= LEARNING_RATE * d_hidden[j] * input[i];
        }
    }

    return 0;
}