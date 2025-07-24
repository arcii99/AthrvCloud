//FormAI DATASET v1.0 Category: Image Classification system ; Style: Cryptic
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

#define DATA_SIZE 784 // 28 * 28
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10
#define INPUT_SIZE HIDDEN_SIZE

// Hidden Layer Weights and Biases
float hidden_weights[HIDDEN_SIZE][DATA_SIZE];
float hidden_bias[HIDDEN_SIZE];

// Output Layer Weights and Biases
float output_weights[OUTPUT_SIZE][HIDDEN_SIZE];
float output_bias[OUTPUT_SIZE];

// Helper function to activate neuron
float activate(float x)
{
    return (1 / (1 + exp(-x)));
}

// Function to initialize weights and biases randomly
void initialize_weights()
{
    int i,j;

    // Initialize Hidden Layer Weights
    for(i = 0; i < HIDDEN_SIZE; i++)
    {
        for(j = 0; j < DATA_SIZE; j++)
        {
            hidden_weights[i][j] = ((float) rand() / (RAND_MAX)) - 0.5;
        }
    }

    // Initialize Hidden Layer Biases
    for(i = 0; i < HIDDEN_SIZE; i++)
    {
        hidden_bias[i] = ((float) rand() / (RAND_MAX)) - 0.5;
    }

    // Initialize Output Layer Weights
    for(i = 0; i < OUTPUT_SIZE; i++)
    {
        for(j = 0; j < HIDDEN_SIZE; j++)
        {
            output_weights[i][j] = ((float) rand() / (RAND_MAX)) - 0.5;
        }
    }

    // Initialize Output Layer Biases
    for(i = 0; i < OUTPUT_SIZE; i++)
    {
        output_bias[i] = ((float) rand() / (RAND_MAX)) - 0.5;
    }
}

// Function to classify image
int classify(float *image)
{
    int i,j;
    float hidden_layer[HIDDEN_SIZE];
    float output_layer[OUTPUT_SIZE];
    float temp;

    // Calculate Hidden Layer Activation Values
    for(i = 0; i < HIDDEN_SIZE; i++)
    {
        temp = 0;
        for(j = 0; j < DATA_SIZE; j++)
        {
            temp += (hidden_weights[i][j] * image[j]);
        }
        hidden_layer[i] = activate(temp + hidden_bias[i]);
    }

    // Calculate Output Layer Activation Values
    for(i = 0; i < OUTPUT_SIZE; i++)
    {
        temp = 0;
        for(j = 0; j < HIDDEN_SIZE; j++)
        {
            temp += (output_weights[i][j] * hidden_layer[j]);
        }
        output_layer[i] = activate(temp + output_bias[i]);
    }

    // Return Maximum of Output Layer Activation Values
    int max_index = 0;
    for(i = 0; i < OUTPUT_SIZE; i++)
    {
        if(output_layer[i] > output_layer[max_index])
        {
            max_index = i;
        }
    }

    return max_index;
}

// Main Function
int main()
{
    float image[DATA_SIZE];
    int i,result;

    // Initialize Weights and Biases
    initialize_weights();

    // Read Image Data from Input
    for(i = 0; i < DATA_SIZE; i++)
    {
        scanf("%f", &image[i]);
    }

    // Classify Image
    result = classify(image);

    // Print Result
    printf("Image is classified as: %d", result);

    return 0;
}