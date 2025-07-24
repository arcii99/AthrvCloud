//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include<stdio.h>
#include<math.h>

typedef struct {
    float x;
    float y;
} Point;

float distance(Point p1, Point p2){
    float d = sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
    return d;
}

float area(Point p1, Point p2, Point p3){
    float a = distance(p1, p2);
    float b = distance(p1, p3);
    float c = distance(p2, p3);
    float s = (a+b+c)/2;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

int main(){
    Point p1, p2, p3;
    printf("Enter coordinates of point 1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Enter coordinates of point 2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);
    printf("Enter coordinates of point 3 (x y): ");
    scanf("%f %f", &p3.x, &p3.y);

    float a = area(p1, p2, p3);
    printf("Area of the triangle is: %.2f\n", a);

    return 0;
}