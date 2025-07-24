//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50 // Maximum size of image

int main()
{
    int choice, i, j, rows, cols, temp; 
    
    int image[MAX_SIZE][MAX_SIZE]; // 2D array to store image

    printf("Enter the number of rows in the image: ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the image: ");
    scanf("%d", &cols);

    // Get the image pixel values
    printf("Enter the pixel values of the image: \n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    // Get user choice for image processing task
    printf("\nEnter your choice for image processing task:\n");
    printf("1. Flip the image\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            // Flip the image
            for(i=0; i<rows; i++)
            {
                for(j=0; j<cols/2; j++)
                {
                    temp = image[i][j];
                    image[i][j] = image[i][cols-1-j];
                    image[i][cols-1-j] = temp;
                }
            }
            printf("Flipping completed!\n");
            break;

        case 2:
            // Change brightness
            int brightness;
            printf("Enter the brightness value: ");
            scanf("%d", &brightness);
            for(i=0; i<rows; i++)
            {
                for(j=0; j<cols; j++)
                {
                    image[i][j] += brightness;
                }
            }
            printf("Brightness changed!\n");
            break;

        case 3:
            // Change contrast
            int contrast;
            printf("Enter the contrast value: ");
            scanf("%d", &contrast);
            for(i=0; i<rows; i++)
            {
                for(j=0; j<cols; j++)
                {
                    image[i][j] = (image[i][j] * contrast)/100;
                }
            }
            printf("Contrast changed!\n");
            break;

        default:
            // Invalid choice
            printf("Invalid choice!\n");
            return 0;
    }

    // Print the processed image
    printf("\nProcessed image:\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}