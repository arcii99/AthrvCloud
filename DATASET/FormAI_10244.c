//FormAI DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IN_SIZE 5
#define HIDDEN_SIZE 3
#define OUT_SIZE 2
#define EPOCHS 1000
#define LEARNING_RATE 0.01

// Activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

int main() {
    // Data set
    double X[IN_SIZE][3] = {{1.0, 2.0, 1.0},
                            {2.0, 1.0, 0.0},
                            {2.0, 3.0, 1.0},
                            {3.0, 2.0, 0.0},
                            {4.0, 3.0, 1.0}};

    // Labels
    double Y[OUT_SIZE][5] = {{1.0, 0.0, 1.0, 0.0, 1.0},
                             {0.0, 1.0, 0.0, 1.0, 0.0}};

    // Random weights initialization
    double W1[HIDDEN_SIZE][IN_SIZE];
    double W2[OUT_SIZE][HIDDEN_SIZE];
    for(int i=0; i<HIDDEN_SIZE; i++) {
        for(int j=0; j<IN_SIZE; j++) {
            W1[i][j] = ((double) rand() / (RAND_MAX));
        }
    }
    for(int i=0; i<OUT_SIZE; i++) {
        for(int j=0; j<HIDDEN_SIZE; j++) {
            W2[i][j] = ((double) rand() / (RAND_MAX));
        }
    }

    // Training loop
    for(int epoch=1; epoch<=EPOCHS; epoch++) {
        double error = 0.0;

        for(int t=0; t<5; t++) {
            // Forward pass
            double hidden[HIDDEN_SIZE];
            double output[OUT_SIZE];
            for(int i=0; i<HIDDEN_SIZE; i++) {
                hidden[i] = 0.0;
                for(int j=0; j<IN_SIZE; j++) {
                    hidden[i] += W1[i][j] * X[j][t];
                }
                hidden[i] = sigmoid(hidden[i]);
            }
            for(int i=0; i<OUT_SIZE; i++) {
                output[i] = 0.0;
                for(int j=0; j<HIDDEN_SIZE; j++) {
                    output[i] += W2[i][j] * hidden[j];
                }
                output[i] = sigmoid(output[i]);
            }

            // Backward pass
            double delta2[OUT_SIZE];
            for(int i=0; i<OUT_SIZE; i++) {
                delta2[i] = (Y[i][t] - output[i]) * output[i] * (1.0 - output[i]);
            }
            double delta1[HIDDEN_SIZE];
            for(int i=0; i<HIDDEN_SIZE; i++) {
                delta1[i] = 0.0;
                for(int j=0; j<OUT_SIZE; j++) {
                    delta1[i] += delta2[j] * W2[j][i] * hidden[i] * (1.0 - hidden[i]);
                }
            }

            // Update weights
            for(int i=0; i<HIDDEN_SIZE; i++) {
                for(int j=0; j<IN_SIZE; j++) {
                    W1[i][j] += LEARNING_RATE * delta1[i] * X[j][t];
                }
            }
            for(int i=0; i<OUT_SIZE; i++) {
                for(int j=0; j<HIDDEN_SIZE; j++) {
                    W2[i][j] += LEARNING_RATE * delta2[i] * hidden[j];
                }
            }

            // Calculate error
            for(int i=0; i<OUT_SIZE; i++) {
                error += pow(Y[i][t] - output[i], 2);
            }
        }

        // Print error for this epoch
        printf("Epoch %d: %.2f\n", epoch, error);
    }

    return 0;
}