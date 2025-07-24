//FormAI DATASET v1.0 Category: Image Classification system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 3
#define NUM_FEATURES 4
#define NUM_SAMPLES 12

int main()
{
    float training_data[NUM_SAMPLES][NUM_FEATURES] = {
        {5.1, 3.5, 1.4, 0.2},
        {4.9, 3.0, 1.4, 0.2},
        {4.7, 3.2, 1.3, 0.2},
        {4.6, 3.1, 1.5, 0.2},
        {5.0, 3.6, 1.4, 0.2},
        {5.4, 3.9, 1.7, 0.4},
        {4.6, 3.4, 1.4, 0.3},
        {5.0, 3.4, 1.5, 0.2},
        {4.4, 2.9, 1.4, 0.2},
        {4.9, 3.1, 1.5, 0.1},
        {5.4, 3.7, 1.5, 0.2},
        {4.8, 3.4, 1.6, 0.2}
    };

    int training_labels[NUM_SAMPLES] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Set all to 0 initially

    float testing_data[NUM_FEATURES] = {5.2, 3.6, 1.2, 0.2};

    int class_histogram[NUM_CLASSES] = {0}; // Initialize to 0

    // Training phase
    for(int i=0; i<NUM_SAMPLES; i++)
    {
        if(training_data[i][0] > 5.0 && training_data[i][1] > 3.5)
        {
            // Set label to 1 (versicolor) if both conditions are met
            training_labels[i] = 1;
        }
        else if(training_data[i][0] < 4.8)
        {
            // Set label to 2 (setosa) if condition is met
            training_labels[i] = 2;
        }
    }

    // Testing phase
    for(int i=0; i<NUM_SAMPLES; i++)
    {
        float distance = 0.0;
        for(int j=0; j<NUM_FEATURES; j++)
        {
            distance += (training_data[i][j] - testing_data[j]) * (training_data[i][j] - testing_data[j]);
        }

        int predicted_class = training_labels[i];
        class_histogram[predicted_class] += 1;
    }

    int max_count = 0;
    int predicted_class = -1;
    for(int i=0; i<NUM_CLASSES; i++)
    {
        if(class_histogram[i] > max_count)
        {
            max_count = class_histogram[i];
            predicted_class = i;
        }
    }

    // Output predicted class
    printf("Predicted class: %d\n", predicted_class);

    return 0;
}