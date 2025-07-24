//FormAI DATASET v1.0 Category: Image Classification system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_LAYER_SIZE 128
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.01

struct neural_network {
    double input_layer[INPUT_SIZE];
    double hidden_layer[HIDDEN_LAYER_SIZE];
    double output_layer[OUTPUT_SIZE];
    double weights_ih[INPUT_SIZE][HIDDEN_LAYER_SIZE];
    double weights_ho[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];
    double bias_h[HIDDEN_LAYER_SIZE];
    double bias_o[OUTPUT_SIZE];
};

void sigmoid(double *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1 / (1 + exp(-array[i]));
    }
}

void feed_forward(struct neural_network *nn) {
    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
        double sum = 0;
        for (int i = 0; i < INPUT_SIZE; i++) {
            sum += nn->input_layer[i] * nn->weights_ih[i][h];
        }
        nn->hidden_layer[h] = sum + nn->bias_h[h];
    }
    sigmoid(nn->hidden_layer, HIDDEN_LAYER_SIZE);

    for (int o = 0; o < OUTPUT_SIZE; o++) {
        double sum = 0;
        for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
            sum += nn->hidden_layer[h] * nn->weights_ho[h][o];
        }
        nn->output_layer[o] = sum + nn->bias_o[o];
    }
    sigmoid(nn->output_layer, OUTPUT_SIZE);
}

void train(struct neural_network *nn, double *inputs, double *targets) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        nn->input_layer[i] = inputs[i];
    }

    feed_forward(nn);

    double output_deltas[OUTPUT_SIZE];
    double hidden_deltas[HIDDEN_LAYER_SIZE];

    for (int o = 0; o < OUTPUT_SIZE; o++) {
        output_deltas[o] = nn->output_layer[o] - targets[o];
    }

    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
        double error = 0;
        for (int o = 0; o < OUTPUT_SIZE; o++) {
            error += output_deltas[o] * nn->weights_ho[h][o];
        }
        hidden_deltas[h] = error * nn->hidden_layer[h] * (1 - nn->hidden_layer[h]);
    }

    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
        for (int o = 0; o < OUTPUT_SIZE; o++) {
            nn->weights_ho[h][o] -= LEARNING_RATE * output_deltas[o] * nn->hidden_layer[h];
        }
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
            nn->weights_ih[i][h] -= LEARNING_RATE * hidden_deltas[h] * nn->input_layer[i];
        }
    }

    for (int o = 0; o < OUTPUT_SIZE; o++) {
        nn->bias_o[o] -= LEARNING_RATE * output_deltas[o];
    }

    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
        nn->bias_h[h] -= LEARNING_RATE * hidden_deltas[h];
    }
}

int main() {
    struct neural_network nn;

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
            nn.weights_ih[i][h] = ((double) rand() / RAND_MAX) - 0.5;
        }
    }

    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++) {
        for (int o = 0; o < OUTPUT_SIZE; o++) {
            nn.weights_ho[h][o] = ((double) rand() / RAND_MAX) - 0.5;
        }
    }

    for (int i = 0; i < 100000; i++) {
        double inputs[INPUT_SIZE];
        double targets[OUTPUT_SIZE];
        FILE *file = fopen("input_data.txt", "r");
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(file, "%lf", &inputs[j]);
        }
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(file, "%lf", &targets[j]);
        }
        fclose(file);

        train(&nn, inputs, targets);

        if (i % 10000 == 0) {
            printf("Iteration %d\n", i);
            printf("Inputs: ");
            for (int j = 0; j < INPUT_SIZE; j++) {
                printf("%.2f ", inputs[j]);
            }
            printf("\nTargets: ");
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                printf("%.2f ", targets[j]);
            }
            printf("\nOutputs: ");
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                printf("%.2f ", nn.output_layer[j]);
            }
            printf("\n\n");
        }
    }

    return 0;
}