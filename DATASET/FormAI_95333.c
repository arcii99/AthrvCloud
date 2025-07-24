//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>

#define MAX_SIZE 100

void watermark(char (*text)[MAX_SIZE], char (*mark)[MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if((*text)[i*cols+j] != ' ' && (*text)[i*cols+j] != '\t' && (*text)[i*cols+j] != '\n') {
                (*text)[i*cols+j] = (*text)[i*cols+j] | (*mark)[i*cols+j];
            }
        }
    }
}

int main() {
    char text[MAX_SIZE][MAX_SIZE];
    char mark[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    
    printf("Enter the number of rows in text: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in text: ");
    scanf("%d", &cols);
    
    printf("Enter the text:\n");
    for(int i = 0; i < rows; i++) {
        scanf("%s", text[i]);
    }
    
    printf("Enter the watermark:\n");
    for(int i = 0; i < rows; i++) {
        scanf("%s", mark[i]);
    }
    
    watermark(text, mark, rows, cols);
    
    printf("The watermarked text is:\n");
    for(int i = 0; i < rows; i++) {
        printf("%s\n", text[i]);
    }
    
    return 0;
}