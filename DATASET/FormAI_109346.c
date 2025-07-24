//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <math.h>

//Function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    float dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    return dist;
}

//Function to calculate the area of a triangle using Heron's formula
float area(float a, float b, float c) {
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s-a) * (s-b) * (s-c));
    return area;
}

int main() {
    float x1, y1, x2, y2, x3, y3;

    //Getting coordinates of three points from user
    printf("Enter coordinates of point 1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter coordinates of point 2: ");
    scanf("%f %f", &x2, &y2);

    printf("Enter coordinates of point 3: ");
    scanf("%f %f", &x3, &y3);

    //Calculating the length of all the sides of the triangle
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    //Calculating the area of the triangle
    float triangle_area = area(a, b, c);

    //Checking if the three points lie on the same line or not.
    if(triangle_area == 0) {
        printf("The three points lie on the same line.\n");
    } else {
        printf("The three points do not lie on the same line.\n");
    }

    return 0;
}