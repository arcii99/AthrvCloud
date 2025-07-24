//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    char text[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int i, j, k;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            k = i*cols + j;
            if(text[k] != 0) {
                printf("%c  ", text[k]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    return 0;
}