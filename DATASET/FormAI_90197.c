//FormAI DATASET v1.0 Category: Image Classification system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMAGES 1000
#define IMG_SIZE 784
#define NUM_CLASSES 10
#define LEARNING_RATE 0.1
#define EPOCHS 50
#define BATCH_SIZE 32

double weights[IMG_SIZE][NUM_CLASSES];
double bias[NUM_CLASSES];
int train_labels[MAX_IMAGES];
double train_images[MAX_IMAGES][IMG_SIZE];
int num_train_images;

void read_data() {
    FILE *f_train_images = fopen("train-images", "rb");
    FILE *f_train_labels = fopen("train-labels", "rb");
    // read train images
    for (int i = 0; i < MAX_IMAGES; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            unsigned char pixel;
            fread(&pixel, sizeof(pixel), 1, f_train_images);
            train_images[i][j] = (double) pixel / 255.0;
        }
    }
    // read train labels
    for (int i = 0; i < MAX_IMAGES; i++) {
        unsigned char label;
        fread(&label, sizeof(label), 1, f_train_labels);
        train_labels[i] = label;
    }
    fclose(f_train_images);
    fclose(f_train_labels);
    num_train_images = MAX_IMAGES;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

int predict(double image[]) {
    int max_class = 0;
    double max_score = -1;
    for (int c = 0; c < NUM_CLASSES; c++) {
        double score = 0;
        for (int i = 0; i < IMG_SIZE; i++) {
            score += weights[i][c] * image[i];
        }
        score += bias[c];
        score = sigmoid(score);
        if (score > max_score) {
            max_score = score;
            max_class = c;
        }
    }
    return max_class;
}

void train() {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < num_train_images; i += BATCH_SIZE) {
            // create batch
            double batch_images[BATCH_SIZE][IMG_SIZE];
            int batch_labels[BATCH_SIZE];
            for (int j = i; j < i + BATCH_SIZE; j++) {
                if (j >= num_train_images) {
                    break;
                }
                for (int k = 0; k < IMG_SIZE; k++) {
                    batch_images[j - i][k] = train_images[j][k];
                }
                batch_labels[j - i] = train_labels[j];
            }
            // apply updates
            for (int j = 0; j < BATCH_SIZE; j++) {
                double image[IMG_SIZE];
                for (int k = 0; k < IMG_SIZE; k++) {
                    image[k] = batch_images[j][k];
                }
                int label = batch_labels[j];
                for (int c = 0; c < NUM_CLASSES; c++) {
                    double score = 0;
                    for (int k = 0; k < IMG_SIZE; k++) {
                        score += weights[k][c] * image[k];
                    }
                    score += bias[c];
                    score = sigmoid(score);
                    double gradient = score;
                    if (label == c) {
                        gradient -= 1;
                    }
                    for (int k = 0; k < IMG_SIZE; k++) {
                        weights[k][c] -= LEARNING_RATE * gradient * image[k];
                    }
                    bias[c] -= LEARNING_RATE * gradient;
                }
            }
        }
    }
}

int main() {
    read_data();
    train();
    int num_test_images = 0;
    FILE *f_test_images = fopen("test-images", "rb");
    while (!feof(f_test_images)) {
        unsigned char pixel;
        fread(&pixel, sizeof(pixel), 1, f_test_images);
        if (feof(f_test_images)) {
            break;
        }
        num_test_images++;
        double image[IMG_SIZE];
        image[0] = (double) pixel / 255.0;
        for (int i = 1; i < IMG_SIZE; i++) {
            fread(&pixel, sizeof(pixel), 1, f_test_images);
            image[i] = (double) pixel / 255.0;
        }
        int label = predict(image);
        printf("%d\n", label);
    }
    fclose(f_test_images);
    return 0;
}