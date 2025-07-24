//FormAI DATASET v1.0 Category: Image Classification system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMG_SIZE 784
#define LEARNING_RATE 0.01

/* Struct for holding image and class label */
typedef struct {
    double img[IMG_SIZE];
    int label;
} Data;

/* Struct for holding weights and biases */
typedef struct {
    double weights[NUM_CLASSES][IMG_SIZE];
    double biases[NUM_CLASSES];
} Model;

/* Function for initializing model with random weights and biases */
void init_model(Model *model) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            model->weights[i][j] = (double) rand() / RAND_MAX;
        }
        model->biases[i] = (double) rand() / RAND_MAX;
    }
}

/* Function for predicting class of an image */
int predict(Data *data, Model *model) {
    double max_score = -INFINITY;
    int max_index = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        double score = model->biases[i];
        for (int j = 0; j < IMG_SIZE; j++) {
            score += data->img[j] * model->weights[i][j];
        }
        if (score > max_score) {
            max_score = score;
            max_index = i;
        }
    }
    return max_index;
}

/* Function for training model on a batch of data */
void train(Data *batch, int batch_size, Model *model) {
    double weight_gradient[NUM_CLASSES][IMG_SIZE] = {0};
    double bias_gradient[NUM_CLASSES] = {0};
    for (int i = 0; i < batch_size; i++) {
        int y_true = batch[i].label;
        double scores[NUM_CLASSES] = {0};
        for (int j = 0; j < NUM_CLASSES; j++) {
            double score = model->biases[j];
            for (int k = 0; k < IMG_SIZE; k++) {
                score += batch[i].img[k] * model->weights[j][k];
            }
            scores[j] = score;
        }
        double exp_scores[NUM_CLASSES] = {0};
        double sum_exp_scores = 0;
        for (int j = 0; j < NUM_CLASSES; j++) {
            exp_scores[j] = exp(scores[j]);
            sum_exp_scores += exp_scores[j];
        }
        double probs[NUM_CLASSES] = {0};
        for (int j = 0; j < NUM_CLASSES; j++) {
            probs[j] = exp_scores[j] / sum_exp_scores;
        }
        for (int j = 0; j < NUM_CLASSES; j++) {
            for (int k = 0; k < IMG_SIZE; k++) {
                double x_jk = batch[i].img[k];
                double loss_gradient = (j == y_true) ? probs[j] - 1 : probs[j];
                weight_gradient[j][k] += x_jk * loss_gradient / batch_size;
            }
            double bias_loss_gradient = (j == y_true) ? probs[j] - 1 : probs[j];
            bias_gradient[j] += bias_loss_gradient / batch_size;
        }
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            model->weights[i][j] -= LEARNING_RATE * weight_gradient[i][j];
        }
        model->biases[i] -= LEARNING_RATE * bias_gradient[i];
    }
}

int main() {
    /* Load data */
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    Data data[10000];
    int num_data = 0;
    char line[800];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }
        data[num_data].label = atoi(token);
        for (int i = 0; i < IMG_SIZE; i++) {
            token = strtok(NULL, ",");
            if (token == NULL) {
                continue;
            }
            data[num_data].img[i] = atof(token) / 255.0;
        }
        num_data++;
    }

    /* Shuffle data */
    for (int i = 0; i < num_data; i++) {
        int j = rand() % num_data;
        Data temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    /* Initialize model */
    Model model;
    init_model(&model);

    /* Train model */
    int batch_size = 32;
    int num_batches = num_data / batch_size;
    for (int epoch = 0; epoch < 10; epoch++) {
        for (int i = 0; i < num_batches; i++) {
            Data *batch = &data[i * batch_size];
            train(batch, batch_size, &model);
        }
    }

    /* Test model */
    int num_correct = 0;
    for (int i = 0; i < num_data; i++) {
        int y_pred = predict(&data[i], &model);
        if (y_pred == data[i].label) {
            num_correct++;
        }
    }
    double accuracy = (double) num_correct / num_data;
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}