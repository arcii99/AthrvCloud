//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {

    printf("\nWOW! I am going to print a unique C pattern!\n\n");

    int rows, cols, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("\nHere comes the C pattern:\n\n");

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(i == 0 || i == rows-1 || (j == 0 && i<=rows/2) || (j == cols-1 && i>=rows/2))
                printf("C");    // print "C" for the upper part, lower part and the two vertical strokes
            else
                printf(" ");    // print a space for the rest of the pattern
        }
        printf("\n");           // move to the next line after each row is printed
    }

    printf("\nWOW! That was a unique C pattern! \n");

    return 0;
}