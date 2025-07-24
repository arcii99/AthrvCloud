//FormAI DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 5
#define NUM_FEATURES 10
#define THRESHOLD 0.5

int main(void) {
    double weights[NUM_CLASSES][NUM_FEATURES]; // Model weights
    double features[NUM_FEATURES]; // Input features
    int prediction; // Predicted class
    int actual; // Actual class
    int num_predictions = 0; // Number of predictions made
    int num_correct_predictions = 0; // Number of correct predictions
    double accuracy; // Classification accuracy

    // Randomly initialize model weights
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            weights[i][j] = (double) rand() / RAND_MAX;
        }
    }

    // Read input features and actual class from file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Failed to open input file\n");
        return 1;
    }
    fscanf(input_file, "%lf", &features[0]); // Read the first feature
    for (int i = 1; i < NUM_FEATURES; i++) {
        fscanf(input_file, ",%lf", &features[i]); // Read the remaining features
    }
    fscanf(input_file, "%d", &actual); // Read the actual class
    fclose(input_file);

    // Compute scores for each class
    double scores[NUM_CLASSES] = {0};
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            scores[i] += weights[i][j] * features[j];
        }
    }

    // Make a prediction
    double max_score = -1;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            prediction = i;
        }
    }

    // Check if prediction is correct
    if (prediction == actual) {
        num_correct_predictions++;
    }
    num_predictions++;
    accuracy = (double) num_correct_predictions / num_predictions;

    // Update weights based on prediction error
    double error = actual - prediction;
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            weights[i][j] += error * features[j];
        }
    }

    // Print results
    printf("Prediction: %d, Actual: %d\n", prediction, actual);
    printf("Accuracy: %lf\n", accuracy);

    // Write new weights to file
    FILE* weights_file = fopen("weights.txt", "w");
    if (weights_file == NULL) {
        printf("Error: Failed to open weights file\n");
        return 1;
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            fprintf(weights_file, "%lf,", weights[i][j]);
        }
        fprintf(weights_file, "\n");
    }
    fclose(weights_file);

    return 0;
}