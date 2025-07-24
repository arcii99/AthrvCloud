//FormAI DATASET v1.0 Category: Pattern printing ; Style: immersive
#include<stdio.h>

int main() {

    // Let's print a unique pattern in C!
    printf("Let's print a pattern in C!\n\n");

    // Declare the size of the pattern
    int size = 5;

    // Loop through the rows and columns to print the pattern
    for(int i = 1; i <= size; i++) {
        for(int j = size; j > 0; j--) {
            if(j <= i) {
                printf("%d", j);
            } else {
                printf(" ");
            }
        }
        for(int j = 1; j <= size; j++) {
            if(j <= i) {
                printf("%d", j);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Let's add a description of the pattern printed
    printf("\nThis pattern is called a diamond pattern. It consists of two triangles, one pointing up and the other pointing down, with the same base. The pattern is symmetric and gives a diamond shape, hence the name.\n");

    return 0;
}