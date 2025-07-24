//FormAI DATASET v1.0 Category: Image Classification system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784     // 28*28
#define OUTPUT_SIZE 10     // 0-9 digits

#define ALPHA 0.1          // learning rate
#define BIAS 1             // bias term

#define NUM_HIDDEN_LAYERS 2
#define HIDDEN_LAYER_SIZE 500

typedef struct {
    double weights[HIDDEN_LAYER_SIZE][INPUT_SIZE];
    double bias[HIDDEN_LAYER_SIZE];
} HiddenLayer;

typedef struct {
    double weights[OUTPUT_SIZE][HIDDEN_LAYER_SIZE];
    double bias[OUTPUT_SIZE];
} OutputLayer;

typedef struct {
    double input[INPUT_SIZE];
    double hidden[NUM_HIDDEN_LAYERS][HIDDEN_LAYER_SIZE];
    double output[OUTPUT_SIZE];
} NeuralNet;

void init(HiddenLayer *hidden_layer, OutputLayer *output_layer) {
    // initialize the weights and biases to random values between 0.0 and 1.0
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_layer->weights[i][j] = ((double) rand() / RAND_MAX);
        }
        hidden_layer->bias[i] = ((double) rand() / RAND_MAX);
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            output_layer->weights[j][i] = ((double) rand() / RAND_MAX);
        }
        output_layer->bias[i] = ((double) rand() / RAND_MAX);
    }
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

void feedforward(NeuralNet *nn, HiddenLayer *hidden_layer, OutputLayer *output_layer) {
    // calculate the hidden layer values
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += nn->input[j] * hidden_layer->weights[i][j];
        }
        sum += BIAS * hidden_layer->bias[i];
        nn->hidden[0][i] = sigmoid(sum);
    }
    for (int layer = 1; layer < NUM_HIDDEN_LAYERS; layer++) {
        for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
            double sum = 0;
            for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                sum += nn->hidden[layer - 1][j] * hidden_layer->weights[i][j];
            }
            sum += BIAS * hidden_layer->bias[i];
            nn->hidden[layer][i] = sigmoid(sum);
        }
    }
    // calculate the output layer values
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            sum += nn->hidden[NUM_HIDDEN_LAYERS - 1][j] * output_layer->weights[i][j];
        }
        sum += BIAS * output_layer->bias[i];
        nn->output[i] = sigmoid(sum);
    }
}

double cost_function(double *expected_output, double *output) {
    double cost = 0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        cost += pow(expected_output[i] - output[i], 2);
    }
    return cost / 2;
}

void backpropagation(NeuralNet *nn, HiddenLayer *hidden_layer, OutputLayer *output_layer, double *expected_output) {
    // calculate the error in the output layer
    double output_error[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_error[i] = (expected_output[i] - nn->output[i]) * nn->output[i] * (1 - nn->output[i]);
    }
    // calculate the error in the hidden layers
    double hidden_error[NUM_HIDDEN_LAYERS][HIDDEN_LAYER_SIZE];
    for (int layer = NUM_HIDDEN_LAYERS - 1; layer >= 0; layer--) {
        for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
            double sum = 0;
            if (layer == NUM_HIDDEN_LAYERS - 1) {
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    sum += output_error[j] * output_layer->weights[j][i];
                }
            } else {
                for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                    sum += hidden_error[layer + 1][j] * hidden_layer->weights[j][i];
                }
            }
            hidden_error[layer][i] = nn->hidden[layer][i] * (1 - nn->hidden[layer][i]) * sum;
        }
    }
    // update the weights and biases in the output layer
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            output_layer->weights[i][j] += ALPHA * output_error[i] * nn->hidden[NUM_HIDDEN_LAYERS - 1][j];
        }
        output_layer->bias[i] += ALPHA * output_error[i];
    }
    // update the weights and biases in the hidden layers
    for (int layer = 0; layer < NUM_HIDDEN_LAYERS; layer++) {
        for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
            for (int j = 0; j < (layer == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE); j++) {
                double input = layer == 0 ? nn->input[j] : nn->hidden[layer - 1][j];
                hidden_layer->weights[i][j] += ALPHA * hidden_error[layer][i] * input;
            }
            hidden_layer->bias[i] += ALPHA * hidden_error[layer][i];
        }
    }
}

