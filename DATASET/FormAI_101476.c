//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include<stdio.h>
#include<math.h>

// function to get the distance between two points
float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main(){
    // declaring variables
    float x1, y1, x2, y2, x3, y3, area;

    // taking input of points
    printf("Enter value of x1: ");
    scanf("%f", &x1);
    printf("Enter value of y1: ");
    scanf("%f", &y1);
    printf("Enter value of x2: ");
    scanf("%f", &x2);
    printf("Enter value of y2: ");
    scanf("%f", &y2);
    printf("Enter value of x3: ");
    scanf("%f", &x3);
    printf("Enter value of y3: ");
    scanf("%f", &y3);

    // calculating length of sides using distance equation
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    // calculating semi-perimeter of triangle
    float s = (a+b+c)/2;

    // calculating area of the triangle using Heron's formula 
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("The area of the given triangle is %.2f", area);

    return 0;
}