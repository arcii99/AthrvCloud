//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

// Define a structure for a rectangle
struct Rectangle {
    float width;
    float height;
};

// Define a function to calculate the area of a rectangle
float area(struct Rectangle rect) {
    return rect.width * rect.height;
}

// Define a function to calculate the perimeter of a rectangle
float perimeter(struct Rectangle rect) {
    return 2 * (rect.width + rect.height);
}

int main() {
    // Create a rectangle with width 5.0 and height 3.0
    struct Rectangle rect = {5.0, 3.0};

    // Print the area and perimeter of the rectangle
    printf("The area of the rectangle is %.2f\n", area(rect));
    printf("The perimeter of the rectangle is %.2f\n", perimeter(rect));

    return 0;
}