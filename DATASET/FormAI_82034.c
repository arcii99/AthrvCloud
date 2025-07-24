//FormAI DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>

// Define the sizes of the input and output matrices
#define ROW_SIZE 4
#define COLUMN_SIZE 4
#define OUTPUT_SIZE 2

// Initialize the input and output matrices
float input[ROW_SIZE][COLUMN_SIZE] = { { 1.1, 2.3, 3.5, 4.7 }, { 5.2, 6.4, 7.6, 8.9 }, { 9.2, 10.3, 11.4, 12.5 }, { 13.6, 14.7, 15.8, 16.9 } };
float output[OUTPUT_SIZE];

// Define the weight matrix and bias variable
float weight[COLUMN_SIZE][OUTPUT_SIZE] = { { 0.2, 0.4 }, { 0.3, 0.5 }, { 0.1, 0.6 }, { 0.7, 0.9 } };
float bias[OUTPUT_SIZE] = { 0.1, 0.2 };

// Define the activation function
float sigmoid(float x)
{
    return 1.0 / (1 + exp(-x));
}

int main()
{
    // Perform matrix multiplication and summation of the biases
    for (int i = 0; i < OUTPUT_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            output[i] += input[i][j] * weight[j][i];
        }
        output[i] += bias[i];
    }

    // Apply the activation function to the output values
    for (int i = 0; i < OUTPUT_SIZE; i++)
    {
        output[i] = sigmoid(output[i]);
    }

    // Print the output values
    printf("The output values are: ");
    for (int i = 0; i < OUTPUT_SIZE; i++)
    {
        printf("%f ", output[i]);
    }

    return 0;
}