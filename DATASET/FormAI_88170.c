//FormAI DATASET v1.0 Category: Image Classification system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMG_SIZE 784

// Function to read in the image file
void readImageFile(FILE *f, unsigned char *imageData)
{
    for(int i=0; i<IMG_SIZE; i++)
    {
        imageData[i] = fgetc(f);
    }
}

// Function to read in the label file
unsigned char readLabelFile(FILE *f)
{
    return fgetc(f);
}

// Function to calculate the softmax of an array
void softmax(double *input, int size, double *output)
{
    double sum=0.0;
    for(int i=0; i<size; i++)
    {
        sum += exp(input[i]);
    }
    for(int i=0; i<size; i++)
    {
        output[i] = exp(input[i]) / sum;
    }
}

int main()
{
    // Read in the trained model
    FILE *modelFile = fopen("model.bin", "rb");
    double weights[NUM_CLASSES][IMG_SIZE];
    double biases[NUM_CLASSES];
    fread(weights, sizeof(double), NUM_CLASSES * IMG_SIZE, modelFile);
    fread(biases, sizeof(double), NUM_CLASSES, modelFile);
    fclose(modelFile);

    // Read in the test data
    FILE *testImageFile = fopen("test_images.bin", "rb");
    FILE *testLabelFile = fopen("test_labels.bin", "rb");

    unsigned char image[IMG_SIZE];
    unsigned char label;

    double output[NUM_CLASSES];

    int correctCount = 0;
    int totalCount = 0;

    while(!feof(testImageFile))
    {
        readImageFile(testImageFile, image);
        label = readLabelFile(testLabelFile);
        totalCount++;

        double input[NUM_CLASSES];
        for(int i=0; i<NUM_CLASSES; i++)
        {
            input[i] = biases[i];
            for(int j=0; j<IMG_SIZE; j++)
            {
                input[i] += weights[i][j] * image[j];
            }
        }

        softmax(input, NUM_CLASSES, output);

        int pred = 0;
        for(int i=1; i<NUM_CLASSES; i++)
        {
            if(output[i] > output[pred])
            {
                pred = i;
            }
        }

        if(pred == label)
        {
            correctCount++;
        }
    }

    printf("Accuracy: %f\n", (double) correctCount / (double) totalCount);
    
    fclose(testImageFile);
    fclose(testLabelFile);

    return 0;
}