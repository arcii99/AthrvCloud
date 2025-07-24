//FormAI DATASET v1.0 Category: Image Classification system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants
#define NUM_INPUTS 784   // number of input neurons (28x28 image flattened)
#define NUM_HIDDEN 128   // number of hidden neurons
#define NUM_OUTPUTS 10   // number of output neurons

// sigmoid function to apply activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// derivative of sigmoid function for backpropagation
double sigmoid_derivative(double x) {
    return sigmoid(x) * (1.0 - sigmoid(x));
}

int main() {
    
    // Step 1: Load and preprocess data
    int i, j, k;
    double training_inputs[60000][NUM_INPUTS];
    double training_outputs[60000][NUM_OUTPUTS];
    double testing_inputs[10000][NUM_INPUTS];
    double testing_outputs[10000][NUM_OUTPUTS];
    
    // TODO: Load MNIST dataset and preprocess data
    
    // Step 2: Initialize weights and biases
    double hidden_weights[NUM_HIDDEN][NUM_INPUTS];
    double output_weights[NUM_OUTPUTS][NUM_HIDDEN];
    double hidden_biases[NUM_HIDDEN];
    double output_biases[NUM_OUTPUTS];
    
    // Initialize weights and biases with random values
    for (i = 0; i < NUM_HIDDEN; i++) {
        hidden_biases[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        for (j = 0; j < NUM_INPUTS; j++) {
            hidden_weights[i][j] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }
    for (i = 0; i < NUM_OUTPUTS; i++) {
        output_biases[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        for (j = 0; j < NUM_HIDDEN; j++) {
            output_weights[i][j] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }
    
    // Step 3: Train the model using backpropagation
    double learning_rate = 0.1;
    int num_epochs = 10;
    int batch_size = 64;
    int num_batches = 60000 / batch_size;
    
    for (i = 0; i < num_epochs; i++) {
        // shuffle training data
        // TODO: Shuffle training inputs and outputs
        
        // loop over batches
        for (j = 0; j < num_batches; j++) {
            // initialize batch gradients to zero
            double hidden_weight_gradients[NUM_HIDDEN][NUM_INPUTS];
            double output_weight_gradients[NUM_OUTPUTS][NUM_HIDDEN];
            double hidden_bias_gradients[NUM_HIDDEN] = {0};
            double output_bias_gradients[NUM_OUTPUTS] = {0};
            
            // loop over batch
            for (k = 0; k < batch_size; k++) {
                // forward pass
                double hidden_activations[NUM_HIDDEN];
                double output_activations[NUM_OUTPUTS];
                for (int h = 0; h < NUM_HIDDEN; h++) {
                    double dot_product = 0;
                    for (int n = 0; n < NUM_INPUTS; n++) {
                        dot_product += training_inputs[j * batch_size + k][n] * hidden_weights[h][n];
                    }
                    hidden_activations[h] = sigmoid(dot_product + hidden_biases[h]);
                }
                for (int o = 0; o < NUM_OUTPUTS; o++) {
                    double dot_product = 0;
                    for (int h = 0; h < NUM_HIDDEN; h++) {
                        dot_product += hidden_activations[h] * output_weights[o][h];
                    }
                    output_activations[o] = sigmoid(dot_product + output_biases[o]);
                }
                
                // backward pass
                double output_errors[NUM_OUTPUTS];
                double hidden_errors[NUM_HIDDEN];
                for (int o = 0; o < NUM_OUTPUTS; o++) {
                    output_errors[o] = (training_outputs[j * batch_size + k][o] - output_activations[o]) * sigmoid_derivative(output_activations[o]);
                    for (int h = 0; h < NUM_HIDDEN; h++) {
                        output_weight_gradients[o][h] += output_errors[o] * hidden_activations[h];
                    }
                    output_bias_gradients[o] += output_errors[o];
                }
                for (int h = 0; h < NUM_HIDDEN; h++) {
                    double sum = 0;
                    for (int o = 0; o < NUM_OUTPUTS; o++) {
                        sum += output_errors[o] * output_weights[o][h];
                    }
                    hidden_errors[h] = sum * sigmoid_derivative(hidden_activations[h]);
                    for (int n = 0; n < NUM_INPUTS; n++) {
                        hidden_weight_gradients[h][n] += hidden_errors[h] * training_inputs[j * batch_size + k][n];
                    }
                    hidden_bias_gradients[h] += hidden_errors[h];
                }
            }
            
            // update weights and biases
            for (int o = 0; o < NUM_OUTPUTS; o++) {
                for (int h = 0; h < NUM_HIDDEN; h++) {
                    output_weights[o][h] += learning_rate * output_weight_gradients[o][h] / batch_size;
                }
                output_biases[o] += learning_rate * output_bias_gradients[o] / batch_size;
            }
            for (int h = 0; h < NUM_HIDDEN; h++) {
                for (int n = 0; n < NUM_INPUTS; n++) {
                    hidden_weights[h][n] += learning_rate * hidden_weight_gradients[h][n] / batch_size;
                }
                hidden_biases[h] += learning_rate * hidden_bias_gradients[h] / batch_size;
            }
        }
    }
    
    // Step 4: Test the model on new data
    int num_correct = 0;
    for (i = 0; i < 10000; i++) {
        double hidden_activations[NUM_HIDDEN];
        double output_activations[NUM_OUTPUTS];
        for (int h = 0; h < NUM_HIDDEN; h++) {
            double dot_product = 0;
            for (int n = 0; n < NUM_INPUTS; n++) {
                dot_product += testing_inputs[i][n] * hidden_weights[h][n];
            }
            hidden_activations[h] = sigmoid(dot_product + hidden_biases[h]);
        }
        for (int o = 0; o < NUM_OUTPUTS; o++) {
            double dot_product = 0;
            for (int h = 0; h < NUM_HIDDEN; h++) {
                dot_product += hidden_activations[h] * output_weights[o][h];
            }
            output_activations[o] = sigmoid(dot_product + output_biases[o]);
        }
        int predicted_class = 0;
        for (int o = 1; o < NUM_OUTPUTS; o++) {
            if (output_activations[o] > output_activations[predicted_class]) {
                predicted_class = o;
            }
        }
        if (predicted_class == testing_outputs[i]) {
            num_correct++;
        }
    }
    
    printf("Accuracy: %d / %d = %lf\n", num_correct, 10000, (double) num_correct / 10000.0);
    
    return 0;
}