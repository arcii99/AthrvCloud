//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>

//This program calculates the area of a triangle given its three vertices

typedef struct{
    float x;
    float y;
}point;

//function to calculate distance between two points
float distance(point p1, point p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

//function to calculate the area of a triangle given three points
float area(point p1, point p2, point p3){
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(){
    point p1, p2, p3;
    printf("Enter the coordinates of the first vertex (x,y):\n");
    scanf("%f,%f", &p1.x, &p1.y);
    printf("Enter the coordinates of the second vertex (x,y):\n");
    scanf("%f,%f", &p2.x, &p2.y);
    printf("Enter the coordinates of the third vertex (x,y):\n");
    scanf("%f,%f", &p3.x, &p3.y);

    float result = area(p1, p2, p3);
    printf("The area of the triangle is: %f", result);

    return 0;
}