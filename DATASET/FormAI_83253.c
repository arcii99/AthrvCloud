//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3){
    double a = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    double b = sqrt(pow((x3 - x2),2) + pow((y3 - y2),2));
    double c = sqrt(pow((x3 - x1),2) + pow((y3 - y1),2));
    double s = (a + b + c)/2;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

int main(){
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first vertex of the triangle (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the second vertex of the triangle (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of the third vertex of the triangle (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);

    double area = triangle_area(x1, y1, x2, y2, x3, y3);
    printf("The area of the triangle is: %lf\n", area);

    return 0;
}