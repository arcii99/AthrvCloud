//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define initial shapes
int shape1[] = {1, 1, 1, 1};
int shape2[] = {2, 2, 2, 2};
int shape3[] = {3, 3, 3, 3};
int* currentShape;
int currentShapeSize;

// Define shape shifting function
void shiftShape() {
    // Get a random number between 1 and 3
    int randomNum = rand() % 3 + 1;

    // Determine the new shape based on the random number
    switch (randomNum) {
        case 1:
            currentShape = shape1;
            currentShapeSize = sizeof(shape1) / sizeof(int);
            break;
        case 2:
            currentShape = shape2;
            currentShapeSize = sizeof(shape2) / sizeof(int);
            break;
        case 3:
            currentShape = shape3;
            currentShapeSize = sizeof(shape3) / sizeof(int);
            break;
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Set the initial shape
    currentShape = shape1;
    currentShapeSize = sizeof(shape1) / sizeof(int);

    // Print the initial shape
    printf("Current Shape:\n");
    for (int i = 0; i < currentShapeSize; i++) {
        printf("%d ", currentShape[i]);
    }
    printf("\n\n");

    // Continuously shift the shape every 3 seconds
    while (1) {
        // Shift the shape
        shiftShape();

        // Print the new shape
        printf("New Shape:\n");
        for (int i = 0; i < currentShapeSize; i++) {
            printf("%d ", currentShape[i]);
        }
        printf("\n\n");

        // Wait for 3 seconds
        printf("Waiting for 3 seconds...\n\n");
        sleep(3);
    }

    return 0;
}