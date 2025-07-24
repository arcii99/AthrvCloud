//FormAI DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784 // 28x28 image
#define NUM_HIDDEN 128 // number of neurons in hidden layer
#define NUM_OUTPUT 10 // number of output classes

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void softmax(double *x, int n) {
    double max = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > max) max = x[i];
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        x[i] = exp(x[i] - max);
        sum += x[i];
    }
    for (int i = 0; i < n; i++) {
        x[i] /= sum;
    }
}

int predict(double *input, double *w1, double *w2, double *b1, double *b2) {
    double h[NUM_HIDDEN];
    double out[NUM_OUTPUT];
    for (int i = 0; i < NUM_HIDDEN; i++) {
        double z = b1[i];
        for (int j = 0; j < INPUT_SIZE; j++) {
            z += input[j] * w1[j * NUM_HIDDEN + i];
        }
        h[i] = sigmoid(z);
    }
    for (int i = 0; i < NUM_OUTPUT; i++) {
        double z = b2[i];
        for (int j = 0; j < NUM_HIDDEN; j++) {
            z += h[j] * w2[j * NUM_OUTPUT + i];
        }
        out[i] = z;
    }
    softmax(out, NUM_OUTPUT);
    int best = 0;
    for (int i = 1; i < NUM_OUTPUT; i++) {
        if (out[i] > out[best]) {
            best = i;
        }
    }
    return best;
}

int main() {
    double w1[INPUT_SIZE * NUM_HIDDEN];
    double w2[NUM_HIDDEN * NUM_OUTPUT];
    double b1[NUM_HIDDEN];
    double b2[NUM_OUTPUT];
    // initialize weights and biases with random values
    for (int i = 0; i < INPUT_SIZE * NUM_HIDDEN; i++) {
        w1[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int i = 0; i < NUM_HIDDEN * NUM_OUTPUT; i++) {
        w2[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int i = 0; i < NUM_HIDDEN; i++) {
        b1[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int i = 0; i < NUM_OUTPUT; i++) {
        b2[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    // load input data from file
    double input[INPUT_SIZE];
    FILE *fp = fopen("input.txt", "r");
    for (int i = 0; i < INPUT_SIZE; i++) {
        fscanf(fp, "%lf", &input[i]);
    }
    fclose(fp);
    // make prediction
    int prediction = predict(input, w1, w2, b1, b2);
    printf("Prediction: %d\n", prediction);
    return 0;
}