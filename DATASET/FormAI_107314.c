//FormAI DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define HEADER_SIZE 54

int main()
{
    char file_name[MAX_FILE_NAME];
    int choice, width, height, x, y, index, r, g, b;
    FILE *image_file;

    // Get the file name from user
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the file in binary mode
    image_file = fopen(file_name, "rb");

    if (image_file == NULL) {
        printf("Error: Failed to open the file.");
        exit(1);
    }

    // Retrieve image metadata
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, image_file);
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Allocate memory for the image data
    int image_size = 3 * width * height;
    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);

    // Retrieve image data
    fread(image_data, sizeof(unsigned char), image_size, image_file);

    // Close the file
    fclose(image_file);

    // Display menu to user
    printf("\nWhat would you like to do with the image?\n");
    printf("1. Convert image to greyscale\n");
    printf("2. Invert image\n");
    printf("3. Flip image horizontally\n");
    printf("4. Rotate image\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform selected image operation
    switch(choice) {
        case 1:
            // Convert image to greyscale
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    index = (y * width + x) * 3;
                    r = image_data[index];
                    g = image_data[index + 1];
                    b = image_data[index + 2];
                    image_data[index] = image_data[index + 1] = image_data[index + 2] = (r + g + b) / 3;
                }
            }
            break;
        case 2:
            // Invert image
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    index = (y * width + x) * 3;
                    image_data[index] = 255 - image_data[index];
                    image_data[index + 1] = 255 - image_data[index + 1];
                    image_data[index + 2] = 255 - image_data[index + 2];
                }
            }
            break;
        case 3:
            // Flip image horizontally
            for (y = 0; y < height; y++) {
                for (x = 0; x < width / 2; x++) {
                    index = (y * width + x) * 3;
                    int flipped_index = (y * width + (width - 1 - x)) * 3;

                    // Swap pixel values
                    unsigned char temp_r = image_data[index];
                    unsigned char temp_g = image_data[index + 1];
                    unsigned char temp_b = image_data[index + 2];

                    image_data[index] = image_data[flipped_index];
                    image_data[index + 1] = image_data[flipped_index + 1];
                    image_data[index + 2] = image_data[flipped_index + 2];

                    image_data[flipped_index] = temp_r;
                    image_data[flipped_index + 1] = temp_g;
                    image_data[flipped_index + 2] = temp_b;
                }
            }
            break;
        case 4:
            // Rotate image
            unsigned char* rotated_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    index = (y * width + x) * 3;
                    int rotated_index = ((width - 1 - x) * height + y) * 3;

                    rotated_data[rotated_index] = image_data[index];
                    rotated_data[rotated_index + 1] = image_data[index + 1];
                    rotated_data[rotated_index + 2] = image_data[index + 2];
                }
            }
            free(image_data);
            image_data = rotated_data;
            // Swap image dimensions
            int temp = width;
            width = height;
            height = temp;
            break;
        default:
            printf("Error: Invalid choice.");
            exit(1);
    }

    // Write image data to file
    char new_file_name[MAX_FILE_NAME];
    strcpy(new_file_name, "new_");
    strcat(new_file_name, file_name);
    image_file = fopen(new_file_name, "wb");

    if (image_file == NULL) {
        printf("Error: Failed to create image file.");
        exit(1);
    }

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, image_file);
    fwrite(image_data, sizeof(unsigned char), image_size, image_file);

    // Close the file
    fclose(image_file);

    // Free allocated memory
    free(image_data);

    printf("Image processing successful.");
    return 0;
}