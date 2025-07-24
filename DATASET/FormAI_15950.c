//FormAI DATASET v1.0 Category: Image Classification system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGES 1000
#define IMAGE_SIZE 28 //28x28 pixels
#define NUM_CLASSES 10
#define NUM_EPOCHS 10
#define LEARNING_RATE 0.01

float images[MAX_IMAGES][IMAGE_SIZE * IMAGE_SIZE];  //Input images
int labels[MAX_IMAGES];                             //Labels of the input images

float weights[IMAGE_SIZE * IMAGE_SIZE][NUM_CLASSES]; //Weights for classification

void train_model() {
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        for (int img = 0; img < MAX_IMAGES; img++) {
            //Forward pass
            int actual_label = labels[img];
            float max_score = 0;
            int predicted_label = 0;

            for (int cls = 0; cls < NUM_CLASSES; cls++) {
                float score = 0;
                for (int pixel = 0; pixel < IMAGE_SIZE * IMAGE_SIZE; pixel++) {
                    score += images[img][pixel] * weights[pixel][cls];
                }
                if (score > max_score) {
                    max_score = score;
                    predicted_label = cls;
                }
            }

            //Backward pass
            for (int cls = 0; cls < NUM_CLASSES; cls++) {
                float target_value = (cls == actual_label ? 1 : 0);
                float error = target_value - (cls == predicted_label ? 1 : 0);

                for (int pixel = 0; pixel < IMAGE_SIZE * IMAGE_SIZE; pixel++) {
                    weights[pixel][cls] += LEARNING_RATE * error * images[img][pixel];
                }
            }
        }
    }
}

int predict_image(float *image) {
    float max_score = 0;
    int predicted_label = 0;

    for (int cls = 0; cls < NUM_CLASSES; cls++) {
        float score = 0;
        for (int pixel = 0; pixel < IMAGE_SIZE * IMAGE_SIZE; pixel++) {
            score += image[pixel] * weights[pixel][cls];
        }
        if (score > max_score) {
            max_score = score;
            predicted_label = cls;
        }
    }

    return predicted_label;
}

int main() {
    //Load input data
    FILE *in_file = fopen("input_images.txt", "r");
    FILE *label_file = fopen("input_labels.txt", "r");

    if (in_file == NULL || label_file == NULL) {
        printf("Failed to open input files\n");
        return 1;
    }

    int num_images = 0;
    while (fscanf(label_file, "%d", &labels[num_images]) == 1) {
        for (int pixel = 0; pixel < IMAGE_SIZE * IMAGE_SIZE; pixel++) {
            if (fscanf(in_file, "%f", &images[num_images][pixel]) != 1) {
                printf("Failed to read input images\n");
                return 1;
            }
        }

        num_images++;
        if (num_images >= MAX_IMAGES) {
            break;
        }
    }

    fclose(in_file);
    fclose(label_file);

    //Initialize weights
    for (int pixel = 0; pixel < IMAGE_SIZE * IMAGE_SIZE; pixel++) {
        for (int cls = 0; cls < NUM_CLASSES; cls++) {
            weights[pixel][cls] = (float) rand() / RAND_MAX;
        }
    }

    //Train the model
    train_model();

    //Test the model
    float test_image[IMAGE_SIZE * IMAGE_SIZE];
    for (int pixel = 0; pixel < IMAGE_SIZE * IMAGE_SIZE; pixel++) {
        if (fscanf(in_file, "%f", &test_image[pixel]) != 1) {
            printf("Failed to read the test image\n");
            return 1;
        }
    }

    int predicted_label = predict_image(test_image);
    printf("Predicted label: %d\n", predicted_label);

    return 0;
}