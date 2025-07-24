//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

struct point{
    float x;
    float y;
};

float distance(struct point a, struct point b){
    float dist;
    dist = sqrt(pow((b.x - a.x),2) + pow((b.y-a.y),2));
    return dist;
}

int main(){
    struct point p1, p2, p3;
    float a, b, c, s, area;

    printf("Enter coordinates of point 1: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates of point 2: ");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Enter coordinates of point 3: ");
    scanf("%f %f", &p3.x, &p3.y);

    a = distance(p1, p2);
    b = distance(p2, p3);
    c = distance(p3, p1);

    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("Area of the triangle is: %.2f", area);

    return 0;
}