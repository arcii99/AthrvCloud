//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INPUT_SIZE 784
#define OUTPUT_SIZE 10
#define HIDDEN_UNITS 128
#define LEARNING_RATE 0.05
#define EPOCHS 50
#define BATCH_SIZE 32

float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

int argmax(float *arr, int size) {
    int index = 0;
    float max_val = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            index = i;
        }
    }

    return index;
}

int main() {
    // Load MNIST dataset
    FILE *f = fopen("train-images.bin", "rb");
    unsigned char buf[INPUT_SIZE * 60000];
    fread(buf, 1, INPUT_SIZE * 60000, f);
    fclose(f);

    f = fopen("train-labels.bin", "rb");
    unsigned char label_buf[60000];
    fread(label_buf, 1, 60000, f);
    fclose(f);

    // Initialize weights and biases
    float hidden_weights[INPUT_SIZE][HIDDEN_UNITS];
    float output_weights[HIDDEN_UNITS][OUTPUT_SIZE];
    float hidden_bias[HIDDEN_UNITS];
    float output_bias[OUTPUT_SIZE];

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_UNITS; j++) {
            hidden_weights[i][j] = ((float) rand() / (RAND_MAX));
        }
    }

    for (int i = 0; i < HIDDEN_UNITS; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            output_weights[i][j] = ((float) rand() / (RAND_MAX));
        }
    }

    for (int i = 0; i < HIDDEN_UNITS; i++) {
        hidden_bias[i] = ((float) rand() / (RAND_MAX));
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_bias[i] = ((float) rand() / (RAND_MAX));
    }

    // Start training loop
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        printf("Epoch: %d\n", epoch);

        float loss = 0.0;
        int correct = 0;

        // Shuffle dataset
        int order[60000];
        for (int i = 0; i < 60000; i++) {
            order[i] = i;
        }

        for (int i = 0; i < 60000 - 1; i++) {
            int j = i + rand() / (RAND_MAX / (60000 - i) + 1);
            int temp = order[j];
            order[j] = order[i];
            order[i] = temp;
        }

        // Train in batches
        for (int i = 0; i < 60000; i += BATCH_SIZE) {
            // Allocate memory for inputs and targets
            float *inputs = malloc(sizeof(float) * INPUT_SIZE * BATCH_SIZE);
            float *targets = malloc(sizeof(float) * OUTPUT_SIZE * BATCH_SIZE);

            // Load batch
            for (int j = 0; j < BATCH_SIZE; j++) {
                int index = order[i + j];

                for (int k = 0; k < INPUT_SIZE; k++) {
                    inputs[j * INPUT_SIZE + k] = buf[index * INPUT_SIZE + k] / 255.0;
                }

                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    if (k == label_buf[index]) {
                        targets[j * OUTPUT_SIZE + k] = 1.0;
                    } else {
                        targets[j * OUTPUT_SIZE + k] = 0.0;
                    }
                }
            }

            // Forward propagation
            float hidden_output[BATCH_SIZE][HIDDEN_UNITS];
            float output[BATCH_SIZE][OUTPUT_SIZE];

            for (int j = 0; j < BATCH_SIZE; j++) {
                for (int k = 0; k < HIDDEN_UNITS; k++) {
                    float sum = 0.0;
                    for (int l = 0; l < INPUT_SIZE; l++) {
                        sum += inputs[j * INPUT_SIZE + l] * hidden_weights[l][k];
                    }
                    hidden_output[j][k] = sigmoid(sum + hidden_bias[k]);
                }

                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    float sum = 0.0;
                    for (int l = 0; l < HIDDEN_UNITS; l++) {
                        sum += hidden_output[j][l] * output_weights[l][k];
                    }
                    output[j][k] = sigmoid(sum + output_bias[k]);
                }
            }

            // Backward propagation
            float hidden_delta[BATCH_SIZE][HIDDEN_UNITS];
            float output_delta[BATCH_SIZE][OUTPUT_SIZE];

            for (int j = 0; j < BATCH_SIZE; j++) {
                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    output_delta[j][k] = (output[j][k] - targets[j * OUTPUT_SIZE + k]) * output[j][k] * (1 - output[j][k]);
                    loss += pow(output[j][k] - targets[j * OUTPUT_SIZE + k], 2);
                    if (argmax(output[j], OUTPUT_SIZE) == label_buf[order[i + j]]) {
                        correct += 1;
                    }
                }

                for (int k = 0; k < HIDDEN_UNITS; k++) {
                    float error = 0.0;
                    for (int l = 0; l < OUTPUT_SIZE; l++) {
                        error += output_delta[j][l] * output_weights[k][l];
                    }
                    hidden_delta[j][k] = error * hidden_output[j][k] * (1 - hidden_output[j][k]);
                }
            }

            // Update weights and biases
            for (int j = 0; j < INPUT_SIZE; j++) {
                for (int k = 0; k < HIDDEN_UNITS; k++) {
                    float grad = 0.0;
                    for (int l = 0; l < BATCH_SIZE; l++) {
                        grad += inputs[l * INPUT_SIZE + j] * hidden_delta[l][k];
                    }
                    hidden_weights[j][k] -= LEARNING_RATE * grad / BATCH_SIZE;
                }
            }

            for (int j = 0; j < HIDDEN_UNITS; j++) {
                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    float grad = 0.0;
                    for (int l = 0; l < BATCH_SIZE; l++) {
                        grad += hidden_output[l][j] * output_delta[l][k];
                    }
                    output_weights[j][k] -= LEARNING_RATE * grad / BATCH_SIZE;
                }
            }

            for (int j = 0; j < HIDDEN_UNITS; j++) {
                float grad = 0.0;
                for (int k = 0; k < BATCH_SIZE; k++) {
                    grad += hidden_delta[k][j];
                }
                hidden_bias[j] -= LEARNING_RATE * grad / BATCH_SIZE;
            }

            for (int j = 0; j < OUTPUT_SIZE; j++) {
                float grad = 0.0;
                for (int k = 0; k < BATCH_SIZE; k++) {
                    grad += output_delta[k][j];
                }
                output_bias[j] -= LEARNING_RATE * grad / BATCH_SIZE;
            }

            // Free memory
            free(inputs);
            free(targets);
        }

        loss /= 60000.0;
        float accuracy = (float) correct / 60000.0;
        printf("Loss: %f, Accuracy: %f\n", loss, accuracy);
    }

    return 0;
}