//FormAI DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 3
#define OUTPUT_SIZE 2
#define HIDDEN_LAYER_SIZE 4

float inputs[INPUT_SIZE];
float hiddenLayer[HIDDEN_LAYER_SIZE];
float outputs[OUTPUT_SIZE];

float weightsInputToHidden[INPUT_SIZE][HIDDEN_LAYER_SIZE];
float weightsHiddenToOutput[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];

float biasHidden[HIDDEN_LAYER_SIZE];
float biasOutput[OUTPUT_SIZE];
float learningRate = 0.5;

void initializeWeights()
{
    for (int i = 0; i < INPUT_SIZE; i++)
    {
        for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
        {
            weightsInputToHidden[i][h] = ((float)rand() / (float)RAND_MAX) * 2 - 1;
        }
    }

    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
    {
        for (int o = 0; o < OUTPUT_SIZE; o++)
        {
            weightsHiddenToOutput[h][o] = ((float)rand() / (float)RAND_MAX) * 2 - 1;
        }
    }

    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++)
    {
        biasHidden[i] = ((float)rand() / (float)RAND_MAX) * 2 - 1;
    }

    for (int i = 0; i < OUTPUT_SIZE; i++)
    {
        biasOutput[i] = ((float)rand() / (float)RAND_MAX) * 2 - 1;
    }
}

float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

void feedForward()
{
    // Calculate values of hidden layer
    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
    {
        float sum = 0;
        for (int i = 0; i < INPUT_SIZE; i++)
        {
            sum += inputs[i] * weightsInputToHidden[i][h];
        }
        sum += biasHidden[h];

        hiddenLayer[h] = sigmoid(sum);
    }

    // Calculate values of output layer
    for (int o = 0; o < OUTPUT_SIZE; o++)
    {
        float sum = 0;
        for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
        {
            sum += hiddenLayer[h] * weightsHiddenToOutput[h][o];
        }
        sum += biasOutput[o];

        outputs[o] = sigmoid(sum);
    }
}

void backPropagation()
{
    // Calculate error on output layer
    float errorOutput[OUTPUT_SIZE];
    for (int o = 0; o < OUTPUT_SIZE; o++)
    {
        errorOutput[o] = (outputs[o] - (float)o) * outputs[o] * (1 - outputs[o]);
    }

    // Calculate error on hidden layer
    float errorHidden[HIDDEN_LAYER_SIZE];
    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
    {
        float sum = 0;
        for (int o = 0; o < OUTPUT_SIZE; o++)
        {
            sum += errorOutput[o] * weightsHiddenToOutput[h][o];
        }
        errorHidden[h] = sum * hiddenLayer[h] * (1 - hiddenLayer[h]);
    }

    // Update weights and biases on output layer
    for (int o = 0; o < OUTPUT_SIZE; o++)
    {
        for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
        {
            weightsHiddenToOutput[h][o] -= learningRate * errorOutput[o] * hiddenLayer[h];
        }
        biasOutput[o] -= learningRate * errorOutput[o];
    }

    // Update weights and biases on hidden layer
    for (int h = 0; h < HIDDEN_LAYER_SIZE; h++)
    {
        for (int i = 0; i < INPUT_SIZE; i++)
        {
            weightsInputToHidden[i][h] -= learningRate * errorHidden[h] * inputs[i];
        }
        biasHidden[h] -= learningRate * errorHidden[h];
    }
}

int main()
{
    srand(0);
    initializeWeights();

    // Train the network to classify images
    for (int epoch = 0; epoch < 1000; epoch++)
    {
        int label = rand() % OUTPUT_SIZE;
        for (int i = 0; i < INPUT_SIZE; i++)
        {
            inputs[i] = ((float)rand() / (float)RAND_MAX) * 2 - 1;
        }
        inputs[label] += 10;

        feedForward();
        backPropagation();
    }

    // Test the network on some images
    int correct = 0;
    for (int i = 0; i < 100; i++)
    {
        int label = rand() % OUTPUT_SIZE;
        for (int i = 0; i < INPUT_SIZE; i++)
        {
            inputs[i] = ((float)rand() / (float)RAND_MAX) * 2 - 1;
        }
        inputs[label] += 10;

        feedForward();

        int prediction = 0;
        if (outputs[1] > outputs[0])
        {
            prediction = 1;
        }
        if (prediction == label)
        {
            correct++;
        }
    }

    printf("Accuracy: %d%%\n", (int)((float)correct / 100 * 100));
    return 0;
}