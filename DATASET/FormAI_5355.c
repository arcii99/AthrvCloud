//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>

// Function to shift a given shape
void shapeShift(int shape[][2], int size, int shiftX, int shiftY) {
    // Shifting shape in x and y directions
    for (int i = 0; i < size; i++) {
        shape[i][0] += shiftX;
        shape[i][1] += shiftY;
    }
}

// Function to print the given shape
void printShape(int shape[][2], int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d,%d)\n", shape[i][0], shape[i][1]);
    }
}

int main() {
    // Defining the shape as an array of points
    int shape[][2] = {{0,0}, {0,1}, {1,1}, {1,0}};
    
    // Printing the original shape
    printf("Original Shape:\n");
    printShape(shape, 4);
    
    // Shifting the shape in x and y directions
    shapeShift(shape, 4, 2, 3);
    
    // Printing the shifted shape
    printf("Shifted Shape:\n");
    printShape(shape, 4);
    
    // Shifting the shape in x direction only
    shapeShift(shape, 4, 2, 0);
    
    // Printing the shifted shape
    printf("Shifted Shape in X direction:\n");
    printShape(shape, 4);
    
    // Shifting the shape in y direction only
    shapeShift(shape, 4, 0, 3);
    
    // Printing the shifted shape
    printf("Shifted Shape in Y direction:\n");
    printShape(shape, 4);
    
    return 0;
}