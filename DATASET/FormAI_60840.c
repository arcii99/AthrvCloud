//FormAI DATASET v1.0 Category: Image Classification system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the image
#define WIDTH 10
#define HEIGHT 10

// Define the number of samples to use for training
#define TRAINING_SAMPLES 100

// Define the number of classes 
#define CLASSES 3

// Define the learning rate
#define LEARNING_RATE 0.01

// Define the number of epochs
#define EPOCHS 100

// Declare the image structure
typedef struct {
    int pixels[WIDTH * HEIGHT];
    int label;
} Image;

// Declare the network structure
typedef struct {
    double weights[WIDTH * HEIGHT][CLASSES];
    double biases[CLASSES];
} Network;

// Declare the functions
void train(Network *network, Image *trainingData, int numTrainingSamples);
void initialiseNetwork(Network *network);
double sigmoid(double x);
double calculateOutput(Network *network, Image *image);
void backpropagate(Network *network, Image *image, double error);
void printImage(Image *image);
void printNetwork(Network *network);

int main() {
    // Define the training data
    Image trainingData[TRAINING_SAMPLES] = {
        {{1,1,1,1,1,1,1,1,1,1,
          1,0,0,0,0,0,0,0,0,1,
          1,0,0,0,0,0,0,0,0,1,
          1,0,0,0,0,0,0,0,0,1,
          1,0,0,0,0,1,1,1,1,1,
          1,0,0,0,0,0,0,0,0,1,
          1,0,0,0,0,0,0,0,0,1,
          1,0,0,0,0,0,0,0,0,1,
          1,0,0,0,0,0,0,0,0,1,
          1,1,1,1,1,1,1,1,1,1}, 1},
        
        {{1,0,0,0,0,0,0,0,0,1,
          0,1,0,0,0,0,0,0,1,0,
          0,0,1,0,0,0,0,1,0,0,
          0,0,0,1,0,0,1,0,0,0,
          0,0,0,0,1,1,0,0,0,0,
          0,0,0,0,1,1,0,0,0,0,
          0,0,0,1,0,0,1,0,0,0,
          0,0,1,0,0,0,0,1,0,0,
          0,1,0,0,0,0,0,0,1,0,
          1,0,0,0,0,0,0,0,0,1}, 2},
          
        {{0,1,1,1,1,1,1,1,1,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,
          0,1,1,1,1,1,1,1,1,0}, 3}
    };
    
    // Initialise the network
    Network network;
    initialiseNetwork(&network);
    
    // Train the network
    train(&network, trainingData, TRAINING_SAMPLES);
    
    // Print the network
    printNetwork(&network);
    
    return 0;
}

// Train the network
void train(Network *network, Image *trainingData, int numTrainingSamples) {
    int i, j, k, epoch;
    double output, error, delta;
    
    // Loop through each epoch
    for (epoch = 0; epoch < EPOCHS; epoch++) {
        
        // Loop through each training sample
        for (i = 0; i < numTrainingSamples; i++) {
            
            // Calculate the output for the current image
            output = calculateOutput(network, &trainingData[i]);
            
            // Calculate the error
            error = trainingData[i].label - output;
            
            // Backpropagate the error
            backpropagate(network, &trainingData[i], error);
        }
    }
}

// Initialise the network
void initialiseNetwork(Network *network) {
    int i, j;
    double range = 1.0 / sqrt(WIDTH * HEIGHT);
    
    // Initialise the weights
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        for (j = 0; j < CLASSES; j++) {
            network->weights[i][j] = (((double) rand() / RAND_MAX) * 2 * range) - range;
        }
    }
    
    // Initialise the biases
    for (i = 0; i < CLASSES; i++) {
        network->biases[i] = 0.0;
    }
}

// Calculate the output for a given image
double calculateOutput(Network *network, Image *image) {
    int i, j;
    double output = 0.0;
    
    // Loop through each pixel in the image
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        
        // Multiply the pixel value by the weight and add to the output
        for (j = 0; j < CLASSES; j++) {
            output += ((double) image->pixels[i] / 255.0) * network->weights[i][j] + network->biases[j];
        }
    }
    
    // Apply the sigmoid function to the output
    output = sigmoid(output);
    
    return output;
}

// Backpropagate the error for a given image
void backpropagate(Network *network, Image *image, double error) {
    int i, j;
    double derivative, delta;
    
    // Loop through each pixel in the image
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        
        // Loop through each class
        for (j = 0; j < CLASSES; j++) {
            
            // Calculate the derivative of the sigmoid function
            derivative = sigmoid(network->weights[i][j] * ((double) image->pixels[i] / 255.0) + network->biases[j]) * (1 - sigmoid(network->weights[i][j] * ((double) image->pixels[i] / 255.0) + network->biases[j]));
            
            // Calculate the delta
            delta = error * derivative * ((double) image->pixels[i] / 255.0) * LEARNING_RATE;
            
            // Update the weight
            network->weights[i][j] += delta;
        }
    }
}

// Print an image
void printImage(Image *image) {
    int i, j;
    
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", image->pixels[i * WIDTH + j]);
        }
        printf("\n");
    }
    
    printf("Label: %d\n", image->label);
}

// Print a network
void printNetwork(Network *network) {
    int i, j;
    
    printf("Weights:\n");
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        for (j = 0; j < CLASSES; j++) {
            printf("%f ", network->weights[i][j]);
        }
        printf("\n");
    }
    
    printf("Biases:\n");
    for (i = 0; i < CLASSES; i++) {
        printf("%f ", network->biases[i]);
    }
    printf("\n");
}

// The sigmoid function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}