//FormAI DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FEATURES 2
#define NUM_CLASSES 3
#define NUM_SAMPLES 6

// Define the decision tree node
typedef struct Node {
    int feature_idx;
    float threshold;
    int class_label;
    struct Node *left;
    struct Node *right;
} Node;

// Define the data structure to store the image features and labels
typedef struct Data {
    float features[NUM_FEATURES];
    int label;
} Data;

// Define the training data
Data training_data[] = {
    {{0.7, 0.9}, 0},  // apple
    {{0.6, 0.4}, 1},  // banana
    {{0.1, 0.5}, 2},  // orange
    {{0.2, 0.8}, 0},  // apple
    {{0.8, 0.3}, 1},  // banana
    {{0.3, 0.2}, 2}   // orange
};

// Define a function to calculate the Gini impurity of a set of samples
float gini_impurity(Data samples[], int num_samples) {
    int class_counts[NUM_CLASSES] = {0};
    for (int i = 0; i < num_samples; i++) {
        class_counts[samples[i].label]++;
    }
    float impurity = 1.0;
    for (int c = 0; c < NUM_CLASSES; c++) {
        float p = (float) class_counts[c] / num_samples;
        impurity -= p * p;
    }
    return impurity;
}

// Define a function to split a set of samples based on a given feature and threshold
void split_data(Data samples[], int num_samples, int feature_idx, float threshold,
                Data left[], int *left_size,
                Data right[], int *right_size) {
    *left_size = 0;
    *right_size = 0;
    for (int i = 0; i < num_samples; i++) {
        if (samples[i].features[feature_idx] < threshold) {
            left[*left_size] = samples[i];
            (*left_size)++;
        } else {
            right[*right_size] = samples[i];
            (*right_size)++;
        }
    }
}

// Define a function to find the best split for a set of samples
void find_best_split(Data samples[], int num_samples, int *best_feature_idx, float *best_threshold) {
    float best_gain = 0.0;
    int left_size, right_size;
    Data left[num_samples], right[num_samples];
    for (int f = 0; f < NUM_FEATURES; f++) {
        for (float t = 0.1; t < 0.9; t += 0.1) {
            split_data(samples, num_samples, f, t, left, &left_size, right, &right_size);
            if ((left_size > 0) && (right_size > 0)) {
                float total_impurity = gini_impurity(samples, num_samples);
                float left_impurity = gini_impurity(left, left_size);
                float right_impurity = gini_impurity(right, right_size);
                float gain = total_impurity - left_impurity - right_impurity;
                if (gain > best_gain) {
                    *best_feature_idx = f;
                    *best_threshold = t;
                    best_gain = gain;
                }
            }
        }
    }
}

// Define a function to build the decision tree
Node *build_tree(Data samples[], int num_samples) {
    // If all samples belong to the same class, create a leaf node
    int class_counts[NUM_CLASSES] = {0};
    for (int i = 0; i < num_samples; i++) {
        class_counts[samples[i].label]++;
    }
    int majority_class = 0;
    for (int c = 0; c < NUM_CLASSES; c++) {
        if (class_counts[c] > class_counts[majority_class]) {
            majority_class = c;
        }
    }
    if (class_counts[majority_class] == num_samples) {
        Node *leaf = (Node *) malloc(sizeof(Node));
        leaf->feature_idx = -1;
        leaf->threshold = 0.0;
        leaf->class_label = majority_class;
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }
    // Split the samples and create a decision node
    int best_feature_idx;
    float best_threshold;
    find_best_split(samples, num_samples, &best_feature_idx, &best_threshold);
    Data left[num_samples], right[num_samples];
    int left_size, right_size;
    split_data(samples, num_samples, best_feature_idx, best_threshold, left, &left_size, right, &right_size);
    Node *node = (Node *) malloc(sizeof(Node));
    node->feature_idx = best_feature_idx;
    node->threshold = best_threshold;
    node->class_label = -1;
    node->left = build_tree(left, left_size);
    node->right = build_tree(right, right_size);
    return node;
}

// Define a function to classify a new image
int classify(Node *root, float features[]) {
    Node *node = root;
    while (node->class_label == -1) {
        if (features[node->feature_idx] < node->threshold) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node->class_label;
}

int main() {
    Node *root = build_tree(training_data, NUM_SAMPLES);
    float test_data[NUM_SAMPLES][NUM_FEATURES] = {
        {0.4, 0.6},
        {0.9, 0.1},
        {0.2, 0.2},
        {0.8, 0.7},
        {0.5, 0.4},
        {0.1, 0.3}
    };
    int expected_results[NUM_SAMPLES] = {0, 1, 2, 0, 1, 2};
    int num_correct = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        int result = classify(root, test_data[i]);
        if (result == expected_results[i]) {
            num_correct++;
        }
    }
    printf("Achieved accuracy: %.2f %%\n", (float) num_correct / NUM_SAMPLES * 100);
    return 0;
}