//FormAI DATASET v1.0 Category: Image Classification system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the number of classes
#define NUM_CLASSES 3

// define the number of features
#define NUM_FEATURES 5

// define the maximum number of samples
#define MAX_SAMPLES 100

// define the learning rate
#define ALPHA 0.1

// define the maximum number of iterations
#define MAX_ITERATIONS 1000

// define the error threshold
#define ERROR_THRESHOLD 0.01

// define the sigmoid function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// define the derivative of the sigmoid function
double sigmoid_derivative(double x) {
    return sigmoid(x) * (1.0 - sigmoid(x));
}

int main() {
    // initialize the training data
    double training_data[MAX_SAMPLES][NUM_FEATURES+1] = {
        {0.5, 1.0, 0.0, 0.0, 0.0, 1.0},
        {0.7, 0.0, 1.0, 0.0, 0.0, 2.0},
        {0.2, 0.0, 0.0, 1.0, 0.0, 3.0},
        {0.3, 0.0, 0.0, 0.0, 1.0, 1.0},
        {0.4, 1.0, 0.0, 0.0, 0.0, 1.0},
        {0.8, 0.0, 1.0, 0.0, 0.0, 2.0},
        {0.1, 0.0, 0.0, 1.0, 0.0, 3.0},
        {0.6, 0.0, 0.0, 0.0, 1.0, 1.0},
        {0.9, 0.0, 1.0, 0.0, 0.0, 2.0},
        {0.2, 0.0, 0.0, 1.0, 0.0, 3.0},
        {0.4, 1.0, 0.0, 0.0, 0.0, 1.0},
        {0.7, 0.0, 1.0, 0.0, 0.0, 2.0},
        {0.3, 0.0, 0.0, 1.0, 0.0, 3.0},
        {0.5, 0.0, 0.0, 0.0, 1.0, 1.0},
        {0.8, 0.0, 1.0, 0.0, 0.0, 2.0},
        {0.1, 0.0, 0.0, 1.0, 0.0, 3.0},
        {0.6, 0.0, 0.0, 0.0, 1.0, 1.0},
        {0.9, 0.0, 1.0, 0.0, 0.0, 2.0},
        {0.2, 0.0, 0.0, 1.0, 0.0, 3.0},
        {0.4, 1.0, 0.0, 0.0, 0.0, 1.0}
    };
    
    // randomly initialize the weights
    double weights[NUM_FEATURES][NUM_CLASSES];
    for (int i = 0; i < NUM_FEATURES; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            weights[i][j] = ((double)rand() / (double)RAND_MAX);
        }
    }
    
    // train the model
    double error = 0.0;
    int iteration = 0;
    do {
        error = 0.0;
        for (int k = 0; k < MAX_SAMPLES; k++) {
            // prepare the input vector
            double input[NUM_FEATURES];
            for (int i = 0; i < NUM_FEATURES; i++) {
                input[i] = training_data[k][i];
            }
            
            // prepare the desired output vector
            double desired_output[NUM_CLASSES];
            for (int i = 0; i < NUM_CLASSES; i++) {
                desired_output[i] = 0.0;
            }
            int class_index = (int)training_data[k][NUM_FEATURES];
            desired_output[class_index] = 1.0;
            
            // calculate the actual output
            double actual_output[NUM_CLASSES];
            for (int i = 0; i < NUM_CLASSES; i++) {
                double sum = 0.0;
                for (int j = 0; j < NUM_FEATURES; j++) {
                    sum += input[j] * weights[j][i];
                }
                actual_output[i] = sigmoid(sum);
            }
            
            // calculate the error
            double sample_error = 0.0;
            for (int i = 0; i < NUM_CLASSES; i++) {
                sample_error += pow((desired_output[i] - actual_output[i]), 2);
            }
            error += sample_error;
            
            // update the weights
            for (int i = 0; i < NUM_FEATURES; i++) {
                for (int j = 0; j < NUM_CLASSES; j++) {
                    double delta = ALPHA * (desired_output[j] - actual_output[j]) * sigmoid_derivative(actual_output[j]) * input[i];
                    weights[i][j] += delta;
                }
            }
        }
        
        // print the error
        printf("Iteration %d, Error %f\n", iteration, error);
        iteration++;
    } while (iteration < MAX_ITERATIONS && error > ERROR_THRESHOLD);
    
    // classify a new sample
    double sample[NUM_FEATURES] = {0.6, 0.0, 0.0, 0.0, 1.0};
    double classification[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        double sum = 0.0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            sum += sample[j] * weights[j][i];
        }
        classification[i] = sigmoid(sum);
        printf("Class %d: %f\n", i, classification[i]);
    }
    
    return 0;
}