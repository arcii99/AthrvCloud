//FormAI DATASET v1.0 Category: Image Classification system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_IMAGES 1000    // number of images for training data
#define IMAGE_SIZE 28         // size of the image in pixels
#define NUM_OF_CLASSES 10     // number of classes for classification

int main() {
    // Initialize training data
    int training_data[NUM_OF_IMAGES][IMAGE_SIZE][IMAGE_SIZE];
    int training_labels[NUM_OF_IMAGES];
    for (int i = 0; i < NUM_OF_IMAGES; i++) {
        training_labels[i] = i % NUM_OF_CLASSES;    // assign label based on which class it belongs to
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                training_data[i][j][k] = rand() % 256;    // randomly generate pixel values
            }
        }
    }

    // Initialize weight matrix
    double weights[IMAGE_SIZE * IMAGE_SIZE][NUM_OF_CLASSES];
    for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE; i++) {
        for (int j = 0; j < NUM_OF_CLASSES; j++) {
            weights[i][j] = ((double) rand() / (double) RAND_MAX) * 2 - 1;    // randomly initialize weights between -1 and 1
        }
    }

    // Train the model using stochastic gradient descent
    double learning_rate = 0.01;
    int num_of_epochs = 10;
    for (int epoch = 0; epoch < num_of_epochs; epoch++) {
        double loss = 0;
        for (int i = 0; i < NUM_OF_IMAGES; i++) {
            double input[IMAGE_SIZE * IMAGE_SIZE];
            for (int j = 0; j < IMAGE_SIZE; j++) {
                for (int k = 0; k < IMAGE_SIZE; k++) {
                    input[j * IMAGE_SIZE + k] = (double) training_data[i][j][k] / 255.0;    // normalize pixel values
                }
            }

            int label = training_labels[i];

            double output[NUM_OF_CLASSES] = {0};
            for (int j = 0; j < NUM_OF_CLASSES; j++) {
                for (int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                    output[j] += weights[k][j] * input[k];    // calculate dot product between input and weights
                }
            }

            // Softmax activation function
            double sum = 0;
            for (int j = 0; j < NUM_OF_CLASSES; j++) {
                sum += exp(output[j]);
            }
            for (int j = 0; j < NUM_OF_CLASSES; j++) {
                output[j] = exp(output[j]) / sum;
            }

            // Calculate loss using cross entropy
            loss += -log(output[label]);

            // Calculate gradient and update weights
            for (int j = 0; j < NUM_OF_CLASSES; j++) {
                double gradient = output[j];
                if (j == label) {
                    gradient -= 1;
                }
                for (int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                    weights[k][j] -= learning_rate * gradient * input[k];    // update weights
                }
            }
        }
        printf("Epoch %d - Loss: %lf\n", epoch + 1, loss / NUM_OF_IMAGES);
    }

    // Test the model using validation data
    int num_of_correct_predictions = 0;
    int num_of_validation_data = 100;
    int validation_data[num_of_validation_data][IMAGE_SIZE][IMAGE_SIZE];
    int validation_labels[num_of_validation_data];
    for (int i = 0; i < num_of_validation_data; i++) {
        int label = rand() % NUM_OF_CLASSES;    // randomly assign label
        validation_labels[i] = label;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                validation_data[i][j][k] = rand() % 256;    // randomly generate pixel values
            }
        }

        double input[IMAGE_SIZE * IMAGE_SIZE];
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                input[j * IMAGE_SIZE + k] = (double) validation_data[i][j][k] / 255.0;    // normalize pixel values
            }
        }

        double output[NUM_OF_CLASSES] = {0};
        for (int j = 0; j < NUM_OF_CLASSES; j++) {
            for (int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                output[j] += weights[k][j] * input[k];    // calculate dot product between input and weights
            }
        }

        // Softmax activation function
        double sum = 0;
        for (int j = 0; j < NUM_OF_CLASSES; j++) {
            sum += exp(output[j]);
        }
        for (int j = 0; j < NUM_OF_CLASSES; j++) {
            output[j] = exp(output[j]) / sum;
        }

        // Find predicted label and check if correct
        int predicted_label = 0;
        double max_output = -1;
        for (int j = 0; j < NUM_OF_CLASSES; j++) {
            if (output[j] > max_output) {
                predicted_label = j;
                max_output = output[j];
            }
        }
        if (predicted_label == label) {
            num_of_correct_predictions++;
        }
    }
    printf("Accuracy on validation data: %lf%%\n", (double) num_of_correct_predictions / (double) num_of_validation_data * 100.0);

    return 0;
}