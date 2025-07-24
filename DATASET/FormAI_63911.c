//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
// Romeo and Juliet's Geometric Algorithm
// A program to calculate the distance between two points in a Cartesian plane
// Written by: Juliet

#include <stdio.h>
#include <math.h>

int main() {
    // Romeo traces his fingers over the coordinates of Juliet's heart
    int x1, x2, y1, y2;

    printf("Romeo, enter the coordinates of Juliet's heart:\n");
    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);

    // Juliet's heart beats faster at the sight of Romeo's strong hands
    printf("Juliet, enter the coordinates of Romeo's hands:\n");
    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);

    // Romeo calculates the distance between the two points
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Juliet's heart flutters as Romeo presents the answer with a flourish
    printf("The distance between Juliet's heart and Romeo's hands is: %lf", distance);

    return 0;
}