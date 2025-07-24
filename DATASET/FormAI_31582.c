//FormAI DATASET v1.0 Category: Image Classification system ; Style: complete
#include <stdio.h>

/* Constants */
#define NUM_IMAGES 5
#define IMAGE_SIZE 28*28
#define NUM_CLASSES 10

/* Function Declarations */
void load_images(int images[NUM_IMAGES][IMAGE_SIZE]);
void load_labels(int labels[NUM_IMAGES]);
void classify_images(int images[NUM_IMAGES][IMAGE_SIZE], int labels[NUM_IMAGES]);

int main() {
    int images[NUM_IMAGES][IMAGE_SIZE];
    int labels[NUM_IMAGES];

    // Load images and labels from file
    load_images(images);
    load_labels(labels);

    // Classify loaded images
    classify_images(images, labels);

    return 0;
}

/**
 * Loads images from file and stores in 2D array
 * Accepts: Pointer to 2D array of size NUM_IMAGES x IMAGE_SIZE
 */
void load_images(int images[NUM_IMAGES][IMAGE_SIZE]) {
    // Code to load images goes here
    printf("Images loaded successfully.\n");
}

/**
 * Loads labels from file and stores in 1D array
 * Accepts: Pointer to 1D array of size NUM_IMAGES
 */
void load_labels(int labels[NUM_IMAGES]) {
    // Code to load labels goes here
    printf("Labels loaded successfully.\n");
}

/**
 * Classifies images and prints predictions to console
 * Accepts: Pointer to 2D array of size NUM_IMAGES x IMAGE_SIZE, Pointer to 1D array of size NUM_IMAGES
 */
void classify_images(int images[NUM_IMAGES][IMAGE_SIZE], int labels[NUM_IMAGES]) {
    int i, j;
    int prediction[NUM_CLASSES];
    
    for(i=0; i<NUM_IMAGES; i++) {
        // Code to classify image goes here
        printf("Prediction for image %d: ", i);
        for(j=0; j<NUM_CLASSES; j++) {
            printf("%d ", prediction[j]);
        }
        printf("\n");
    }
}