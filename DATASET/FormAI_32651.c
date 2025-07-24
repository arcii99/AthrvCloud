//FormAI DATASET v1.0 Category: Image Classification system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 784
#define LAYER_1_SIZE 300
#define LAYER_2_SIZE 100
#define OUTPUT_SIZE 10

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

int main() {

    // input layer
    double input[INPUT_SIZE];

    // hidden layer 1
    double weights_1[INPUT_SIZE][LAYER_1_SIZE];
    double bias_1[LAYER_1_SIZE];
    double output_1[LAYER_1_SIZE];

    // hidden layer 2
    double weights_2[LAYER_1_SIZE][LAYER_2_SIZE];
    double bias_2[LAYER_2_SIZE];
    double output_2[LAYER_2_SIZE];

    // output layer
    double weights_3[LAYER_2_SIZE][OUTPUT_SIZE];
    double bias_3[OUTPUT_SIZE];
    double output_3[OUTPUT_SIZE];

    // read input
    char image_str[INPUT_SIZE + 1];
    fgets(image_str, INPUT_SIZE + 1, stdin);
    for (int i = 0; i < INPUT_SIZE; i++) {
        input[i] = (double) (image_str[i] - '0') / 255.0;
    }

    // initialize weights and biases randomly
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < LAYER_1_SIZE; j++) {
            weights_1[i][j] = (double) rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < LAYER_1_SIZE; i++) {
        bias_1[i] = (double) rand() / RAND_MAX;
    }
    for (int i = 0; i < LAYER_1_SIZE; i++) {
        for (int j = 0; j < LAYER_2_SIZE; j++) {
            weights_2[i][j] = (double) rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < LAYER_2_SIZE; i++) {
        bias_2[i] = (double) rand() / RAND_MAX;
    }
    for (int i = 0; i < LAYER_2_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            weights_3[i][j] = (double) rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        bias_3[i] = (double) rand() / RAND_MAX;
    }

    // feedforward
    for (int i = 0; i < LAYER_1_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += input[j] * weights_1[j][i];
        }
        output_1[i] = sigmoid(sum + bias_1[i]);
    }
    for (int i = 0; i < LAYER_2_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < LAYER_1_SIZE; j++) {
            sum += output_1[j] * weights_2[j][i];
        }
        output_2[i] = sigmoid(sum + bias_2[i]);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < LAYER_2_SIZE; j++) {
            sum += output_2[j] * weights_3[j][i];
        }
        output_3[i] = sigmoid(sum + bias_3[i]);
    }

    // output results
    double max_val = -1.0;
    int max_index = -1;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (output_3[i] > max_val) {
            max_val = output_3[i];
            max_index = i;
        }
    }
    printf("The input image is classified as %d\n", max_index);

    return 0;
}