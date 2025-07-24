//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include<stdio.h>
#include<math.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area;

    printf("Enter the coordinates of the first point (x1,y1): ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinates of the second point (x2,y2): ");
    scanf("%d%d",&x2,&y2);
    printf("Enter the coordinates of the third point (x3,y3): ");
    scanf("%d%d",&x3,&y3);

    a = sqrt(pow((x2-x1),2)+pow((y2-y1),2)); //distance formula
    b = sqrt(pow((x3-x2),2)+pow((y3-y2),2));
    c = sqrt(pow((x1-x3),2)+pow((y1-y3),2));

    if(a+b>c && b+c>a && c+a>b) //Checking if the triangle is valid
    {
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c)); //Heron's formula

        printf("Side 1 is %.2f units, Side 2 is %.2f units, Side 3 is %.2f units.\n", a,b,c);
        printf("Area of the triangle is: %.2f square units.\n", area);
    }
    else
    {
        printf("Invalid triangle.\n");
    }

    return 0;
}