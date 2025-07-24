//FormAI DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define NUM_OF_CLASSES 3
#define NUM_OF_FEATURES 4
#define THRESHOLD 100

typedef struct {
    float features[NUM_OF_FEATURES];
    int label;
} Data;

typedef struct {
    float weights[NUM_OF_FEATURES];
    float bias;
} Model;

int predict(Data data, Model model) {
    float score = model.bias;
    for (int i = 0; i < NUM_OF_FEATURES; i++) {
        score += data.features[i] * model.weights[i];
    }
    if (score > THRESHOLD) {
        return 1;
    } else {
        return 0;
    }
}

int train_model(Model* model, Data* data, int num_of_data_points, int num_of_iterations, float learning_rate) {
    for (int iter = 0; iter < num_of_iterations; iter++) {
        float total_loss = 0.0;
        for (int i = 0; i < num_of_data_points; i++) {
            int y_hat = predict(data[i], *model);
            float error = data[i].label - y_hat;
            total_loss += error * error;
            for (int j = 0; j < NUM_OF_FEATURES; j++) {
                model->weights[j] += learning_rate * error * data[i].features[j];
            }
            model->bias += learning_rate * error;
        }
        printf("Iteration %d, Loss: %f\n", iter+1, total_loss);
        if (total_loss < 0.1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Data data[] = {
        {{5.1, 3.5, 1.4, 0.2}, 1},
        {{4.9, 3.0, 1.4, 0.2}, 1},
        {{5.0, 3.6, 1.4, 0.2}, 1},
        {{7.0, 3.2, 4.7, 1.4}, 0},
        {{6.4, 3.2, 4.5, 1.5}, 0},
        {{6.9, 3.1, 4.9, 1.5}, 0},
        {{6.3, 3.3, 6.0, 2.5}, 1},
        {{5.8, 2.7, 5.1, 1.9}, 1},
        {{7.1, 3.0, 5.9, 2.1}, 1},
    };
    Model model = {{0.0, 0.0, 0.0, 0.0}, 0.0};
    if (train_model(&model, data, NUM_OF_CLASSES * 3, 100, 0.01)) {
        printf("Model converged!\n");
    } else {
        printf("Failed to converge.\n");
    }
    printf("Weights: [");
    for (int i = 0; i < NUM_OF_FEATURES; i++) {
        printf("%f,", model.weights[i]);
    }
    printf("]\n");
    printf("Bias: %f\n", model.bias);
    Data test_data[] = {
        {{5.0, 3.5, 1.3, 0.3}, 1},
        {{6.5, 2.8, 4.6, 1.5}, 0},
        {{7.2, 3.0, 5.8, 1.6}, 1},
    };
    int correct_predictions = 0;
    for (int i = 0; i < 3; i++) {
        int y = predict(test_data[i], model);
        if (y == test_data[i].label) {
            correct_predictions++;
        }
    }
    float accuracy = (float) correct_predictions / 3.0;
    printf("Accuracy: %f\n", accuracy);
    return 0;
}