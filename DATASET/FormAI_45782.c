//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include<stdio.h>

float areaTriangle(float a, float b, float c) {
    // using Heron's formula to calculate the area of a triangle
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    float a, b, c;
    printf("Enter the sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if(a + b > c && b + c > a && c + a > b) {
        printf("The area of the triangle is: %f\n", areaTriangle(a, b, c));
    }
    else {
        printf("The sides do not form a valid triangle. Please try again.\n");
    }

    return 0;
}