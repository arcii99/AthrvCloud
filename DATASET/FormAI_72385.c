//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 

#define ROWS 8 
#define COLS 8 

// Function to embed digital watermark in an image 
void embedWatermark(int image[ROWS][COLS], int watermark[ROWS][COLS]) 
{ 
    int i, j; 

    for (i = 0; i < ROWS; i++) { 
        for (j = 0; j < COLS; j++) { 
            // bitwise OR operation to embed the watermark 
            image[i][j] |= watermark[i][j]; 
        } 
    } 
} 

// Function to extract digital watermark from an image 
void extractWatermark(int image[ROWS][COLS], int watermark[ROWS][COLS]) 
{ 
    int i, j; 

    for (i = 0; i < ROWS; i++) { 
        for (j = 0; j < COLS; j++) { 
            // bitwise AND operation to extract the watermark 
            watermark[i][j] = image[i][j] & 1; 
        } 
    } 
} 

// Function to print the matrix on console 
void printMatrix(int matrix[ROWS][COLS]) 
{ 
    int i, j; 

    for (i = 0; i < ROWS; i++) { 
        for (j = 0; j < COLS; j++) { 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int image[ROWS][COLS] = {{0, 1, 0, 1, 0, 1, 0, 1}, 
                             {1, 1, 1, 1, 1, 1, 1, 1}, 
                             {0, 1, 0, 1, 0, 1, 0, 1}, 
                             {1, 1, 1, 1, 1, 1, 1, 1}, 
                             {0, 1, 0, 1, 0, 1, 0, 1}, 
                             {1, 1, 1, 1, 1, 1, 1, 1}, 
                             {0, 1, 0, 1, 0, 1, 0, 1}, 
                             {1, 1, 1, 1, 1, 1, 1, 1}}; 

    int watermark[ROWS][COLS] = {{0, 0, 0, 0, 1, 0, 0, 0}, 
                                  {0, 0, 0, 1, 0, 1, 0, 0}, 
                                  {0, 0, 1, 0, 0, 0, 1, 0}, 
                                  {0, 1, 0, 0, 0, 0, 0, 1}, 
                                  {1, 1, 1, 1, 1, 1, 1, 1}, 
                                  {0, 1, 0, 0, 0, 0, 0, 1}, 
                                  {0, 0, 1, 0, 0, 0, 1, 0}, 
                                  {0, 0, 0, 1, 0, 1, 0, 0}}; 

    printf("Original Image:\n"); 
    printMatrix(image); 

    printf("Watermark to Embed:\n"); 
    printMatrix(watermark); 

    embedWatermark(image, watermark); 

    printf("Image with Embedded Watermark:\n"); 
    printMatrix(image); 

    int extractedWatermark[ROWS][COLS]; 

    extractWatermark(image, extractedWatermark); 

    printf("Extracted Watermark:\n"); 
    printMatrix(extractedWatermark); 

    return 0; 
}