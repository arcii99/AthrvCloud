//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>

int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &rows, &cols);
    int image[rows][cols];

    printf("\nEnter the image values: \n");
    // read image values
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("[%d, %d]: ", i, j);
            scanf("%d", &image[i][j]);
        }
    }

    int choice;
    printf("\nSelect an operation:\n");
    printf("1. Flip horizontally\n");
    printf("2. Flip vertically\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // flipping horizontally
            printf("\nFlipping horizontally...\n");
            for (i=0; i<rows; i++) {
                for (j=0; j<cols/2; j++) {
                    int temp = image[i][j];
                    image[i][j] = image[i][cols-j-1];
                    image[i][cols-j-1] = temp;
                }
            }
            break;

        case 2:
            // flipping vertically
            printf("\nFlipping vertically...\n");
            for (i=0; i<rows/2; i++) {
                for (j=0; j<cols; j++) {
                    int temp = image[i][j];
                    image[i][j] = image[rows-i-1][j];
                    image[rows-i-1][j] = temp;
                }
            }
            break;

        default:
            printf("\nInvalid choice!\n");
            return 1;
    }

    printf("\nOutput image: \n");
    // print output image
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }   
        printf("\n");
    }

    return 0;
}