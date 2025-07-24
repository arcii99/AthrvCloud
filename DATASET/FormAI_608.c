//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include<stdio.h>
#include<math.h>

//Function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {

    //Take input from user
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point: ");
    scanf("%f %f", &x3, &y3);

    //Calculate the unique sides and angles of the triangle
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);
    float A = acos((b*b + c*c - a*a)/(2*b*c));
    float B = acos((a*a + c*c - b*b)/(2*a*c));
    float C = acos((a*a + b*b - c*c)/(2*a*b));

    //Print out the unique properties of the triangle
    printf("\nUnique Sides: a = %.2f  b = %.2f  c = %.2f", a, b, c);
    printf("\nUnique Angles: A = %.2f  B = %.2f  C = %.2f\n", A, B, C);

    return 0;
}