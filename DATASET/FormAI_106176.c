//FormAI DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_HEIGHT 28
#define IMAGE_WIDTH 28
#define NUM_CLASSES 10

typedef struct {
    int height;
    int width;
    int* pixels;
    int label;
} Image;

typedef struct {
    int weights[IMAGE_HEIGHT * IMAGE_WIDTH];
    int bias;
} Classifier;

Image load_image(char* file_path) {
    Image img;
    FILE* img_file = fopen(file_path, "r");

    // Read height and width
    fscanf(img_file, "%d %d", &img.height, &img.width);

    // Allocate memory for pixels
    img.pixels = (int*)malloc(sizeof(int) * img.height * img.width);

    // Read pixel values
    for (int i = 0; i < img.width * img.height; i++) {
        fscanf(img_file, "%d", &img.pixels[i]);
    }

    img.label = -1;
    fclose(img_file);
    return img;
}

Classifier train_classifier(char* training_data_path) {
    Classifier classifier;

    // Initialize weights and bias to random values
    srand(0);
    for (int i = 0; i < IMAGE_HEIGHT * IMAGE_WIDTH; i++) {
        classifier.weights[i] = rand() % 100;
    }
    classifier.bias = rand() % 100;

    // Load training data
    FILE* training_data_file = fopen(training_data_path, "r");

    //One epoch
    for (int j = 0; j < NUM_CLASSES; j++) {
        //get all images with the current label
        for (int i = 0; i < 1000; i++) {
            Image img = load_image(training_data_file);
            if (img.label == j) {
                //calculate prediction
                int prediction = classifier.bias;
                for (int h = 0; h < img.height; h++) {
                    for (int w = 0; w < img.width; w++) {
                        prediction += img.pixels[h * img.width + w] * classifier.weights[h * img.width + w];
                    }
                }
                //update parameters
                if ((prediction >= 0 && j != img.label) || (prediction < 0 && j == img.label)) {
                    for (int h = 0; h < img.height; h++) {
                        for (int w = 0; w < img.width; w++) {
                            int pixel_value = img.pixels[h * img.width + w];
                            if (j == img.label) {
                                classifier.weights[h * img.width + w] += pixel_value;
                            } else {
                                classifier.weights[h * img.width + w] -= pixel_value;
                            }
                        }
                    }
                    if (j == img.label) {
                        classifier.bias++;
                    } else {
                        classifier.bias--;
                    }
                }
            }
            free(img.pixels);
        }
        rewind(training_data_file);
    }
    fclose(training_data_file);
    return classifier;
}

int classify_image(Image img, Classifier classifier) {
    
    int prediction = classifier.bias;

    for (int h = 0; h < img.height; h++) {
        for (int w = 0; w < img.width; w++) {
            prediction += img.pixels[h * img.width + w] * classifier.weights[h * img.width + w];
        }
    }

    if (prediction >= 0) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
       printf("Usage: %s training_data_path test_data_path\n", argv[0]);
       exit(1);
    }

    char* training_data_path = argv[1];
    char* test_data_path = argv[2];

    Classifier classifier = train_classifier(training_data_path);

    FILE* test_data_file = fopen(test_data_path, "r");
    
    int num_correct = 0;
    for (int i = 0; i < 1000; i++) {
        Image img = load_image(test_data_file);
        int predicted_label = classify_image(img, classifier);
        if (predicted_label == img.label) {
            num_correct++;
        }

        free(img.pixels);
    }

    printf("Accuracy: %f\n", (float)num_correct / 1000);
    fclose(test_data_file);

    return 0;
}