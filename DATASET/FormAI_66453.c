//FormAI DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_CLASSES 5
#define NUM_OF_FEATURES 10
#define TRAIN_SET_SIZE 1000
#define TEST_SET_SIZE 100

double train_set[TRAIN_SET_SIZE][NUM_OF_FEATURES+1]; // +1 for label
double test_set[TEST_SET_SIZE][NUM_OF_FEATURES+1]; // +1 for label

// Initialize train and test sets with random values
void initialize_sets() {
    for(int i=0; i<TRAIN_SET_SIZE; i++) {
        for(int j=0; j<NUM_OF_FEATURES; j++) {
            train_set[i][j] = (double)rand() / RAND_MAX;
        }
        train_set[i][NUM_OF_FEATURES] = rand() % NUM_OF_CLASSES; // Assign label randomly
    }

    for(int i=0; i<TEST_SET_SIZE; i++) {
        for(int j=0; j<NUM_OF_FEATURES; j++) {
            test_set[i][j] = (double)rand() / RAND_MAX;
        }
        test_set[i][NUM_OF_FEATURES] = -1; // Label is unknown
    }
}

// Calculate Euclidean distance between two data points
double euclidean_distance(double* point1, double* point2) {
    double sum = 0;
    for(int i=0; i<NUM_OF_FEATURES; i++) {
        double diff = point1[i] - point2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

// Find k nearest neighbors of a given point
void find_k_nearest_neighbors(int k, double* point, double (*dist_func)(double*, double*), double distances[k], int indexes[k]) {
    for(int i=0; i<k; i++) {
        indexes[i] = i;
        distances[i] = dist_func(point, train_set[i]);
    }

    for(int i=k; i<TRAIN_SET_SIZE; i++) {
        double dist = dist_func(point, train_set[i]);
        for(int j=0; j<k; j++) {
            if(dist < distances[j]) {
                for(int l=k-2; l>=j; l--) {
                    indexes[l+1] = indexes[l];
                    distances[l+1] = distances[l];
                }
                indexes[j] = i;
                distances[j] = dist;
                break;
            }
        }
    }
}

// Predict the label of a given test point
int predict_label(int k, double* point, double (*dist_func)(double*, double*)) {
    double distances[k];
    int indexes[k];
    find_k_nearest_neighbors(k, point, dist_func, distances, indexes);

    int votes[NUM_OF_CLASSES] = {0};
    for(int i=0; i<k; i++) {
        int label = (int)train_set[indexes[i]][NUM_OF_FEATURES];
        votes[label]++;
    }

    int max_votes = 0;
    int label = -1;
    for(int i=0; i<NUM_OF_CLASSES; i++) {
        if(votes[i] > max_votes) {
            max_votes = votes[i];
            label = i;
        }
    }

    return label;
}

int main() {
    srand(42); // For reproducibility

    // Initialize train and test sets
    initialize_sets();

    // Predict labels for test set
    int num_of_correct = 0;
    for(int i=0; i<TEST_SET_SIZE; i++) {
        int predicted_label = predict_label(5, test_set[i], euclidean_distance);
        if(predicted_label != -1) {
            test_set[i][NUM_OF_FEATURES] = predicted_label;
        }
        if(predicted_label == (int)test_set[i][NUM_OF_FEATURES]) {
            num_of_correct++;
        }
    }
    double accuracy = (double)num_of_correct / TEST_SET_SIZE * 100.0;

    printf("Accuracy: %.2f %%\n", accuracy);

    return 0;
}