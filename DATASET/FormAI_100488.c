//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>

// function to calculate the distance between two points
float distance(int x1, int y1, int x2, int y2) {
    float d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of three points: \n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Calculating the sides of the triangle
    float a, b, c;
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);

    // Calculating the semiperimeter and area of the triangle
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Printing the output
    printf("The sides of the triangle are: a = %.2f, b = %.2f, c = %.2f\n", a, b, c);
    printf("The semiperimeter of the triangle is: %.2f\n", s);
    printf("The area of the triangle is: %.2f\n", area);

    return 0;
}