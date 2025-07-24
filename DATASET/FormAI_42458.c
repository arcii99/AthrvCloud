//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>

// Define the image classification function
void classifyImage(float image[][3], int size)
{
    float maxScore = 0;
    int maxIndex = 0;

    // Define the set of weights for each class
    float class1Weights[] = {0.2, 0.5, 0.3};
    float class2Weights[] = {0.1, 0.3, 0.6};
    float class3Weights[] = {0.4, 0.1, 0.5};

    // Calculate the score for each class based on the weights and the image values
    float class1Score = 0;
    float class2Score = 0;
    float class3Score = 0;
    for (int i = 0; i < size; i++)
    {
        class1Score += image[i][0] * class1Weights[i];
        class2Score += image[i][1] * class2Weights[i];
        class3Score += image[i][2] * class3Weights[i];
    }

    // Determine the class with the highest score
    if (class1Score > maxScore)
    {
        maxScore = class1Score;
        maxIndex = 1;
    }
    if (class2Score > maxScore)
    {
        maxScore = class2Score;
        maxIndex = 2;
    }
    if (class3Score > maxScore)
    {
        maxScore = class3Score;
        maxIndex = 3;
    }

    // Print out the result
    printf("Image classified as Class %d with score of %.2f\n", maxIndex, maxScore);
}

int main()
{
    // Define an example image
    float image[3][3] = {{1.0, 0.5, 0.2},
                         {0.1, 0.9, 0.4},
                         {0.3, 0.2, 0.8}};

    // Call the image classification function
    classifyImage(image, 3);

    return 0;
}