//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point{
    double x,y;
}Point;

double dist(Point p1, Point p2){
    return sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));
}

bool onSegment(Point p, Point q, Point r){
    if(q.x <= fmax(p.x, r.x) && q.x >= fmax(p.x, r.x) && q.y <= fmax(p.y, r.y)
            && q.y >= fmin(p.y, r.y))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r){
   double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
   if (val == 0) return 0; 
   return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}

int main(){
    Point p1 = {0, 0}, q1 = {10, 0};
    Point p2 = {5, 5}, q2 = {7, 7};
    if(doIntersect(p1, q1, p2, q2))
        printf("Segments intersect.\n");
    else
        printf("Segments do not intersect.\n");
    
    printf("Distance between (%lf,%lf) and (%lf,%lf) is %lf.\n",p1.x,p1.y,q1.x,q1.y,dist(p1,q1));

    return 0;
}