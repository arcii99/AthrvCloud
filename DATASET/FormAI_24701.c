//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
    int x,y;
};

struct Shape
{
    int type;
    struct Point *points;
    int num_points;
};

float get_distance(struct Point p1, struct Point p2)
{
    return sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));
}

float get_perimeter(struct Shape s)
{
    int i;
    float perimeter = 0.0;
    for(i=0; i<s.num_points-1; i++)
    {
        perimeter += get_distance(s.points[i],s.points[i+1]);
    }
    perimeter += get_distance(s.points[s.num_points-1],s.points[0]);
    return perimeter;
}

int main()
{
    int num_shapes,i,j,k;
    printf("Enter the number of shapes: ");
    scanf("%d",&num_shapes);

    struct Shape shapes[num_shapes];
    for(i=0; i<num_shapes; i++)
    {
        printf("Enter the type of shape %d (1 for triangle, 2 for square): ",i+1);
        scanf("%d",&shapes[i].type);

        printf("Enter the number of points in shape %d: ",i+1);
        scanf("%d",&shapes[i].num_points);

        shapes[i].points = (struct Point*)malloc(shapes[i].num_points*sizeof(struct Point));
        for(j=0; j<shapes[i].num_points; j++)
        {
            printf("Enter x coordinate of point %d: ",j+1);
            scanf("%d",&shapes[i].points[j].x);

            printf("Enter y coordinate of point %d: ",j+1);
            scanf("%d",&shapes[i].points[j].y);
        }
    }

    for(i=0; i<num_shapes; i++)
    {
        printf("Shape %d - Perimeter: %.2f\n",i+1,get_perimeter(shapes[i]));
    }

    for(i=0; i<num_shapes; i++)
    {
        free(shapes[i].points);
    }

    return 0;
}