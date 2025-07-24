//FormAI DATASET v1.0 Category: Image Classification system ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define NUM_CLASSES 10
#define IMG_WIDTH 28
#define IMG_HEIGHT 28
#define IMG_SIZE IMG_WIDTH * IMG_HEIGHT

// Define structures
typedef struct {
    float data[IMG_SIZE];
    int label;    
} image;

typedef struct {
    float weights[NUM_CLASSES][IMG_SIZE];
    float biases[NUM_CLASSES];
} model;

// Function to load the image data and labels from CSV files
void load_data(const char* images_path, const char* labels_path, int num_images, image* images) {
    FILE* images_file = fopen(images_path, "r");
    FILE* labels_file = fopen(labels_path, "r");

    for (int i = 0; i < num_images; i++) {
        // Read comma-separated image data values from file
        for (int j = 0; j < IMG_SIZE; j++) {
            fscanf(images_file, "%f,", &images[i].data[j]);
        }

        // Read image label from file
        fscanf(labels_file, "%d,", &images[i].label);
    }

    fclose(images_file);
    fclose(labels_file);
}

// Function to predict the class of an image using the trained model
int predict(model* m, image* img) {
    float scores[NUM_CLASSES];

    // Compute the unnormalized scores for each class
    for (int i = 0; i < NUM_CLASSES; i++) {
        scores[i] = m->biases[i];

        for (int j = 0; j < IMG_SIZE; j++) {
            scores[i] += m->weights[i][j] * img->data[j];
        }
    }

    // Find the class with the highest score (i.e., the predicted class)
    int best_class = 0;
    float best_score = scores[0];

    for (int i = 1; i < NUM_CLASSES; i++) {
        if (scores[i] > best_score) {
            best_class = i;
            best_score = scores[i];
        }
    }

    return best_class;
}

int main() {
    // Initialize the model with random weights and biases
    model m;

    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            m.weights[i][j] = (float) rand() / RAND_MAX;
        }

        m.biases[i] = (float) rand() / RAND_MAX;
    }

    // Load the training data
    int num_train_images = 60000;
    image* train_images = malloc(num_train_images * sizeof(image));
    load_data("train_images.csv", "train_labels.csv", num_train_images, train_images);

    // Train the model using stochastic gradient descent
    float learning_rate = 0.01;
    int batch_size = 100;
    int num_batches = num_train_images / batch_size;

    for (int epoch = 0; epoch < 5; epoch++) {
        for (int i = 0; i < num_batches; i++) {
            // Update the weights and biases using a random batch of images
            int start = i * batch_size;
            int end = (i + 1) * batch_size;

            for (int j = start; j < end; j++) {
                // Make a prediction for the current image
                int pred = predict(&m, &train_images[j]);

                // Compute the gradient of the loss function with respect to
                // the weights and biases for the predicted class
                float dL_dw[NUM_CLASSES][IMG_SIZE];
                float dL_db[NUM_CLASSES];

                for (int k = 0; k < NUM_CLASSES; k++) {
                    if (k == train_images[j].label) {
                        dL_db[k] = pred == k ? 1.0 : 0.0;

                        for (int l = 0; l < IMG_SIZE; l++) {
                            dL_dw[k][l] = pred == k ? train_images[j].data[l] : 0.0;
                        }
                    } else {
                        dL_db[k] = 0.0;

                        for (int l = 0; l < IMG_SIZE; l++) {
                            dL_dw[k][l] = 0.0;
                        }
                    }
                }

                // Update the weights and biases using the gradient descent rule
                for (int k = 0; k < NUM_CLASSES; k++) {
                    m.biases[k] -= learning_rate * dL_db[k];

                    for (int l = 0; l < IMG_SIZE; l++) {
                        m.weights[k][l] -= learning_rate * dL_dw[k][l];
                    }
                }
            }
        }

        printf("Epoch %d complete\n", epoch + 1);
    }

    // Load the test data
    int num_test_images = 10000;
    image* test_images = malloc(num_test_images * sizeof(image));
    load_data("test_images.csv", "test_labels.csv", num_test_images, test_images);

    // Evaluate the model on the test data
    int num_correct = 0;

    for (int i = 0; i < num_test_images; i++) {
        int pred = predict(&m, &test_images[i]);

        if (pred == test_images[i].label) {
            num_correct++;
        }
    }

    float accuracy = (float) num_correct / num_test_images;
    printf("Test accuracy: %.2f%%\n", accuracy * 100);

    // Free allocated memory
    free(train_images);
    free(test_images);

    return 0;
}