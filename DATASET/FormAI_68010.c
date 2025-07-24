//FormAI DATASET v1.0 Category: Image Classification system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 100
#define MAX_IMAGES 1000
#define MAX_PIXELS 1000000
#define NUM_CLASSES 10

typedef struct Image {
    char name[MAX_NAME_LENGTH];
    int pixels[MAX_PIXELS];
    int class;
} Image;

typedef struct ImageSet {
    Image images[MAX_IMAGES];
    int numImages;
} ImageSet;

typedef struct Classifier {
    float means[NUM_CLASSES][MAX_PIXELS];
    float variances[NUM_CLASSES][MAX_PIXELS];
} Classifier;

void loadImageSet(const char* filename, ImageSet* imageSet) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    char buffer[MAX_NAME_LENGTH];
    int numPixels;
    fscanf(file, "%d %d", &imageSet->numImages, &numPixels);
    for (int i = 0; i < imageSet->numImages; i++) {
        fscanf(file, "%s", buffer);
        strcpy(imageSet->images[i].name, buffer);
        for (int j = 0; j < numPixels; j++) {
            fscanf(file, "%d", &imageSet->images[i].pixels[j]);
        }
        fscanf(file, "%d", &imageSet->images[i].class);
    }
    fclose(file);
}

void computeMeanAndVariance(const ImageSet* imageSet, Classifier* classifier) {
    // Compute class means
    for (int i = 0; i < imageSet->numImages; i++) {
        const Image* image = &imageSet->images[i];
        const int class = image->class;
        for (int j = 0; j < MAX_PIXELS; j++) {
            classifier->means[class][j] += (float) image->pixels[j] / imageSet->numImages;
        }
    }
    // Compute class variances
    for (int i = 0; i < imageSet->numImages; i++) {
        const Image* image = &imageSet->images[i];
        const int class = image->class;
        for (int j = 0; j < MAX_PIXELS; j++) {
            const float diff = (float) image->pixels[j] - classifier->means[class][j];
            classifier->variances[class][j] += diff * diff / imageSet->numImages;
        }
    }
}

int classifyImage(const Image* image, const Classifier* classifier) {
    float maxProb = -INFINITY;
    int maxClass = -1;
    for (int c = 0; c < NUM_CLASSES; c++) {
        float prob = 0;
        for (int i = 0; i < MAX_PIXELS; i++) {
            const float diff = (float) image->pixels[i] - classifier->means[c][i];
            prob += -0.5 * log(2 * M_PI * classifier->variances[c][i])
                  - 0.5 * pow(diff, 2) / classifier->variances[c][i];
        }
        if (prob > maxProb) {
            maxProb = prob;
            maxClass = c;
        }
    }
    return maxClass;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <train_file> <test_file>\n", argv[0]);
        exit(1);
    }
    ImageSet trainSet;
    loadImageSet(argv[1], &trainSet);
    Classifier classifier;
    memset(&classifier, 0, sizeof(classifier));
    computeMeanAndVariance(&trainSet, &classifier);
    ImageSet testSet;
    loadImageSet(argv[2], &testSet);
    int correct = 0;
    for (int i = 0; i < testSet.numImages; i++) {
        const Image* image = &testSet.images[i];
        const int predictedClass = classifyImage(image, &classifier);
        if (predictedClass == image->class) {
            correct++;
        }
        printf("%s %d %d\n", image->name, predictedClass, image->class);
    }
    const float accuracy = (float) correct / testSet.numImages;
    printf("Accuracy: %.2f%%\n", accuracy * 100);
    return 0;
}