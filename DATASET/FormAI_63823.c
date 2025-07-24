//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include<stdio.h>
#include<math.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area;

    printf("Enter the coordinates of vertex 1 (x1, y1): \n");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of vertex 2 (x2, y2): \n");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of vertex 3 (x3, y3): \n");
    scanf("%d %d", &x3, &y3);

    a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    b=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));

    printf("The area of the given triangle is: %f", area);

    return 0;
}