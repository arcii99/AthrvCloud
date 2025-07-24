//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
} Point;

double euclidean_distance(Point a, Point b){
    return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}

int main(){
    printf("Enter the coordinates of three points:\n");
    Point a, b, c;
    printf("A:\n");
    scanf("%lf %lf", &a.x, &a.y);
    printf("B:\n");
    scanf("%lf %lf", &b.x, &b.y);
    printf("C:\n");
    scanf("%lf %lf", &c.x, &c.y);

    double ab = euclidean_distance(a, b);
    double bc = euclidean_distance(b, c);
    double ac = euclidean_distance(a, c);

    double max_distance = 0;
    Point farthest_point;
    if(ab > max_distance){
        max_distance = ab;
        farthest_point = c;
    }
    if(bc > max_distance){
        max_distance = bc;
        farthest_point = a;
    }
    if(ac > max_distance){
        max_distance = ac;
        farthest_point = b;
    }

    printf("Farthest point from the line formed by the other two points: (%.2lf, %.2lf)\n", farthest_point.x, farthest_point.y);

    return 0;
}