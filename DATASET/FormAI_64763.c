//FormAI DATASET v1.0 Category: Image Classification system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 784
#define TRAIN_SIZE 60000
#define TEST_SIZE 10000

struct Image {
    float pixel[IMAGE_SIZE];
    int label;
};

struct Network {
    float weights[IMAGE_SIZE][NUM_CLASSES];
};

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

int max_index(float *arr, int n) {
    int max_i = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_i]) {
            max_i = i;
        }
    }
    return max_i;
}

void train(struct Image *images, struct Network *net, float learning_rate) {
    for (int i = 0; i < TRAIN_SIZE; i++) {
        float activations[NUM_CLASSES] = {0};
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < NUM_CLASSES; k++) {
                activations[k] += images[i].pixel[j] * net->weights[j][k];
            }
        }

        for (int k = 0; k < NUM_CLASSES; k++) {
            float expected = (k == images[i].label) ? 1 : 0;
            float actual = sigmoid(activations[k]);
            float error = actual - expected;
            for (int j = 0; j < IMAGE_SIZE; j++) {
                net->weights[j][k] -= learning_rate * images[i].pixel[j] * error;
            }
        }
    }
}

void test(struct Image *images, struct Network *net, int *results) {
    for (int i = 0; i < TEST_SIZE; i++) {
        float activations[NUM_CLASSES] = {0};
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < NUM_CLASSES; k++) {
                activations[k] += images[i].pixel[j] * net->weights[j][k];
            }
        }
        results[i] = max_index(activations, NUM_CLASSES);
    }
}

int main() {
    struct Image train_images[TRAIN_SIZE];
    FILE *fp = fopen("train-images-idx3-ubyte", "rb");
    fseek(fp, 16, SEEK_SET);
    for (int i = 0; i < TRAIN_SIZE; i++) {
        fread(train_images[i].pixel, sizeof(float), IMAGE_SIZE, fp);
    }
    fclose(fp);

    int train_labels[TRAIN_SIZE];
    fp = fopen("train-labels-idx1-ubyte", "rb");
    fseek(fp, 8, SEEK_SET);
    fread(train_labels, sizeof(int), TRAIN_SIZE, fp);
    fclose(fp);

    struct Image test_images[TEST_SIZE];
    fp = fopen("t10k-images-idx3-ubyte", "rb");
    fseek(fp, 16, SEEK_SET);
    for (int i = 0; i < TEST_SIZE; i++) {
        fread(test_images[i].pixel, sizeof(float), IMAGE_SIZE, fp);
    }
    fclose(fp);

    int test_labels[TEST_SIZE];
    fp = fopen("t10k-labels-idx1-ubyte", "rb");
    fseek(fp, 8, SEEK_SET);
    fread(test_labels, sizeof(int), TEST_SIZE, fp);
    fclose(fp);

    srand(0);
    struct Network net;
    for (int j = 0; j < NUM_CLASSES; j++) {
        for (int i = 0; i < IMAGE_SIZE; i++) {
            net.weights[i][j] = ((float) rand() / RAND_MAX) - 0.5;
        }
    }

    float learning_rate = 0.1;
    for (int epoch = 0; epoch < 10; epoch++) {
        train(train_images, &net, learning_rate);
        int correct = 0;
        int results[TEST_SIZE];
        test(test_images, &net, results);
        for (int i = 0; i < TEST_SIZE; i++) {
            if (results[i] == test_labels[i]) {
                correct++;
            }
        }
        float accuracy = ((float) correct) / TEST_SIZE;
        printf("Epoch %d: accuracy = %f\n", epoch, accuracy);
    }

    return 0;
}