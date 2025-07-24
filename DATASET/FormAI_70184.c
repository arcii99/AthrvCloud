//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c;
    float s, area;

    printf("Enter the lengths of the sides of a triangle:\n");
    scanf("%d %d %d", &a, &b, &c);

    s = (float)(a+b+c)/2;

    area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("Area of the triangle = %f", area);

    return 0;
}