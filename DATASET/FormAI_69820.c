//FormAI DATASET v1.0 Category: Image Classification system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 28
#define INPUT_SIZE (IMAGE_SIZE * IMAGE_SIZE)
#define HIDDEN_SIZE 128

/* Define the neural network data structure */
typedef struct neural_network {
    float input[INPUT_SIZE];
    float hidden[HIDDEN_SIZE];
    float output[NUM_CLASSES];
    float weights_input_hidden[INPUT_SIZE * HIDDEN_SIZE];
    float weights_hidden_output[HIDDEN_SIZE * NUM_CLASSES];
} neural_network;

/* Initialize a neural network */
void initialize_network(neural_network *nn) {
    /* Randomly initialize the weights */
    for (int i = 0; i < INPUT_SIZE * HIDDEN_SIZE; i++) {
        nn->weights_input_hidden[i] = (float) rand() / (float) RAND_MAX;
    }
    for (int i = 0; i < HIDDEN_SIZE * NUM_CLASSES; i++) {
        nn->weights_hidden_output[i] = (float) rand() / (float) RAND_MAX;
    }
}

/* Calculate the output of the network for a given input */
void forward_propagation(neural_network *nn) {
    /* Calculate the hidden layer */
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        nn->hidden[i] = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            nn->hidden[i] += nn->input[j] * nn->weights_input_hidden[j * HIDDEN_SIZE + i];
        }
        nn->hidden[i] = 1 / (1 + exp(-nn->hidden[i])); /* Apply the sigmoid function */
    }
    /* Calculate the output layer */
    for (int i = 0; i < NUM_CLASSES; i++) {
        nn->output[i] = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            nn->output[i] += nn->hidden[j] * nn->weights_hidden_output[j * NUM_CLASSES + i];
        }
        nn->output[i] = exp(nn->output[i]); /* Apply the exponential function */
    }
    /* Normalize the output layer */
    float sum = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        sum += nn->output[i];
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        nn->output[i] /= sum;
    }
}

/* Train the neural network on a set of images */
void train_neural_network(neural_network *nn, float *images, int *labels, int num_images, int num_epochs, float learning_rate) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int image = 0; image < num_images; image++) {
            /* Set the input layer */
            for (int i = 0; i < INPUT_SIZE; i++) {
                nn->input[i] = images[image * INPUT_SIZE + i];
            }
            /* Forward propagation */
            forward_propagation(nn);
            /* Calculate the error signal */
            float target[NUM_CLASSES];
            memset(target, 0, sizeof(target));
            target[labels[image]] = 1;
            float error[NUM_CLASSES];
            for (int i = 0; i < NUM_CLASSES; i++) {
                error[i] = (target[i] - nn->output[i]) * nn->output[i] * (1 - nn->output[i]); /* Apply the derivative of the sigmoid function */
            }
            /* Backpropagation */
            for (int i = 0; i < HIDDEN_SIZE; i++) {
                for (int j = 0; j < NUM_CLASSES; j++) {
                    nn->weights_hidden_output[i * NUM_CLASSES + j] += learning_rate * error[j] * nn->hidden[i];
                }
            }
            for (int i = 0; i < INPUT_SIZE; i++) {
                for (int j = 0; j < HIDDEN_SIZE; j++) {
                    float sum = 0;
                    for (int k = 0; k < NUM_CLASSES; k++) {
                        sum += error[k] * nn->weights_hidden_output[j * NUM_CLASSES + k];
                    }
                    nn->weights_input_hidden[i * HIDDEN_SIZE + j] += learning_rate * nn->input[i] * nn->hidden[j] * nn->hidden[j] * (1 - nn->hidden[j]) * sum; /* Apply the derivative of the sigmoid function */
                }
            }
        }
    }
}

/* Test the neural network on a set of images and return the accuracy */
float test_neural_network(neural_network *nn, float *images, int *labels, int num_images) {
    int num_correct = 0;
    for (int image = 0; image < num_images; image++) {
        /* Set the input layer */
        for (int i = 0; i < INPUT_SIZE; i++) {
            nn->input[i] = images[image * INPUT_SIZE + i];
        }
        /* Forward propagation */
        forward_propagation(nn);
        /* Check if the prediction matches the label */
        int prediction = 0;
        for (int i = 0; i < NUM_CLASSES; i++) {
            if (nn->output[i] > nn->output[prediction]) {
                prediction = i;
            }
        }
        if (prediction == labels[image]) {
            num_correct++;
        }
    }
    return (float) num_correct / (float) num_images;
}

int main() {
    /* Load the data */
    FILE *images_file = fopen("mnist_images.bin", "rb");
    FILE *labels_file = fopen("mnist_labels.bin", "rb");
    int num_images = 1000;
    float images[num_images * INPUT_SIZE];
    int labels[num_images];
    fread(images, sizeof(images), 1, images_file);
    fread(labels, sizeof(labels), 1, labels_file);
    fclose(images_file);
    fclose(labels_file);
    /* Initialize the neural network */
    neural_network nn;
    initialize_network(&nn);
    /* Train the neural network */
    train_neural_network(&nn, images, labels, num_images, 10, 0.1);
    /* Test the neural network */
    float accuracy = test_neural_network(&nn, images, labels, num_images);
    printf("Accuracy: %f\n", accuracy);
    return 0;
}