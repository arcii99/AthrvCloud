//FormAI DATASET v1.0 Category: Image Classification system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define IMAGE_SIZE 28
#define NUM_CLASSES 10
#define NUM_FILTERS 16
#define FILTER_SIZE 3
#define CONV_OUTPUT_SIZE 26
#define POOLED_OUTPUT_SIZE 13
#define FC_INPUT_SIZE 676
#define HIDDEN_LAYER_SIZE 256

// Convolutional filters
float filters[NUM_FILTERS][FILTER_SIZE][FILTER_SIZE];

// Convolutional layer output
float conv_output[NUM_FILTERS][CONV_OUTPUT_SIZE][CONV_OUTPUT_SIZE];

// Pooling layer output
float pooled_output[NUM_FILTERS][POOLED_OUTPUT_SIZE][POOLED_OUTPUT_SIZE];

// Fully connected layer weights and biases
float fc_weights[FC_INPUT_SIZE][HIDDEN_LAYER_SIZE];
float fc_biases[HIDDEN_LAYER_SIZE];

// Output layer weights and biases
float output_weights[HIDDEN_LAYER_SIZE][NUM_CLASSES];
float output_biases[NUM_CLASSES];

// Image data
float image[IMAGE_SIZE][IMAGE_SIZE];

// Class probabilities
float class_probs[NUM_CLASSES];

// Load the convolutional filters from file
void load_filters() {
    FILE *fp = fopen("filters.bin", "rb");
    if(fp == NULL) {
        printf("Failed to open filters file\n");
        exit(1);
    }

    // Read in each filter
    for(int i=0; i<NUM_FILTERS; i++) {
        for(int j=0; j<FILTER_SIZE; j++) {
            for(int k=0; k<FILTER_SIZE; k++) {
                fread(&filters[i][j][k], sizeof(float), 1, fp);
            }
        }
    }

    fclose(fp);
}

// Perform a convolution operation on the image using the filters
void convolve() {
    // Loop over each filter
    for(int f=0; f<NUM_FILTERS; f++) {
        // Loop over each pixel in the output
        for(int i=0; i<CONV_OUTPUT_SIZE; i++) {
            for(int j=0; j<CONV_OUTPUT_SIZE; j++) {
                // Compute the dot product of the filter and the image patch
                float sum = 0;
                for(int x=0; x<FILTER_SIZE; x++) {
                    for(int y=0; y<FILTER_SIZE; y++) {
                        sum += image[i+x][j+y] * filters[f][x][y];
                    }
                }
                conv_output[f][i][j] = sum;
            }
        }
    }
}

// Perform max pooling on the convolved output
void pool() {
    // Loop over each filter
    for(int f=0; f<NUM_FILTERS; f++) {
        // Loop over each pixel in the pooled output
        for(int i=0; i<POOLED_OUTPUT_SIZE; i++) {
            for(int j=0; j<POOLED_OUTPUT_SIZE; j++) {
                // Find the maximum value in the pooling region
                float max = conv_output[f][2*i][2*j];
                if(conv_output[f][2*i][2*j+1] > max) max = conv_output[f][2*i][2*j+1];
                if(conv_output[f][2*i+1][2*j] > max) max = conv_output[f][2*i+1][2*j];
                if(conv_output[f][2*i+1][2*j+1] > max) max = conv_output[f][2*i+1][2*j+1];
                pooled_output[f][i][j] = max;
            }
        }
    }
}

// Flatten the pooled output into a vector for the fully connected layer
void flatten(float *fc_input) {
    for(int f=0; f<NUM_FILTERS; f++) {
        for(int i=0; i<POOLED_OUTPUT_SIZE; i++) {
            for(int j=0; j<POOLED_OUTPUT_SIZE; j++) {
                *fc_input = pooled_output[f][i][j];
                fc_input++;
            }
        }
    }
}

// Compute the output of the fully connected layer
void fc_layer(float *fc_input, float *fc_output) {
    // Compute the dot product of the input with each weight vector
    for(int i=0; i<HIDDEN_LAYER_SIZE; i++) {
        float sum = 0;
        for(int j=0; j<FC_INPUT_SIZE; j++) {
            sum += *fc_input * fc_weights[j][i];
            fc_input++;
        }
        sum += fc_biases[i];

        // Apply ReLU activation function
        if(sum < 0) sum = 0;

        *fc_output = sum;
        fc_output++;
    }
}

// Compute the output of the output layer
void output_layer(float *fc_output) {
    // Compute the dot product of the input with each weight vector
    for(int i=0; i<NUM_CLASSES; i++) {
        float sum = 0;
        for(int j=0; j<HIDDEN_LAYER_SIZE; j++) {
            sum += *fc_output * output_weights[j][i];
            fc_output++;
        }
        sum += output_biases[i];

        class_probs[i] = sum;
    }
}

// Predict the class of the image
int predict() {
    // Find the class with the highest probability
    float max_prob = 0;
    int max_class = -1;
    for(int i=0; i<NUM_CLASSES; i++) {
        if(class_probs[i] > max_prob) {
            max_prob = class_probs[i];
            max_class = i;
        }
    }
    return max_class;
}

int main() {
    // Load the convolutional filters
    load_filters();

    // Load the image data
    FILE *fp = fopen("image.bin", "rb");
    if(fp == NULL) {
        printf("Failed to open image file\n");
        return 1;
    }

    fread(&image, sizeof(float), IMAGE_SIZE*IMAGE_SIZE, fp);

    fclose(fp);

    // Perform convolution
    convolve();

    // Perform max pooling
    pool();

    // Flatten for fully connected layer
    float fc_input[FC_INPUT_SIZE];
    flatten(fc_input);

    // Compute output of fully connected layer
    float fc_output[HIDDEN_LAYER_SIZE];
    fc_layer(fc_input, fc_output);

    // Compute output of output layer
    output_layer(fc_output);

    // Predict the class of the image
    int prediction = predict();

    printf("Predicted class: %d\n", prediction);

    return 0;
}