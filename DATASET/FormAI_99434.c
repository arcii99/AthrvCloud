//FormAI DATASET v1.0 Category: Image Classification system ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the happy C Image Classification system example program!\n");

    // Initialize image
    int image[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    // Print image
    printf("Original image:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Classify image
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += image[i][j];
        }
    }

    if (sum > 30) {
        printf("This is a happy image!\n");
    } else {
        printf("This is not a happy image.\n");
    }

    printf("Thank you for using the happy C Image Classification system example program!\n");
    return 0;
}