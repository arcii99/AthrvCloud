//FormAI DATASET v1.0 Category: Image compression ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

// Function to print the compressed image
void printCompressedImage(char *image, int size)
{
    // Count variable to keep track of repeated pixels
    int count = 1;
 
    // Iterate through the pixels of the image
    for (int i = 0; i < size; i++)
    {
        // If the current pixel is same as the next pixel
        if (image[i] == image[i + 1])
        {
            count++;
        }
        else
        {
            // Print the current pixel and the count of repeated pixels
            printf("%d%c", count, image[i]);
            count = 1;
        }
    }
}

int main()
{
    char image[] = "RRRRGGGBBB";
    int size = sizeof(image)/sizeof(image[0]) - 1; // Subtracting '\0' character from the size
 
    // Print the original image
    printf("Original Image:\n%s\n", image);
 
    // Print the compressed image
    printf("\nCompressed Image:\n");
    printCompressedImage(image, size);
   
    return 0;
}