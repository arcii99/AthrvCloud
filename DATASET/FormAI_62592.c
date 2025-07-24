//FormAI DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 3
#define NUM_FEATURES 4
#define NUM_SAMPLES 8

void train_model(double data[][NUM_FEATURES + 1], double weights[][NUM_FEATURES], int num_iterations);
int classify(double data_point[], double weights[][NUM_FEATURES]);

int main() {
    double data[NUM_SAMPLES][NUM_FEATURES + 1] = {
        {5.1, 3.5, 1.4, 0.2, 0},
        {4.9, 3.0, 1.4, 0.2, 0},
        {4.7, 3.2, 1.3, 0.2, 0},
        {7.0, 3.2, 4.7, 1.4, 1},
        {6.4, 3.2, 4.5, 1.5, 1},
        {6.9, 3.1, 4.9, 1.5, 1},
        {6.3, 3.3, 6.0, 2.5, 2},
        {5.8, 2.7, 5.1, 1.9, 2},
    };
    
    double weights[NUM_CLASSES][NUM_FEATURES] = {0};
    int num_iterations = 100;
    
    train_model(data, weights, num_iterations);
    
    double test_point[NUM_FEATURES] = {6.0, 3.0, 4.0, 1.7};
    int predicted_class = classify(test_point, weights);
    
    printf("Predicted class: %d\n", predicted_class);
    
    return 0;
}

void train_model(double data[][NUM_FEATURES + 1], double weights[][NUM_FEATURES], int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        for (int j = 0; j < NUM_SAMPLES; j++) {
            double *datapoint = data[j];
            int true_class = (int) datapoint[NUM_FEATURES];
            
            double max_score = -9999;
            int predicted_class = -1;
            
            for (int k = 0; k < NUM_CLASSES; k++) {
                double score = 0;
                for (int l = 0; l < NUM_FEATURES; l++) {
                    score += datapoint[l] * weights[k][l];
                }
                if (score > max_score) {
                    max_score = score;
                    predicted_class = k;
                }
            }
            
            if (predicted_class != true_class) {
                for (int l = 0; l < NUM_FEATURES; l++) {
                    weights[true_class][l] += datapoint[l];
                    weights[predicted_class][l] -= datapoint[l];
                }
            }
        }
    }
}

int classify(double data_point[], double weights[][NUM_FEATURES]) {
    double max_score = -9999;
    int predicted_class = -1;
            
    for (int k = 0; k < NUM_CLASSES; k++) {
        double score = 0;
        for (int l = 0; l < NUM_FEATURES; l++) {
            score += data_point[l] * weights[k][l];
        }
        if (score > max_score) {
            max_score = score;
            predicted_class = k;
        }
    }
    
    return predicted_class;
}