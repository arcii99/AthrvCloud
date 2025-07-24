//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>

// Function to calculate the Euclidean Distance between two points
float euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float side1, side2, side3;

    printf("Enter the coordinates of first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of third point (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Calculate the length of all sides of the triangle
    side1 = euclideanDistance(x1, y1, x2, y2);
    side2 = euclideanDistance(x2, y2, x3, y3);
    side3 = euclideanDistance(x3, y3, x1, y1);

    // Check if the given sides form a triangle or not
    if ((side1 + side2) <= side3 || (side1 + side3) <= side2 || (side2 + side3) <= side1) {
        printf("\nGiven points do not form a triangle.\n");
        return 0;
    }

    // Check for the type of the triangle
    if (side1 == side2 && side2 == side3) {
        printf("\nEquilateral Triangle.\n");
    } else if (side1 == side2 || side2 == side3 || side1 == side3) {
        printf("\nIsosceles Triangle.\n");
    } else if (side1 != side2 && side2 != side3 && side1 != side3) {
        printf("\nScalene Triangle.\n");
    }

    return 0;
}