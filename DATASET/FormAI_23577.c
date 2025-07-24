//FormAI DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_SIZE 784
#define HIDDEN_SIZE 100
#define OUTPUT_SIZE 10
#define TRAIN_SIZE 60000
#define TEST_SIZE 10000
#define LEARNING_RATE 0.1
#define EPOCHS 100

// sigmoid function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// derivative of sigmoid function
double sigmoid_derivative(double x) {
    double sig = sigmoid(x);
    return sig * (1 - sig);
}

// load data from MNIST dataset
void load_data(char *images, char *labels, double **x, double **y, int size) {
    FILE *fp_images = fopen(images, "rb");
    FILE *fp_labels = fopen(labels, "rb");

    if (fp_images == NULL || fp_labels == NULL) {
        printf("Error: Failed to open file\n");
        exit(1);
    }

    // skip header information of images file
    for (int i = 0; i < 16; i++) {
        fgetc(fp_images);
    }

    // skip header information of labels file
    for (int i = 0; i < 8; i++) {
        fgetc(fp_labels);
    }

    // allocate memory for input and output data
    *x = malloc(sizeof(double) * size * IMAGE_SIZE);
    *y = malloc(sizeof(double) * size * OUTPUT_SIZE);

    for (int i = 0; i < size; i++) {
        unsigned char label = fgetc(fp_labels);
        for (int j = 0; j < IMAGE_SIZE; j++) {
            unsigned char pixel = fgetc(fp_images);

            // normalize pixel values to range [0, 1]
            (*x)[i * IMAGE_SIZE + j] = (double) pixel / 255.0;
        }

        // create one-hot encoding for output label
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            (*y)[i * OUTPUT_SIZE + j] = (label == j) ? 1.0 : 0.0;
        }
    }

    fclose(fp_images);
    fclose(fp_labels);
}

