//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define ROW 50
#define COL 50

void printArray(char matrix[][COL], int row, int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    printf("Welcome to the Digital Watermarking Example Program - Relax and Let's get creative!\n");
    printf("This program is designed to illustrate how to embed digital watermark into an image.\n");

    // Initialize matrix with some data. In this example, it will be a 4x4 matrix of letter 'A'
    char matrix[ROW][COL];
    int i, j;
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            matrix[i][j] = 'A';
        }
    }

    printf("\nThe original image before embedding the watermark:\n");
    printArray(matrix, ROW, COL);

    // Let's embed the digital watermark in the image. We will choose letter 'W' as our digital watermark.
    // We will embed it in the bottom right corner of the image.
    matrix[ROW-1][COL-1] = 'W';

    printf("\nThe image after embedding the watermark:\n");
    printArray(matrix, ROW, COL);

    // Now, let's try to extract the digital watermark from the image.
    char watermark = matrix[ROW-1][COL-1];

    printf("\nThe digital watermark extracted from the image is: %c\n", watermark);

    printf("\nThat's it for the Digital Watermarking Example Program. Hope you enjoyed it!\n");

    return 0;
}