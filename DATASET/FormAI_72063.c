//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
// Ada Lovelace Style C Program: Geometric Algorithms

#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  

typedef struct{  
    double x,y;  
}Point;  

// Function to calculate distance between two points
double calculateDistance(Point p1, Point p2){  
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));  
} 

// Function to calculate perimeter of a given rectangle
double calculatePerimeter(Point A, Point B){  
    double length, width, perimeter;
    length = fabs(B.x - A.x);  
    width = fabs(B.y - A.y);  
    perimeter = 2*(length + width);  
    return perimeter;  
}  

// Function to calculate area of a given rectangle
double calculateArea(Point A, Point B){  
    double length, width, area;  
    length = fabs(B.x - A.x);  
    width = fabs(B.y - A.y);  
    area = length * width;  
    return area;  
}  

// Function to check if a given point lies inside a rectangle or not
int isPointInside(Point point, Point A, Point B){
    double Max_x = fmax(A.x, B.x);  
    double Min_x = fmin(A.x, B.x);  
    double Max_y = fmax(A.y, B.y);  
    double Min_y = fmin(A.y, B.y);
    if(point.x >= Min_x && point.x <= Max_x && point.y >= Min_y && point.y <= Max_y)
        return 1;
    else
        return 0;
}

int main(){  
    Point A, B, P;
    double d, perimeter, area;
    printf("Enter the co-ordinates of Point A\n");  
    scanf("%lf%lf", &A.x, &A.y);  
    printf("Enter the co-ordinates of Point B\n");  
    scanf("%lf%lf", &B.x, &B.y);  
    printf("Enter the co-ordinates of Point P\n");  
    scanf("%lf%lf", &P.x, &P.y);  
    d = calculateDistance(A, B);
    perimeter = calculatePerimeter(A, B);
    area = calculateArea(A, B);
    printf("Distance between point A and point B is: %lf\n", d);
    printf("Perimeter of rectangle formed with points A and B is: %lf\n", perimeter);
    printf("Area of rectangle formed with points A and B is: %lf\n", area);
    if(isPointInside(P, A, B))
        printf("Point P lies inside the rectangle formed by points A and B.\n");
    else
        printf("Point P does not lie inside the rectangle formed by points A and B.\n");
    return 0;  
}