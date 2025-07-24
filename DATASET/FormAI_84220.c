//FormAI DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_SIZE 100

const double threshold = 0.5;

void sigmoid(double *x) {
    *x = 1 / (1 + exp(-(*x)));
}

int classify_image(double data[MAX_DATA_SIZE], double *weights) {
    double dot_product = 0.0;
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        dot_product += data[i] * weights[i];
    }

    sigmoid(&dot_product);

    if (dot_product >= threshold) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    double training_data_1[] = {0.2, 0.3, 0.5, 0.7, 0.3, 0.6, 0.2, 0.4, 0.8, 0.1, 0.3, 0.5, 0.7, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.7, 0.2, 0.4, 0.6};
    double training_data_2[] = {0.1, 0.4, 0.6, 0.7, 0.2, 0.5, 0.3, 0.6, 0.2, 0.3, 0.5, 0.7, 0.9, 0.2, 0.3, 0.5, 0.7, 0.8, 0.3, 0.5, 0.2, 0.4, 0.6, 0.9, 0.1, 0.3, 0.5, 0.6, 0.8, 0.2, 0.4};
    double training_data_3[] = {0.1, 0.3, 0.6, 0.7, 0.3, 0.5, 0.2, 0.4, 0.8, 0.1, 0.3, 0.5, 0.7, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.7, 0.2, 0.4, 0.6};
    double training_data_4[] = {0.2, 0.4, 0.6, 0.7, 0.3, 0.5, 0.2, 0.4, 0.9, 0.1, 0.4, 0.5, 0.7, 0.2, 0.4, 0.6, 0.8, 0.2, 0.4, 0.6, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.7, 0.3, 0.5, 0.6};
    double training_data_5[] = {0.1, 0.3, 0.5, 0.6, 0.3, 0.4, 0.2, 0.4, 0.7, 0.1, 0.3, 0.5, 0.7, 0.2, 0.4, 0.6, 0.8, 0.2, 0.4, 0.6, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.7, 0.3, 0.5, 0.6};

    double weights[MAX_DATA_SIZE];
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        weights[i] = drand48(); // randomly initialize weights
    }

    int num_iterations = 50000;
    double learning_rate = 0.1;

    for (int i = 0; i < num_iterations; i++) {
        double total_error = 0.0;

        // Train on training_data_1
        int target_output = 1;
        int output = classify_image(training_data_1, weights);
        double error = target_output - output;
        total_error += pow(error, 2);

        for (int j = 0; j < MAX_DATA_SIZE; j++) {
            weights[j] += learning_rate * error * training_data_1[j];
        }

        // Train on training_data_2
        target_output = 1;
        output = classify_image(training_data_2, weights);
        error = target_output - output;
        total_error += pow(error, 2);

        for (int j = 0; j < MAX_DATA_SIZE; j++) {
            weights[j] += learning_rate * error * training_data_2[j];
        }

        // Train on training_data_3
        target_output = 1;
        output = classify_image(training_data_3, weights);
        error = target_output - output;
        total_error += pow(error, 2);

        for (int j = 0; j < MAX_DATA_SIZE; j++) {
            weights[j] += learning_rate * error * training_data_3[j];
        }

        // Train on training_data_4
        target_output = 0;
        output = classify_image(training_data_4, weights);
        error = target_output - output;
        total_error += pow(error, 2);

        for (int j = 0; j < MAX_DATA_SIZE; j++) {
            weights[j] += learning_rate * error * training_data_4[j];
        }

        // Train on training_data_5
        target_output = 0;
        output = classify_image(training_data_5, weights);
        error = target_output - output;
        total_error += pow(error, 2);

        for (int j = 0; j < MAX_DATA_SIZE; j++) {
            weights[j] += learning_rate * error * training_data_5[j];
        }

        if (i % 1000 == 0) {
            printf("Iteration %d, Total error: %f\n", i, total_error);
        }
    }

    // Test the classifier on some new data
    double test_data[] = {0.1, 0.2, 0.3, 0.7, 0.2, 0.5, 0.3, 0.6, 0.9, 0.1, 0.2, 0.4, 0.6, 0.2, 0.4, 0.7, 0.9, 0.1, 0.3, 0.5, 0.2, 0.4, 0.6, 0.8, 0.1, 0.3, 0.5, 0.7, 0.2, 0.4, 0.6};
    int output = classify_image(test_data, weights);

    if (output == 1) {
        printf("The image is classified as a cat.\n");
    } else {
        printf("The image is classified as not a cat.\n");
    }

    return 0;
}