//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

/* Decentralized area calculation for a triangle */

struct Point {
    float x, y;
};

float area(struct Point A, struct Point B, struct Point C) {
    float a, b, c;
    a = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    b = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    c = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    struct Point A, B, C;
    printf("Enter the coordinates of the first point A:\n");
    scanf("%f%f", &A.x, &A.y);
    printf("Enter the coordinates of the second point B:\n");
    scanf("%f%f", &B.x, &B.y);
    printf("Enter the coordinates of the third point C:\n");
    scanf("%f%f", &C.x, &C.y);
    float area_ABC = area(A, B, C);
    printf("The area of the triangle ABC is: %.2f\n", area_ABC);
    return 0;
}