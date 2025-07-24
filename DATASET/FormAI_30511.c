//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: genious
#include<stdio.h>
#include<math.h>

int main(){
    // Welcome message for the user
    printf("Welcome to the geometric algorithms program!\n");

    // Taking input from the user
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of point A: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of point B: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of point C: ");
    scanf("%f %f", &x3, &y3);

    // Calculating the distance between points
    float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    // Calculating the perimeter of the triangle
    float perimeter = AB + BC + AC;

    // Calculating the semiperimeter
    float s = perimeter / 2;

    // Calculating the area of the triangle using Heron's formula
    float area = sqrt(s * (s - AB) * (s - BC) * (s - AC));

    // Calculating the angle between BC and BA
    float angle_BA_BC = atan2((y2-y1), (x2-x1)) - atan2((y3-y2), (x3-x2));
    angle_BA_BC = angle_BA_BC * (180/3.14159);

    // Calculating the angle between AC and AB
    float angle_AB_AC = atan2((y1-y3), (x1-x3)) - atan2((y2-y1), (x2-x1));
    angle_AB_AC = angle_AB_AC * (180/3.14159);

    // Printing the results
    printf("\nThe distance between point A and point B is: %f\n", AB);
    printf("The distance between point B and point C is: %f\n", BC);
    printf("The distance between point A and point C is: %f\n", AC);
    printf("The perimeter of the triangle is: %f\n", perimeter);
    printf("The area of the triangle is: %f\n", area);
    printf("The angle between BC and BA is: %f degrees\n", angle_BA_BC);
    printf("The angle between AC and AB is: %f degrees\n", angle_AB_AC);

    return 0;
}