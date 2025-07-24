//FormAI DATASET v1.0 Category: Image Classification system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 28 // Image dimensions
#define NUM_CLASSES 10 // Number of classes
#define NUM_HIDDEN 64 // Number of hidden layer nodes

/* Function to read image data from file */
void read_image(FILE *fp, float img[IMAGE_SIZE][IMAGE_SIZE]) {
    char buf[1024];
    for (int i = 0; i < IMAGE_SIZE; i++) {
        fgets(buf, 1024, fp);
        for (int j = 0; j < IMAGE_SIZE; j++) {
            img[i][j] = (float)(buf[j] - '0') / 255.0;
        }
    }
}

/* Function to read label data from file */
int read_label(FILE *fp) {
    char c;
    fscanf(fp, "%c", &c);
    return (int)(c - '0');
}

/* Function to compute sigmoid activation function */
float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

/* Main function */
int main(void) {
    /* Initialize weights */
    float w1[IMAGE_SIZE * IMAGE_SIZE][NUM_HIDDEN];
    float w2[NUM_HIDDEN][NUM_CLASSES];
    for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE; i++) {
        for (int j = 0; j < NUM_HIDDEN; j++) {
            w1[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
        }
    }
    for (int i = 0; i < NUM_HIDDEN; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            w2[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
        }
    }

    /* Read training data */
    FILE *train_img_fp = fopen("train-images.txt", "r");
    FILE *train_lbl_fp = fopen("train-labels.txt", "r");
    float train_img[60000][IMAGE_SIZE][IMAGE_SIZE];
    int train_lbl[60000];
    for (int i = 0; i < 60000; i++) {
        read_image(train_img_fp, train_img[i]);
        train_lbl[i] = read_label(train_lbl_fp);
    }

    /* Train model */
    int num_epochs = 10;
    int batch_size = 32;
    float learning_rate = 0.01;
    printf("Training model...\n");
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        printf("Epoch %d:", epoch+1);
        for (int i = 0; i < 60000 / batch_size; i++) {
            /* Initialize gradients */
            float grad_w1[IMAGE_SIZE * IMAGE_SIZE][NUM_HIDDEN] = {0};
            float grad_w2[NUM_HIDDEN][NUM_CLASSES] = {0};
            for (int j = 0; j < batch_size; j++) {
                /* Forward pass */
                float h[NUM_HIDDEN];
                float output[NUM_CLASSES];
                for (int k = 0; k < NUM_HIDDEN; k++) {
                    h[k] = 0;
                    for (int l = 0; l < IMAGE_SIZE * IMAGE_SIZE; l++) {
                        h[k] += train_img[i*batch_size+j][l/IMAGE_SIZE][l%IMAGE_SIZE] * w1[l][k];
                    }
                    h[k] = sigmoid(h[k]);
                }
                for (int k = 0; k < NUM_CLASSES; k++) {
                    output[k] = 0;
                    for (int l = 0; l < NUM_HIDDEN; l++) {
                        output[k] += h[l] * w2[l][k];
                    }
                    output[k] = sigmoid(output[k]);
                }
                /* Compute loss and backpropagate */
                float loss = 0;
                float d_output[NUM_CLASSES];
                float d_h[NUM_HIDDEN];
                for (int k = 0; k < NUM_CLASSES; k++) {
                    float target = (train_lbl[i*batch_size+j] == k);
                    loss += -target * log(output[k]) - (1-target) * log(1-output[k]);
                    d_output[k] = (output[k] - target) * output[k] * (1 - output[k]);
                }
                for (int k = 0; k < NUM_HIDDEN; k++) {
                    d_h[k] = 0;
                    for (int l = 0; l < NUM_CLASSES; l++) {
                        d_h[k] += d_output[l] * w2[k][l];
                    }
                    d_h[k] *= h[k] * (1 - h[k]);
                }
                for (int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                    for (int l = 0; l < NUM_HIDDEN; l++) {
                        grad_w1[k][l] += train_img[i*batch_size+j][k/IMAGE_SIZE][k%IMAGE_SIZE] * d_h[l];
                    }
                }
                for (int k = 0; k < NUM_HIDDEN; k++) {
                    for (int l = 0; l < NUM_CLASSES; l++) {
                        grad_w2[k][l] += h[k] * d_output[l];
                    }
                }
            }
            /* Update weights */
            for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
                for (int k = 0; k < NUM_HIDDEN; k++) {
                    w1[j][k] -= learning_rate * grad_w1[j][k] / batch_size;
                }
            }
            for (int j = 0; j < NUM_HIDDEN; j++) {
                for (int k = 0; k < NUM_CLASSES; k++) {
                    w2[j][k] -= learning_rate * grad_w2[j][k] / batch_size;
                }
            }
            printf(".");
        }
        printf("\n");
    }

    /* Read test data */
    FILE *test_img_fp = fopen("test-images.txt", "r");
    FILE *test_lbl_fp = fopen("test-labels.txt", "r");
    float test_img[10000][IMAGE_SIZE][IMAGE_SIZE];
    int test_lbl[10000];
    for (int i = 0; i < 10000; i++) {
        read_image(test_img_fp, test_img[i]);
        test_lbl[i] = read_label(test_lbl_fp);
    }

    /* Evaluate model */
    int num_correct = 0;
    printf("Evaluating model...\n");
    for (int i = 0; i < 10000; i++) {
        /* Forward pass */
        float h[NUM_HIDDEN];
        float output[NUM_CLASSES];
        for (int j = 0; j < NUM_HIDDEN; j++) {
            h[j] = 0;
            for (int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                h[j] += test_img[i][k/IMAGE_SIZE][k%IMAGE_SIZE] * w1[k][j];
            }
            h[j] = sigmoid(h[j]);
        }
        for (int j = 0; j < NUM_CLASSES; j++) {
            output[j] = 0;
            for (int k = 0; k < NUM_HIDDEN; k++) {
                output[j] += h[k] * w2[k][j];
            }
            output[j] = sigmoid(output[j]);
        }
        /* Determine predicted label */
        int pred_lbl = 0;
        float max_prob = 0;
        for (int j = 0; j < NUM_CLASSES; j++) {
            if (output[j] > max_prob) {
                pred_lbl = j;
                max_prob = output[j];
            }
        }
        if (pred_lbl == test_lbl[i]) {
            num_correct++;
        }
    }
    float accuracy = (float)num_correct / 10000.0;
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}