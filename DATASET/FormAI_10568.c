//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c;

    printf("Enter the sides of triangle:\n");
    scanf("%f%f%f", &a, &b, &c);
    //Checking if it forms a triangle or not
    if((a+b)>c && (a+c)>b && (b+c)>a){
        //Calculating the perimeter and semi-perimeter
        float perimeter = a+b+c;
        float s = perimeter/2;
        //Calculating the area of the triangle using Heron's formula
        float area = sqrt(s*(s-a)*(s-b)*(s-c));

        printf("Perimeter of the triangle: %.2f units\n", perimeter);
        printf("Area of the triangle: %.2f sq. units\n", area);
        //Calculating the inradius
        float inradius = area/s;

        printf("Inradius of the triangle: %.2f units\n", inradius);

        //Calculating the circumradius
        float circumradius = (a*b*c)/(4*area);

        printf("Circumradius of the triangle: %.2f units\n", circumradius);

        //Calculating the centroid and orthocenter of the triangle
        float centroid_x = (a+b+c)/3;
        float centroid_y = (sqrt(3)/3)*(a+b+c)/3;
        float orthocenter_x = (a*a + b*b - c*c)/(2*b);
        float orthocenter_y = (sqrt(a*a - orthocenter_x*orthocenter_x));

        printf("Centroid of the triangle: (%.2f, %.2f)\n", centroid_x, centroid_y);
        printf("Orthocenter of the triangle: (%.2f, %.2f)\n", orthocenter_x, orthocenter_y);

    }else{
        printf("Sides do not form a triangle.\n");
    }

    return 0;
}