int main() {
    double *x_train, *y_train, *x_test, *y_test;
    double *w1, *w2, *b1, *b2;
    double *z1, *z2, *a1, *a2, *delta1, *delta2;
    double c_train = 0, c_test = 0;
    int correct_train = 0, correct_test = 0;

    // load training and testing data
    load_data("train-images.idx3-ubyte", "train-labels.idx1-ubyte", &x_train, &y_train, TRAIN_SIZE);
    load_data("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte", &x_test, &y_test, TEST_SIZE);

    // initialize parameters
    w1 = malloc(sizeof(double) * IMAGE_SIZE * HIDDEN_SIZE);
    w2 = malloc(sizeof(double) * HIDDEN_SIZE * OUTPUT_SIZE);
    b1 = malloc(sizeof(double) * HIDDEN_SIZE);
    b2 = malloc(sizeof(double) * OUTPUT_SIZE);
    z1 = malloc(sizeof(double) * HIDDEN_SIZE);
    z2 = malloc(sizeof(double) * OUTPUT_SIZE);
    a1 = malloc(sizeof(double) * HIDDEN_SIZE);
    a2 = malloc(sizeof(double) * OUTPUT_SIZE);
    delta1 = malloc(sizeof(double) * HIDDEN_SIZE);
    delta2 = malloc(sizeof(double) * OUTPUT_SIZE);

    for (int i = 0; i < IMAGE_SIZE * HIDDEN_SIZE; i++) {
        // initialize weights for input to hidden layer
        w1[i] = (double) rand() / RAND_MAX - 0.5;
    }

    for (int i = 0; i < HIDDEN_SIZE * OUTPUT_SIZE; i++) {
        // initialize weights for hidden to output layer
        w2[i] = (double) rand() / RAND_MAX - 0.5;
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        // initialize biases for hidden layer
        b1[i] = (double) rand() / RAND_MAX - 0.5;
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        // initialize biases for output layer
        b2[i] = (double) rand() / RAND_MAX - 0.5;
    }

    // train the neural network
    for (int e = 0; e < EPOCHS; e++) {
        c_train = 0;
        correct_train = 0;
        for (int i = 0; i < TRAIN_SIZE; i++) {
            // feedforward
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                z1[j] = 0;
                for (int k = 0; k < IMAGE_SIZE; k++) {
                    z1[j] += w1[k * HIDDEN_SIZE + j] * x_train[i * IMAGE_SIZE + k];
                }
                z1[j] += b1[j];
                a1[j] = sigmoid(z1[j]);
            }

            for (int j = 0; j < OUTPUT_SIZE; j++) {
                z2[j] = 0;
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    z2[j] += w2[k * OUTPUT_SIZE + j] * a1[k];
                }
                z2[j] += b2[j];
                a2[j] = sigmoid(z2[j]);
            }

            // compute cost
            double cost = 0;
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                cost += y_train[i * OUTPUT_SIZE + j] * log(a2[j]) + (1 - y_train[i * OUTPUT_SIZE + j]) * log(1 - a2[j]);
            }
            c_train += cost;

            // backpropagation
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                delta2[j] = a2[j] - y_train[i * OUTPUT_SIZE + j];
            }

            for (int j = 0; j < HIDDEN_SIZE; j++) {
                delta1[j] = 0;
                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    delta1[j] += w2[j * OUTPUT_SIZE + k] * delta2[k] * sigmoid_derivative(z1[j]);
                }
            }

            // update parameters
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                for (int k = 0; k < IMAGE_SIZE; k++) {
                    w1[k * HIDDEN_SIZE + j] -= LEARNING_RATE * x_train[i * IMAGE_SIZE + k] * delta1[j];
                }
                b1[j] -= LEARNING_RATE * delta1[j];
            }

            for (int j = 0; j < OUTPUT_SIZE; j++) {
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    w2[k * OUTPUT_SIZE + j] -= LEARNING_RATE * a1[k] * delta2[j];
                }
                b2[j] -= LEARNING_RATE * delta2[j];
            }

            // count number of correct predictions for training data
            int max_index = 0;
            double max_value = a2[0];
            for (int j = 1; j < OUTPUT_SIZE; j++) {
                if (a2[j] > max_value) {
                    max_index = j;
                    max_value = a2[j];
                }
            }
            if (y_train[i * OUTPUT_SIZE + max_index] == 1) {
                correct_train++;
            }
        }

        c_train /= TRAIN_SIZE;

        // test the neural network
        c_test = 0;
        correct_test = 0;
        for (int i = 0; i < TEST_SIZE; i++) {
            // feedforward
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                z1[j] = 0;
                for (int k = 0; k < IMAGE_SIZE; k++) {
                    z1[j] += w1[k * HIDDEN_SIZE + j] * x_test[i * IMAGE_SIZE + k];
                }
                z1[j] += b1[j];
                a1[j] = sigmoid(z1[j]);
            }

            for (int j = 0; j < OUTPUT_SIZE; j++) {
                z2[j] = 0;
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    z2[j] += w2[k * OUTPUT_SIZE + j] * a1[k];
                }
                z2[j] += b2[j];
                a2[j] = sigmoid(z2[j]);
            }

            // compute cost
            double cost = 0;
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                cost += y_test[i * OUTPUT_SIZE + j] * log(a2[j]) + (1 - y_test[i * OUTPUT_SIZE + j]) * log(1 - a2[j]);
            }
            c_test += cost;

            // count number of correct predictions for testing data
            int max_index = 0;
            double max_value = a2[0];
            for (int j = 1; j < OUTPUT_SIZE; j++) {
                if (a2[j] > max_value) {
                    max_index = j;
                    max_value = a2[j];
                }
            }
            if (y_test[i * OUTPUT_SIZE + max_index] == 1) {
                correct_test++;
            }
        }

        c_test /= TEST_SIZE;

        printf("Epoch %3d: Train cost = %.4f, Test cost = %.4f, Train accuracy = %.4f, Test accuracy = %.4f\n",
            e + 1, c_train, c_test, (double) correct_train / TRAIN_SIZE, (double) correct_test / TEST_SIZE);
    }

    free(x_train);
    free(y_train);
    free(x_test);
    free(y_test);
    free(w1);
    free(w2);
    free(b1);
    free(b2);
    free(z1);
    free(z2);
    free(a1);
    free(a2);
    free(delta1);
    free(delta2);

    return 0;
}