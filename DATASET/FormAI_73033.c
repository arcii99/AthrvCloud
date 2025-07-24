//FormAI DATASET v1.0 Category: Image Classification system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define our image size
#define WIDTH 28
#define HEIGHT 28

// Define the number of classification classes
#define CLASSES 10

// Define the learning rate
#define LR 0.01

// Define the number of training and testing data
#define N_TRAIN 10000
#define N_TEST 1000

// Define our training and testing data structures
typedef struct Data {
    int label;
    double features[WIDTH * HEIGHT];
} Data;

// Define our weight matrix
static double w[CLASSES][WIDTH * HEIGHT];

// Helper function to get the index of a 2D array
int index(int x, int y, int width) {
    return y * width + x;
}

// Helper function to read data from a file
void read_data(const char* filename, Data* data, int n) {
    FILE* file = fopen(filename, "rb");
    for (int i = 0; i < n; i++) {
        fread(&data[i].label, sizeof(data[i].label), 1, file);
        for (int j = 0; j < WIDTH * HEIGHT; j++) {
            unsigned char pixel = 0;
            fread(&pixel, sizeof(pixel), 1, file);
            data[i].features[j] = ((double) pixel) / 255.0;
        }
    }
    fclose(file);
}

// Helper function to get the maximum value index from an array
int argmax(double* arr, int n) {
    int max_i = 0;
    double max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_i = i;
        }
    }
    return max_i;
}

// Helper function to train our model
void train(Data* data, int n) {
    for (int i = 0; i < n; i++) {
        // Compute the dot product between our weight matrix and features
        double out[CLASSES];
        for (int c = 0; c < CLASSES; c++) {
            out[c] = 0;
            for (int j = 0; j < WIDTH * HEIGHT; j++) {
                out[c] += w[c][j] * data[i].features[j];
            }
        }

        // Compute the softmax function
        double sum_exp = 0;
        for (int c = 0; c < CLASSES; c++) {
            sum_exp += exp(out[c]);
        }
        for (int c = 0; c < CLASSES; c++) {
            double softmax = exp(out[c]) / sum_exp;

            // Update the weights for the correct class
            double label_one_hot[CLASSES] = {0};
            label_one_hot[data[i].label] = 1;
            for (int j = 0; j < WIDTH * HEIGHT; j++) {
                w[c][j] -= LR * (softmax - label_one_hot[c]) * data[i].features[j];
            }
        }
    }
}

// Helper function to test our model
double test(Data* data, int n) {
    int correct = 0;
    for (int i = 0; i < n; i++) {
        // Compute the dot product between our weight matrix and features
        double out[CLASSES];
        for (int c = 0; c < CLASSES; c++) {
            out[c] = 0;
            for (int j = 0; j < WIDTH * HEIGHT; j++) {
                out[c] += w[c][j] * data[i].features[j];
            }
        }

        // Compute the predicted label
        int pred = argmax(out, CLASSES);
        if (pred == data[i].label) {
            correct++;
        }
    }
    return ((double) correct) / ((double) n);
}

int main() {
    // Read in our training and testing data
    Data train_data[N_TRAIN];
    Data test_data[N_TEST];
    read_data("train-images-idx3-ubyte", train_data, N_TRAIN);
    read_data("t10k-images-idx3-ubyte", test_data, N_TEST);

    // Train our model for 10 epochs
    for (int epoch = 0; epoch < 10; epoch++) {
        train(train_data, N_TRAIN);
        double acc = test(test_data, N_TEST);
        printf("Epoch %d: Testing Accuracy = %f\n", epoch+1, acc);
    }

    return 0;
}