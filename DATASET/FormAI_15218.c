//FormAI DATASET v1.0 Category: Image Classification system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Neural Network constants
#define n_input 784 // 28x28 image pixels
#define n_hidden 128 // Number of nodes in hidden layer
#define n_output 10 // Number of classes to predict
#define learning_rate 0.01
#define epochs 100
#define batch_size 32
#define activation(x) (1.0 / (1.0 + exp(-x)))

// Function to load datasets
void load_dataset(float **x_train, float **y_train, float **x_test, float **y_test) {
    // Load training dataset
    FILE *fp = fopen("train_x.txt", "r");
    *x_train = (float *) malloc(60000 * n_input * sizeof(float));
    for(int i = 0; i < 60000; i++) {
        for(int j = 0; j < n_input; j++) {
            fscanf(fp, "%f", &(*x_train)[i * n_input + j]);
        }
    }
    fclose(fp);
    fp = fopen("train_y.txt", "r");
    *y_train = (float *) malloc(60000 * n_output * sizeof(float));
    for(int i = 0; i < 60000; i++) {
        int label;
        fscanf(fp, "%d", &label);
        for(int j = 0; j < n_output; j++) {
            (*y_train)[i * n_output + j] = (j == label) ? 1.0 : 0.0;
        }
    }
    fclose(fp);

    // Load test dataset
    fp = fopen("test_x.txt", "r");
    *x_test = (float *) malloc(10000 * n_input * sizeof(float));
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < n_input; j++) {
            fscanf(fp, "%f", &(*x_test)[i * n_input + j]);
        }
    }
    fclose(fp);
    fp = fopen("test_y.txt", "r");
    *y_test = (float *) malloc(10000 * n_output * sizeof(float));
    for(int i = 0; i < 10000; i++) {
        int label;
        fscanf(fp, "%d", &label);
        for(int j = 0; j < n_output; j++) {
            (*y_test)[i * n_output + j] = (j == label) ? 1.0 : 0.0;
        }
    }
    fclose(fp);
}

// Function to initialize weights
float *initialize_weights(int n_prev, int n_curr) {
    float *weights = (float *) malloc(n_prev * n_curr * sizeof(float));
    for(int i = 0; i < n_prev; i++) {
        for(int j = 0; j < n_curr; j++) {
            weights[i * n_curr + j] = ((float) rand() / (float) RAND_MAX) * 2.0 - 1.0;
        }
    }
    return weights;
}

int main() {
    // Load dataset
    float *x_train, *y_train, *x_test, *y_test;
    load_dataset(&x_train, &y_train, &x_test, &y_test);

    // Initialize weights
    float *w1 = initialize_weights(n_input, n_hidden);
    float *w2 = initialize_weights(n_hidden, n_output);

    // Train model
    for(int e = 0; e < epochs; e++) {
        float loss = 0.0;
        for(int i = 0; i < 60000; i += batch_size) {
            // Forward pass
            int end = (i + batch_size < 60000) ? i + batch_size : 60000;
            float *x_batch = &x_train[i * n_input];
            float *y_batch = &y_train[i * n_output];
            float *z1 = (float *) malloc(batch_size * n_hidden * sizeof(float));
            float *a1 = (float *) malloc(batch_size * n_hidden * sizeof(float));
            float *z2 = (float *) malloc(batch_size * n_output * sizeof(float));
            float *a2 = (float *) malloc(batch_size * n_output * sizeof(float));
            for(int j = 0; j < batch_size; j++) {
                for(int k = 0; k < n_hidden; k++) {
                    z1[j * n_hidden + k] = 0.0;
                    for(int l = 0; l < n_input; l++) {
                        z1[j * n_hidden + k] += x_batch[j * n_input + l] * w1[l * n_hidden + k];
                    }
                    a1[j * n_hidden + k] = activation(z1[j * n_hidden + k]);
                }
                for(int k = 0; k < n_output; k++) {
                    z2[j * n_output + k] = 0.0;
                    for(int l = 0; l < n_hidden; l++) {
                        z2[j * n_output + k] += a1[j * n_hidden + l] * w2[l * n_output + k];
                    }
                    a2[j * n_output + k] = activation(z2[j * n_output + k]);
                    loss += -y_batch[j * n_output + k] * log(a2[j * n_output + k]);
                }
            }
            loss /= batch_size;

            // Backward pass
            float *d2 = (float *) malloc(batch_size * n_output * sizeof(float));
            float *d1 = (float *) malloc(batch_size * n_hidden * sizeof(float));
            for(int j = 0; j < batch_size; j++) {
                for(int k = 0; k < n_output; k++) {
                    d2[j * n_output + k] = a2[j * n_output + k] - y_batch[j * n_output + k];
                }
                for(int k = 0; k < n_hidden; k++) {
                    d1[j * n_hidden + k] = 0.0;
                    for(int l = 0; l < n_output; l++) {
                        d1[j * n_hidden + k] += d2[j * n_output + l] * w2[k * n_output + l];
                    }
                    d1[j * n_hidden + k] *= a1[j * n_hidden + k] * (1.0 - a1[j * n_hidden + k]);
                }
            }

            // Update weights
            for(int j = 0; j < n_input; j++) {
                for(int k = 0; k < n_hidden; k++) {
                    float dw1 = 0.0;
                    for(int l = 0; l < batch_size; l++) {
                        dw1 += d1[l * n_hidden + k] * x_batch[l * n_input + j];
                    }
                    w1[j * n_hidden + k] -= learning_rate / batch_size * dw1;
                }
            }
            for(int j = 0; j < n_hidden; j++) {
                for(int k = 0; k < n_output; k++) {
                    float dw2 = 0.0;
                    for(int l = 0; l < batch_size; l++) {
                        dw2 += d2[l * n_output + k] * a1[l * n_hidden + j];
                    }
                    w2[j * n_output + k] -= learning_rate / batch_size * dw2;
                }
            }

            // Free memory
            free(z1);
            free(a1);
            free(z2);
            free(a2);
            free(d1);
            free(d2);
        }
        printf("Epoch %d, Loss: %f\n", e, loss);
    }

    // Test model
    int correct = 0;
    for(int i = 0; i < 10000; i++) {
        float *x = &x_test[i * n_input];
        float *y = &y_test[i * n_output];
        float *z1 = (float *) malloc(n_hidden * sizeof(float));
        float *a1 = (float *) malloc(n_hidden * sizeof(float));
        float *z2 = (float *) malloc(n_output * sizeof(float));
        float *a2 = (float *) malloc(n_output * sizeof(float));
        for(int j = 0; j < n_hidden; j++) {
            z1[j] = 0.0;
            for(int k = 0; k < n_input; k++) {
                z1[j] += x[k] * w1[k * n_hidden + j];
            }
            a1[j] = activation(z1[j]);
        }
        for(int j = 0; j < n_output; j++) {
            z2[j] = 0.0;
            for(int k = 0; k < n_hidden; k++) {
                z2[j] += a1[k] * w2[k * n_output + j];
            }
            a2[j] = activation(z2[j]);
            if(a2[j] > a2[correct]) {
                correct = j;
            }
        }
        if(y[correct] == 1.0) {
            correct++;
        }
        free(z1);
        free(a1);
        free(z2);
        free(a2);
    }
    printf("Accuracy: %f\n", (float) correct / 10000);

    // Free memory
    free(x_train);
    free(y_train);
    free(x_test);
    free(y_test);
    free(w1);
    free(w2);

    return 0;
}