//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CLASSES 3
#define NUM_FEATURES 10
#define NUM_SAMPLES_TRAIN 1000
#define NUM_SAMPLES_TEST 100

int main() {

    int train_data[NUM_CLASSES][NUM_SAMPLES_TRAIN][NUM_FEATURES]; // training data
    int test_data[NUM_SAMPLES_TEST][NUM_FEATURES]; // test data
    int train_labels[NUM_CLASSES][NUM_SAMPLES_TRAIN]; // training labels
    int test_labels[NUM_SAMPLES_TEST]; // test labels
    int predictions[NUM_SAMPLES_TEST]; // predicted labels
    float class_probabilities[NUM_CLASSES]; //class probabilities
    float feature_probabilities[NUM_CLASSES][NUM_FEATURES][2]; // feature probabilities

    // initialize data
    srand(time(NULL));

    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_SAMPLES_TRAIN; j++) {
            for (int k = 0; k < NUM_FEATURES; k++) {
                train_data[i][j][k] = rand() % 2;
            }
            train_labels[i][j] = i;
        }
    }

    for (int i = 0; i < NUM_SAMPLES_TEST; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            test_data[i][j] = rand() % 2;
        }
        test_labels[i] = rand() % NUM_CLASSES;
    }

    // train model
    for (int i = 0; i < NUM_CLASSES; i++) {
        int class_count = 0;
        for (int j = 0; j < NUM_SAMPLES_TRAIN; j++) {
            if (train_labels[i][j] == i) {
                class_count++;
            }
        }
        class_probabilities[i] = (float) class_count / NUM_SAMPLES_TRAIN;

        for (int j = 0; j < NUM_FEATURES; j++) {
            int feature_count_0 = 0;
            int feature_count_1 = 0;

            for (int k = 0; k < NUM_SAMPLES_TRAIN; k++) {
                if (train_labels[i][k] == i) {
                    if (train_data[i][k][j] == 0) {
                        feature_count_0++;
                    } else {
                        feature_count_1++;
                    }
                }
            }

            feature_probabilities[i][j][0] = (float) feature_count_0 / class_count;
            feature_probabilities[i][j][1] = (float) feature_count_1 / class_count;
        }
    }

    // test model
    int num_correct_predictions = 0;

    for (int i = 0; i < NUM_SAMPLES_TEST; i++) {
        float max_probability = 0;
        int predicted_label = -1;

        for (int j = 0; j < NUM_CLASSES; j++) {
            float probability = class_probabilities[j];

            for (int k = 0; k < NUM_FEATURES; k++) {
                if (test_data[i][k] == 0) {
                    probability *= feature_probabilities[j][k][0];
                } else {
                    probability *= feature_probabilities[j][k][1];
                }
            }

            if (probability > max_probability) {
                max_probability = probability;
                predicted_label = j;
            }
        }

        predictions[i] = predicted_label;

        if (predicted_label == test_labels[i]) {
            num_correct_predictions++;
        }
    }

    float accuracy = (float) num_correct_predictions / NUM_SAMPLES_TEST;

    // print results
    printf("Accuracy: %.2f\n", accuracy);

    printf("Class probabilities:\n");
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("Class %d: %.2f\n", i, class_probabilities[i]);
    }

    printf("Feature probabilities:\n");
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            printf("Class %d, feature %d: %.2f %.2f\n", i, j, feature_probabilities[i][j][0], feature_probabilities[i][j][1]);
        }
    }

    printf("Test data:\n");
    printf("True labels: ");
    for (int i = 0; i < NUM_SAMPLES_TEST; i++) {
        printf("%d ", test_labels[i]);
    }
    printf("\nPredicted labels: ");
    for (int i = 0; i < NUM_SAMPLES_TEST; i++) {
        printf("%d ", predictions[i]);
    }
    printf("\n");

    return 0;
}