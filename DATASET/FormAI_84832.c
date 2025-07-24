//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include<stdio.h>
#include<math.h>

struct point
{
    int x;
    int y;
};

float distance(struct point a, struct point b)
{
    float dist;
    dist = sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
    return dist;
}

int main()
{
    struct point p1, p2;
    printf("Enter the x and y coordinates of first point:\n");
    scanf("%d %d",&p1.x, &p1.y);
    printf("Enter the x and y coordinates of second point:\n");
    scanf("%d %d",&p2.x, &p2.y);
    printf("The distance between the two points is %.2f\n", distance(p1,p2));

    return 0;
}