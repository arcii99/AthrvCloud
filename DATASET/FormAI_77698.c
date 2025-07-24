//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <math.h>

// Defining the structure of a point
struct Point
{
    float x;
    float y;
};

// Defining the structure of a line
struct Line
{
    struct Point p1;
    struct Point p2;
};

// Function to calculate the distance between two points
float distance(struct Point p1, struct Point p2)
{
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dist = sqrt(dx*dx + dy*dy);
    return dist;
}

// Function to check if a point lies on a line
int onLine(struct Point p, struct Line l)
{
    float d1 = distance(p, l.p1);
    float d2 = distance(p, l.p2);
    float d = distance(l.p1, l.p2);
    if (d1+d2 == d)
    {
        return 1;
    }
    return 0;
}

// Function to check if two line segments intersect
int intersect(struct Line l1, struct Line l2)
{
    struct Point p1 = l1.p1;
    struct Point q1 = l1.p2;
    struct Point p2 = l2.p1;
    struct Point q2 = l2.p2;
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1!=o2 && o3!=o4)
    {
        return 1;
    }
    if (o1==0 && onLine(p2, l1))
    {
        return 1;
    }
    if (o2==0 && onLine(q2, l1))
    {
        return 1;
    }
    if (o3==0 && onLine(p1, l2))
    {
        return 1;
    }
    if (o4==0 && onLine(q1, l2))
    {
        return 1;
    }
    return 0;
}

// Function to calculate the orientation of three points
int orientation(struct Point p, struct Point q, struct Point r)
{
    float val = (q.y - p.y) * (r.x - q.x) -
                (q.x - p.x) * (r.y - q.y);
    if (val == 0)
    {
        return 0;
    }
    if (val > 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

// Main function
int main()
{
    struct Point a = {1, 1};
    struct Point b = {2, 2};
    struct Point c = {3, 3};
    struct Point d = {4, 4};
    struct Line ab = {a, b};
    struct Line cd = {c, d};
    int intersecting = intersect(ab, cd);
    if (intersecting)
    {
        printf("The two line segments intersect\n");
    }
    else
    {
        printf("The two line segments do not intersect\n");
    }
    return 0;
}