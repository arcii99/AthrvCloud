//FormAI DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_IMAGE_SIZE 1024
#define MAX_FILTER_SIZE 3

void readImageFile(char*, int[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int*, int*);
void writeImageFile(char*, int[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int, int);
void applyFilter(int[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int, int, int[MAX_FILTER_SIZE][MAX_FILTER_SIZE], int);
void displayFilter(int[MAX_FILTER_SIZE][MAX_FILTER_SIZE]);
void displayMenu();

int main()
{
    char fileName[MAX_FILE_NAME];
    int choice, image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], numRows, numCols;
    int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name of the image file: ");
                scanf("%s", fileName);
                readImageFile(fileName, image, &numRows, &numCols);
                printf("\nSuccessfully read the following image:\n\n");
                writeImageFile("temp.pgm", image, numRows, numCols);
                break;
            case 2:
                printf("\nEnter the name of the output file: ");
                scanf("%s", fileName);
                writeImageFile(fileName, image, numRows, numCols);
                printf("\nSuccessfully saved the image as: %s\n\n", fileName);
                break;
            case 3:
                applyFilter(image, numRows, numCols, filter, MAX_FILTER_SIZE);
                printf("\nFilter applied successfully!\n\n");
                break;
            case 4:
                displayFilter(filter);
                break;
            case 5:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }
    } while (1);
    
    return 0;
}

void readImageFile(char* fileName, int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int* numRows, int* numCols)
{
    FILE* fp;
    char buffer[MAX_IMAGE_SIZE];
    int temp;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("\nError: Unable to read the image file, please try again.\n");
        exit(1);
    }

    fgets(buffer, MAX_IMAGE_SIZE, fp);
    fgets(buffer, MAX_IMAGE_SIZE, fp); /* Get rid of the comment line */

    fscanf(fp, "%d %d", numCols, numRows);
    fscanf(fp, "%d", &temp);

    for (int i = 0; i < *numRows; i++) {
        for (int j = 0; j < *numCols; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);
}

void writeImageFile(char* fileName, int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int numRows, int numCols)
{
    FILE* fp;

    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("\nError: Unable to save the image file, please try again.\n");
        exit(1);
    }

    fprintf(fp, "P2\n");
    fprintf(fp, "# Image created by Image Editor\n");
    fprintf(fp, "%d %d\n", numCols, numRows);
    fprintf(fp, "255\n");

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void applyFilter(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int numRows, int numCols, int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE], int filterSize)
{
    int filteredImage[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], sum = 0;

    for (int i = 0; i < numRows - filterSize + 1; i++) {
        for (int j = 0; j < numCols - filterSize + 1; j++) {
            sum = 0;
            for (int k = 0; k < filterSize; k++) {
                for (int l = 0; l < filterSize; l++) {
                    sum += image[i + k][j + l] * filter[k][l];
                }
            }
            filteredImage[i][j] = sum / 9;
        }
    }

    /* Copy the filtered image back to the original image */
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            image[i][j] = filteredImage[i][j];
        }
    }
}

void displayFilter(int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE])
{
    printf("\nThe current filter is:\n\n");
    for (int i = 0; i < MAX_FILTER_SIZE; i++) {
        for (int j = 0; j < MAX_FILTER_SIZE; j++) {
            printf("%d ", filter[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayMenu()
{
    printf("\nPlease select an option:\n");
    printf("\n1. Load an image file");
    printf("\n2. Save the current image");
    printf("\n3. Apply the current filter to the image");
    printf("\n4. Display the current filter");
    printf("\n5. Exit the program\n\n");
    printf("Enter your choice: ");
}