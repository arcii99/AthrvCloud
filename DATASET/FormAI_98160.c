//FormAI DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_LAYER 784
#define HIDDEN_LAYER 256
#define OUTPUT_LAYER 10

//sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

//feedforward function
void feedforward(double *input, double **ihWeights, double **hoWeights, double *hiddenOutput, double *finalOutput) {
    //calculate hidden layer output
    for(int i=0; i<HIDDEN_LAYER; i++){
        double sum = 0;
        for(int j=0; j<INPUT_LAYER; j++){
            sum += input[j] * ihWeights[j][i];
        }
        hiddenOutput[i] = sigmoid(sum);
    }
    //calculate output layer output
    for(int i=0; i<OUTPUT_LAYER; i++){
        double sum = 0;
        for(int j=0; j<HIDDEN_LAYER; j++){
            sum += hiddenOutput[j] * hoWeights[j][i];
        }
        finalOutput[i] = sigmoid(sum);
    }
}

//backpropagation function
void backpropagation(double *input, double *expectedOutput, double **ihWeights, double **hoWeights, double *hiddenOutput, double *finalOutput) {
    double outputError[OUTPUT_LAYER];
    double hiddenError[HIDDEN_LAYER];
    double lr = 0.1; //learning rate
    //calculate output error
    for(int i=0; i<OUTPUT_LAYER; i++){
        outputError[i] = (expectedOutput[i] - finalOutput[i]) * finalOutput[i] * (1 - finalOutput[i]); 
    }
    //update hoWeights
    for(int i=0; i<HIDDEN_LAYER; i++){
        for(int j=0; j<OUTPUT_LAYER; j++){
            hoWeights[i][j] += lr * outputError[j] * hiddenOutput[i];
        }
    }
    //calculate hidden error
    for(int i=0; i<HIDDEN_LAYER; i++){
        double sum = 0;
        for(int j=0; j<OUTPUT_LAYER; j++){
            sum += outputError[j] * hoWeights[i][j];
        }
        hiddenError[i] = sum * hiddenOutput[i] * (1 - hiddenOutput[i]);
    }
    //update ihWeights
    for(int i=0; i<INPUT_LAYER; i++){
        for(int j=0; j<HIDDEN_LAYER; j++){
            ihWeights[i][j] += lr * hiddenError[j] * input[i];
        }
    }
}

int main() {
    //create and initialize input and expected output
    double input[INPUT_LAYER];
    double expectedOutput[OUTPUT_LAYER];
    for(int i=0; i<INPUT_LAYER; i++){
        input[i] = rand()/(double)RAND_MAX;
    }
    for(int i=0; i<OUTPUT_LAYER; i++){
        expectedOutput[i] = rand()/(double)RAND_MAX;
    }
    //create and initialize weights
    double **ihWeights = (double **)malloc(INPUT_LAYER * sizeof(double *));
    for(int i=0; i<INPUT_LAYER; i++){
        ihWeights[i] = (double *)malloc(HIDDEN_LAYER * sizeof(double));
        for(int j=0; j<HIDDEN_LAYER; j++){
            ihWeights[i][j] = rand()/(double)RAND_MAX;
        }
    }
    double **hoWeights = (double **)malloc(HIDDEN_LAYER * sizeof(double *));
    for(int i=0; i<HIDDEN_LAYER; i++){
        hoWeights[i] = (double *)malloc(OUTPUT_LAYER * sizeof(double));
        for(int j=0; j<OUTPUT_LAYER; j++){
            hoWeights[i][j] = rand()/(double)RAND_MAX;
        }
    }
    //create and initialize outputs
    double hiddenOutput[HIDDEN_LAYER];
    double finalOutput[OUTPUT_LAYER];
    //run neural network
    feedforward(input, ihWeights, hoWeights, hiddenOutput, finalOutput);
    backpropagation(input, expectedOutput, ihWeights, hoWeights, hiddenOutput, finalOutput);
    //free memory
    for(int i=0; i<INPUT_LAYER; i++){
        free(ihWeights[i]);
    }
    free(ihWeights);
    for(int i=0; i<HIDDEN_LAYER; i++){
        free(hoWeights[i]);
    }
    free(hoWeights);
    return 0;
}