//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: careful
#include<stdio.h>
#include<math.h>

// function to calculate the area of a triangle
float triangle_area(float x1, float y1, float x2, float y2, float x3, float y3){
    float area = 0.5 * fabs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
    return area;
}

// function to calculate the centroid of a triangle
void triangle_centroid(float x1, float y1, float x2, float y2, float x3, float y3, float *xc, float *yc){
    *xc = (x1 + x2 + x3)/3;
    *yc = (y1 + y2 + y3)/3;
}

// function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2){
    float dist = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    return dist;
}

int main(){
    float x1, y1, x2, y2, x3, y3;
    printf("Enter x and y coordinates of first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter x and y coordinates of second point: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter x and y coordinates of third point: ");
    scanf("%f %f", &x3, &y3);

    // calculate the area of triangle using given coordinates
    float area = triangle_area(x1, y1, x2, y2, x3, y3);
    printf("Area of the triangle is: %f \n", area);

    // calculate the centroid of triangle using given coordinates
    float xc, yc;
    triangle_centroid(x1, y1, x2, y2, x3, y3, &xc, &yc);
    printf("Centroid of the triangle is: (%f, %f) \n", xc, yc);

    // calculate the distance between first and second point
    float dist12 = distance(x1, y1, x2, y2);
    printf("Distance between first and second point is: %f \n", dist12);

    // calculate the distance between second and third point
    float dist23 = distance(x2, y2, x3, y3);
    printf("Distance between second and third point is: %f \n", dist23);

    // calculate the distance between third and first point
    float dist31 = distance(x3, y3, x1, y1);
    printf("Distance between third and first point is: %f \n", dist31);

    return 0;
}