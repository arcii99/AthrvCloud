//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute the distance between two points
float get_distance(int x1, int y1, int x2, int y2) {
    int x_diff = x2 - x1;
    int y_diff = y2 - y1;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Main function
int main() {
    int x1, y1, x2, y2;
    printf("Enter the x and y coordinates of the first point:\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter the x and y coordinates of the second point:\n");
    scanf("%d %d", &x2, &y2);
    float distance = get_distance(x1, y1, x2, y2);
    printf("The distance between the two points is %f\n", distance);
    return 0;
}