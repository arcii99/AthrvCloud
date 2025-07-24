//FormAI DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 3
#define IMAGE_SIZE 28
#define MAX_FILENAME_LENGTH 100

typedef struct Image {
    int data[IMAGE_SIZE][IMAGE_SIZE];
    int label;
} Image;

int read_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    char buffer[MAX_FILENAME_LENGTH];
    fgets(buffer, MAX_FILENAME_LENGTH, file); // Read first line
    image->label = atoi(buffer);
    for (int i = 0; i < IMAGE_SIZE; i++) {
        fread(&(image->data[i][0]), sizeof(int), IMAGE_SIZE, file);
    }
    fclose(file);
    return 0;
}

double calculate_distance(int a[IMAGE_SIZE][IMAGE_SIZE], int b[IMAGE_SIZE][IMAGE_SIZE]) {
    double distance = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            distance += (a[i][j] - b[i][j]) * (a[i][j] - b[i][j]);
        }
    }
    return distance;
}

int classify_image(Image *image, Image prototypes[NUM_CLASSES]) {
    int predicted_label = 0;
    double min_distance = calculate_distance(image->data, prototypes[0].data);
    for (int i = 1; i < NUM_CLASSES; i++) {
        double distance = calculate_distance(image->data, prototypes[i].data);
        if (distance < min_distance) {
            predicted_label = i;
            min_distance = distance;
        }
    }
    return predicted_label;
}

int main() {
    // Load prototypes
    Image prototypes[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        char filename[MAX_FILENAME_LENGTH];
        snprintf(filename, MAX_FILENAME_LENGTH, "prototype%d.txt", i);
        if (read_image(&prototypes[i], filename) != 0) {
            printf("Error reading prototype %d from file %s\n", i, filename);
            return 1;
        }
    }

    // Classify test images
    Image test_images[NUM_CLASSES];
    double accuracy = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        char filename[MAX_FILENAME_LENGTH];
        snprintf(filename, MAX_FILENAME_LENGTH, "test%d.txt", i);
        if (read_image(&test_images[i], filename) != 0) {
            printf("Error reading test image %d from file %s\n", i, filename);
            return 1;
        }
        int predicted_label = classify_image(&test_images[i], prototypes);
        printf("Predicted label for test image %d is %d (true label is %d)\n", i, predicted_label, i);
        if (predicted_label == i) {
            accuracy += 1;
        }
    }
    accuracy /= NUM_CLASSES;
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}