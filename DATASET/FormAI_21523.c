//FormAI DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28
#define NUM_CLASSES 10

// Define structs
typedef struct {
    float** data;
    int labels[NUM_CLASSES];
    int num_samples;
} dataset;

typedef struct {
    float** weights;
    float bias;
} neuron;

typedef struct {
    neuron** neurons;
    int num_neurons;
} layer;

typedef struct {
    layer** layers;
    int num_layers;
} model;

// Function prototypes
dataset* load_data(char* filename);
void print_image(float* image);
float** allocate_2d_array(int n, int m);
void free_2d_array(float** arr, int n);
void free_dataset(dataset* ds);
void initialize_model(model* m);
void train_model(model* m, dataset* train_data, int num_epochs, float learning_rate);
void forward_pass(model* m, float* input, float* output);
void test_model(model* m, dataset* test_data);

int main() {
    // Load data
    dataset* train_data = load_data("train_data.txt");
    dataset* test_data = load_data("test_data.txt");

    // Initialize model
    model* m = (model*) malloc(sizeof(model));
    initialize_model(m);

    // Train model
    train_model(m, train_data, 100, 0.01);

    // Test model
    test_model(m, test_data);

    // Free memory
    free_dataset(train_data);
    free_dataset(test_data);
    free(m);
}

// Load data from file
dataset* load_data(char* filename) {
    dataset* ds = (dataset*) malloc(sizeof(dataset));

    // Open file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read number of samples
    fscanf(fp, "%d", &(ds->num_samples));

    // Allocate memory for data
    ds->data = allocate_2d_array(ds->num_samples, IMAGE_WIDTH * IMAGE_HEIGHT);

    // Read data and labels
    for (int i = 0; i < ds->num_samples; i++) {
        fscanf(fp, "%d", &(ds->labels[i]));
        for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
            fscanf(fp, "%f", &(ds->data[i][j]));
        }
    }

    // Close file
    fclose(fp);

    return ds;
}

// Print an image to stdout
void print_image(float* image) {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%.1f ", image[i * IMAGE_WIDTH + j]);
        }
        printf("\n");
    }
}

// Allocate memory for a 2D array
float** allocate_2d_array(int n, int m) {
    float** arr = (float**) malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        arr[i] = (float*) malloc(m * sizeof(float));
        memset(arr[i], 0, m * sizeof(float));
    }
    return arr;
}

// Free memory for a 2D array
void free_2d_array(float** arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Free memory for a dataset
void free_dataset(dataset* ds) {
    free_2d_array(ds->data, ds->num_samples);
    free(ds);
}

// Initialize the model
void initialize_model(model* m) {
    m->num_layers = 2;

    // Initialize input layer
    layer* input_layer = (layer*) malloc(sizeof(layer));
    input_layer->num_neurons = IMAGE_WIDTH * IMAGE_HEIGHT;
    input_layer->neurons = (neuron**) malloc(input_layer->num_neurons * sizeof(neuron*));
    for (int i = 0; i < input_layer->num_neurons; i++) {
        input_layer->neurons[i] = (neuron*) malloc(sizeof(neuron));
        input_layer->neurons[i]->weights = NULL;
        input_layer->neurons[i]->bias = 0;
    }

    // Initialize output layer
    layer* output_layer = (layer*) malloc(sizeof(layer));
    output_layer->num_neurons = NUM_CLASSES;
    output_layer->neurons = (neuron**) malloc(output_layer->num_neurons * sizeof(neuron*));
    for (int i = 0; i < output_layer->num_neurons; i++) {
        output_layer->neurons[i] = (neuron*) malloc(sizeof(neuron));
        output_layer->neurons[i]->weights = allocate_2d_array(input_layer->num_neurons, 1);
        for (int j = 0; j < input_layer->num_neurons; j++) {
            output_layer->neurons[i]->weights[j][0] = ((float) rand() / RAND_MAX) * 0.1 - 0.05;
        }
        output_layer->neurons[i]->bias = ((float) rand() / RAND_MAX) * 0.1 - 0.05;
    }

    // Add layers to model
    m->layers = (layer**) malloc(m->num_layers * sizeof(layer*));
    m->layers[0] = input_layer;
    m->layers[1] = output_layer;
}

// Train the model using the given input data and labels
void train_model(model* m, dataset* train_data, int num_epochs, float learning_rate) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        float epoch_error = 0;
        for (int i = 0; i < train_data->num_samples; i++) {
            // Calculate output for current input
            float output[NUM_CLASSES];
            forward_pass(m, train_data->data[i], output);

            // Calculate error
            float error = 0;
            for (int j = 0; j < NUM_CLASSES; j++) {
                float label = train_data->labels[i] == j ? 1 : 0;
                error += 0.5 * (label - output[j]) * (label - output[j]);
            }

            // Add error to epoch error
            epoch_error += error;

            // Backpropagate error
            for (int j = 0; j < NUM_CLASSES; j++) {
                float label = train_data->labels[i] == j ? 1 : 0;
                float delta = (output[j] - label) * output[j] * (1 - output[j]);

                for (int k = 0; k < m->layers[1]->num_neurons; k++) {
                    m->layers[1]->neurons[k]->weights[j][0] -= learning_rate * delta * m->layers[0]->neurons[k]->weights[j][0];
                    m->layers[1]->neurons[k]->bias -= learning_rate * delta;
                }
            }
        }

        // Print epoch error
        printf("Epoch %d: Error = %f\n", epoch + 1, epoch_error / train_data->num_samples);
    }
}

// Calculate the output of the model for the given input
void forward_pass(model* m, float* input, float* output) {
    // Set input layer
    for (int i = 0; i < m->layers[0]->num_neurons; i++) {
        m->layers[0]->neurons[i]->bias = input[i];
    }

    // Calculate output layer
    for (int i = 0; i < m->layers[1]->num_neurons; i++) {
        float net = m->layers[1]->neurons[i]->bias;
        for (int j = 0; j < m->layers[0]->num_neurons; j++) {
            net += m->layers[1]->neurons[i]->weights[j][0] * m->layers[0]->neurons[j]->bias;
        }
        output[i] = 1 / (1 + exp(-net));
    }
}

// Test the model using the given test data
void test_model(model* m, dataset* test_data) {
    int num_correct = 0;
    for (int i = 0; i < test_data->num_samples; i++) {
        // Calculate output
        float output[NUM_CLASSES];
        forward_pass(m, test_data->data[i], output);

        // Find maximum output
        int max_index = 0;
        float max_value = output[0];
        for (int j = 1; j < NUM_CLASSES; j++) {
            if (output[j] > max_value) {
                max_index = j;
                max_value = output[j];
            }
        }

        // Check if output is correct
        if (test_data->labels[i] == max_index) {
            num_correct++;
        }
    }

    // Print accuracy
    printf("Accuracy: %.2f%% (%d / %d)\n", (float) num_correct / test_data->num_samples * 100, num_correct, test_data->num_samples);
}