//FormAI DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of classes
#define NUM_CLASSES 5

/* Define struct for image classification */
typedef struct {
    int class; // class label
    double feature1; // feature 1
    double feature2; // feature 2
} image;

/* Define struct for class information */
typedef struct {
    int num_images; // number of images in class
    double mean_feature1; // mean value of feature 1 in class
    double mean_feature2; // mean value of feature 2 in class
    double covariance[2][2]; // covariance matrix of features
} class_info;

/* Function prototypes */
void compute_class_info(image [], int, class_info[]);
int classify_image(image, class_info[]);

/* Main function */
int main()
{
    // Define the images to classify
    image images[] = {
        {0, 1.5, 2.0},
        {0, 2.0, 3.0},
        {0, 1.0, 1.5},
        {1, 4.5, 5.0},
        {1, 5.0, 6.0},
        {1, 6.0, 6.5},
        {2, 8.5, 9.0},
        {2, 9.0, 10.0},
        {2, 10.0, 10.5},
        {3, 12.5, 13.0},
        {3, 13.0, 14.0},
        {3, 14.0, 14.5},
        {4, 16.5, 17.0},
        {4, 17.0, 18.0},
        {4, 18.0, 18.5}
    };

    // Compute the class information
    class_info class[NUM_CLASSES];
    compute_class_info(images, sizeof(images)/sizeof(image), class);

    // Classify each image and output the result
    for (int i = 0; i < sizeof(images)/sizeof(image); i++) {
        int label = classify_image(images[i], class);
        printf("Image %d: Class %d\n", i+1, label);
    }

    return 0;
}

/* Compute the class information */
void compute_class_info(image images[], int num_images, class_info class[NUM_CLASSES])
{
    // Initialize class information
    for (int i = 0; i < NUM_CLASSES; i++) {
        class[i].num_images = 0;
        class[i].mean_feature1 = 0.0;
        class[i].mean_feature2 = 0.0;
        class[i].covariance[0][0] = 0.0;
        class[i].covariance[0][1] = 0.0;
        class[i].covariance[1][0] = 0.0;
        class[i].covariance[1][1] = 0.0;
    }

    // Calculate sum of feature values for each class
    for (int i = 0; i < num_images; i++) {
        int c = images[i].class;
        class[c].num_images++;
        class[c].mean_feature1 += images[i].feature1;
        class[c].mean_feature2 += images[i].feature2;
    }

    // Calculate mean feature values for each class
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (class[i].num_images == 0) {
            continue;
        }
        class[i].mean_feature1 /= class[i].num_images;
        class[i].mean_feature2 /= class[i].num_images;
    }

    // Calculate covariance matrix for each class
    for (int i = 0; i < num_images; i++) {
        int c = images[i].class;
        class[c].covariance[0][0] += pow(images[i].feature1 - class[c].mean_feature1, 2);
        class[c].covariance[0][1] += (images[i].feature1 - class[c].mean_feature1) * (images[i].feature2 - class[c].mean_feature2);
        class[c].covariance[1][0] += (images[i].feature2 - class[c].mean_feature2) * (images[i].feature1 - class[c].mean_feature1);
        class[c].covariance[1][1] += pow(images[i].feature2 - class[c].mean_feature2, 2);
    }

    // Normalize covariance matrices
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (class[i].num_images == 0) {
            continue;
        }
        class[i].covariance[0][0] /= class[i].num_images - 1;
        class[i].covariance[0][1] /= class[i].num_images - 1;
        class[i].covariance[1][0] /= class[i].num_images - 1;
        class[i].covariance[1][1] /= class[i].num_images - 1;
    }
}

/* Classify an image using the calculated class information */
int classify_image(image img, class_info class[NUM_CLASSES])
{
    double max_likelihood = 0.0;
    int max_label = 0;

    // Calculate likelihood of image belonging to each class
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (class[i].num_images == 0) {
            continue;
        }

        double likelihood = 0.0;

        // Calculate discriminant function
        double a = (img.feature1 - class[i].mean_feature1) * ((class[i].covariance[1][1] * (img.feature2 - class[i].mean_feature2))
                 - (class[i].covariance[0][1] * (img.feature1 - class[i].mean_feature1)))
                 + (img.feature2 - class[i].mean_feature2) * ((class[i].covariance[0][0] * (img.feature1 - class[i].mean_feature1))
                 - (class[i].covariance[0][1] * (img.feature2 - class[i].mean_feature2)));

        double b = class[i].covariance[0][0] * class[i].covariance[1][1] 
                - class[i].covariance[0][1] * class[i].covariance[1][0];

        double c = log(class[i].num_images / ((double) sizeof(class) / sizeof(class[0])));

        likelihood = -0.5 * (a + c) / b;

        // Update max likelihood
        if (likelihood > max_likelihood) {
            max_likelihood = likelihood;
            max_label = i;
        }
    }

    return max_label;
}