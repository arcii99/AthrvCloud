//FormAI DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_IMAGE_SIZE 1024 // Maximum image size is 1KB

int main()
{
    char filename[100], choice;
    FILE *fp;
    unsigned char image[MAX_IMAGE_SIZE], grayscale_image[MAX_IMAGE_SIZE];
    int x, y, width, height, val;

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Read image width and height
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    printf("Image dimensions: %d x %d\n", width, height);

    // Read image data
    fseek(fp, 54, SEEK_SET);
    fread(image, sizeof(char), MAX_IMAGE_SIZE, fp);

    printf("Choose a filter to apply:\n");
    printf("a. Grayscale\n");
    printf("b. Invert\n");
    printf("c. Brightness\n");
    printf("d. Contrast\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    choice = tolower(choice);

    switch (choice) {
        case 'a':
            // Convert to Grayscale
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    val = image[(y * width) + x] / 3;
                    grayscale_image[(y * width) + x] = val;
                }
            }
            
            // Write Grayscale image to file
            fp = fopen("grayscale_image.bmp", "wb");
            fwrite(image, sizeof(char), 54, fp);
            fwrite(grayscale_image, sizeof(char), MAX_IMAGE_SIZE, fp);
            fclose(fp);
            
            printf("Grayscale image saved to file.\n");
            break;
        
        case 'b':
            // Invert the image
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    image[(y * width) + x] = 255 - image[(y * width) + x];
                }
            }
            
            // Write Inverted image to file
            fp = fopen("inverted_image.bmp", "wb");
            fwrite(image, sizeof(char), 54, fp);
            fwrite(image, sizeof(char), MAX_IMAGE_SIZE, fp);
            fclose(fp);
            
            printf("Inverted image saved to file.\n");
            break;
        
        case 'c':
            // Increase brightness of the image
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    val = image[(y * width) + x] + 50;
                    if (val > 255) val = 255;
                    image[(y * width) + x] = val;
                }
            }
            
            // Write Brightness adjusted image to file
            fp = fopen("brightness_image.bmp", "wb");
            fwrite(image, sizeof(char), 54, fp);
            fwrite(image, sizeof(char), MAX_IMAGE_SIZE, fp);
            fclose(fp);
            
            printf("Brightness adjusted image saved to file.\n");
            break;

        case 'd':
            // Increase contrast of the image
            double contrast = 1.5;
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    val = (int)((((image[(y * width) + x] / 255.0) - 0.5) * contrast + 0.5 ) * 255.0);
                    if (val < 0) val = 0;
                    if (val > 255) val = 255;
                    image[(y * width) + x] = val;
                }
            }
            
            // Write Contrast adjusted image to file
            fp = fopen("contrast_image.bmp", "wb");
            fwrite(image, sizeof(char), 54, fp);
            fwrite(image, sizeof(char), MAX_IMAGE_SIZE, fp);
            fclose(fp);
            
            printf("Contrast adjusted image saved to file.\n");
            break;

        default:
            printf("Error: Invalid choice.\n");
            exit(1);
    }

    return 0;
}