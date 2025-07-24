//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

void printLine(int n, char c) {
    for(int i=1; i<=n; i++) {
        printf("%c ", c);
    }
    printf("\n");
}

int main() {
    printf("Printing a unique 'C' pattern!\n");

    int height;
    printf("Enter the height of the 'C': ");
    scanf("%d", &height);
    printf("\n");

    int width = height/2 + 3;

    // Printing the upper part of the 'C'
    for(int i=1; i<=width; i++) {
        if(i == width || i == 1 || i == 2) {
            printLine(height, '*');
        } else {
            printf("*\n");
        }
    }

    // Printing the center part of the 'C'
    for(int i=1; i<=height/2; i++) {
        printLine(3, '*');
    }

    // Printing the lower part of the 'C'
    for(int i=1; i<=width; i++) {
        if(i == width || i == 1 || i == 2) {
            printLine(height, '*');
        } else {
            printf("*\n");
        }
    }

    return 0;
}