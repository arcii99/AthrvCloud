//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
    int size;
    
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Size too small. Please enter a size of 2 or above.\n");
        return 1;
    }

    int spaces = size - 1;
    
    printf("Here's your pattern!\n");

    for (int i = 1; i <= size; i++) {
        // print spaces
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }

        // print stars for top half of pattern
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        // print stars for bottom half of pattern
        for (int j = i - 1; j >= 1; j--) {
            printf("* ");
        }

        printf("\n");
        spaces--;
    }

    return 0;
}