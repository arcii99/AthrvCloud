//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: cheerful
// Welcome to the Amazing Image Processing program!
// This program will allow you to flip images and adjust brightness/contrast with ease!
// Let's get started!

#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main()
{
    // Declare variable to hold the file path
    char file_path[100];

    // Prompt the user to enter a file path
    printf("Please enter the file path of the image you would like to process: ");
    scanf("%s", file_path);

    // Declare variables to hold the image data
    int width, height, max_val;
    unsigned char *image_data;

    // Open the image file
    FILE *fp;
    fp = fopen(file_path, "rb");

    // Read the header information
    fscanf(fp, "P5\n%d %d\n%d\n", &width, &height, &max_val);

    // Allocate memory for the image data
    image_data = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    // Read the image data
    fread(image_data, sizeof(unsigned char), width * height, fp);

    // Close the file
    fclose(fp);

    // Ask the user what they would like to do with the image
    int choice;
    printf("\nWhat would you like to do with the image?\n");
    printf("1. Flip the image\n");
    printf("2. Adjust brightness/contrast\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    // Process the image based on the user's choice
    switch(choice)
    {
        case 1:
            // Flip the image
            for(int y = 0; y < height; y++)
            {
                for(int x = 0; x < width/2; x++)
                {
                    unsigned char temp = image_data[y*width + x];
                    image_data[y*width + x] = image_data[y*width + (width - x - 1)];
                    image_data[y*width + (width - x - 1)] = temp;
                }
            }
            printf("\nImage flipped!\n");
            break;
        case 2:
            // Adjust brightness/contrast
            int brightness, contrast;
            printf("\nEnter a value for brightness (between -255 and 255): ");
            scanf("%d", &brightness);
            printf("Enter a value for contrast (between -100 and 100): ");
            scanf("%d", &contrast);
            for(int i = 0; i < width * height; i++)
            {
                int new_value = ((int)image_data[i] + brightness) * (100 + contrast) / 100 - brightness;
                if(new_value > 255)
                {
                    image_data[i] = 255;
                }
                else if(new_value < 0)
                {
                    image_data[i] = 0;
                }
                else
                {
                    image_data[i] = (unsigned char)new_value;
                }
            }
            printf("\nBrightness/contrast adjusted!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    // Save the modified image
    int new_width = height, new_height = width;
    fp = fopen("modified_image.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", new_width, new_height, max_val);
    for(int y = 0; y < new_height; y++)
    {
        for(int x = 0; x < new_width; x++)
        {
            unsigned char pixel = image_data[x*new_height + y];
            fwrite(&pixel, sizeof(unsigned char), 1, fp);
        }
    }
    fclose(fp);

    // Free the memory allocated for the image data
    free(image_data);

    // Give the user a friendly message and end the program
    printf("\nYour modified image has been saved!\n");
    return 0;
}