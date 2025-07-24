//FormAI DATASET v1.0 Category: Image Classification system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 32
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.1
#define EPOCHS 1000

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

void forward(double *input, double *hidden, double *output, double ih_weights[HIDDEN_SIZE][INPUT_SIZE], double ho_weights[OUTPUT_SIZE][HIDDEN_SIZE]) {
    // calculate hidden layer values
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden[i] = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden[i] += input[j] * ih_weights[i][j];
        }
        hidden[i] = sigmoid(hidden[i]);
    }

    // calculate output layer values
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output[i] += hidden[j] * ho_weights[i][j];
        }
        output[i] = sigmoid(output[i]);
    }
}

void train(double *input, int target, double ih_weights[HIDDEN_SIZE][INPUT_SIZE], double ho_weights[OUTPUT_SIZE][HIDDEN_SIZE]) {
    double hidden[HIDDEN_SIZE], output[OUTPUT_SIZE];
    forward(input, hidden, output, ih_weights, ho_weights);

    // calculate error for output layer
    double output_error[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (i == target) {
            output_error[i] = output[i] - 1;
        } else {
            output_error[i] = output[i];
        }
    }

    // calculate error for hidden layer
    double hidden_error[HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden_error[i] = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            hidden_error[i] += ho_weights[j][i] * output_error[j];
        }
        hidden_error[i] *= hidden[i] * (1 - hidden[i]);
    }

    // update weights
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            ih_weights[i][j] -= LEARNING_RATE * hidden_error[i] * input[j];
        }
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            ho_weights[i][j] -= LEARNING_RATE * output_error[i] * hidden[j];
        }
    }
}

int predict(double *input, double ih_weights[HIDDEN_SIZE][INPUT_SIZE], double ho_weights[OUTPUT_SIZE][HIDDEN_SIZE]) {
    double hidden[HIDDEN_SIZE], output[OUTPUT_SIZE];
    forward(input, hidden, output, ih_weights, ho_weights);

    int max_index = -1;
    double max_val = -1;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (output[i] > max_val) {
            max_val = output[i];
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    // initialize weights
    double ih_weights[HIDDEN_SIZE][INPUT_SIZE];
    double ho_weights[OUTPUT_SIZE][HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            ih_weights[i][j] = (double)rand() / RAND_MAX * 2 - 1;
        }
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            ho_weights[i][j] = (double)rand() / RAND_MAX * 2 - 1;
        }
    }

    // load data
    FILE *fp = fopen("data.csv", "r");
    if (!fp) {
        printf("Failed to open data file\n");
        return 1;
    }

    double *data[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        data[i] = (double*)malloc(INPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(fp, "%lf,", &data[i][j]);
        }
        int target;
        fscanf(fp, "%d\n", &target);
        for (int j = 0; j < EPOCHS; j++) {
            train(data[i], target, ih_weights, ho_weights);
        }
    }

    // predict test data
    FILE *fp_test = fopen("test.csv", "r");
    if (!fp_test) {
        printf("Failed to open test file\n");
        return 1;
    }

    double test[INPUT_SIZE];
    int correct_count = 0, total_count = 0;
    while (!feof(fp_test)) {
        for (int i = 0; i < INPUT_SIZE; i++) {
            fscanf(fp_test, "%lf,", &test[i]);
        }
        int label;
        fscanf(fp_test, "%d\n", &label);

        int pred = predict(test, ih_weights, ho_weights);
        if (pred == label) {
            correct_count++;
        }
        total_count++;
    }

    printf("Accuracy: %f\n", (double)correct_count / total_count * 100);

    // free memory
    fclose(fp);
    fclose(fp_test);
    for (int i = 0; i < INPUT_SIZE; i++) {
        free(data[i]);
    }

    return 0;
}