//FormAI DATASET v1.0 Category: Image Classification system ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void classify(char* image)
{
    if(image == NULL) // base case
    {
        printf("Error: Image not found!\n");
        return;
    }
    else
    {
        // Some code to classify the image
        printf("Image class: ");
        int randNum = rand() % 5; // generate random number from 0 to 4
        switch(randNum)
        {
            case 0:
                printf("Animal\n");
                break;
            case 1:
                printf("Nature\n");
                break;
            case 2:
                printf("Human\n");
                break;
            case 3:
                printf("Vehicle\n");
                break;
            case 4:
                printf("Object\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }
        // Recursively classify the other images in the dataset
        printf("Classifying next image...\n");
        classify(NULL); // Passing null as image parameter for testing purposes
    }
}

int main()
{
    printf("Starting image classification...\n");
    classify("image1.jpg"); // Passing a test image name
    printf("Finished classification\n");
    return 0;
}