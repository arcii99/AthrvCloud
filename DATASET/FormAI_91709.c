//FormAI DATASET v1.0 Category: Image Classification system ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

#define NUM_CLASSES 10
#define IMG_SIZE 784
#define HIDDEN_SIZE 128

// Initialize weights randomly
void initializeWeights(float* inputHidden, float* hiddenOutput) {
    for(int i = 0; i < IMG_SIZE * HIDDEN_SIZE; i++) {
        inputHidden[i] = (float)rand()/RAND_MAX;
    }

    for(int i = 0; i < HIDDEN_SIZE * NUM_CLASSES; i++) {
        hiddenOutput[i] = (float)rand()/RAND_MAX;
    }
}

// Compute the dot product of two matrices
void dotProduct(float* mat1, float* mat2, float* result, int m1_rows, int m1_cols, int m2_cols) {
    for(int i = 0; i < m1_rows; i++) {
        for(int j = 0; j < m2_cols; j++) {
            float sum = 0;
            for(int k = 0; k < m1_cols; k++) {
                sum += mat1[i * m1_cols + k] * mat2[k * m2_cols + j];
            }
            result[i * m2_cols + j] = sum;
        }
    }
}

// Compute the sigmoid activation function
void sigmoid(float* input, int size) {
    for(int i = 0; i < size; i++) {
        input[i] = 1/(1 + exp(-input[i]));
    }
}

// Train the model
void trainModel(float* inputHidden, float* hiddenOutput, float* input, float* target) {
    float hiddenLayer[HIDDEN_SIZE];
    dotProduct(input, inputHidden, hiddenLayer, 1, IMG_SIZE, HIDDEN_SIZE);
    sigmoid(hiddenLayer, HIDDEN_SIZE);

    float outputLayer[NUM_CLASSES];
    dotProduct(hiddenLayer, hiddenOutput, outputLayer, 1, HIDDEN_SIZE, NUM_CLASSES);
    sigmoid(outputLayer, NUM_CLASSES);

    // Compute the error
    float error[NUM_CLASSES];
    for(int i = 0; i < NUM_CLASSES; i++) {
        error[i] = (target[i] - outputLayer[i]) * outputLayer[i] * (1 - outputLayer[i]);
    }

    // Update the hidden to output weights
    float deltaHO[HIDDEN_SIZE][NUM_CLASSES];
    for(int i = 0; i < HIDDEN_SIZE; i++) {
        for(int j = 0; j < NUM_CLASSES; j++) {
            deltaHO[i][j] = 0.1 * error[j] * hiddenLayer[i]; 
            hiddenOutput[i * NUM_CLASSES + j] += deltaHO[i][j];
        }
    }

    // Compute the hidden layer error
    float hiddenError[HIDDEN_SIZE];
    dotProduct(error, hiddenOutput, hiddenError, 1, NUM_CLASSES, HIDDEN_SIZE);
    for(int i = 0; i < HIDDEN_SIZE; i++) {
        hiddenError[i] *= hiddenLayer[i] * (1 - hiddenLayer[i]);
    }

    // Update the input to hidden weights
    float deltaIH[IMG_SIZE][HIDDEN_SIZE];
    for(int i = 0; i < IMG_SIZE; i++) {
        for(int j = 0; j < HIDDEN_SIZE; j++) {
            deltaIH[i][j] = 0.1 * hiddenError[j] * input[i];
            inputHidden[i * HIDDEN_SIZE + j] += deltaIH[i][j];
        }
    }
}

// Test the model
int testModel(float* inputHidden, float* hiddenOutput, float* input, float* target) {
    float hiddenLayer[HIDDEN_SIZE];
    dotProduct(input, inputHidden, hiddenLayer, 1, IMG_SIZE, HIDDEN_SIZE);
    sigmoid(hiddenLayer, HIDDEN_SIZE);

    float outputLayer[NUM_CLASSES];
    dotProduct(hiddenLayer, hiddenOutput, outputLayer, 1, HIDDEN_SIZE, NUM_CLASSES);
    sigmoid(outputLayer, NUM_CLASSES);

    float maxOutput = 0;
    int maxIndex = -1;
    for(int i = 0; i < NUM_CLASSES; i++) {
        if(outputLayer[i] > maxOutput) {
            maxOutput = outputLayer[i];
            maxIndex = i;
        }
    }

    int targetIndex = -1;
    for(int i = 0; i < NUM_CLASSES; i++) {
        if(target[i] == 1) {
            targetIndex = i;
            break;
        }
    }

    if(maxIndex == targetIndex) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Load the training data
    float trainingInput[1000][IMG_SIZE];
    float trainingTarget[1000][NUM_CLASSES];
    // ...

    // Load the testing data
    float testingInput[100][IMG_SIZE];
    float testingTarget[100][NUM_CLASSES];
    // ...

    // Initialize the weights
    float inputHidden[IMG_SIZE * HIDDEN_SIZE];
    float hiddenOutput[HIDDEN_SIZE * NUM_CLASSES];
    initializeWeights(inputHidden, hiddenOutput);

    // Train the model
    for(int epoch = 0; epoch < 100; epoch++) {
        for(int i = 0; i < 1000; i++) {
            trainModel(inputHidden, hiddenOutput, trainingInput[i], trainingTarget[i]);
        }
    }

    // Test the model
    int numCorrect = 0;
    for(int i = 0; i < 100; i++) {
        numCorrect += testModel(inputHidden, hiddenOutput, testingInput[i], testingTarget[i]);
    }
    printf("Accuracy: %f\n", (float)numCorrect/100);

    // Free memory
    free(inputHidden);
    free(hiddenOutput);

    return 0;
}