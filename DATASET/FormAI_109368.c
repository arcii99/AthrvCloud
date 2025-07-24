//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Definition of a structure point with x and y coordinates */
struct Point{
    int x,y;
};

/* Definition of a structure line with two points */
struct Line{
    struct Point p1,p2;
};

/* Function to check if three points are in a straight line */
int isCollinear(struct Point p1, struct Point p2, struct Point p3){
    int collinear = (p2.y-p1.y)*(p3.x-p2.x) == (p3.y-p2.y)*(p2.x-p1.x);
    return collinear;
}

/* Function to calculate the distance between two points */
float distance(struct Point p1, struct Point p2){
    return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}

/* Function to calculate the area of a triangle */
float triangleArea(struct Point p1, struct Point p2, struct Point p3){
    float s = (distance(p1,p2) + distance(p2,p3) + distance(p3,p1))/2;
    float area = sqrt(s*(s-distance(p1,p2))*(s-distance(p2,p3))*(s-distance(p3,p1)));
    return area;
}

/* Function to find the intersection point of two lines */
struct Point findIntersection(struct Line l1, struct Line l2) {
    int x1 = l1.p1.x, x2 = l1.p2.x, x3 = l2.p1.x, x4 = l2.p2.x;
    int y1 = l1.p1.y, y2 = l1.p2.y, y3 = l2.p1.y, y4 = l2.p2.y;
    int numx = ((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4));
    int denx = ((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
    int numy = ((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4));
    int deny = ((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
    float x = (float)numx/denx;
    float y = (float)numy/deny;
    struct Point intersection = {x,y};
    return intersection;
}

/* Main function */
int main(){
    int n; // number of points
    struct Point *points;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    points = (struct Point*) malloc(n*sizeof(struct Point)); // Dynamically allocate memory for array of points
    printf("\nEnter the coordinates of the points: ");
    for(int i=0; i<n ;i++){
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    /* Steps to find the centroid of the polygon */
    float centroid_x=0, centroid_y=0;
    for(int i=0; i<n ;i++){
        centroid_x += points[i].x;
        centroid_y += points[i].y;
    }
    centroid_x /= n;
    centroid_y /= n;
    struct Point centroid = {centroid_x, centroid_y};
    printf("\nThe centroid of the polygon is (%.2f, %.2f).", centroid_x, centroid_y);

    /* Steps to find the area of the polygon */
    float area = 0;
    for(int i=0; i<n-2 ;i++){
        if(!isCollinear(points[i],points[i+1],points[i+2])){
            area += triangleArea(points[i],points[i+1],points[i+2]);
        }
    }
    printf("\nThe area of the polygon is %.2f.", area);

    /* Steps to find the shortest distance from a point to a line */
    struct Point p;
    struct Line l;
    printf("\nEnter the coordinates of the point: ");
    scanf("%d %d", &p.x, &p.y);
    printf("Enter the coordinates of the endpoints of the line: ");
    scanf("%d %d %d %d", &l.p1.x, &l.p1.y, &l.p2.x, &l.p2.y);
    float distance_point_line = (abs((l.p2.y-l.p1.y)*p.x - (l.p2.x-l.p1.x)*p.y + l.p2.x*l.p1.y - l.p2.y*l.p1.x))/sqrt(pow(l.p2.y-l.p1.y,2)+pow(l.p2.x-l.p1.x,2));
    printf("The shortest distance from the point (%d,%d) to the line passing through (%d,%d) and (%d,%d) is %.2f.", p.x, p.y, l.p1.x, l.p1.y, l.p2.x, l.p2.y, distance_point_line);

    /* Steps to find the intersection point of two lines */
    struct Line l1, l2;
    printf("\nEnter the coordinates of the endpoints of line 1: ");
    scanf("%d %d %d %d", &l1.p1.x, &l1.p1.y, &l1.p2.x, &l1.p2.y);
    printf("Enter the coordinates of the endpoints of line 2: ");
    scanf("%d %d %d %d", &l2.p1.x, &l2.p1.y, &l2.p2.x, &l2.p2.y);
    struct Point intersection_point = findIntersection(l1, l2);
    printf("The intersection point of the two lines is (%.2f, %.2f).", intersection_point.x, intersection_point.y);

    free(points); // Free the dynamically allocated memory
    return 0;
}