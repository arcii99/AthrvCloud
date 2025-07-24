//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Image Classification system!\n");
    printf("Please input the file name of the image you want to classify.\n");
    char filename[50];
    scanf("%s", filename);

    // Code to read and preprocess the image goes here
    // ...

    // Code to classify the image using some Machine Learning Model goes here
    // For the purpose of this example, we'll use random guessing
    int label = rand() % 10;
    printf("The image has been classified as class %d.\n", label);

    printf("Thank you for using the Image Classification system!\n");
    return 0;
}