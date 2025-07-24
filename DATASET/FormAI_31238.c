//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include<stdio.h>
#include<math.h>

struct Point
{
    double x,y;
};

// A function to calculate the distance between two points
double distance(struct Point p1, struct Point p2)
{
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

// A function to calculate the area of a triangle using Shoelace formula
double area(struct Point A, struct Point B, struct Point C)
{
    double area = 0.5 * fabs((A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x));
    return area;
}

// A function to check if a point lies inside a triangle or not
int isInsideTriangle(struct Point A, struct Point B, struct Point C, struct Point P)
{
    double ABC = area(A,B,C);
    double ABP = area(A,B,P);
    double BCP = area(B,C,P);
    double CAP = area(C,A,P);
    if(ABC == ABP + BCP + CAP)
        return 1;
    else
        return 0;
}

int main()
{
    struct Point A,B,C,P;
    printf("Enter the coordinates of vertex A: ");
    scanf("%lf %lf",&A.x,&A.y);
    printf("Enter the coordinates of vertex B: ");
    scanf("%lf %lf",&B.x,&B.y);
    printf("Enter the coordinates of vertex C: ");
    scanf("%lf %lf",&C.x,&C.y);
    printf("Enter the coordinates of point P: ");
    scanf("%lf %lf",&P.x,&P.y);

    double perimeter = distance(A,B) + distance(B,C) + distance(C,A);
    double s = perimeter/2;
    double area_of_triangle = sqrt(s*(s-distance(A,B))*(s-distance(B,C))*(s-distance(C,A)));

    if(isInsideTriangle(A,B,C,P))
        printf("Point P lies inside the triangle\n");
    else
        printf("Point P does not lie inside the triangle\n");

    printf("The perimeter of the triangle is: %.2lf\n",perimeter);
    printf("The area of the triangle is: %.2lf",area_of_triangle);

    return 0;
}