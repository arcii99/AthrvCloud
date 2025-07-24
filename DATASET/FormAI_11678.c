//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <stdbool.h>

// define a structure for a point with x and y coordinates
struct point {
   double x;
   double y;
};

// define a structure for a line segment with two points
struct line {
   struct point p1;
   struct point p2;
};

// function to calculate the distance between two points
double distance(struct point p1, struct point p2) {
   double x_diff = p2.x - p1.x;
   double y_diff = p2.y - p1.y;
   return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// function to check if a point is on a line segment
bool is_on_line(struct point p, struct line l) {
   double d1 = distance(p, l.p1);
   double d2 = distance(p, l.p2);
   double line_dist = distance(l.p1, l.p2);
   double t = (d1 + d2) - line_dist;
   return fabs(t) < 0.001;
}

// function to check if two line segments intersect
bool do_lines_intersect(struct line l1, struct line l2) {
   double denom = ((l2.p2.y - l2.p1.y) * (l1.p2.x - l1.p1.x)) -
                 ((l2.p2.x - l2.p1.x) * (l1.p2.y - l1.p1.y));
   if (fabs(denom) < 0.001) {
       // lines are parallel
       return false;
   }
   double ua = (((l2.p2.x - l2.p1.x) * (l1.p1.y - l2.p1.y)) -
                ((l2.p2.y - l2.p1.y) * (l1.p1.x - l2.p1.x))) / denom;
   double ub = (((l1.p2.x - l1.p1.x) * (l1.p1.y - l2.p1.y)) -
                ((l1.p2.y - l1.p1.y) * (l1.p1.x - l2.p1.x))) / denom;
   return (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1);
}

int main() {
   struct point p1 = {1.0, 1.0};
   struct point p2 = {3.0, 3.0};
   struct point p3 = {2.0, 2.0};
   struct point p4 = {4.0, 4.0};
   struct point p5 = {5.0, 5.0};
   struct point p6 = {6.0, 6.0};
   struct point p7 = {7.0, 7.0};
   
   struct line l1 = {p1, p2};
   struct line l2 = {p3, p4};
   struct line l3 = {p5, p6};
   struct line l4 = {p6, p7};
   
   printf("Distance between p1 and p2: %f\n", distance(p1, p2));
   printf("Is p3 on l1? %s\n", is_on_line(p3, l1) ? "true" : "false");
   printf("Do l2 and l3 intersect? %s\n", do_lines_intersect(l2, l3) ? "true" : "false");
   printf("Do l3 and l4 intersect? %s\n", do_lines_intersect(l3, l4) ? "true" : "false");
   
   return 0;
}