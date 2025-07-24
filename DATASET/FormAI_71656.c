//FormAI DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 784
#define OUTPUT_SIZE 10
#define HIDDEN_SIZE 200
#define TRAIN_SIZE 60000
#define TEST_SIZE 10000
#define LEARNING_RATE 0.1
#define EPOCHS 20
#define BATCH_SIZE 128

// Activation Function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Derivative of Activation Function
double sigmoidDerivative(double x) {
    return x * (1 - x);
}

int main() {
    // Initialize Weights for Hidden and Output Layers
    double hiddenWeights[INPUT_SIZE][HIDDEN_SIZE], outputWeights[HIDDEN_SIZE][OUTPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            hiddenWeights[i][j] = (double)rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            outputWeights[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // Read in Training and Test Data
    FILE *trainData = fopen("trainData.txt", "r");
    FILE *trainLabels = fopen("trainLabels.txt", "r");
    FILE *testData = fopen("testData.txt", "r");
    FILE *testLabels = fopen("testLabels.txt", "r");
    double trainInputs[TRAIN_SIZE][INPUT_SIZE], testInputs[TEST_SIZE][INPUT_SIZE], trainOutputs[TRAIN_SIZE][OUTPUT_SIZE], testOutputs[TEST_SIZE][OUTPUT_SIZE];
    int trainLabelsArr[TRAIN_SIZE], testLabelsArr[TEST_SIZE];
    for (int i = 0; i < TRAIN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(trainData, "%lf", &trainInputs[i][j]);
        }
        fscanf(trainLabels, "%d", &trainLabelsArr[i]);
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            trainOutputs[i][j] = (j == trainLabelsArr[i]) ? 1 : 0;
        }
    }
    for (int i = 0; i < TEST_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(testData, "%lf", &testInputs[i][j]);
        }
        fscanf(testLabels, "%d", &testLabelsArr[i]);
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            testOutputs[i][j] = (j == testLabelsArr[i]) ? 1 : 0;
        }
    }
    
    // Train Model
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        double error = 0;
        for (int batch = 0; batch < TRAIN_SIZE / BATCH_SIZE; batch++) {
            // Forward Propagation
            double hiddenLayer[BATCH_SIZE][HIDDEN_SIZE], outputLayer[BATCH_SIZE][OUTPUT_SIZE];
            for (int i = 0; i < BATCH_SIZE; i++) {
                for (int j = 0; j < HIDDEN_SIZE; j++) {
                    double sum = 0;
                    for (int k = 0; k < INPUT_SIZE; k++) {
                        sum += trainInputs[batch*BATCH_SIZE + i][k] * hiddenWeights[k][j];
                    }
                    hiddenLayer[i][j] = sigmoid(sum);
                }
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    double sum = 0;
                    for (int k = 0; k < HIDDEN_SIZE; k++) {
                        sum += hiddenLayer[i][k] * outputWeights[k][j];
                    }
                    outputLayer[i][j] = sigmoid(sum);
                }
            }
            
            // Back Propagation
            double hiddenErrors[BATCH_SIZE][HIDDEN_SIZE], outputErrors[BATCH_SIZE][OUTPUT_SIZE];
            for (int i = 0; i < BATCH_SIZE; i++) {
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    outputErrors[i][j] = (outputLayer[i][j] - trainOutputs[batch*BATCH_SIZE + i][j]) * sigmoidDerivative(outputLayer[i][j]);
                    error += pow(outputLayer[i][j] - trainOutputs[batch*BATCH_SIZE + i][j], 2);
                }
                for (int j = 0; j < HIDDEN_SIZE; j++) {
                    double sum = 0;
                    for (int k = 0; k < OUTPUT_SIZE; k++) {
                        sum += outputErrors[i][k] * outputWeights[j][k];
                    }
                    hiddenErrors[i][j] = sum * sigmoidDerivative(hiddenLayer[i][j]);
                }
            }
            
            // Update Weights
            for (int i = 0; i < INPUT_SIZE; i++) {
                for (int j = 0; j < HIDDEN_SIZE; j++) {
                    double sum = 0;
                    for (int k = 0; k < BATCH_SIZE; k++) {
                        sum += trainInputs[batch*BATCH_SIZE + k][i] * hiddenErrors[k][j];
                    }
                    hiddenWeights[i][j] -= LEARNING_RATE * sum / BATCH_SIZE;
                }
            }
            for (int i = 0; i < HIDDEN_SIZE; i++) {
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    double sum = 0;
                    for (int k = 0; k < BATCH_SIZE; k++) {
                        sum += hiddenLayer[k][i] * outputErrors[k][j];
                    }
                    outputWeights[i][j] -= LEARNING_RATE * sum / BATCH_SIZE;
                }
            }
        }
        
        // Calculate Error and Accuracy on Test Data
        double testError = 0;
        int correct = 0;
        for (int i = 0; i < TEST_SIZE; i++) {
            double hiddenLayer[HIDDEN_SIZE], outputLayer[OUTPUT_SIZE];
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                double sum = 0;
                for (int k = 0; k < INPUT_SIZE; k++) {
                    sum += testInputs[i][k] * hiddenWeights[k][j];
                }
                hiddenLayer[j] = sigmoid(sum);
            }
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                double sum = 0;
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    sum += hiddenLayer[k] * outputWeights[k][j];
                }
                outputLayer[j] = sigmoid(sum);
                testError += pow(outputLayer[j] - testOutputs[i][j], 2);
            }
            int maxIndex = 0;
            for (int j = 1; j < OUTPUT_SIZE; j++) {
                if (outputLayer[j] > outputLayer[maxIndex]) {
                    maxIndex = j;
                }
            }
            if (maxIndex == testLabelsArr[i]) {
                correct++;
            }
        }
        printf("Epoch %d: Train Error=%.5lf, Test Error=%.5lf, Accuracy=%.2lf%%\n", epoch+1, error/TRAIN_SIZE/OUTPUT_SIZE, testError/TEST_SIZE/OUTPUT_SIZE, (double)correct/TEST_SIZE*100);
    }
    
    return 0;
}