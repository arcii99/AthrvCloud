//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

//function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2) {
    float dist = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    return dist;
}

int main() {
    float x1,y1,x2,y2,x3,y3;
    printf("Enter coordinates of three points:\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    float s = (a + b + c) / 2;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area of the triangle formed by the three points = %.2f square units",area);

    return 0;
}