//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <math.h>

int main(){
    printf("Welcome to the Triangle Calculator!\n");
    printf("Please enter the length of SIDE A:\n");
    double a;
    scanf("%lf", &a);
    printf("Please enter the length of SIDE B:\n");
    double b;
    scanf("%lf", &b);
    printf("Please enter the degree of ANGLE C:\n");
    double cDegrees;
    scanf("%lf", &cDegrees);
    double c = cDegrees * M_PI / 180;
    
    printf("\nCalculating...\n");
    double area = 0.5 * a * b * sin(c);
    double perimeter = a + b + sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(c));
    double height1 = b * sin(c);
    double height2 = a * sin(c);
    double height = height1 < height2 ? height1 : height2;
    double angleA = asin(a * sin(c) / perimeter) * 180 / M_PI;
    double angleB = asin(b * sin(c) / perimeter) * 180 / M_PI;
    
    printf("\nThe area of the triangle is %.2f square units!\n", area);
    printf("The perimeter of the triangle is %.2f units!\n", perimeter);
    printf("The height of the triangle is %.2f units!\n", height);
    printf("The angles of the triangle are %.2f degrees and %.2f degrees!\n", angleA, angleB);
    
    if(angleA == 90 || angleB == 90 || cDegrees == 90){
        printf("Wow, that's a right triangle! I haven't seen one of those in a while!\n");
    }
    else if(angleA == angleB && angleB == cDegrees/3){
        printf("That's an equilateral triangle! I feel like doing a little dance!\n");
    }
    else if(angleA == angleB && angleB != cDegrees/3 || angleA == cDegrees/3 && angleB != cDegrees/3 || angleB == cDegrees/3 && angleA != cDegrees/3){
        printf("That's an isosceles triangle! That's like me, always two of a kind!\n");
    }
    else{
        printf("That's just your average, run-of-the-mill triangle. Nothing special, but still kinda cool!\n");
    }
    
    return 0;
}