void train(NeuralNet *nn, HiddenLayer *hidden_layer, OutputLayer *output_layer, int num_epochs, double **inputs, double **expected_outputs, int num_inputs) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        double total_cost = 0;
        for (int i = 0; i < num_inputs; i++) {
            for (int j = 0; j < INPUT_SIZE; j++) {
                nn->input[j] = inputs[i][j];
            }
            feedforward(nn, hidden_layer, output_layer);
            total_cost += cost_function(expected_outputs[i], nn->output);
            backpropagation(nn, hidden_layer, output_layer, expected_outputs[i]);
        }
        printf("Epoch %d: total cost = %lf\n", epoch + 1, total_cost);
    }
}

void test(NeuralNet *nn, HiddenLayer *hidden_layer, OutputLayer *output_layer, double **inputs, double **expected_outputs, int num_inputs) {
    int num_correct = 0;
    for (int i = 0; i < num_inputs; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            nn->input[j] = inputs[i][j];
        }
        feedforward(nn, hidden_layer, output_layer);
        int predicted_digit = 0;
        for (int j = 1; j < OUTPUT_SIZE; j++) {
            if (nn->output[j] > nn->output[predicted_digit]) {
                predicted_digit = j;
            }
        }
        int actual_digit = 0;
        for (int j = 1; j < OUTPUT_SIZE; j++) {
            if (expected_outputs[i][j] > expected_outputs[i][actual_digit]) {
                actual_digit = j;
            }
        }
        if (predicted_digit == actual_digit) {
            num_correct++;
        }
    }
    printf("Accuracy: %d/%d\n", num_correct, num_inputs);
}

int main() {
    srand(42); // seed random number generator
    
    // initialize neural net and layers
    NeuralNet nn;
    HiddenLayer hidden_layer;
    OutputLayer output_layer;
    init(&hidden_layer, &output_layer);
    
    // load training data
    double **inputs = malloc(60000 * sizeof(double *));
    for (int i = 0; i < 60000; i++) {
        inputs[i] = malloc(INPUT_SIZE * sizeof(double));
    }
    double **expected_outputs = malloc(60000 * sizeof(double *));
    for (int i = 0; i < 60000; i++) {
        expected_outputs[i] = malloc(OUTPUT_SIZE * sizeof(double));
    }
    FILE *f = fopen("mnist_train.csv", "r");
    char line[10000];
    int i = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        char *ptr = line;
        for (int j = 0; j < INPUT_SIZE; j++) {
            inputs[i][j] = strtod(ptr, &ptr) / 255;
        }
        int expected_output = strtol(ptr, NULL, 10);
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            expected_outputs[i][j] = 0;
        }
        expected_outputs[i][expected_output] = 1;
        i++;
    }
    fclose(f);
    
    // load test data
    double **test_inputs = malloc(10000 * sizeof(double *));
    for (int i = 0; i < 10000; i++) {
        test_inputs[i] = malloc(INPUT_SIZE * sizeof(double));
    }
    double **test_expected_outputs = malloc(10000 * sizeof(double *));
    for (int i = 0; i < 10000; i++) {
        test_expected_outputs[i] = malloc(OUTPUT_SIZE * sizeof(double));
    }
    f = fopen("mnist_test.csv", "r");
    i = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        char *ptr = line;
        for (int j = 0; j < INPUT_SIZE; j++) {
            test_inputs[i][j] = strtod(ptr, &ptr) / 255;
        }
        int expected_output = strtol(ptr, NULL, 10);
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            test_expected_outputs[i][j] = 0;
        }
        test_expected_outputs[i][expected_output] = 1;
        i++;
    }
    fclose(f);
    
    // train and test the neural net
    train(&nn, &hidden_layer, &output_layer, 10, inputs, expected_outputs, 60000);
    test(&nn, &hidden_layer, &output_layer, test_inputs, test_expected_outputs, 10000);
    
    // clean up memory
    for (int i = 0; i < 60000; i++) {
        free(inputs[i]);
        free(expected_outputs[i]);
    }
    free(inputs);
    free(expected_outputs);
    for (int i = 0; i < 10000; i++) {
        free(test_inputs[i]);
        free(test_expected_outputs[i]);
    }
    free(test_inputs);
    free(test_expected_outputs);
    
    return 0;
}