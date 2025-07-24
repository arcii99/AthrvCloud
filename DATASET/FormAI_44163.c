//FormAI DATASET v1.0 Category: Image Classification system ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define OUTPUT_SIZE 10
#define CONV_SIZE 3
#define POOL_SIZE 2
#define NUM_FILTERS 32
#define HIDDEN_SIZE 128
#define BATCH_SIZE 64
#define LEARNING_RATE 0.001
#define NUM_EPOCHS 10

typedef struct {
    double data[INPUT_SIZE];
    int label;
} image_t;

typedef struct {
    double data[OUTPUT_SIZE];
} output_t;

typedef struct {
    double weights[CONV_SIZE][CONV_SIZE][NUM_FILTERS];
    double bias;
} conv_layer_t;

typedef struct {
    double weights[HIDDEN_SIZE][OUTPUT_SIZE];
    double bias[HIDDEN_SIZE];
} hidden_layer_t;

typedef struct {
    double weights[OUTPUT_SIZE][HIDDEN_SIZE];
    double bias[OUTPUT_SIZE];
} output_layer_t;

int main() {
    // Load MNIST dataset
    image_t* train_images = (image_t*)malloc(60000 * sizeof(image_t));
    output_t* train_labels = (output_t*)malloc(60000 * sizeof(output_t));
    image_t* test_images = (image_t*)malloc(10000 * sizeof(image_t));
    output_t* test_labels = (output_t*)malloc(10000 * sizeof(output_t));
    // Code for loading images and labels from files goes here...
    
    // Initialize CNN layers
    conv_layer_t conv_layer;
    hidden_layer_t hidden_layer;
    output_layer_t output_layer;
    for (int i = 0; i < CONV_SIZE; i++) {
        for (int j = 0; j < CONV_SIZE; j++) {
            for (int k = 0; k < NUM_FILTERS; k++) {
                conv_layer.weights[i][j][k] = ((double)(rand() % 1000) / 500.0) - 1.0;
            }
        }
    }
    conv_layer.bias = ((double)(rand() % 1000) / 500.0) - 1.0;
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            hidden_layer.weights[i][j] = ((double)(rand() % 1000) / 500.0) - 1.0;
        }
        hidden_layer.bias[i] = ((double)(rand() % 1000) / 500.0) - 1.0;
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output_layer.weights[i][j] = ((double)(rand() % 1000) / 500.0) - 1.0;
        }
        output_layer.bias[i] = ((double)(rand() % 1000) / 500.0) - 1.0;
    }
    
    // Train CNN
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        printf("Epoch %d\n", epoch+1);
        for (int batch_start = 0; batch_start < 60000; batch_start += BATCH_SIZE) {
            // Forward pass
            for (int i = 0; i < BATCH_SIZE; i++) {
                double conv_output[28][28][NUM_FILTERS];
                for (int j = 0; j < 28; j++) {
                    for (int k = 0; k < 28; k++) {
                        for (int l = 0; l < NUM_FILTERS; l++) {
                            double sum = 0.0;
                            for (int m = 0; m < CONV_SIZE; m++) {
                                for (int n = 0; n < CONV_SIZE; n++) {
                                    if (j+m-1 >= 0 && j+m-1 < 28 && k+n-1 >= 0 && k+n-1 < 28) {
                                        sum += train_images[batch_start+i].data[(j+m-1)*28+(k+n-1)] * conv_layer.weights[m][n][l];
                                    }
                                }
                            }
                            conv_output[j][k][l] = fmax(0.0, sum + conv_layer.bias);
                        }
                    }
                }
                double pool_output[14][14][NUM_FILTERS];
                for (int j = 0; j < 14; j++) {
                    for (int k = 0; k < 14; k++) {
                        for (int l = 0; l < NUM_FILTERS; l++) {
                            double max = 0.0;
                            for (int m = 0; m < POOL_SIZE; m++) {
                                for (int n = 0; n < POOL_SIZE; n++) {
                                    double val = conv_output[j*2+m][k*2+n][l];
                                    if (val > max) {
                                        max = val;
                                    }
                                }
                            }
                            pool_output[j][k][l] = max;
                        }
                    }
                }
                double hidden_output[HIDDEN_SIZE];
                for (int j = 0; j < HIDDEN_SIZE; j++) {
                    double sum = 0.0;
                    for (int k = 0; k < 14; k++) {
                        for (int l = 0; l < 14; l++) {
                            for (int m = 0; m < NUM_FILTERS; m++) {
                                sum += pool_output[k][l][m] * hidden_layer.weights[j][m];
                            }
                        }
                    }
                    hidden_output[j] = fmax(0.0, sum + hidden_layer.bias[j]);
                }
                double output_output[OUTPUT_SIZE];
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    double sum = 0.0;
                    for (int k = 0; k < HIDDEN_SIZE; k++) {
                        sum += hidden_output[k] * output_layer.weights[j][k];
                    }
                    output_output[j] = sum + output_layer.bias[j];
                }
                double output_exp[OUTPUT_SIZE];
                double output_softmax[OUTPUT_SIZE];
                double output_error[OUTPUT_SIZE];
                double label_onehot[OUTPUT_SIZE];
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    output_exp[j] = exp(output_output[j]);
                    label_onehot[j] = 0.0;
                    if (j == train_images[batch_start+i].label) {
                        label_onehot[j] = 1.0;
                    }
                }
                double output_exp_sum = 0.0;
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    output_exp_sum += output_exp[j];
                }
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    output_softmax[j] = output_exp[j] / output_exp_sum;
                    output_error[j] = output_softmax[j] - label_onehot[j];
                }
                
                // Backward pass
                for (int j = 0; j < OUTPUT_SIZE; j++) {
                    output_layer.bias[j] -= LEARNING_RATE * output_error[j];
                    for (int k = 0; k < HIDDEN_SIZE; k++) {
                        output_layer.weights[j][k] -= LEARNING_RATE * output_error[j] * hidden_output[k];
                    }
                }
                double hidden_error[HIDDEN_SIZE];
                for (int j = 0; j < HIDDEN_SIZE; j++) {
                    double sum = 0.0;
                    for (int k = 0; k < OUTPUT_SIZE; k++) {
                        sum += output_error[k] * output_layer.weights[k][j];
                    }
                    if (hidden_output[j] > 0.0) {
                        hidden_error[j] = sum;
                    } else {
                        hidden_error[j] = 0.0;
                    }
                    hidden_layer.bias[j] -= LEARNING_RATE * hidden_error[j];
                    for (int k = 0; k < 14; k++) {
                        for (int l = 0; l < 14; l++) {
                            for (int m = 0; m < NUM_FILTERS; m++) {
                                hidden_layer.weights[j][m] -= LEARNING_RATE * hidden_error[j] * pool_output[k][l][m];
                            }
                        }
                    }
                }
                double pool_error[14][14][NUM_FILTERS];
                for (int j = 0; j < 14; j++) {
                    for (int k = 0; k < 14; k++) {
                        for (int l = 0; l < NUM_FILTERS; l++) {
                            double max = 0.0;
                            int max_index = -1;
                            for (int m = 0; m < POOL_SIZE; m++) {
                                for (int n = 0; n < POOL_SIZE; n++) {
                                    double val = conv_output[j*2+m][k*2+n][l];
                                    if (val > max) {
                                        max = val;
                                        max_index = m*POOL_SIZE+n;
                                    }
                                }
                            }
                            for (int m = 0; m < POOL_SIZE; m++) {
                                for (int n = 0; n < POOL_SIZE; n++) {
                                    if (max_index == m*POOL_SIZE+n) {
                                        pool_error[j*2+m][k*2+n][l] = hidden_error[0];
                                    } else {
                                        pool_error[j*2+m][k*2+n][l] = 0.0;
                                    }
                                }
                            }
                        }
                    }
                }
                double conv_error[28][28][NUM_FILTERS];
                for (int j = 0; j < 28; j++) {
                    for (int k = 0; k < 28; k++) {
                        for (int l = 0; l < NUM_FILTERS; l++) {
                            double sum = 0.0;
                            for (int m = 0; m < POOL_SIZE; m++) {
                                for (int n = 0; n < POOL_SIZE; n++) {
                                    for (int o = 0; o < NUM_FILTERS; o++) {
                                        if (j-m+1 >= 0 && j-m+1 < 14 && k-n+1 >= 0 && k-n+1 < 14) {
                                            sum += pool_error[j-m+1][k-n+1][o] * conv_layer.weights[m][n][o];
                                        }
                                    }
                                }
                            }
                            if (conv_output[j][k][l] > 0.0) {
                                conv_error[j][k][l] = sum;
                            } else {
                                conv_error[j][k][l] = 0.0;
                            }
                            conv_layer.bias -= LEARNING_RATE * conv_error[j][k][l];
                            for (int m = 0; m < CONV_SIZE; m++) {
                                for (int n = 0; n < CONV_SIZE; n++) {
                                    if (j-m+1 >= 0 && j-m+1 < 28 && k-n+1 >= 0 && k-n+1 < 28) {
                                        conv_layer.weights[m][n][l] -= LEARNING_RATE * conv_error[j][k][l] * train_images[batch_start+i].data[(j-m+1)*28+(k-n+1)];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // Evaluate CNN on test set
    int num_correct = 0;
    for (int i = 0; i < 10000; i++) {
        double conv_output[28][28][NUM_FILTERS];
        for (int j = 0; j < 28; j++) {
            for (int k = 0; k < 28; k++) {
                for (int l = 0; l < NUM_FILTERS; l++) {
                    double sum = 0.0;
                    for (int m = 0; m < CONV_SIZE; m++) {
                        for (int n = 0; n < CONV_SIZE; n++) {
                            if (j+m-1 >= 0 && j+m-1 < 28 && k+n-1 >= 0 && k+n-1 < 28) {
                                sum += test_images[i].data[(j+m-1)*28+(k+n-1)] * conv_layer.weights[m][n][l];
                            }
                        }
                    }
                    conv_output[j][k][l] = fmax(0.0, sum + conv_layer.bias);
                }
            }
        }
        double pool_output[14][14][NUM_FILTERS];
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k < 14; k++) {
                for (int l = 0; l < NUM_FILTERS; l++) {
                    double max = 0.0;
                    for (int m = 0; m < POOL_SIZE; m++) {
                        for (int n = 0; n < POOL_SIZE; n++) {
                            double val = conv_output[j*2+m][k*2+n][l];
                            if (val > max) {
                                max = val;
                            }
                        }
                    }
                    pool_output[j][k][l] = max;
                }
            }
        }
        double hidden_output[HIDDEN_SIZE];
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < 14; k++) {
                for (int l = 0; l < 14; l++) {
                    for (int m = 0; m < NUM_FILTERS; m++) {
                        sum += pool_output[k][l][m] * hidden_layer.weights[j][m];
                    }
                }
            }
            hidden_output[j] = fmax(0.0, sum + hidden_layer.bias[j]);
        }
        double output_output[OUTPUT_SIZE];
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < HIDDEN_SIZE; k++) {
                sum += hidden_output[k] * output_layer.weights[j][k];
            }
            output_output[j] = sum + output_layer.bias[j];
        }
        int predicted_label = 0;
        double max_output = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (output_output[j] > max_output) {
                predicted_label = j;
                max_output = output_output[j];
            }
        }
        if (predicted_label == test_labels[i].data) {
            num_correct++;
        }
    }
    printf("Test accuracy: %f\n", (double)num_correct / 10000.0);
    
    // Clean up
    free(train_images);
    free(train_labels);
    free(test_images);
    free(test_labels);
    
    return 0;
}