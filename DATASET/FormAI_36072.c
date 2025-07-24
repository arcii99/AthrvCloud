//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_EXAMPLES 1000
#define INPUT_SIZE 784
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.05
#define NUM_EPOCHS 200

double activation_function(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double activation_function_derivative(double x) {
    double fx = activation_function(x);
    return fx * (1.0 - fx);
}

int main() {
    double input[NUM_EXAMPLES][INPUT_SIZE];
    double output[NUM_EXAMPLES][OUTPUT_SIZE];
    double weight_hidden[INPUT_SIZE][OUTPUT_SIZE];
    double weight_output[OUTPUT_SIZE][OUTPUT_SIZE];
    double bias_hidden[OUTPUT_SIZE];
    double bias_output[OUTPUT_SIZE];
    
    // initialize weights and biases
    srand(0);
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            weight_hidden[i][j] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
        }
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            weight_output[i][j] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
        }
        bias_hidden[i] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
        bias_output[i] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
    }
    
    // load training data
    FILE* input_file = fopen("inputs.txt", "r");
    FILE* output_file = fopen("outputs.txt", "r");
    for (int i = 0; i < NUM_EXAMPLES; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(input_file, "%lf", &input[i][j]);
        }
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(output_file, "%lf", &output[i][j]);
        }
    }
    fclose(input_file);
    fclose(output_file);
    
    // train model
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        double loss = 0.0;
        for (int example = 0; example < NUM_EXAMPLES; example++) {
            // forward pass
            double hidden_layer[OUTPUT_SIZE];
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                double weighted_sum = 0.0;
                for (int j = 0; j < INPUT_SIZE; j++) {
                    weighted_sum += input[example][j] * weight_hidden[j][i];
                }
                weighted_sum += bias_hidden[i];
                hidden_layer[i] = activation_function(weighted_sum);
            }
            double output_layer[OUTPUT_SIZE];
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                double weighted_sum = 0.0;
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    weighted_sum += hidden_layer[j] * weight_output[j][i];
                }
                weighted_sum += bias_output[i];
                output_layer[i] = activation_function(weighted_sum);
            }
            
            // calculate loss
            double example_loss = 0.0;
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                example_loss += pow(output_layer[i] - output[example][i], 2);
            }
            loss += example_loss;
            
            // backward pass
            double delta_output[OUTPUT_SIZE];
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                double error_derivative = output_layer[i] - output[example][i];
                delta_output[i] = error_derivative * activation_function_derivative(output_layer[i]);
            }
            double delta_hidden[OUTPUT_SIZE];
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                double weighted_sum = 0.0;
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    weighted_sum += delta_output[j] * weight_output[i][j];
                }
                delta_hidden[i] = weighted_sum * activation_function_derivative(hidden_layer[i]);
            }
            
            // update weights and biases
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                for (int j = 0; j < INPUT_SIZE; j++) {
                    weight_hidden[j][i] -= LEARNING_RATE * delta_hidden[i] * input[example][j];
                }
            }
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    weight_output[j][i] -= LEARNING_RATE * delta_output[i] * hidden_layer[j];
                }
                bias_output[i] -= LEARNING_RATE * delta_output[i];
            }
            for (int i = 0; i < OUTPUT_SIZE; i++) {
                bias_hidden[i] -= LEARNING_RATE * delta_hidden[i];
            }
        }
        loss /= NUM_EXAMPLES;
        printf("Epoch %d, loss = %.6f\n", epoch, loss);
    }
    
    // test model
    input_file = fopen("test_inputs.txt", "r");
    output_file = fopen("test_outputs.txt", "r");
    int num_correct = 0;
    for (int i = 0; i < NUM_EXAMPLES; i++) {
        double input_vector[INPUT_SIZE];
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(input_file, "%lf", &input_vector[j]);
        }
        double expected_output[OUTPUT_SIZE];
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(output_file, "%lf", &expected_output[j]);
        }
        
        double hidden_layer[OUTPUT_SIZE];
        for (int i = 0; i < OUTPUT_SIZE; i++) {
            double weighted_sum = 0.0;
            for (int j = 0; j < INPUT_SIZE; j++) {
                weighted_sum += input_vector[j] * weight_hidden[j][i];
            }
            weighted_sum += bias_hidden[i];
            hidden_layer[i] = activation_function(weighted_sum);
        }
        double output_layer[OUTPUT_SIZE];
        for (int i = 0; i < OUTPUT_SIZE; i++) {
            double weighted_sum = 0.0;
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                weighted_sum += hidden_layer[j] * weight_output[j][i];
            }
            weighted_sum += bias_output[i];
            output_layer[i] = activation_function(weighted_sum);
        }
        
        int predicted_label = -1;
        double max_probability = -1.0;
        for (int i = 0; i < OUTPUT_SIZE; i++) {
            if (output_layer[i] > max_probability) {
                predicted_label = i;
                max_probability = output_layer[i];
            }
        }
        int actual_label = -1;
        for (int i = 0; i < OUTPUT_SIZE; i++) {
            if (expected_output[i] == 1.0) {
                actual_label = i;
                break;
            }
        }
        if (predicted_label == actual_label) {
            num_correct++;
        }
    }
    fclose(input_file);
    fclose(output_file);
    double accuracy = (double)num_correct / (double)NUM_EXAMPLES;
    printf("Test accuracy = %.6f\n", accuracy);
    
    return 0;
}