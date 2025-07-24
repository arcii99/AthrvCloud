//FormAI DATASET v1.0 Category: Image Classification system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define input matrix dimensions
#define INPUT_HEIGHT 128
#define INPUT_WIDTH 128

// Define number of output classes
#define NUM_CLASSES 10

// Define number of hidden neurons
#define NUM_HIDDEN_NEURONS 100

// Define learning rate
#define LEARNING_RATE 0.001

// Define number of training epochs
#define NUM_EPOCHS 100

// Define activation function (sigmoid)
float sigmoid(float x) {
  return 1.0 / (1.0 + exp(-x));
}

// Define derivative of activation function (sigmoid)
float sigmoid_der(float x) {
  float sig = sigmoid(x);
  return sig * (1 - sig);
}

int main(void) {
  // Load input matrix and output classes from file
  float input[INPUT_HEIGHT * INPUT_WIDTH];
  int output_class;
  FILE* data_file = fopen("data.dat", "r");
  if (data_file == NULL) {
    printf("Error loading data file\n");
  }
  fread(input, sizeof(float), INPUT_HEIGHT * INPUT_WIDTH, data_file);
  fread(&output_class, sizeof(int), 1, data_file);
  fclose(data_file);

  // Initialize weights randomly, between -1 and 1
  float input_weights[INPUT_HEIGHT * INPUT_WIDTH][NUM_HIDDEN_NEURONS];
  float hidden_weights[NUM_HIDDEN_NEURONS][NUM_CLASSES];
  for (int i = 0; i < INPUT_HEIGHT * INPUT_WIDTH; i++) {
    for (int j = 0; j < NUM_HIDDEN_NEURONS; j++) {
      input_weights[i][j] = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
    }
  }
  for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
    for (int j = 0; j < NUM_CLASSES; j++) {
      hidden_weights[i][j] = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
    }
  }

  // Loop over training epochs
  for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
    // Feed forward through network
    float input_layer[NUM_HIDDEN_NEURONS]; // Hidden layer
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
      float net = 0;
      for (int j = 0; j < INPUT_HEIGHT * INPUT_WIDTH; j++) {
        net += input[j] * input_weights[j][i];
      }
      input_layer[i] = sigmoid(net);
    }
    float output_layer[NUM_CLASSES]; // Output layer
    for (int i = 0; i < NUM_CLASSES; i++) {
      float net = 0;
      for (int j = 0; j < NUM_HIDDEN_NEURONS; j++) {
        net += input_layer[j] * hidden_weights[j][i];
      }
      output_layer[i] = sigmoid(net);
    }

    // Calculate error and weight updates
    float error[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
      error[i] = output_class == i ? output_layer[i] - 1.0 : output_layer[i];
    }
    float hidden_error[NUM_HIDDEN_NEURONS];
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
      float weighted_error = 0;
      for (int j = 0; j < NUM_CLASSES; j++) {
        weighted_error += error[j] * hidden_weights[i][j];
      }
      hidden_error[i] = weighted_error * sigmoid_der(input_layer[i]);
    }
    // Update input layer weights
    for (int i = 0; i < INPUT_HEIGHT * INPUT_WIDTH; i++) {
      for (int j = 0; j < NUM_HIDDEN_NEURONS; j++) {
        input_weights[i][j] -= LEARNING_RATE * input[i] * hidden_error[j];
      }
    }
    // Update hidden layer weights
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
      for (int j = 0; j < NUM_CLASSES; j++) {
        hidden_weights[i][j] -= LEARNING_RATE * input_layer[i] * error[j];
      }
    }
  }
  
  return 0;
}