//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include<stdio.h>
#include<math.h>

typedef struct 
{
    float x;
    float y;
}Point;

float distance(Point p1, Point p2)
{
    float x = (p2.x - p1.x);
    float y = (p2.y - p1.y);
    
    return sqrt(x*x + y*y);
}

int main()
{
    Point p1, p2, p3;
    float perimeter, area;
    
    printf("Enter the coordinates of P1: ");
    scanf("%f %f",&p1.x,&p1.y);
    printf("Enter the coordinates of P2: ");
    scanf("%f %f",&p2.x,&p2.y);
    printf("Enter the coordinates of P3: ");
    scanf("%f %f",&p3.x,&p3.y);
    
    float a = distance(p1,p2);
    float b = distance(p2,p3);
    float c = distance(p3,p1);
    
    if(a+b>c && b+c>a && c+a>b)
    {
        perimeter = a+b+c;
        float s = perimeter/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        
        printf("Perimeter: %f\n",perimeter);
        printf("Area: %f",area);
    }
    else
    {
        printf("Invalid triangle.");
    }
    
    return 0;
}