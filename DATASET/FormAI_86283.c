//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include<stdio.h>
#include<math.h>

// function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2){
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

// function to calculate the area of a triangle given three sides
float triangle_area(float a, float b, float c){
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

int main(){
    float x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of three points:\n");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);

    float dist1 = distance(x1, y1, x2, y2);
    float dist2 = distance(x2, y2, x3, y3);
    float dist3 = distance(x3, y3, x1, y1);

    float perimeter = dist1 + dist2 + dist3;
    float area = triangle_area(dist1, dist2, dist3);

    printf("Perimeter of triangle: %.2f\n", perimeter);
    printf("Area of triangle: %.2f\n", area);

    return 0;
}